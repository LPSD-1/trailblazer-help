# Privacy policy

**Trail Blazer — Offline maps**
Application id `com.trailblazerofflinemaps`

Last updated: 12 September 2026

## The short version

Trail Blazer has no user accounts, no sign-in, no analytics, no crash
reporting, no advertising and no tracking identifiers of any kind.

Your rides, your waypoints, your saved plans and your settings are written to
your phone and stay there. They are not uploaded to us, they are not uploaded
to anyone else, and they are excluded from Android's own cloud backup on
purpose.

The app does use the network for five things, and only those five: downloading
map data, drawing the online basemap, looking up an address you type, speech
recognition, and Google Play billing. Each is described below, including
exactly what the other end can see.

We do not operate a server that receives anything from the app. There is
nowhere for us to store your data even if we wanted to.

---

## Who we are

Trail Blazer is published by the developer named on the Google Play listing for
`com.trailblazerofflinemaps`. For data protection purposes that developer is the
data controller for the very small amount of processing described here.

---

## What the app stores on your phone

All of this is in the app's own private storage. No other app can read it, and
none of it is transmitted.

| What | Where | Contains |
|---|---|---|
| Recorded rides | `app_flutter/user_content/tracks/<id>.json` | A timestamped list of positions, with elevation and speed where the phone reported them |
| Waypoints | `app_flutter/user_content/waypoints.json` | Position, name and note for each mark you make |
| Saved plans | `app_flutter/user_content/plans/<id>.json` | The stops in a planned route |
| Imported GPX | Same as rides and waypoints | Whatever was in the file you imported |
| Downloaded map data | App support directory: `lane-packages/`, `routing/segments/`, `trips/`, `basemaps/` | Public map data. Nothing about you |
| Offline basemap regions | MapLibre's own tile database | Map tiles for the areas you chose |
| Licence receipt | `files/licence/receipt.json` | See "What the receipt holds" below |
| Settings | Android `SharedPreferences` | See "What the settings hold" below |

A recorded ride is a precise history of where you have been. The app treats it
that way: it is the single most sensitive thing on the phone, and it is the
thing most carefully kept off the network.

### What the settings hold

The app's preferences file holds only choices you have made. There are no
identifiers in it. The complete set of keys is:

`settings.theme_mode`, `settings.units`, `settings.keep_awake`,
`settings.auto_lock`, `map.basemap`, `map.chrome_mode`, `map.show_gauges`,
`lanes.favourites` (the lanes you starred), `lanes.scope`, `rider.vehicle`,
`packages.vehicle`, `downloads.includeImagery`, `downloads.imageryDetail`,
`updates.policy`, `updates.wifi_only`, `updates.last_checked`, `setup.seen`,
`routing.style`, `routing.includeTracks`, `journey.travel_mode`,
`ride.odometer_metres`, `ride.fuelRangeMetres`, `ride.fuelFilledAtOdometerM`,
`ride.active.plan`, `ride.active.entry`, `ride.active.adhoc`.

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
fetches the published index and then the files you asked for.

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

### 3. Address search — the one place a position is sent

Typing a place name into the search box sends that text to OpenStreetMap's
Nominatim service at `https://nominatim.openstreetmap.org/search`.

What is sent:

- the text you typed,
- a `User-Agent` of `TrailBlazer/0.1 (offline green-lane navigation)`, which
  Nominatim's usage policy requires,
- **and, if the app currently knows your position, a `viewbox`: a box one degree
  of latitude and longitude either side of you.** It is sent only so that nearby
  results are offered first.

One degree is roughly 110 km north to south, so the box is about the size of a
couple of counties, not a pinpoint. It is nonetheless derived from where you are,
and it is the only case anywhere in the app in which anything derived from your
position is transmitted. If that is not acceptable to you, do not use the
address search: grid references, coordinates, your own marks, rides and plans,
and the names of lanes in the packs you carry are all searched entirely on the
phone.

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

Buying the app, or an update pack, goes through Google Play. Google receives
whatever Google receives for any Play purchase — your Play account, your payment
details, and the product you bought. We never see your payment details and we
operate no server that receives anything about your purchase.

The app asks Play for the product's localised price and title, and asks Play
what your account already owns so that a reinstall restores it. Purchases are
verified on the device only. What the app writes down locally is described under
"What the receipt holds" above.

Google's handling of a Play purchase is covered by the
[Google Privacy Policy](https://policies.google.com/privacy).

---

## What does not happen

Verified against the source and the dependency lockfile:

- **No analytics or telemetry.** There is no Firebase, no Crashlytics, no
  Sentry, no Amplitude, no Mixpanel, no Segment, no PostHog, no Bugsnag and no
  App Center anywhere in the project.
- **No advertising, and no advertising identifier.**
- **No account, no sign-in, no email address collected.**
- **No contacts, calendar, photos, files or SMS access.**
- **No server of ours.** Every network destination named above belongs to a
  third party publishing static data or providing a public service.
- **Recorded rides are never uploaded**, including to Android backup.

### Every third-party package the app ships, and what it does

| Package | What it does | Network? |
|---|---|---|
| `flutter_riverpod`, `riverpod_annotation` | State management inside the app | No |
| `maplibre_gl` | Renders the map and stores offline regions | Fetches map tiles (see §2) |
| `pmtiles` | Reads downloaded satellite imagery archives | No |
| `geolocator` | Position fixes and the recording foreground service | No |
| `sensors_plus`, `flutter_compass` | Roll, gradient and compass heading | No |
| `latlong2` | Coordinate arithmetic | No |
| `gpx`, `xml` | Reading and writing GPX files | No |
| `cryptography`, `crypto`, `convert` | Decrypting downloaded packs; hashing the purchase token | No |
| `http` | Fetching the data index, packs and address search | Yes (see §1, §3) |
| `background_downloader` | Hands pack downloads to the OS so they survive the app closing | Yes (see §1) |
| `shared_preferences` | Settings, on the device | No |
| `sqflite`, `path_provider`, `path` | Local storage | No |
| `permission_handler` | Asks for the notification permission when a ride starts | No |
| `wakelock_plus` | Keeps the screen awake while riding | No |
| `file_picker` | Choosing a GPX file to import | No |
| `share_plus` | Sharing a GPX file you exported | No |
| `flutter_secure_storage` | Present but not used by any shipped code path | No |
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
notification you cannot swipe away while it runs. `POST_NOTIFICATIONS` is
requested at that moment, for that notification. If you refuse it the ride still
records; you simply lose the indicator.

**`ACCESS_BACKGROUND_LOCATION` is deliberately not declared and never
requested.** The recording service does not need it, and declaring it would ask
you for a far broader permission than the app uses.

The app also declares `RECORD_AUDIO` (the voice button), `WAKE_LOCK` (keeping
the screen on while riding) and `INTERNET`. The microphone is marked as not
required, so the app still installs on a device without one.

### If you refuse

The app keeps working. You get a banner explaining what is missing, with a
button to the relevant system settings. You cannot see your position or record a
ride, but you can still browse the map, download data, read lane detail, plan a
route between points you pick by hand, and import and export GPX.

### Is your location ever transmitted?

Once, in one narrow case, and nowhere else: the approximately one-degree
`viewbox` sent to Nominatim when you use the address search, described in §3
above. Your position is not sent when you record, when you download, when you
route, when you plan, or when you buy anything.

Offline routing runs entirely on the phone through a routing engine compiled
into the app — that is why routing tiles are downloaded rather than a route
being requested from a server. No start point, end point or route is ever sent
anywhere.

---

## A note on the loopback server

To draw downloaded satellite imagery, the app runs a tiny HTTP server bound to
`127.0.0.1` on an ephemeral port, behind a random per-run path. It serves public
satellite imagery from the archive on your phone. Nothing outside the device can
reach it, and it carries nothing of yours.

---

## The trial, and how it is measured

The app is free to install and fully usable for **30 days** from first install.
After that there is a one-time purchase. The trial is measured from two records,
whichever is earlier: Android's own `firstInstallTime` for the app, and the
`firstSeen` date in the licence receipt. Both are dates. Neither identifies you.

If you do not buy the app, you keep your data. There is an export on the paywall
screen that writes out every ride, waypoint and plan as GPX, precisely so that a
locked app never holds your own recordings hostage.

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
- **Export it.** Any ride can be exported to GPX, and the paywall screen exports
  everything at once.
- **Delete it.** Delete individual rides, waypoints and plans in the app; or use
  Android's "Clear storage" to remove everything the app has written; or
  uninstall the app, which removes all of it. Note that the licence receipt is
  the one file included in Android backup, so a reinstall on a phone with backup
  turned on will restore your purchase — and only your purchase.
- **Object or complain.** Contact us at the address below. In the UK you may
  also complain to the Information Commissioner's Office at
  [ico.org.uk](https://ico.org.uk).

We cannot retrieve, restore or delete your rides on your behalf, because we have
never had them.

---

## Data retention

Data on your phone is kept until you delete it or uninstall the app. We retain
nothing, because we receive nothing.

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
are ODbL, from OpenStreetMap.
