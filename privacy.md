# Privacy policy

**Trail Blazer — Offline maps**
Application id `com.trailblazerofflinemaps`

Last updated: 3 October 2026

## The short version

Trail Blazer has no user accounts, no sign-in, no analytics, no crash
reporting, no advertising and no tracking identifiers of any kind. Two Google
components it uses, Play billing and the Nearby Connections service behind
group ride, send Google their own performance figures, as they do in any app;
see sections 5 and 7. None of that reaches us.

Your rides, your waypoints, your saved plans and your settings are written to
your phone and stay there. They are never uploaded to us, and they are
excluded from Android's own cloud backup on purpose. They go to no one else
either, with one exception that only you can make, one at a time: in a group
ride you can send one of your plans, or one of your tracks - **including a
ride you recorded** - to the riders in your group, and to nobody else,
end-to-end encrypted. It goes only when you pick it and press Send. See §7.

The app does use the network for six things, and only those six: downloading
map data (and checking it for updates), drawing the online basemap, looking up
an address you type, speech recognition, Google Play billing, and fetching the
latest rain and river readings for your region when you open a lane that has a
rain gauge or a ford (and the weather forecast for the region you are planning
a ride in). Each is described below, including exactly what the other
end can see. A seventh, only if your riding group has set one up: a relay run by
one of the riders, which carries the group's encrypted positions to riders out
of radio range (§7).

**Your position is not one of them, ever.** Not rounded, not coarsened, not
anonymised - not sent to us or to any of them. It leaves your phone in one
way only, and only when you switch it on: in a group ride, to the riders
**you** chose by showing them your group's code, phone to phone or through a
relay one of **you** runs, end-to-end encrypted, and never to us. See §7.
Where you **have** ridden can leave the same way, to the same riders and no
one else, but only if you choose to: a ride you recorded, sent to your group
with "Share a plan with the group" (§7).
The only other way is one you do yourself: a message you send from your own
messaging app or share sheet - the Where am I? screen's **Send this**, or a
safety check-in text the app gets ready and **you** press Send on. The app
cannot send a text by itself. See "Safety check-in" below.

We do not operate a server that receives anything from the app. There is
nowhere for us to store your data even if we wanted to.

---

## Who we are

Trail Blazer is published by the developer named on the Google Play listing for
`com.trailblazerofflinemaps`. For data protection purposes that developer is the
data controller for the very small amount of processing described here.

---

## What the app stores on your phone

All of this except the last row is in the app's own private storage. No other
app can read it, and none of it is transmitted.

| What | Where | Contains |
|---|---|---|
| Recorded rides | `app_flutter/user_content/tracks/<id>.json` | A timestamped list of positions, with elevation and speed where the phone reported them |
| The trail you ride without recording | `files/user_content/session_trail.log` | Latitude, longitude and time, one line for about every 15 m you move while the app has a position fix and you are not recording. See "The unrecorded trail" below |
| Waypoints | `app_flutter/user_content/waypoints.json` | Position, name and note for each mark you make |
| Saved plans | `app_flutter/user_content/plans/<id>.json` | The stops in a planned route |
| Lane notes | `app_flutter/user_content/lane_notes.json` | What you wrote about a lane, whether you mean to ride it, and when |
| Lane photographs | `app_flutter/user_content/lane_photos/<lane>/` | Copies of the pictures you attached to a lane note, as they were, including any location and date the camera wrote into them |
| Imported files (GPX, KML, KMZ, GeoJSON, FIT, TCX) | Same as rides and waypoints | Whatever was in the file you imported: read on the phone; a KML network link is never followed |
| Downloaded map data | App support directory: `lane-packages/`, `routing/segments/`, `trips/`, `basemaps/` | Public map data. Nothing about you |
| Rain and river readings | App support directory: `conditions/wet/<region>.json`, `conditions/rivers/<region>.json` | The last rain and river feed fetched for each region, kept so it can be shown with no signal. Public data, but the file names say which regions you have opened lanes in |
| Weather forecast | App support directory: `conditions/forecast/<region>.json` | The last forecast file fetched for each region, kept so it can be shown with no signal. Public data, but the file names say which regions you have planned rides or opened lanes in |
| Offline basemap regions | MapLibre's own tile database | Map tiles for the areas you chose |
| Licence receipt | `files/licence/receipt.json` | See "What the receipt holds" below |
| Group ride | Android's encrypted storage (`flutter_secure_storage`) | The group you are in - its id, its key, the name you know it by, and a relay address if the group has one - and a random secret this install made, from which your id in each group is worked out. Removed when you leave the group, except the secret. A shared route (the line of a plan sent to or taken from the group) is kept in the app's settings under `group_ride.shared_route.v1` until put away, the group is left, or 12 hours pass. See §7 |
| Settings | Android `SharedPreferences` | See "What the settings hold" below |
| Safety check-in | Android `SharedPreferences` (`checkin.*`), and the app's private `trailblazer_checkin` preferences for the alarm | Your back-by time, the number you typed, and - only while a check-in is set - where you last were and the text ready to send. See "Safety check-in" below |
| Fault-finding file | `Android/data/com.trailblazerofflinemaps/files/diagnostics.json` | What the app has loaded and what it concluded: which map data is open, the map settings, and the lanes near its last fix with its verdict on each. No coordinates |

The fault-finding file is the one thing here that is NOT in private storage.
It sits in the app's folder on the phone's shared storage, so a computer
connected to your unlocked phone by USB can read it, and on Android 8, 9 and
10 so can another app you have allowed to read your storage. It is there so a
fault can be diagnosed over a cable. It holds no coordinates, but it names
the lanes within about 170 m of where the app last had a fix, to the nearest
50 m, so it does say roughly which lanes you were near. Nothing in the app
reads it back or sends it anywhere, and clearing the app's storage or
uninstalling removes it.

A recorded ride is a precise history of where you have been. The app treats it
that way: it is the single most sensitive thing on the phone, and it is the
thing most carefully kept off the network. It leaves the phone only if you
send it yourself: to your group ride (§7), or as a file you share.

### The unrecorded trail

Pressing Record is not the only way a history of where you have been ends up on
the phone, and you should know that before deciding whether to press it.

While the app is running and has a position fix, it lays a trail behind you on
the map, so that you can always find your way back. That trail is also written to
`files/user_content/session_trail.log` as you go, **whenever you are not
recording** (while you are, the ride itself is being saved instead, so the
same stretch is not kept twice), so that if the phone dies or Android closes
the app the day's riding is not lost. It is the same kind of history as a
recorded ride: latitude, longitude and time, a line for about every 15 m. So
riding with the app open keeps a history of where you went whether or not you
press Record.

- It stays in the app's private storage. It is never sent anywhere, and it is
  not in Android backup (only `files/licence/` is).
- The next time you open the app, a trail from the last 12 hours is offered
  back to you. Keeping it turns it into a recorded ride and dropping it throws
  it away; either way the file is deleted.
- Anything older than 12 hours is never offered back. Once nothing in the file
  is younger than that, the app empties it the next time it starts.
- Clearing the app's storage, or uninstalling, removes it.

### Lane photographs

When you attach a photograph to a lane note, you choose it in Android's own
picker and the app copies that one file into its private storage. It does not
ask for permission to read your photo library and cannot see any picture you
did not pick. The copy is kept as it was, so any location and date your camera
wrote into the picture stay in it; the app does not read them, and the
photograph is never uploaded. Photographs are not included in the "Back up what
you have put in" file, and they go when you delete them, clear the app's
storage or uninstall.

### Safety check-in

A safety check-in is a back-by time you set (the Where am I? screen, or
Settings > Safety check-in). Everything about it is stored only on your phone,
in the app's private storage, and none of it is sent anywhere by the app:

- **The time** (`checkin.dueUtcMs`). Removed when you answer the check-in.
- **The check-in contact** (`checkin.contact`): the phone number you typed, if
  any. Kept so the sheet can offer it next time; delete it by clearing the
  field. The app has no permission to read your contacts, and the number never
  leaves the phone except in a text you send.
- **Where you last were** (`checkin.snapshot`): the last position, its grid
  reference, how accurate and how old it was, the lane you were nearest and
  whether you ride a motorbike or a 4x4. Written ONLY while a check-in is set -
  at most once a minute or every 100 m - and deleted when you answer it. With
  no check-in set nothing is written.
- **The alarm's copy.** Because the alarm has to work with the app closed,
  the time, the number and the text ready to send (which contains that
  position) are also held in the app's private `trailblazer_checkin`
  preferences, for Android's alarm to read. They are cleared when you answer,
  and the time alone is kept if you answered from the notification, until the
  app next opens and clears it.

When the check-in is overdue the app gets a text ready in your own messaging
app (or the share sheet, with no number). **You press Send**; the app cannot
send a text by itself and has no server. A text you send goes from your phone
to the person you chose, through your mobile network, like any other message.

### What the settings hold

The app's preferences file holds the choices you have made, and a small amount
of work in progress so that it survives Android closing the app. It holds no
identifier except your id in a group ride, in the name of one key (below),
which only that group's riders ever see. It is not in Android backup.

**Four of the keys hold places.** `plan.editor.draft` is the plan you are
editing and have not saved yet: the latitude, longitude and name of each of its
stops. It is written as you edit and removed when you save or discard the plan.
`ride.active.adhoc` is an unsaved route you are riding, with the same stops;
`ride.active.join` is the latitude and longitude of the stop you joined a
planned ride at; `ride.active.skipped` is the latitude and longitude of each
stop you skipped on the ride. All three are there so a ride in progress comes
back after the app is closed, and all three are removed when the ride ends.

The complete set of keys is:

- Display and the map: `settings.theme_mode`, `settings.units`,
  `settings.keep_awake`, `settings.auto_lock`, `settings.auto_record`,
  `terms.accepted` (which version of the terms of use you agreed to),
  `settings.brightness`, `settings.map_ui_scale` (how big the map's buttons
  are drawn),
  `settings.screen_mode`, `settings.screen_mode.after_dark` (whether the
  screen goes unlit by itself after sunset, and whether it last did so for
  dark or for light - no place and no time), `settings.roadbook_tab`,
  `map.basemap`,
  `map.chrome_mode`, `map.show_gauges`, `map.orientation`, `map.lane_filters`,
  `map.lane_overview_mode`, `map.tro_filter`, `map.hillshade`,
  `map.heightColours`, `map.multidirectional`, `map.terrainExaggeration`,
  `map.terrain3d`, `map.buildings3d`, `dashboard.gauges`,
  `dashboard.gauges.road`, `dashboard.layout`, `pois.visible`, `pois.categories`,
  `accessibility.handedness`, `accessibility.lane_colours`.
- Spoken warnings: `voice.boundary`, `voice.lane_entry`, `voice.closures`,
  `voice.gradient`, `voice.auto_record`.
- Handlebar remote: `controller.enabled` (whether the app answers a remote)
  and `controller.key_map` (only the buttons you taught it with Learn, as key
  codes; nothing else about the remote, and nothing about where you were).
- Lanes and vehicle: `lanes.favourites` (the lanes you starred), `lanes.scope`,
  `rider.vehicle`, `packages.vehicle`.
- Recording by itself: `auto_record.stand_down_since` (the time you last
  finished a ride, so the drive home after it is not recorded as another -
  a time, not a place; removed once the phone has lain still, and not used
  more than four hours after).
- Downloads and updates: `downloads.includeImagery`, `downloads.imageryDetail`,
  `updates.policy`, `updates.wifi_only`, `updates.connections`,
  `updates.last_checked` (dates), `updates.held` (which kinds of map data have
  an update waiting until your downloads are covered), `backup.last_written`
  (a date), and `regions.plannedPieces`: the map areas of a download still in
  progress (each area's name and the rectangle it covers, which for a download
  along a plan follows that plan), so a download stopped by the app being
  closed can carry on; each area is removed when it finishes or you stop it.
- Routing and planning: `routing.style`, `routing.includeTracks`,
  `routing.avoid_closures`, `journey.travel_mode`, `journey.travel_mode.rides`,
  `dayout.km`, `dayout.lanes`, `plan.editor.draft` (see above), and one
  `plan.lanes.<plan id>` per saved plan, holding the lanes that plan touched
  and what they allowed when you last looked, so the app can tell you what has
  changed since.
- The ride: `ride.odometer_metres`, `ride.fuelRangeMetres`,
  `ride.fuelFilledAtOdometerM`, `ride.tripA.startOdometerM`,
  `ride.tripB.startOdometerM` (where you last zeroed Trip A and Trip B on the
  odometer - numbers, not places), `ride.active.plan`, `ride.active.entry`,
  `ride.active.adhoc`, `ride.active.join` and `ride.active.skipped` (see
  above), and `ride.active.alive` (the time a ride in progress was last
  started, changed or seen moving - a time, not a place - so a ride brought
  back more than two hours later waits for you to move before it uses the
  GPS; removed when the ride ends). `follow.active` is the track you are
  following (which saved track, which way round, the part being ridden and
  the parts skipped - the track's line stays in the track itself), and
  `follow.active.alive` the time that follow was last started, changed or
  seen moving, for the same reason as `ride.active.alive`; both are removed
  when you stop following.
- Safety check-in: `checkin.dueUtcMs`, `checkin.contact` and
  `checkin.snapshot` (a place, only while a check-in is set), and
  `checkin.cancelling` (a flag, set only while a cancel is being made, so a
  cancel the app was closed in the middle of is finished next time) with
  `checkin.cancelling.phoneDueMs` (the due time the phone held when that
  cancel was asked for - a time, not a place - removed with the flag). See
  "Safety check-in" above.
- Hints already shown: `setup.seen`, `welcome.seen`, `walkthrough.seen`,
  `coach.restricted_byway`, `coach.riding_mode`.
- Group ride: `group_ride.display_name` (the name the riders in your group see
  beside your marker), and one `group_ride.seq.<your id in a group>` per group
  you have shared in, a count of the positions sent, kept so a rider who
  leaves and rejoins is not mistaken for a replay;
  `group_ride.started_group`, the id of a group this phone started, so it
  can be renamed when you change your name; and `group_ride.code_copied`,
  a flag that you copied the group's code, so leaving knows to take it off
  the clipboard (the code itself is not kept here); and
  `group_ride.answered_offers.v1`, the plans offered to you that you took or
  ignored (the group's id and, for each, the sender's id in the group, a
  random number and when you answered), so the same plan is not offered again after a restart; cleared
  when you leave the group, each answer going after 12 hours; and
  `group_ride.sharing.v1`, written while you are sharing your location with
  your group: the group's id and when the share started (a time, not a
  place), so that if Android closes the app mid-share the next launch can
  tell you the share ended. Removed when you stop sharing, or at that next
  launch. None of those is a place. `group_ride.shared_route.v1` IS a list of places: the line of a plan
  you sent to your group or took from another rider, its regroup points,
  the plan's name, the display name of the rider who sent it, the group's id
  (so a route from another group is never used) and a reference to the offer
  it came from (that rider's id in the group and a random number, so the same
  plan handed over again is not offered twice), kept so it survives the app
  closing mid-ride, and removed when you put it away, leave the group, or 12
  hours after it was taken. The group itself - its key - and this install's
  secret are NOT in this file: they are in
  Android's encrypted storage, under `group_ride.active_group.v1` and
  `group_ride.install_secret.v1` (see the storage table above).

`ride.odometer_metres` is a running total of distance. It is a number, not a
route.

### What the receipt holds

`files/licence/receipt.json` is the only record of what you have paid for. It
holds four things:

- when this install was first seen,
- the latest date this install has ever seen on the clock (so that winding the
  phone's date back does not extend a paid window),
- whether the app has been bought,
- for each update pack bought: which pack, when the store said it was bought,
  and a SHA-256 fingerprint of the store's purchase token.

It deliberately holds **no** account name, no email address, no device
identifier and no raw purchase token. The purchase token is the credential
Google's own API uses to look a purchase up, which would tie the file to a named
Play account; the app hashes it instead, because the only question the receipt
needs to answer is "have I already counted this payment?".

### Android backup

`android:allowBackup` is on, and the backup rules are an allowlist with exactly
one entry: `files/licence/`.

That means the receipt travels to a new phone, so you do not lose what you paid
for. **Everything else is excluded, including every recorded ride.** Your
location history is neither backed up to Google nor transferred device to
device.

---

## What leaves your phone, and when

### 1. Map data downloads

When you download lanes, routing, ready-made trips or satellite imagery, the app
fetches the published index and then the files you asked for. The app also
fetches the index each time it starts, so that it knows what is published and
can offer the right download for where you are; that request is for the same
public file and carries nothing about you. On the schedule you set under
Settings, it also checks the index for newer versions of what you already
have, and fetches the update, over the connection you chose, if there is one.
Setting a kind of data to update manually stops those checks and update
downloads for it; it does not stop the index being read when the app starts.

- The index and most packs come from `https://lpsd-1.github.io/trailblazer-datasets/`
  (GitHub Pages), with some larger files served from GitHub Releases.
- **Routing tiles are fetched directly from `https://brouter.de/`**, a
  volunteer-run service that publishes the road network tiles the offline router
  reads. We are in the process of mirroring these to our own hosting; until a
  given tile is mirrored, your phone requests it from brouter.de.

These are ordinary HTTPS requests for static files. No identifier is sent. As
with any web request, the server at the other end can see your IP address and
which files you asked for — which implies the parts of the world you intend to
ride in.

### 2. The online basemap

The map is drawn from OpenFreeMap (`https://tiles.openfreemap.org/`), which
serves OpenStreetMap data. While you have a signal, the app requests the map
tiles for the area on screen, and when you download an offline region it
requests the tiles for that region.

**This means OpenFreeMap can see, from your IP address, roughly where you are
looking.** It is the ordinary cost of an online map. Once you have downloaded a
region it is served from the phone and no request is made.

No API key is used and no account exists, so nothing links one session to
another beyond what an IP address implies.

### 3. Address search

Typing a place name into the search box sends that text to OpenStreetMap's
Nominatim service at `https://nominatim.openstreetmap.org/search`.

What is sent:

- the text you typed,
- `countrycodes=gb`, which limits the answers to Great Britain. The app only
  covers England and Wales, so this says nothing about you that using the app
  does not,
- a `User-Agent` of `TrailBlazer/0.1 (offline green-lane navigation)`, which
  Nominatim's usage policy requires.

**Your position is not sent.** It used to be: a `viewbox` a degree of latitude
and longitude either side of you, so that nearby results came back first. That
has been removed. The app asks for a wider set of results and sorts them by
distance from you *on the phone*, which gives the same answer without telling
anybody where you are.

This is not a claim that the request is anonymous. It carries the text you
typed and, like any request to any server, your IP address, which implies a
town. What it no longer carries is a box drawn around where you are standing.

Grid references, coordinates, your own marks, rides and plans, and the names
of lanes in the packs you carry are all searched entirely on the phone and send
nothing at all. Nor is a what3words address, or a grid reference with a digit
missing, which the app cannot read and says so instead.

A postcode is searched on the phone first, in the place names you have
downloaded. When they hold that postcode, nothing is sent, and nor is the part
of it you have typed so far once it reaches the sector ("SA38 9"), even if you
pause there. If you search straight after opening the app, a postcode waits a
moment for the place names to finish opening before anything is sent. When they
do not hold it (you have not downloaded the place names for that area, or the
postcode is not in them), a postcode is sent like a place name, because
otherwise it could not be looked up at all. The first half of a postcode on its
own ("SA38", a district of thousands of homes) is sent like any other text if
you pause on it. Download the place names for the areas you ride and your
postcodes stay on the phone.

A request is only made when you have typed at least three characters, and typing
is debounced by 600 ms, so a typed word is one request rather than fifteen.

Nominatim is operated by the OpenStreetMap Foundation under
[their privacy policy](https://wiki.osmfoundation.org/wiki/Privacy_Policy).

### 4. Speech recognition

The voice button asks the platform for **on-device** recognition, so that
hands-free control keeps working with no signal. The microphone is only active
while a command is being listened for — a few seconds after you press the
button — and audio is never recorded, stored or sent by this app.

Be aware of the honest limit: the app requests on-device recognition but cannot
force it. If your phone has no local speech model installed, the platform's own
recogniser may fall back to a network service run by your device vendor, and
that speech would be handled under that vendor's policy, not ours. The
microphone is declared optional in the app's manifest, and the voice button can
simply be left alone.

### 5. Google Play billing

The app is free. Buying an update pack goes through Google Play. Google receives
whatever Google receives for any Play purchase — your Play account, your payment
details, and the product you bought. We never see your payment details and we
operate no server that receives anything about your purchase.

The app asks Play for the product's localised price and title, and asks Play
what your account already owns so that a reinstall restores it. Purchases are
verified on the device only. What the app writes down locally is described under
"What the receipt holds" above.

Google's billing library also sends Google its own diagnostic figures about
how the purchase screens performed, as it does in every app that sells through
Play. We never receive them.

When the app opens, it asks the Play Store app on your phone whether a newer
version of Trail Blazer is available, using Google's in-app updates library.
That question goes to Play, not to us, and if you tap Update, Play downloads
and installs the new version as it would from the store. We never receive
anything from it.

Google's handling of a Play purchase is covered by the
[Google Privacy Policy](https://policies.google.com/privacy).

### 6. Rain and river readings, and the weather forecast

Some lanes are soft after rain, and some cross a ford. For those, the lane's
detail page shows how much rain has fallen at the nearest rain gauge and how
high the nearest river is. Which gauge and which river belong to a lane is in
the map data you already downloaded. The readings change through the day, so
they are fetched separately, as two small public files covering a whole region
of the country:

- `published/wet/<region>.json` (rainfall), fetched when you open a lane that
  has a rain gauge, and
- `published/rivers/<region>.json` (river levels), fetched when you open a lane
  that has a ford,

from the same host as the map data in §1
(`https://lpsd-1.github.io/trailblazer-datasets/`). The readings come from the
Environment Agency's public gauges.

This happens every time you open such a lane, with no download asked for, so
that what you see is current rather than what it was the first time you looked.
A lane with no gauge and no ford fetches nothing. With no signal, the last copy
fetched is shown, with its age, for as long as it is recent enough to mean
anything.

What is sent: an ordinary HTTPS request for that file, with no identifier and no
query. **Your position is not sent, and neither is the lane you opened.** The
region is one of the few large regions the map data is published in (for
example "midlands"), and it is worked out on the phone.

What the other end can see: your IP address, which region's file you asked for,
when, and how often. That says which part of the country you are looking at
lanes in, at about the scale of a few counties, and roughly when you are
looking. It is the same kind of inference as downloading a region's map data,
and it is made more often.

**The weather forecast** comes the same way. The plan editor, the day-out
sheet and the day-out preview show what the forecast says for the hours of the
ride you are planning, and the lane detail page adds the rain forecast for the
next 24 hours to a lane's rain line. For that the app fetches one more small
public file per region:

- `published/forecast/<region>.json`, fetched when one of those planning
  screens is open with a ride on it, and when you open a lane that has a rain
  gauge,

from the same host as above. It is built four times a day by the same
scheduled job that publishes the rain readings, from MET Norway's public
forecast (api.met.no), for a grid of points about 28 km apart covering the
whole region. **Your phone never contacts MET Norway.** It downloads the whole
region's file and picks out the grid points nearest your stops on the phone.

What is sent: the same kind of plain HTTPS request, with no identifier and no
query. **Neither your position nor your plan's stops are sent.** The region is
worked out on the phone from the stops, the same way as for a lane.

What the other end can see: your IP address, which region's forecast you asked
for, when, and how often - which says which part of the country you are
planning a ride in, at the scale of a few counties. Nothing is fetched in the
background or while the app is closed: only while a planning screen or a lane's
page is open. With no signal, the last forecast fetched is shown with its age,
and none is shown once it is more than 12 hours old.

### 7. Group ride: your position, to the riders you chose

If you ride with other people who use Trail Blazer, you can see each other on
the map. **It is off unless you are in a group and switch on "Share my
position on this ride"**, and being in a group is not the same as sharing.

- **Who receives it.** The phones of the riders in your group, and no one
  else. A group is joined by scanning a code another member shows you; that
  code carries the group's key, and the key is what lets a phone read the
  group's positions. So anyone who scans or photographs the code can see the
  group. The app says so on the screen before it shows the code. Nobody can be
  removed from a group, because there is no server to remove them from; the
  way to leave someone out is to start a new group.
- **Scanning a code.** The camera is used only to read the code, on your
  phone, by an open-source reader (ZXing) built into the app. Nothing it sees
  is kept or leaves your phone, and no Google scanner or ML Kit is involved.
  The app asks for the camera only when you tap Scan a code, and a code sent
  to you as text can be pasted instead.
- **How it travels.** Phone to phone, over Bluetooth and Wi-Fi, using Google's
  Nearby Connections, which runs inside Google Play services on your phone.
  Google says Nearby Connections sends Google performance figures: how fast
  and reliably connections are made, the phone model, the country, the Play
  services version and the app's package name. That goes from Play services to
  Google, carries no position or anything you share, and never reaches us.
  Positions are passed along through the group, so a rider at the back of a
  long line still sees the one at the front. **Nothing goes through a server of
  ours: there is no server of ours.**
- **Through a relay, if your group has one.** One rider may run a small relay
  on their own account (a free Cloudflare account, or their own computer),
  from the open-source software at github.com/LPSD-1/trailblazer-relay, and
  put its address and access token in the group's code. Every phone that
  scanned that code then also sends its packets to the relay over an
  encrypted connection (`wss://`), and the relay passes them to the other
  phones in the group, so riders out of radio range still see each other. We
  do not run a relay and never receive anything from one. The relay cannot
  read a packet: it never has the group's key. What it, the rider who runs it
  and the company hosting it can see is what any server sees - each phone's
  internet address, when it connects, a random-looking room id worked out
  from the group's key, how many phones are connected, and how often they
  send and how much. Every position packet is the same size, so its size says
  nothing about who is in it. A plan you send to the group goes as parts of
  another fixed size, so the relay (or a Bluetooth scanner nearby) can tell
  that a plan was sent and roughly how big it is, but not what is in it. The relay can still tell which packets a connected phone
  sent for itself and which it passed along for someone else, and from how
  many arrive, and when, it can guess how many riders there are, including
  riders whose packets only reach it passed along by another phone. It keeps the last 64 packets in memory only, so a rider
  joining mid-ride sees everyone at once, and forgets a room when the last
  phone leaves. Without a relay in the group's code, the app opens no
  internet connection for group ride at all. "Test the relay", in Settings,
  connects to the relay you type in, with the token you type in, sends one
  random test message through a throwaway room, and checks that your group's
  own room has space without sending anything into it.
- **What is sent.** Your position and when it was taken, how accurate it is,
  your speed, direction of travel and battery level, whether you are stopped,
  have asked for help or are leaving, the name you chose, and your id in this
  group (worked out on your phone, and different in every group, so your ids in
  two groups cannot be matched). When sharing ends and you are still in the
  group, one last "stopped sharing" message goes too, with no position in it:
  see "How long". Every packet is encrypted with AES-256-GCM under a key only
  the members hold, and every packet is the same size whatever your name, so a phone that is not in the group, or anything in
  between, sees only noise: it can see that packets are being sent, from
  where, and how often, but not what they say.
- **A plan you choose to send.** "Share a plan with the group" sends one of
  your plans - its stops, their names, the style of each leg, any regroup
  points, and the line your phone worked out for it - **or one of your
  tracks**, to the group only, encrypted in the same way and over the same
  radios and relay as your position. The tracks it offers are all of yours:
  files you imported **and rides you recorded yourself**, so a recorded ride,
  the history of where you rode, can go to your group this way. A track
  goes as a plan along it: up to 30 stops on its ends and bends, the track
  itself (simplified) as its line, and its name, which for a recorded ride
  is the date and time it started unless you renamed it; the plan's id is
  made from the track's, which for a recorded ride also says when it started.
  The times, speeds and heights of the points along it are not sent. A plan
  with a leg set to go "via my tracks" sends that leg as the places it joins
  and leaves your own tracks, recorded rides included, each labelled with
  that track's name.
  Nothing new reaches any server, and nothing
  of ours. It goes only when you pick a plan or a track and press Send, and
  only while sharing is on. A plan
  another rider sends you is saved to your plans only if you tap Take it; its
  line is then kept on your phone as the group's shared route (under
  `group_ride.shared_route.v1`, see "What the settings hold") until you put it
  away, leave the group, or 12 hours pass.
- **What a stranger nearby can see.** That a phone near them is using this
  feature, and which phones are riding together. While sharing (and while a
  goodbye goes out after it: see "Leaving"), the phone advertises a short tag worked out from the group's key and the date - never
  your name - and every phone in the group advertises the same tag all day. So
  someone with a Bluetooth scanner, at a gate or a car park, can tell which
  phones are riding together and how many, and can recognise the same group
  again later that day. They cannot tell whose phones they are, and the tag
  changes each day, so they cannot tell it is the same group, or follow the
  same phone, from one day to the next.
- **How long.** Until you switch it off, the ride you are recording finishes,
  or 12 hours pass, whichever is first. While it is on, the ongoing
  notification says "Sharing your position with" your group, and how many
  riders, and your own marker has a ring round it. When it ends, whichever of
  those ends it, your phone sends the group one last "stopped sharing" message,
  over the same radios and relay as your position, so the others see that you
  chose to stop and are not told they have lost contact with you. It carries
  your name, your id in the group and the time it was sent - no position: not
  where you are, and not where you were - and their phones keep showing the
  place they last had for you. It is sent three times, since links drop
  messages, and only if you had already sent something; after it, nothing more
  is sent until you switch sharing on again (or leave: see "Leaving").
- **"I need help".** One tap marks every packet you send with a call for help
  until you cancel it. The other riders' phones sound an alarm and show where
  you are. It does not contact the emergency services.
- **What is kept.** On your phone: the group and its key, in Android's
  encrypted storage, and the name and send counts listed under "What the
  settings hold". The positions of the other riders are held in memory while
  you share and are not written anywhere. One exception: a rider's call for
  help that has not been cancelled stays on your map, in memory, with the
  last place it came from, after your own share ends - so a rider who
  finishes their ride on the way to help can still find them. It goes when
  that rider cancels (heard the next time you share), or when you leave the
  group or close the app.
- **Leaving.** Leaving deletes the group and its key from your phone, and
  tells the others you have left, so their phones take your marker down. If
  your share is off at the time - after the ride has ended, say - the radios
  come on for that goodbye alone, for up to 20 seconds while they look for
  the others, and then go off. That goodbye carries your name and your id in
  the group, which the others already have, and no position: not where you
  are, and not where you were. If you never shared in the group, nobody has
  your marker, and nothing is sent.
- **A copied code.** "Copy the code as text" puts the group's code - its key
  - on your phone's clipboard, where other apps you paste into can read it
  and a keyboard that keeps a clipboard history may keep it. When you leave
  the group - with Leave, by starting a new one, or by joining another - the
  app empties the clipboard if it still holds that code; anything you have
  copied since is left alone. A copy your keyboard's history has already
  kept is out of the app's reach: clear it there.

The permissions it needs are listed under "Location" below, and Android asks
for them the first time you switch sharing on, after the app has said what
they are for.

---

## What does not happen

Verified against the source and the dependency lockfile:

- **No analytics or telemetry of ours.** There is no Firebase, no Crashlytics, no
  Sentry, no Amplitude, no Mixpanel, no Segment, no PostHog, no Bugsnag and no
  App Center anywhere in the project. Nor is there Google's ML Kit, which
  Google says reports usage and performance metrics to Google: the group code
  is read by ZXing instead, and the release check
  (`tool/check_release_apk.py`) fails any build whose code contains ML Kit or
  the Play services Vision API.
- **No advertising, and no advertising identifier.**
- **No account, no sign-in, no email address collected.**
- **No contacts, calendar or SMS access, and no permission to read your photos
  or files.** The safety check-in's number is typed, and its text is sent
  by you from your own messaging app: the app holds no permission to read or
  send messages. The app sees only a file you pick yourself in Android's picker: a
  track file to import (GPX, KML, KMZ, GeoJSON, FIT or TCX), or a photograph to
  attach to a lane note, which is copied
  into the app's private storage (see "Lane photographs").
- **No server of ours.** Every network destination named above belongs to a
  third party publishing static data or providing a public service. Group ride
  (§7) goes from phone to phone and uses no server of ours; the only server
  it can use is a relay one of your group's riders runs themselves, and that
  relay cannot read what passes through it.
- **Recorded rides are never uploaded**, including to Android backup.
- **A handlebar remote needs no Bluetooth permission, and nothing is sent.**
  It pairs in your phone's own Bluetooth settings as a keyboard, and the app
  reads its button presses the way any app reads a keyboard. The app does not
  scan for, connect to or identify the remote, and keeps only the two
  settings above.

### Every third-party package the app ships, and what it does

| Package | What it does | Network? |
|---|---|---|
| `flutter_riverpod`, `riverpod_annotation` | State management inside the app | No |
| `maplibre_gl` | Renders the map and stores offline regions | Fetches map tiles (see §2) |
| `pmtiles` | Reads downloaded satellite imagery archives | No |
| `geolocator` | Position fixes and the recording foreground service | No |
| `sensors_plus`, `flutter_compass` | Roll, gradient, compass heading, and whether the phone is moving or lying still | No |
| `latlong2` | Coordinate arithmetic | No |
| `gpx`, `xml` | Reading and writing GPX files, and reading KML and TCX. A KML's network link is never followed | No |
| `cryptography`, `crypto`, `convert` | Decrypting downloaded packs; hashing the purchase token | No |
| `http` | Fetching the data index, packs, address search, the rain and river readings and the weather forecast | Yes (see §1, §3, §6) |
| `background_downloader` | Hands pack downloads to the OS so they survive the app closing | Yes (see §1) |
| `shared_preferences` | Settings, on the device | No |
| `sqlite3`, `sqlite3_flutter_libs` | Reads the downloaded lane data, which is an SQLite database, and applies updates to it | No |
| `path_provider`, `path` | Local storage | No |
| `permission_handler` | Asks for the notification permission when a ride starts, "Nearby devices" (and, up to Android 12, location) when group sharing first starts, and the camera when you tap Scan a code | No |
| `wakelock_plus` | Keeps the screen awake while riding | No |
| `battery_plus` | Reads the battery level and whether it is charging, so the app can do less when the battery is low | No |
| `file_picker` | Choosing track files to import (GPX, KML, KMZ, GeoJSON, FIT, TCX), or a photograph for a lane note | No |
| `share_plus` | Sharing a GPX file you exported | No |
| `flutter_secure_storage` | Keeps the group ride's key and this install's group secret in Android's encrypted storage (§7) | No |
| `nearby_connections` | Group ride, phone to phone, through Google Nearby Connections in Play services (§7) | Your positions: no, Bluetooth and Wi-Fi between phones. Play services sends Google its own connection statistics (§7) |
| `pretty_qr_code` | Draws the group ride's code on screen | No |
| ZXing (`com.journeyapps:zxing-android-embedded`, `com.google.zxing:core`; an Android library, Apache-2.0) | Reads a group ride's code through the camera, on the phone, when you tap Scan a code | No |
| `speech_to_text`, `flutter_tts` | The voice button and spoken replies | Platform-dependent (see §4) |
| `in_app_purchase`, `in_app_purchase_android` | Google Play billing | Yes (see §5) |
| `collection`, `intl` | Utilities and formatting | No |

---

## Location

### Why it is needed

To show where you are on the map, to record a ride, to drive the dashboard
gauges, and to work out a route from where you are standing.

### What is requested

The app declares `ACCESS_FINE_LOCATION` and `ACCESS_COARSE_LOCATION`. It asks
for them the first time it needs a position — at first run, or when you start a
ride — and it explains why on screen before asking.

It also declares `FOREGROUND_SERVICE` and `FOREGROUND_SERVICE_LOCATION`. When
you start recording, Android runs a foreground service so that the track keeps
being recorded with the screen off, with an ongoing "Recording your ride"
notification while it runs. On Android 13 and older you cannot swipe that
notification away. From Android 14 Android lets you swipe away any ongoing
notification, this one included: it stays put on the lock screen, but once the
phone is unlocked a swipe removes it. Swiping it away does not stop the
recording. The ride keeps recording until you press Finish ride in the app,
even though nothing in the notification shade says so any more.
`POST_NOTIFICATIONS` is
requested at that moment, for that notification. If you refuse it the ride still
records; you simply lose the indicator.

**`ACCESS_BACKGROUND_LOCATION` is deliberately not declared and never
requested.** The recording service does not need it, and declaring it would ask
you for a far broader permission than the app uses.

The app also declares `RECORD_AUDIO` (the voice button), `WAKE_LOCK` (keeping
the screen on while riding) and `INTERNET`. The microphone is marked as not
required, so the app still installs on a device without one.

The libraries the app is built with add four more, and Google Play lists them
with the rest:

- `RECEIVE_BOOT_COMPLETED`, from Android's WorkManager, which carries map
  downloads that outlive the app. After the phone restarts, it lets an
  unfinished download be picked up again. The app declares it itself as well,
  for the safety check-in (below). It does not otherwise start itself when the
  phone starts.
- `ACCESS_NETWORK_STATE`, from the same download machinery, so that a download
  waits for a connection, and for Wi-Fi when you asked for Wi-Fi only.
- `ACCESS_WIFI_STATE`, declared by the MapLibre map library, which watches
  whether the phone is online so it knows when it can fetch online map tiles.
  The app itself never reads which Wi-Fi network you are on.
- `com.android.vending.BILLING`, from Google Play's billing library, for buying
  an update pack (see §5).

None of these reads anything about you, and none of them sends anything.

The safety check-in adds one of its own and uses one of those:

- `SCHEDULE_EXACT_ALARM`, so the check-in's alarm sounds at your back-by
  time. From Android 14 it is not granted to a new install; the check-in then
  uses an ordinary alarm, which Android may run up to about ten minutes late,
  and the sheet says so with a button to allow it. Nothing is read or sent.
- `RECEIVE_BOOT_COMPLETED`: with a check-in set, its alarm is set again after
  the phone restarts, the app is updated or the clock or time zone changes.
  With none set, the app does nothing at those moments.

It does NOT declare `SEND_SMS` (you press Send), `USE_EXACT_ALARM`,
`USE_FULL_SCREEN_INTENT` or `READ_CONTACTS`. Notifications
(`POST_NOTIFICATIONS`) are asked for when you start a check-in; if you refuse,
the check-in is not set, and the app says why.

Group ride (§7) asks for the ones Google's Nearby Connections needs, at the
moment you first switch sharing on and after saying why: on Android 12 and
later `BLUETOOTH_SCAN`, `BLUETOOTH_ADVERTISE` and `BLUETOOTH_CONNECT`, and on
Android 13 and later `NEARBY_WIFI_DEVICES`, which Android shows together as
"Nearby devices". It also declares `ACCESS_LOCAL_NETWORK`, which Google lists
for Nearby Connections on Android 17; the app does not ask for it separately.
Older Android uses the legacy `BLUETOOTH` and `BLUETOOTH_ADMIN`, and
`CHANGE_WIFI_STATE`, none of which shows a prompt.

Up to Android 12, Nearby Connections also needs location: approximate
(`ACCESS_COARSE_LOCATION`) to Android 9, and precise (`ACCESS_FINE_LOCATION`)
on Android 10, 11 and 12. These are the same location permissions the map
uses, so if you have already given the map precise location nothing more is
asked. If you refused the map its location, or on Android 12 chose
"Approximate", sharing asks for it when you switch sharing on, after saying
so; on Android 12 that is Android's own prompt to change approximate to
precise. From Android 12L on, group ride does not need location for this.
All of these are used to find and talk to the other riders' phones and
for nothing else. Bluetooth and Wi-Fi are marked as not required, so the app
still installs on a device without them.

Group ride also declares `CAMERA`, for one thing: reading a group's code when
you tap **Scan a code**. Android asks for it then, and only then, after the
app's own line: "The camera is used only to read the code; nothing it sees
leaves your phone." It is never asked for at install or when the app starts.
The code is read on your phone by ZXing, an open-source reader built into the
app; the picture is not kept, not saved and not sent anywhere, and no Google
scanning service is involved. If you say no, **Paste a code** still joins a
group from a code someone sent you as text. The camera is marked as not
required, so the app still installs on a device without one.

### If you refuse

The app keeps working. You get a banner explaining what is missing, with a
button to the relevant system settings. You cannot see your position or record a
ride, but you can still browse the map, download data, read lane detail, plan a
route between points you pick by hand, import GPX, KML, KMZ, GeoJSON, FIT and TCX,
and export GPX.

### Is your location ever transmitted?

Not to us. The one exception is one you switch on yourself: in a group ride
your position goes to the phones of the riders in your group, encrypted,
directly from your phone to theirs, or through a relay one of those riders
runs, which passes it on without being able to read it (§7). The same way,
to the same riders and no one else, goes a plan or a track you pick in "Share
a plan with the group" and send, and a track can be a ride you recorded: a
history of where you went (§7, "A plan you choose to send").

Your position is not sent when you record, when you download, when you route,
when you plan, when you search, when you open a lane, or when you buy anything.

Two features that would have sent it were removed rather than kept:

- a coarse box around you, sent to Nominatim to bias address results, dropped
  once it was clear the sorting it helped with was already done on the phone;
- the first version of the rainfall feature, built in September 2026, which
  would have sent a position rounded to about 28 km to a weather service to
  fetch recent rainfall. That version was removed before any release carried
  it.

Rainfall is genuinely useful for deciding whether a byway will be soft, so it
came back in a form that sends no position at all: the app fetches the
readings for a whole region, from the same host as the map data, and picks out
the gauge for your lane on the phone. That is §6 above, and it says exactly
what the other end can see. A promise about your location with an exception in
it is not the same promise, so the feature was changed to fit the promise
rather than the other way round.

The qualification that belongs here: any request to any server carries your IP
address, and an IP implies a town. That is true of downloading a map pack as
much as of searching, and it is not something an app can prevent. What it can
do is not send anything sharper, and it does not.

Offline routing runs entirely on the phone through a routing engine compiled
into the app — that is why routing tiles are downloaded rather than a route
being requested from a server. No start point, end point or route is ever sent
anywhere.

---

## A note on the loopback server

To draw the map from what you have downloaded, the app runs a tiny HTTP server
bound to `127.0.0.1` on an ephemeral port, behind a random per-run path. The map
engine reads the downloaded data it draws through it: the lanes and the traffic
orders (as map tiles from the lane data on your phone, or as a GeoJSON file
while those tiles are not available), downloaded satellite imagery, and
downloaded height data for hill shading and 3D. All of it is public data from
the packs on your phone. What is yours in it is the choosing: the GeoJSON files
are cut to your map filters (with an "around me" area chosen, to the lanes near
where you are), and the one of lanes marks the lanes you have starred, so the
map can draw them. They never carry your position itself, your notes or your
recordings. Nothing outside the device can reach the server, and nothing it
serves leaves the phone.

---

## The free download period, and how it is measured

The app is free and never locks. For the first **30 days** from first install,
downloading maps is free too; after that, new map downloads need an update
pack, and everything already downloaded keeps working. The 30 days are measured
from two records, whichever is earlier: Android's own `firstInstallTime` for the
app, and the `firstSeen` date in the licence receipt. Both are dates. Neither
identifies you.

Whether or not you ever buy anything, your data stays yours and in reach: the
app never locks you out of your own rides, waypoints or plans.

---

## Children

Trail Blazer is not directed at children and collects nothing from anyone.

## Special category data

None is collected. The app does not ask for or infer health, biometric,
political, religious or similar data.

---

## Your rights, and how to exercise them

Because the app holds your data only on your own device and transmits none of it
to us, most requests are things you can carry out yourself and immediately:

- **See your data.** It is in the app — the Tracks screen, your waypoints, your
  plans.
- **Export it.** Any ride can be exported to GPX, and **Back up what you have
  put in** in Settings writes out your rides, waypoints, plans and lane notes
  as one file.
- **Delete it.** Delete individual rides, waypoints and plans in the app; or use
  Android's "Clear storage" to remove everything the app has written; or
  uninstall the app, which removes all of it. Note that the licence receipt is
  the one file included in Android backup, so a reinstall on a phone with backup
  turned on will restore the months of map updates you paid for — and only
  that.
- **Object or complain.** Contact us at the address below. In the UK you may
  also complain to the Information Commissioner's Office at
  [ico.org.uk](https://ico.org.uk).

We cannot retrieve, restore or delete your rides on your behalf, because we have
never had them.

---

## Data retention

Data on your phone is kept until you delete it or uninstall the app, except the
unrecorded trail, which goes as described under "The unrecorded trail". We
retain nothing, because we receive nothing.

---

## Changes to this policy

If this policy changes, the updated version will be published here and the date
at the top will change. Material changes will be noted in the app's release
notes.

---

## Contact

Lucaspottersoftwaredevelopment@gmail.com

---

## Map and lane data attribution

Lane data is public sector information from local highway authority definitive
maps, obtained via [rowmaps.com](https://www.rowmaps.com) and used under the
[Open Government Licence v3.0](https://www.nationalarchives.gov.uk/doc/open-government-licence/version/3/).
The basemap is OpenStreetMap data under the ODbL, served by OpenFreeMap. Routing
tiles are published by [brouter.de](https://brouter.de). Address search results
are ODbL, from OpenStreetMap. Weather forecasts are from MET Norway
(api.met.no), under [CC BY 4.0](https://creativecommons.org/licenses/by/4.0/),
summarised for the ride window.
