// A Trail Blazer handlebar controller, in about sixty lines.
//
// Reference implementation of docs/CONTROLLER_SPEC.md v1.0. It exists so the
// specification cannot be wrong about what it asks for: everything below is
// stock ESP32 Arduino plus one library, and it was written by reading the spec
// rather than the app.
//
// HARDWARE. Any ESP32 with Bluetooth Classic. Four momentary switches from the
// listed pins to ground - no resistors, the internal pull-ups do it. Four is
// the number that fits on a handlebar beside a clutch lever, which is why the
// spec has long-press at all.
//
// BUILD. Arduino IDE, board "ESP32 Dev Module", library "ESP32 BLE Keyboard"
// by T-vK (Library Manager, or github.com/T-vK/ESP32-BLE-Keyboard). Flash it,
// then pair "Trail Blazer Remote" from the tablet's Bluetooth settings the same
// way you would pair a keyboard. Nothing is installed on the tablet.
//
// CHECK IT. Settings -> Controller in the app reports every code it receives,
// the action it maps to, and how long the press was. You do not need us, or the
// app, to verify this: it is a Bluetooth keyboard, so any text editor shows you
// the arrows working.
//
// LICENCE. MIT. The specification it implements is CC0. Build what you like.

#include <BleKeyboard.h>

BleKeyboard keyboard("Trail Blazer Remote", "Open Hardware", 100);

// ---------------------------------------------------------------------------
// The buttons.
//
// Deliberately the four from the spec that a gloved thumb can find without
// looking: two for moving through the roadbook, one to confirm or recentre, one
// to mark where you are.
//
// NOTE WHAT IS NOT HERE: nothing detects a long press. The spec puts that
// timing in the app on purpose - hardware that decided for itself would leave
// two controllers disagreeing about the threshold, and a rider unable to say
// which was wrong. This sketch reports key-down and key-up and nothing else.
// ---------------------------------------------------------------------------
struct Button {
  uint8_t pin;
  uint8_t key;        // the HID key from CONTROLLER_SPEC.md section 3.1
  const char* name;   // for the serial log only
  bool wasDown;
  unsigned long changedAt;
};

Button buttons[] = {
  {12, KEY_LEFT_ARROW,  "previous", false, 0},
  {13, KEY_RIGHT_ARROW, "next",     false, 0},
  {14, KEY_RETURN,      "confirm",  false, 0},  // held >=600ms: recentre
  {27, KEY_F1,          "mark",     false, 0},  // held >=600ms: mark with note
};

const size_t BUTTON_COUNT = sizeof(buttons) / sizeof(buttons[0]);

// A switch bouncing looks like a very fast double press, and a double press on
// `record` would start and stop a recording. Cheap switches bounce for a
// millisecond or two; twenty-five is generous and still far below the 600 ms
// that separates a short press from a long one.
const unsigned long DEBOUNCE_MS = 25;

void setup() {
  Serial.begin(115200);
  for (size_t i = 0; i < BUTTON_COUNT; i++) {
    pinMode(buttons[i].pin, INPUT_PULLUP);
  }
  keyboard.begin();
  Serial.println("Trail Blazer reference controller - pair me as a keyboard");
}

void loop() {
  // Not connected yet, or the tablet has gone away. Do nothing rather than
  // queue presses: a rider pressing buttons at a dead link expects nothing to
  // happen, not everything to happen at once when it comes back.
  if (!keyboard.isConnected()) {
    delay(100);
    return;
  }

  const unsigned long now = millis();

  for (size_t i = 0; i < BUTTON_COUNT; i++) {
    Button& b = buttons[i];
    const bool isDown = digitalRead(b.pin) == LOW;   // pull-up: LOW is pressed

    if (isDown == b.wasDown) continue;
    if (now - b.changedAt < DEBOUNCE_MS) continue;

    b.wasDown = isDown;
    b.changedAt = now;

    if (isDown) {
      // HELD DOWN, not tapped. `press` sends key-down and leaves it down, so
      // the app can time the press itself - which is what the spec requires.
      // `write` would send down and up together and every press would look
      // short, so the long-press half of the profile would simply never fire.
      keyboard.press(b.key);
      Serial.printf("down  %s\n", b.name);
    } else {
      keyboard.release(b.key);
      Serial.printf("up    %s\n", b.name);
    }
  }

  // Fast enough that a press is never missed, slow enough to leave the radio
  // alone. A rider cannot press a button in under 5 ms.
  delay(5);
}
