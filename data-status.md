# Where our data comes from

Trail Blazer's map is built from public records: councils' rights of way and
highway records, the Department for Transport's traffic orders, and a handful
of national datasets. This page shows where each piece comes from, how fresh
it is, and the councils doing an especially good job of sharing their data.
It updates itself through the day, and the app shows the same thing under
**Settings → Map updates → Where our data comes from**.

> **The map is a guide, not permission to ride or drive anywhere.** Not every
> closure is shown, so go by the signs on the ground: they and the law come
> first. Traffic orders reach the map only where a council publishes them, and
> not every council does yet, so a lane with no order on the map can still
> have one in force.

<noscript>
<p class="ds-fallback"><strong>The live figures need JavaScript</strong>, which is switched off in this browser. Everything on this page is also in a plain file anyone can read: <a href="https://lpsd-1.github.io/trailblazer-datasets/published/status.json">status.json</a>. Or open the app and go to <strong>Settings → Map updates → Where our data comes from</strong>, which keeps a copy you can read with no signal.</p>
</noscript>

<div id="ds" class="ds" hidden>
<p class="ds-updated" id="ds-updated"></p>
<p class="ds-fallback" id="ds-error" hidden>The live figures could not be loaded just now. Try again in a few minutes, or read the file directly: <a href="https://lpsd-1.github.io/trailblazer-datasets/published/status.json">status.json</a>.</p>
<div id="ds-body" hidden>
<h2 id="how-fresh">How fresh the data is</h2>
<p>Each kind of data is refreshed on its own timetable. If a refresh hits a problem, the map keeps the last good copy until the next one works.</p>
<table class="ds-table ds-runs">
<thead><tr><th scope="col">Data</th><th scope="col">How often</th><th scope="col">Last refreshed</th><th scope="col">Status</th></tr></thead>
<tbody id="ds-runs"></tbody>
</table>
<h2 id="doing-it-well">Councils doing it well</h2>
<p>A thank you to the councils and national parks that meet at least two of these: they share their own data openly, they publish it under the Open Government Licence, and they publish their traffic orders to the Department for Transport's D-TRO service.</p>
<ul class="ds-honours" id="ds-honours"></ul>
<h2 id="every-council">Every council and national park</h2>
<p>What the map holds from each highway authority in England and Wales, and where it came from. Tap a name to see its sources.</p>
<label class="ds-search-label" for="ds-search">Find a council</label>
<input class="ds-search" id="ds-search" type="search" placeholder="Devon, Powys, Peak District..." autocomplete="off">
<p class="ds-none" id="ds-none" hidden></p>
<section id="ds-england"><h3>England</h3>
<table class="ds-table ds-auth"><thead><tr><th scope="col">Council</th><th scope="col">Byways</th><th scope="col">Unsurfaced roads</th><th scope="col" class="ds-dtro-col">D-TRO</th></tr></thead><tbody></tbody></table>
</section>
<section id="ds-wales"><h3>Wales</h3>
<table class="ds-table ds-auth"><thead><tr><th scope="col">Council</th><th scope="col">Byways</th><th scope="col">Unsurfaced roads</th><th scope="col" class="ds-dtro-col">D-TRO</th></tr></thead><tbody></tbody></table>
</section>
<h2 id="recent-changes">Recent changes</h2>
<ul class="ds-notes" id="ds-notes"></ul>
</div>
</div>

<style>
.ds [hidden], .ds[hidden] { display: none !important; }
.ds-fallback { padding: 12px 14px; border-radius: 8px; background: #f3f4f6; color: #1f2933; }
.ds-updated { color: #52606d; font-size: 0.95em; }
.ds-table { width: 100%; border-collapse: collapse; display: table; margin: 8px 0 20px; }
.markdown-body .ds-table { display: table; width: 100%; }
.ds-table th, .ds-table td { text-align: left; vertical-align: top; padding: 8px 10px; border: 0; border-bottom: 1px solid #e4e7eb; }
.ds-table th { font-weight: 600; background: #f5f7fa; }
.ds-table td.ds-num, .ds-table th.ds-num { text-align: right; font-variant-numeric: tabular-nums; }
.ds-what { display: block; color: #52606d; font-size: 0.9em; margin-top: 2px; }
.ds-small { display: block; color: #52606d; font-size: 0.85em; margin-top: 2px; }
.ds-badge { display: inline-block; padding: 1px 8px; border-radius: 999px; font-size: 0.9em; white-space: nowrap; }
.ds-ok { background: #e3f4e8; color: #1b5e34; }
.ds-running { background: #e6effa; color: #1d4f8c; }
.ds-problem { background: #fdf1dc; color: #7a4b00; white-space: normal; }
.ds-unknown { background: #eef0f2; color: #3e4c59; }
.ds-honours { list-style: none; padding-left: 0; }
.ds-honours li { padding: 8px 0; border-bottom: 1px solid #e4e7eb; }
.ds-honours .ds-reason { display: inline-block; margin: 4px 6px 0 0; padding: 1px 8px; border-radius: 999px; background: #e3f4e8; color: #1b5e34; font-size: 0.85em; }
.ds-search-label { display: block; font-weight: 600; margin-bottom: 4px; }
.ds-search { width: 100%; max-width: 420px; box-sizing: border-box; padding: 10px 12px; font-size: 16px; border: 1px solid #9aa5b1; border-radius: 8px; margin-bottom: 12px; }
.ds-auth details summary { cursor: pointer; font-weight: 600; }
.ds-auth details ul { margin: 6px 0 0; padding-left: 18px; font-size: 0.9em; }
.ds-auth details li { margin-bottom: 4px; }
.ds-none { color: #52606d; }
.ds-notes li { margin-bottom: 6px; }
.ds-hide-dtro .ds-dtro-col { display: none; }
@media (max-width: 640px) {
  .ds-table, .markdown-body .ds-table { display: block; }
  .ds-table thead { display: none; }
  .ds-table tbody, .ds-table tr { display: block; }
  .ds-table tr { padding: 10px 0; border-bottom: 1px solid #e4e7eb; }
  .ds-table td { display: block; border: 0; padding: 2px 0; }
  .ds-table td.ds-num { text-align: left; }
  .ds-table td[data-label]::before { content: attr(data-label) ": "; color: #52606d; }
  .ds-table td.ds-first::before { content: none; }
}
</style>

<script>
(function () {
  var URL_ = "https://lpsd-1.github.io/trailblazer-datasets/published/status.json";
  var RESULT = {
    ok: ["All good", "ds-ok"],
    running: ["Refreshing now", "ds-running"],
    problem: ["Having a problem — being looked at", "ds-problem"],
    unknown: ["Not known", "ds-unknown"]
  };
  var root = document.getElementById("ds");
  root.hidden = false;
  function el(tag, cls, text) {
    var e = document.createElement(tag);
    if (cls) e.className = cls;
    if (text !== undefined && text !== null) e.textContent = String(text);
    return e;
  }
  function str(v) { return typeof v === "string" && v.trim() ? v.trim() : null; }
  function num(v) { return typeof v === "number" && isFinite(v) ? Math.round(v) : null; }
  function list(v) { return Array.isArray(v) ? v.filter(function (x) { return x && typeof x === "object"; }) : []; }
  function when(v) {
    if (!str(v)) return null;
    var d = new Date(v);
    return isNaN(d.getTime()) ? null : d;
  }
  function day(v) {
    var m = /^(\d{4})-(\d{2})-(\d{2})$/.exec(str(v) || "");
    return m ? new Date(Date.UTC(+m[1], +m[2] - 1, +m[3])) : null;
  }
  function dateText(d) {
    return d.toLocaleDateString("en-GB", { day: "numeric", month: "short", year: "numeric", timeZone: "UTC" });
  }
  function ago(d) {
    var mins = Math.round((Date.now() - d.getTime()) / 60000);
    if (mins < 1) return "just now";
    if (mins < 60) return mins + (mins === 1 ? " minute ago" : " minutes ago");
    var hours = Math.round(mins / 60);
    if (hours < 24) return hours + (hours === 1 ? " hour ago" : " hours ago");
    var days = Math.round(hours / 24);
    if (days < 14) return days + (days === 1 ? " day ago" : " days ago");
    return "on " + dateText(d);
  }
  function count(n) { return n === null ? "Not known" : n.toLocaleString("en-GB"); }
  function cell(tr, label, cls) {
    var td = el("td", cls);
    if (label) td.setAttribute("data-label", label);
    tr.appendChild(td);
    return td;
  }
  function showRuns(datasets) {
    var body = document.getElementById("ds-runs");
    list(datasets).forEach(function (d) {
      var name = str(d.name);
      if (!name) return;
      var tr = el("tr");
      var first = cell(tr, null, "ds-first");
      first.appendChild(el("strong", null, name));
      if (str(d.what)) first.appendChild(el("span", "ds-what", d.what));
      cell(tr, "How often").textContent = str(d.schedule) || "Not known";
      var last = when(d.last_run);
      var lastCell = cell(tr, "Last refreshed");
      lastCell.textContent = last ? ago(last) : "Not known";
      var asOf = day(d.data_as_of);
      if (asOf) lastCell.appendChild(el("span", "ds-small", "Data dated " + dateText(asOf)));
      var r = RESULT[d.result] || RESULT.unknown;
      var statusCell = cell(tr, "Status");
      statusCell.appendChild(el("span", "ds-badge " + r[1], r[0]));
      var ok = when(d.last_ok);
      if (d.result === "problem" && ok) {
        statusCell.appendChild(el("span", "ds-small", "Still using the data from the last good refresh, " + ago(ok) + "."));
      }
      body.appendChild(tr);
    });
  }
  function showHonours(honours) {
    var ul = document.getElementById("ds-honours");
    var rows = list(honours).filter(function (h) { return str(h.name); });
    if (!rows.length) {
      ul.appendChild(el("li", null, "None listed just now."));
      return;
    }
    rows.forEach(function (h) {
      var li = el("li");
      li.appendChild(el("strong", null, h.name));
      li.appendChild(document.createElement("br"));
      (Array.isArray(h.reasons) ? h.reasons : []).forEach(function (reason) {
        if (str(reason)) li.appendChild(el("span", "ds-reason", reason));
      });
      ul.appendChild(li);
    });
  }
  var rowsByCountry = { England: [], Wales: [] };
  function showAuthorities(authorities) {
    var anyDtro = false;
    list(authorities).forEach(function (a) {
      var name = str(a.name);
      var country = a.country === "Wales" ? "Wales" : a.country === "England" ? "England" : null;
      if (!name || !country) return;
      var tr = el("tr");
      var first = cell(tr, null, "ds-first");
      var details = el("details");
      details.appendChild(el("summary", null, name));
      var full = str(a.full_name) || name;
      details.appendChild(el("span", "ds-small", full + (a.kind === "park" ? " (national park)" : "")));
      var sources = el("ul");
      list(a.sources).forEach(function (s) {
        if (!str(s.what)) return;
        var asOf = day(s.as_of);
        var text = s.what + (str(s.from) ? ": " + s.from : "") + (asOf ? " (dated " + dateText(asOf) + ")" : "");
        sources.appendChild(el("li", null, text));
      });
      if (!sources.children.length) sources.appendChild(el("li", null, "No sources listed yet."));
      details.appendChild(sources);
      list(a.activity).forEach(function (line) {
        if (str(line.text)) details.appendChild(el("span", "ds-small", line.text));
      });
      first.appendChild(details);
      cell(tr, "Byways", "ds-num").textContent = count(num(a.byways));
      cell(tr, "Unsurfaced roads", "ds-num").textContent = count(num(a.unsurfaced_roads));
      var dtro = str(a.dtro);
      if (dtro) anyDtro = true;
      var dtroCell = cell(tr, "D-TRO", "ds-dtro-col");
      dtroCell.textContent = dtro || "Not known";
      var key = (name + " " + full).toLowerCase();
      rowsByCountry[country].push({ tr: tr, key: key });
      document.querySelector("#ds-" + country.toLowerCase() + " tbody").appendChild(tr);
    });
    if (!anyDtro) root.classList.add("ds-hide-dtro");
    filter("");
  }
  function filter(query) {
    var q = query.trim().toLowerCase();
    var shown = 0;
    ["England", "Wales"].forEach(function (country) {
      var here = 0;
      rowsByCountry[country].forEach(function (r) {
        var match = !q || r.key.indexOf(q) !== -1;
        r.tr.hidden = !match;
        if (match) here++;
      });
      document.getElementById("ds-" + country.toLowerCase()).hidden = here === 0;
      shown += here;
    });
    var none = document.getElementById("ds-none");
    none.hidden = shown > 0;
    none.textContent = shown > 0 ? "" : "No council matches “" + query.trim() + "”.";
  }
  function showNotes(notes) {
    var ul = document.getElementById("ds-notes");
    list(notes).forEach(function (n) {
      if (!str(n.text)) return;
      var d = day(n.date);
      ul.appendChild(el("li", null, (d ? dateText(d) + ": " : "") + n.text));
    });
    if (!ul.children.length) ul.appendChild(el("li", null, "Nothing new just now."));
  }
  document.getElementById("ds-search").addEventListener("input", function (e) {
    filter(e.target.value);
  });
  function fail() {
    document.getElementById("ds-error").hidden = false;
  }
  fetch(URL_, { cache: "no-cache" }).then(function (r) {
    if (!r.ok) throw new Error("HTTP " + r.status);
    return r.json();
  }).then(function (s) {
    if (!s || typeof s !== "object" || s.schema !== 1) {
      fail();
      return;
    }
    var generated = when(s.generated);
    document.getElementById("ds-updated").textContent = "Last updated: " +
      (generated ? generated.toLocaleString("en-GB", { day: "numeric", month: "long", year: "numeric", hour: "2-digit", minute: "2-digit" }) + " (" + ago(generated) + ")" : "not known");
    showRuns(s.datasets);
    showHonours(s.honours);
    showAuthorities(s.authorities);
    showNotes(s.notes);
    document.getElementById("ds-body").hidden = false;
  }).catch(fail);
})();
</script>

---

The figures come from
[status.json](https://lpsd-1.github.io/trailblazer-datasets/published/status.json),
which our data system rewrites whenever something on this page changes. It
holds no personal details, only council names and counts. Lane data contains
public sector information licensed under the
[Open Government Licence v3.0](https://www.nationalarchives.gov.uk/doc/open-government-licence/version/3/).
