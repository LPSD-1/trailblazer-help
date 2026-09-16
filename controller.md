# Trail Blazer Controller Profile

**Version 1.0 (draft) — 16 September 2026**

An open profile for handlebar controllers. Anyone may build hardware to this
document, sell it, give it away or solder one on a kitchen table, without asking
permission and without telling us.

---

## 1. What this is, and what it deliberately is not

This is **not a new protocol.** Bluetooth HID is already an open standard, every
phone and tablet already speaks it, and every hobbyist board — ESP32, nRF52,
RP2040, a Pi Pico W — can emit it in about ten lines. Inventing a transport on
top of that would buy nothing and cost every implementer a week.

What this document defines is the layer that is genuinely missing: **a stable,
versioned mapping from HID key codes to named rider actions.** A controller that
sends these codes works with Trail Blazer the moment it pairs, with no
configuration, no app update and no involvement from us.

It also defines what a conforming *app* must do, because a mapping only one side
honours is not a standard.

### Why a standard at all

A rider on a green lane has gloves on, a visor down, and a phone in a bracket
they should not be touching. The controller is the one accessory that makes the
screen less necessary rather than more — and the market for handlebar remotes
that work with a specific app is small enough that nobody builds one. Publishing
the profile removes the reason not to.

---

## 2. Transport

**Bluetooth HID, keyboard type.** The controller pairs with the host as an
ordinary Bluetooth keyboard and sends standard key reports.

This choice is load-bearing:

- The app needs **no Bluetooth permission at all**. Pairing is handled by the
  operating system, key events arrive through the normal input path, and there
  is no scanner, no connection manager and no background service.
- It works on every Android version the app supports, and would work on iOS.
- An implementer can test their hardware against any text editor before they
  ever install the app.

### What is NOT used, and why

- **Media keys** (`PLAY_PAUSE`, `MEDIA_NEXT`, `MEDIA_PREVIOUS`). These are not
  delivered to the focused window; Android routes them to whichever app holds
  the media session. A remote that sends them will drive whatever music is
  playing rather than the map. Many cheap "BT remote shutters" do exactly this.
  Trail Blazer may support them separately as a compatibility path, but they are
  **outside this profile** and hardware built to it must not rely on them.
- **Volume keys.** Intercepted by the system, and stealing them from a rider
  wearing an intercom is hostile.
- **Letter and number keys.** They insert text. A remote pressing `M` while the
  search box has focus types `m` into it. See §4.

---

## 3. The key map

### 3.1 Short press

| Action | HID usage | Key | What a rider expects |
|---|---|---|---|
| `next` | 0x4F | Arrow Right | Next instruction, next item, next lane |
| `previous` | 0x50 | Arrow Left | The one before |
| `zoomIn` | 0x52 | Arrow Up | Closer |
| `zoomOut` | 0x51 | Arrow Down | Wider |
| `confirm` | 0x28 | Enter / Return | Take the highlighted thing |
| `dismiss` | 0x29 | Escape | Close, cancel, go back |
| `mark` | 0x3A | F1 | Drop a waypoint here, now |
| `speak` | 0x3B | F2 | Say the last instruction again |
| `recentre` | 0x3C | F3 | Put me back in the middle |
| `record` | 0x3D | F4 | Start or stop recording the ride |
| `mute` | 0x3E | F5 | Silence or restore spoken guidance |
| `reserved6`…`reserved12` | 0x3F–0x45 | F6–F12 | Reserved. See §6. |

Function keys carry the actions and arrows carry navigation, deliberately.
Function keys never insert text, are never claimed by the Android system, and
are emitted by every BLE HID library without special handling.

### 3.2 Long press

A key held for **600 ms or more** is a long press and is a distinct action. This
is what lets a four-button remote — which is what fits on a handlebar next to a
clutch — reach eight actions.

| Held key | Action |
|---|---|
| Enter | `recentre` |
| F1 | `markWithNote` — drop a waypoint and open it for a note |
| F4 | `recordDiscard` — stop recording and throw the ride away (confirmed on screen) |

**The controller does nothing special for a long press.** It sends key-down,
holds, and sends key-up, exactly as a keyboard does. The timing is the app's
job — hardware must not try to detect long presses itself, or two
implementations will disagree about the threshold.

### 3.3 Auto-repeat

A controller **MAY** auto-repeat a held key, and **SHOULD NOT** repeat faster
than 10 Hz.

A conforming app must treat repeats as repeats: holding `zoomOut` should zoom
out smoothly, and holding `F4` must **not** start and stop the recording forty
times. See §4.

---

## 4. What a conforming app must do

These are requirements on Trail Blazer, and on anything else that adopts this
profile. A mapping only the hardware honours is not a standard.

1. **Never consume a key while a text field has focus.** The rider is typing a
   place name; the arrows must move the cursor and Escape must close the
   keyboard. This is the single most important rule here, and the reason letters
   are not used at all.
2. **Long-press timing belongs to the app**, at the threshold in §3.2, measured
   between key-down and key-up.
3. **A repeat must not re-trigger a toggle.** `record`, `mute` and every other
   toggle fire once per physical press. Continuous actions — zoom, next,
   previous — may act on each repeat.
4. **An unmapped key is not an error.** It is shown to the rider, with its code,
   on the controller screen (§5). Silence would make a non-conforming remote
   indistinguishable from a flat battery.
5. **Actions the current screen cannot perform are ignored quietly**, never with
   an error. `next` on a screen with nothing to advance does nothing.
6. **Every action must also be reachable by touch.** The controller is an
   accelerator, never the only way. A rider whose remote's battery dies on a
   moor has not lost the app.

---

## 5. Conformance, and how to check it

Trail Blazer contains a **controller screen** (Settings → Controller) which:

- reports every key event it receives, with the HID code and the action it maps
  to, or `unmapped`;
- reports press duration, so long-press behaviour can be checked;
- reports repeat rate;
- lets a rider **learn** any non-conforming remote by pressing a button and
  choosing an action for it.

That learn mode is the escape hatch that makes the profile safe to publish: a
remote that follows this document works out of the box, and one that does not
still works after a minute of setup. Neither case needs an app update.

**Hardware built to this document can be verified without our help**: pair it,
open that screen, press every button, and read what comes back.

---

## 6. Versioning

This is version **1.0**. The codes in §3.1 will not be reassigned — a controller
built today keeps working. Future versions may only:

- assign meanings to the reserved keys F6–F12;
- add long-press actions for keys that have none;
- relax a requirement in §4.

If an incompatible change ever proves unavoidable it will be a new profile with
a new name, not a version 2 of this one, so that no hardware in somebody's
handlebar silently changes meaning.

---

## 7. Reference implementation

[`reference-controller/reference-controller.ino`](reference-controller/reference-controller.ino)
is a working four-button controller for an ESP32, in about sixty lines of
Arduino. It is not a product; it exists so that this document cannot be wrong
about what it asks for.

It is the only source published here. The app itself is closed — you do not need
it, and nothing in this profile depends on seeing it.

---

## 8. Licence

This specification is published under **CC0 1.0** — public domain. Build what you
like, sell it if you like, and neither credit nor permission is required.

The reference implementation is **MIT**.

There is no certification, no logo, no fee and no registry. If it sends the
codes, it works.
