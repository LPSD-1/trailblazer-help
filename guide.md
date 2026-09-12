# Trail Blazer — rider's guide

Offline green-lane navigation for the UK. This guide covers everything from
first run to what to do when something will not work.

- [What it is for](#what-it-is-for)
- [The thing to read before you ride](#the-thing-to-read-before-you-ride)
- [First run](#first-run)
- [Reading the map](#reading-the-map)
- [Downloading data](#downloading-data)
- [Recording a ride](#recording-a-ride)
- [Waypoints](#waypoints)
- [Planning a route](#planning-a-route)
- [Following a route](#following-a-route)
- [The voice button](#the-voice-button)
- [Screen lock](#screen-lock)
- [Controls that get out of the way](#controls-that-get-out-of-the-way)
- [The dashboard](#the-dashboard)
- [Settings](#settings)
- [Trial and purchase](#trial-and-purchase)
- [Troubleshooting](#troubleshooting)
- [Privacy](#privacy)

---

## What it is for

Trail Blazer shows the green lanes of England and Wales over a map, records
where you rode, and works with no signal. You download the areas you ride
before you go, and after that the phone needs nothing from the network.

It also imports and follows your own GPX, drives a rider's dashboard, and can
be worked hands-free with gloves on.

Nothing is bundled inside the app. You carry the ground you want and no more.

---

## The thing to read before you ride

Lane data comes from **local highway authority definitive maps** — the legal
record of public rights of way — obtained via [rowmaps.com](https://www.rowmaps.com)
and used under the Open Government Licence v3.0.

**Traffic Regulation Orders and temporary closures are not in that data.**

The definitive map records that a right of way exists and what class it is. It
does not record that a byway is shut this winter, or that a TRO bans motor
vehicles on it. A lane shown here as a byway open to all traffic may still be
closed to you today.

The app says the same thing against every pack of official data:

> From the official record. Temporary closures and Traffic Regulation Orders
> are NOT included — check signage.

Where a country has no official register, the app draws community-mapped tracks
instead and labels them differently:

> Community-mapped tracks. This shows where they are, NOT whether you may
> legally ride them. Check local rules and signage.

Check signage on the ground and your local authority's TRO register before you
ride. This data is guidance, not permission.

---

## First run

The app asks three things, in this order, and explains each one before asking.

1. **What do you ride?** Lane data is published per vehicle, and this decides
   which lanes you are shown and which packs get downloaded. Change it later in
   Settings.
2. **Location permission.** It is used on the phone to work out which country
   and area to suggest. You can refuse and pick a country by hand.
3. **What to download.** Once it has a fix it offers the country you are in, or
   the smaller area you are in, each with its size.

Two ways out of the sheet are always available: **Browse all countries** to
pick ground yourself, and **Not now** to go straight to the map.

Downloading the country or the area also fetches the background map for that
ground. You need both: lanes are drawn on top of the map, so lanes without a
map is lanes over a blank screen.

---

## Reading the map

A lane is drawn with three separate visual channels. Each one carries different
information, and you can read any of them on its own.

### Colour says whether you may ride it

Two colours, and only two.

| Colour | Meaning |
|---|---|
| **Green** | You may ride this today |
| **Red** | You may not ride this today |

That is the only question colour answers. There is no colour code for lane
class, because a byway with a Traffic Regulation Order running on it used to
draw in full-access green — dashed and faded, but green, which is the one
colour on this map that means go.

### Width says the access class

The line is drawn thicker or thinner according to what class of way it is.

| Width | Class |
|---|---|
| Boldest | Full access — byway open to all traffic |
| Normal | Everything else |
| Thinnest | Restricted |

Lines get thicker as you zoom in, but the ratio between classes holds at every
zoom.

### Dashes say closed or seasonal

| Pattern | Meaning |
|---|---|
| Solid | Nothing extra to know |
| Tight short dashes, faded | Closed to you — reads as a barrier |
| Long dashes | Seasonal restraint — a caution, not a barrier |

**A seasonal lane is drawn green on purpose.** A seasonal restraint is a
request, not an order, and riding one is not an offence. Colouring it red would
tell you something untrue in the other direction. It gets long dashes instead,
so it still reads as "there is something to know here" without claiming the
lane is shut.

### If you are colour-blind

Read width and dashes. They carry the same information and do not depend on
hue at all.

Around one man in twelve cannot separate red from green, so hue is never the
only channel. A lane you may not ride is red **and** dashed tight **and** drawn
at 55% opacity, and its class is still carried by line width. Three channels,
two of which survive colour blindness.

A lane you have starred gets an amber halo drawn underneath it, wider than the
line. That is deliberately not one of the three legal channels.

### Tapping a lane

Tap any lane for its access, designation, which vehicles may use it, and why it
is restricted if it is.

---

## Downloading data

Open **Downloads**. Four one-tap choices, smallest first:

- **Just where I am standing** — for when the signal is about to go
- **The area I am in**
- **The country I am in**
- **Everything** — every country published; check the size and use wifi

Above 1 GB you get a confirmation showing the size and the number of packs.
Downloads are handed to the operating system, so they carry on when you close
the app and survive the phone being locked or the app being killed. You can
close the app and come back.

### The kinds of data

| Kind | What it gives you |
|---|---|
| **Lanes** | Which tracks and byways exist, and their status |
| **Routing** | Lets the app work out routes with no signal |
| **Ready-made trips** | Well-known days out, ready to ride or change |
| **Satellite imagery** | Aerial photos, to see what a track really looks like |

Satellite imagery is by a long way the largest thing published — Britain alone
runs to hundreds of megabytes. It is **included by default**, because a rider
who downloads a county and then finds the satellite view empty has been handed
an incomplete download rather than protected from a big one.

There is a switch on the Downloads screen — **Include satellite imagery** —
and turning it off removes those bytes from every size quoted on the buttons
above it. If two or more levels of detail are published for your ground, a
picker appears with a sample photograph of the same patch at each level, so you
can judge detail against size by eye.

### Browsing by hand

**Browse** drills down continent, then country, then area. Sizes are filtered
to what you ride, so a motorcyclist is not quoted the cost of 437,000
footpaths. An area with nothing for your vehicle is not listed.

On an area, **Get all** takes only what is missing or out of date, and says how
much that is.

### The background map

The lanes are drawn over a map, and the map needs downloading too. The one-tap
buttons do both halves. To add more ground later, open **Offline maps**:

- Pick a **named region**, or
- **Around my position** at 10 km, 25 km or 50 km, each quoting its real size.

Above 100 MB you are asked to confirm. Re-downloading a region replaces it
rather than resuming, so retry and refresh both ask first — on a weak
connection you can end up with less than you have now.

### Updates

Each kind of data has its own re-check interval, published with the index and
overridable by you. There is an **only check on wifi** switch, and it is
honoured by the operating system rather than by the app.

---

## Recording a ride

The record button sits on the map.

- **Tap** to start. The button turns red.
- **Hold** to pause. Pausing starts a new segment, so the gap is neither drawn
  as a line nor counted in your distance.
- **Tap** while paused to resume.
- **Tap** while recording to finish. You are asked "Finish this ride?" before
  anything stops.

While recording, Android runs a foreground service with an ongoing "Recording
your ride" notification. That is what keeps the track being logged with the
screen off and the phone in a tank bag. Without it Android throttles background
location to a few updates an hour and you get a straight line across country.

The ride autosaves as it goes, so a flat battery costs you the last few points
rather than the day. If the position stream goes dead for 15 minutes the ride
is ended and saved by itself.

Recording ignores fixes that are too close together, too soon after the last
one, or impossibly fast. A gap of more than two minutes breaks the track into a
new segment rather than drawing a straight line through it, which is what
happens in a tunnel.

Your rides are yours. Export any of them to GPX from the Tracks screen, whether
or not you have bought the app.

---

## Waypoints

Mark a gate, a ford, a parking spot or a wrong turn. A mark is named
automatically — "Waypoint 4" — and you can give it a real name and a note
afterwards.

Marking works by voice, which is the point: "mark this" with gloves on, and the
app says back which one it made, so several marks in an afternoon can be told
apart before you look at the screen.

Waypoints come out in the GPX export alongside your rides.

---

## Planning a route

There are three different things here, and the difference matters.

**A plan** is yours. It is an ordered list of stops you can edit, reorder and
re-run. Only the stops are saved, never the line — so a plan reopened next
season follows today's rights of way rather than replaying a route worked out
against last year's data.

**A ready-made trip** is one we published: a name, a description and the points
it passes through. Tap **Add to my plans** to take a copy you can change. The
published one stays as published for the next person.

**A route** is the line the app works out between them, on the phone.

### Route styles

| Style | What it does |
|---|---|
| **Fastest** | Main roads, quickest way there |
| **Fun** | Back roads and bends. Still tarmac |
| **Green lanes** | Includes byways and unsurfaced tracks |

Each stop carries the style for the leg to the next one, so a plan can run out
on the fast road and back over the lanes.

### What you are travelling on

Car, motorbike, bicycle or walking. This changes the time estimate rather than
the route, so the journey is timed for the thing you are actually on instead of
for a car crawling over a byway at 1 km/h.

It is a separate question from the vehicle your lane filter is set to. Your
filter can say 4x4 while you go for a walk this afternoon.

### The day-out planner

**A day out from here** builds a loop from the real byways around you. Pick how
long you have:

- **A morning** — 30 km
- **Half a day** — 60 km
- **A full day** — 100 km
- **A long one** — 160 km

It chains lanes near you into a loop within that budget, ignoring anything under
250 m. Open lanes are always preferred; a restricted one is used only if that
would otherwise leave you with nothing, and when one is in the loop the app
names it rather than slipping it in:

> One of these is under a restriction: [name]. Check it before you set off.

**Another one** rerolls the suggestion. **Keep it** saves it to your plans.

The starting point is pinned to where you were when you opened the sheet, so
the suggestion does not rewrite itself while you are reading it.

### Your own GPX

Import tracks, routes and waypoints from any GPX file. This is never gated by
sign-in or purchase, and it needs no download at all.

---

## Following a route

Start a plan, or follow one of your own tracks, and the app shows distance
remaining, percentage done, and estimated arrival time on a 24-hour clock.

If you leave the line by more than about 40 metres you get told plainly, with
the direction back:

> Off route — 210 m away to the NE

The app re-plans by itself, at most once every 15 seconds, from where you are
now to the stops you have not reached yet — not back to the start. If it cannot
work out a new route it says so and keeps the old line drawn, because silence
reads as "still guiding me".

When the fix goes quiet, the figures go to dashes rather than freezing on a
stale number.

---

## The voice button

One large round button on the map, sized to be hit in winter gloves without
looking. Press it and speak. Recognition runs on the device where the platform
supports it, so it works with no signal.

### What you can say

| Say | What happens |
|---|---|
| "start recording", "record ride", "start ride", "begin recording" | Starts recording |
| "stop recording", "end ride", "finish ride" | Stops recording |
| "pause recording", "pause ride" | Pauses recording |
| "mark", "mark this", "drop pin", "mark waypoint", "save this spot", "mark gate" | Drops a waypoint |
| "show lanes", "lanes on" | Shows lanes |
| "hide lanes", "lanes off" | Hides lanes |
| "zoom in", "closer" / "zoom out", "wider" | Zooms |
| "centre on me", "find me", "recentre" | Centres on your position |
| "north up", "face north" | Locks the map north |
| "heading up", "track up", "follow heading" | Turns the map with you |
| "day mode", "brighten" / "night mode", "darken" | Switches theme |
| "dashboard", "show gauges" | Opens the dashboard |
| "show map", "back to map" | Returns to the map |
| "nearest lane", "closest lane", "find a lane" | Finds the nearest lane |
| "how far", "how much further", "distance remaining" | Reads out distance to go |
| "where am i", "grid reference", "grid ref" | Reads out your position |
| "plan a day out", "what can i ride", "suggest a loop" | Opens the day-out planner |
| "stop the journey", "stop navigating", "cancel the route" | Ends the journey |
| "repeat", "say again" | Repeats the last thing said |
| "cancel", "never mind", "forget it" | Cancels |
| "help", "what can i say" | Lists commands |

To set a destination, start with any of **"take me to"**, **"navigate to"**,
**"directions to"**, **"set a route to"**, **"plan a route to"**, **"route
to"**, **"ride to"** or **"go to"**, then say the place.

Filler is stripped before matching, so "could you please hide the lanes" works.
"Trail" and "blazer" are treated as wake words. A negative — "don't hide the
lanes" — is refused rather than guessed at.

### What gets confirmed first

Stopping or pausing a recording, stopping a journey, and cancelling are all
confirmed aloud before they happen if the app is not confident it heard you.
Setting a new destination while you are already riding a journey is **always**
confirmed, whatever the confidence, because it would silently replace the route
you are on and there is no undo.

Answer with yes, yeah, yep, aye, ok or correct — or no, nope, nah or cancel.
The question expires after 20 seconds.

There is no bare "pause" on purpose. A one-word match scores full confidence
and would skip the confirmation, and a misheard pause means the rest of the
ride is silently not recorded.

### Grid references

A grid reference is read out character by character — "N Y, 2 1 5, 0 7 2" —
because that is intelligible through a helmet and "NY215072" is not. Outside
Great Britain you get spoken decimal coordinates with "north" and "west"
instead of a minus sign.

---

## Screen lock

Rain is a stream of taps. So is a wet glove, a branch on a narrow lane, and a
cuff resting on a tank bag. Any of them can switch tabs, stop a recording or
throw away a route, and you would find out miles later.

Tap the padlock on the map to lock the screen. **Every touch in the app is
blocked**, including the Android back button and the back gesture, until you
deliberately undo it.

To unlock, **press and hold for 900 ms** on the control at the bottom. A ring
fills so you can see how long is long enough. A tap will not do it, because a
tap is exactly what rain produces.

While locked, the map hides its controls. Nothing on screen could be pressed
anyway.

Locking does not survive a restart, and that is deliberate — nothing is lost by
starting unlocked.

### Locking itself

Turn on **Lock screen automatically** in Settings and the screen locks itself
the first time you are detected moving after starting a journey. It fires once
per journey and then leaves you alone, so stop-starting through a village does
not relock it every time.

It is off by default. A screen that locks itself is a surprise the first time,
and a surprise on a motorbike is worth avoiding.

---

## Controls that get out of the way

Three modes, in Settings:

- **Auto** — controls fade out while you ride and come back a few seconds after
  you stop.
- **Always show** — controls stay on screen all the time.
- **Minimal** — controls stay hidden. Tap the handle at the edge when you need
  them.

On Auto, the controls hide after 3 seconds of riding above about 4.5 mph, and
come back after 5 seconds stationary below about 1.8 mph. The two different
speeds stop them flickering at a crawl.

You can always pull them back with the handle at the edge. A manual reveal
stays until you hide it yourself; no timer takes it away.

---

## The dashboard

Say "dashboard", or open it from the map. Twelve gauges, glove-sized and
high-contrast, that survive doubled system text:

Speed · Clock · Trip · Moving time · Altitude · Heading · Grid reference ·
Max speed · Average moving speed · Tilt · Gradient · Odometer

It is a screen you open rather than a tab that is always there, because
repainting twelve gauges continuously costs battery whether you are looking at
them or not.

**Readings go to a dash rather than lying.** Anything older than 10 seconds
shows "—" instead of a stale confident number. Your position is the exception:
it is kept for 30 seconds and then labelled with its age ("40s old", "4 min
old"), because losing your last known position in an emergency would be its own
failure.

**Tilt, not lean.** The gauge reads device roll against the force it feels. In
a steady banked turn that force lines up with the bike, so the reading falls
towards zero exactly when you are most leaned over. Calling it lean would put a
number on the dashboard that is most wrong when you are most likely to look at
it.

**The trip tile is also a fuel gauge.** Long-press it to reset the trip and
mark the tank as full. Double-tap it to set how far you get on a tank, and the
tile then fills green, amber and red as you use it up.

---

## Settings

- **Units** — miles or kilometres. Miles by default.
- **Theme** — day, night or follow the system.
- **Keep the screen awake** — on by default. If your phone overrules it, the
  screen tells you rather than pretending.
- **Lock screen automatically** — off by default. See above.
- **Map view** — Auto, Always show or Minimal.
- **What you ride** — changes which lanes you see and which packs download.
- **Update schedule** and **only check on wifi**.
- **Map updates** — what you have bought and how long it runs.

---

## Trial and purchase

The app installs free and everything works for **30 days**. No account, no
sign-in, nothing to fill in.

After that there is a **one-time purchase**. One payment, no subscription,
nothing to cancel. Google Play handles it, and it restores on any device you
sign into with the same account.

Map data is sold separately as **update packs**: a one-off payment buying one,
three, six or twelve months during which you can download new and corrected
lane data as councils publish it. These stack — buy a year and then a month and
the month runs from the end of the year, so renewing early never destroys time
you have paid for. Nothing recurs and nothing needs cancelling.

When an update window runs out, **everything you have already downloaded keeps
working**. Only new downloads stop.

The trial is measured from when the app was installed, read from Android's own
records and from a receipt file. That receipt is the one thing backed up to your
Google account, so changing phone keeps what you paid for.

**Your rides are yours either way.** If you do not buy the app, the paywall
screen has an export that writes out every ride, waypoint and plan as GPX. An
app that took your own recordings away would earn exactly the review it
deserves.

---

## Troubleshooting

### No position fix

- Check location is switched on for the phone, and allowed for Trail Blazer.
  The app shows a banner with a button straight to the right settings screen.
- Indoors or in a valley a first fix can take several minutes. The dashboard
  keeps your last known position and labels how old it is.
- If you refused location permanently, Android will not ask again. Use the
  **Open settings** button on the banner.
- Recording still works without the notification permission. You lose the
  ongoing indicator, not the ride.

### The map is blank

An empty map has five different causes and they are not the same problem. The
app tells you which one it is, and tapping the notice takes you where it is
undone:

- **"No lane data for where you are"** — nothing is downloaded here. This does
  not mean there is no right of way. Download the area.
- **"The map is set to show one area and this is not it"** — you picked an area
  once and have ridden out of it. Clear it in the filters.
- **"Lanes are switched off"** — the empty map is that switch, not the ground.
- **"Your filters are hiding every lane here"** — the filter, not the absence of
  a right of way.
- **"The lane pack for here is on the phone but could not be loaded"** —
  re-download it.

If the **background** is blank rather than the lanes, you have lanes but no
map tiles for this ground. Open **Offline maps** and download the region. With
no signal and no downloaded region the map will be blank, and lanes are drawn
on top of it. The dashboard and recording work either way.

### A route will not compute

The app names what is wrong instead of saying "no route":

- **"Routing data is missing for part of this route. Download [areas], then try
  again."** — it names areas you will find on the download screen. Get them.
- **"That took too long to work out"** or **"too big to work out on this
  phone"** — try a shorter route, or add a stop part-way along it. A stop
  splits the search into two smaller ones.
- **"No route found between those points"** — there is genuinely no way through
  for the travel mode and style you picked. Try Fastest, or a different
  destination.

Routing runs entirely on the phone. If it says data is missing, it means a
downloaded file, not a lost signal.

### No signal

Almost everything works. With the area downloaded you get the map, the lanes,
lane detail, routing, recording, the dashboard, the voice button and your own
GPX.

Two things need a connection:

- **Address search.** Grid references, coordinates, your own marks, rides and
  plans, and the names of lanes in the packs you carry are all searched on the
  phone. Only typed place names and addresses need the network, and the app
  says so rather than showing an empty list.
- **Downloading anything new.**

If you are about to lose signal, **Just where I am standing** on the Downloads
screen is the fastest way to get what you need.

### A ride is missing from the list

If a recording file cannot be read, the app moves it aside and keeps telling
you it is there rather than pretending the ride never happened. The notice
stays up until you deal with it.

### Something was downloaded but nothing changed

Downloads are checked against a hash before they are published to the app. A
file that fails is discarded rather than opened. Try it again on a better
connection.

---

## Privacy

The short version: no account, no analytics, no tracking, and your rides never
leave the phone. The full policy — including the one narrow case in which
anything derived from your position is transmitted — is in
[privacy.md](privacy.md).

---

## Attribution

Lane data: local highway authority definitive maps via
[rowmaps.com](https://www.rowmaps.com), under the
[Open Government Licence v3.0](https://www.nationalarchives.gov.uk/doc/open-government-licence/version/3/).
Contains public sector information licensed under the Open Government Licence
v3.0.

Basemap: OpenStreetMap data under the ODbL, served by OpenFreeMap. Routing
tiles published by [brouter.de](https://brouter.de).

Lane information is guidance only. Always check signage and current Traffic
Regulation Orders before riding.
