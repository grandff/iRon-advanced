<div align="center">

<h1>iRon-Advanced</h1>
Leichte und leistungsstarke erweiterte Overlays für iRacing<br><br>

[**English**](../../README.md) | [**English (UK)**](../en-GB/README.md) | [**한국어**](../ko/README.md) | [**日本語**](../ja/README.md) | [**简体中文**](../zh/README.md) | **Deutsch** | [**Français**](../fr/README.md) | [**Italiano**](../it/README.md) | [**Português**](../pt/README.md) | [**Русский**](../ru/README.md)

</div>

---

Dieses Projekt ist eine stark erweiterte Version des ursprünglichen `iRon`-Overlays. Unter Beibehaltung der Kernphilosophie des Originalprojekts – extrem leichtgewichtig zu sein und ohne externe Laufzeitabhängigkeiten auszukommen – fügt es leistungsstarke, unverzichtbare Funktionen für iRacing-Spieler hinzu.

> **Basierend auf dem originalen iRon-Projekt (von lespalt):** [https://github.com/lespalt/iRon](https://github.com/lespalt/iRon)

<br>

### ✨ Was ist anders als beim originalen iRon?

**1. 💾 Automatisches Speichern des globalen Layouts**
* Beim originalen iRon wurden die Fensterpositionen bei jedem Neustart der Anwendung zurückgesetzt.
* **iRon-Advanced** speichert Ihr Bildschirmkoordinaten-Layout, die Fenstergrößen und die Ein-/Ausschaltzustände der Overlays im Windows-Pfad `Documents\iRon_Advanced\config.json`. Beim erneuten Starten wird Ihr letztes Layout perfekt wiederhergestellt!

**2. 📊 Verbesserte Tabellen & Telemetrie**
* Ein **dreistelliges Länderkürzel** (z. B. `[KOR]`, `[USA]`) wurde direkt vor den Fahrernamen im Standings-Overlay hinzugefügt, um die Herkunft der Konkurrenten schnell zu erkennen.
* Überflüssige Fahrzeugmodell-Texte wurden bereinigt, um ein äußerst professionelles, aufgeräumtes Erscheinungsbild zu gewährleisten.
* Die **erwarteten iRating-Änderungen in Echtzeit (+/-)** basierend auf dem Elo-Bewertungssystem wurden direkt im Relative-Overlay hinzugefügt.

**3. 🚀 Brandneue Overlays hinzugefügt:**
* **Visueller Spotter links & rechts (NEU):** Visuelle Warnungen für den toten Winkel. Die linke und rechte Anzeige sind getrennt und können unabhängig voneinander verschoben und in der Größe angepasst werden! Sie blinken **Gelb** oder **Rot**, basierend auf dem tatsächlichen Abstand der Autos neben Ihnen, und bleiben bei freier Bahn zu 100 % transparent.
* **Radar (Abstandsradar):** Ein Abstandsradar aus der Vogelperspektive, das vollständig transparent bleibt, wenn sich keine Autos in der Nähe befinden, um das Sichtfeld nicht zu stören.
* **Vorfallswarnung (Smart Incident):** Ein blinkendes Warnbanner und die Anzeige der genauen Entfernung bei Unfällen innerhalb von 150 m vor Ihnen.
* **Verkehr (Multiklassen-Verkehr):** Dynamische blaue Flagge auf der Benutzeroberfläche, basierend auf Rundenzeit-Unterschieden, wenn sich schnellere Klassen von hinten nähern.

---

# Inhalt

- [Download](#-download)
- [Overlays](#-overlays)
  - [*Relative*](#relative)
  - [*DDU*](#ddu)
  - [*Inputs*](#inputs)
  - [*Standings*](#standings)
  - [*Cover*](#cover)
  - [*Spotter (NEU)*](#spotter-neu)
  - [*Radar (NEU)*](#radar-neu)
  - [*Vorfallswarnung (NEU)*](#vorfallswarnung-neu)
  - [*Mehrklassen-Verkehr (NEU)*](#mehrklassen-verkehr-neu)
  - [*Head-to-Head (NEU)*](#head-to-head-neu)
  - [*Bomb Avenge (NEU)*](#bomb-avenge-neu)
- [Installation & Ausführung](#-installation--ausführung)
- [Konfiguration](#️-konfiguration)
- [Kompilieren aus dem Quellcode](#️-kompilieren-aus-dem-quellcode)
- [Abhängigkeiten](#-abhängigkeiten)

---

## 📥 Download

Die neueste kompilierte Version (Binary) finden Sie [hier](https://github.com/grandff/iRon-advanced/releases/latest).

<br>

## 📺 Overlays

### *Relative*
Ähnlich wie die *Relative*-Box in iRacing, jedoch mit zusätzlichen Informationen wie Lizenz, iRating, gefahrenen Runden seit dem letzten Boxenstopp und **erwarteten iRating-Änderungen in Echtzeit** für Teilnehmer der aktuellen Klasse. Sie können auch Ihre Freunde hervorheben, indem Sie deren Namen zu einer Buddy-Liste hinzufügen.
Am oberen Rand befindet sich eine optionale Minimap. Sie kann entweder im relativen Modus (das eigene Auto fixiert in der Mitte) oder im absoluten Modus (Start-/Ziellinie fixiert in der Mitte) betrieben werden.

![relative](https://github.com/lespalt/iRon/blob/main/relative.png?raw=true)

### *DDU*
Ein Dashboard (DDU), das wichtige Informationen bündelt, für die Sie sonst durch verschiedene Boxen in iRacing blättern müssten.
Der Kraftstoffrechner zeigt die geschätzten verbleibenden Runden, die verbleibende Kraftstoffmenge, den geschätzten Kraftstoffverbrauch pro Runde, den geschätzten _zusätzlichen_ Kraftstoffbedarf zum Beenden des Rennens und die Kraftstoffmenge, die beim nächsten Boxenstopp nachgetankt werden soll.

![ddu](https://github.com/lespalt/iRon/blob/main/ddu.png?raw=true)

### *Inputs*
Zeigt Gas, Bremse und Lenkung in einem bewegten Diagramm an. Äußerst nützlich, um konstantes Trail-Braking zu trainieren.

![inputs](https://github.com/lespalt/iRon/blob/main/inputs.png?raw=true)

### *Standings*
Zeigt den Gesamtstand des Feldes, einschließlich Sicherheitsbewertung (Safety Rating), iRating, Anzahl der Runden seit dem letzten Boxenstopp („Pit Age“) und einem übersichtlichen **Länderkürzel** links neben dem Namen jedes Fahrers. Hauptsächlich nützlich während Gelbphasen (Caution) oder vor dem Rennen, um ein Gefühl für das Niveau der Konkurrenz zu bekommen.

![standings](https://github.com/lespalt/iRon/blob/main/standings.png?raw=true)

### *Cover*
Hier verzichten wir auf einen Screenshot. Es handelt sich um ein einfaches, leeres, schwarzes Rechteck, das nützlich ist, um ablenkende Dashboards im Spiel abzudecken, wie beispielsweise das in der Next-Gen-NASCAR.

### *Spotter (NEU)*
Ein visueller Spotter, der farbige Rechtecke auf der linken und rechten Seite Ihres Bildschirms zeichnet, wenn sich ein Auto in Ihrem toten Winkel befindet.
* Das linke und rechte Panel sind **unabhängig voneinander konfigurierbar, verschiebbar und in der Größe anpassbar**.
* Zeigt einen **gelben** Warnbalken für Fahrzeuge in der Nähe an und wechselt zu einem leuchtend **roten** Alarmbalken, wenn ein Auto gefährlich nahe kommt (<= 2,2 m).
* Standardmäßig vollständig transparent; wird nur dann halbtransparent, wenn die Layout-Bearbeitung aktiv ist.

![spotter](../../screenshot_placeholder_spotter.png)

### *Radar (NEU)*
Ein Abstandsradar, das eine Ansicht der Fahrzeuge um Sie herum aus der Vogelperspektive darstellt.
* Bleibt standardmäßig zu 100 % transparent, wenn keine Autos in der Nähe sind, um eine klare Sicht auf den Bildschirm zu gewährleisten.
* Aktiviert sich und rendert eine Draufsicht der umliegenden Fahrzeuge, sobald diese in den Nahbereich einfahren.

![radar](../../screenshot_placeholder_radar.png)

### *Incident Warning (NEU)*
Ein intelligentes Warnsystem für Vorfälle. Anstatt nur ein generisches Banner für eine gelbe Flagge anzuzeigen, berechnet dieses Overlay, ob ein Auto vor Ihnen während einer Gelbphase von der Strecke abgekommen ist. Wenn ein verunfalltes oder von der Strecke abgekommenes Fahrzeug innerhalb von 150 Metern vor Ihnen erkannt wird, wird ein auffälliges, blinkendes Warnbanner gerendert, das die Entfernung zum Unfall angibt.

![incident](../../screenshot_placeholder_incident.png)

### *Multiclass Traffic (NEU)*
Ein dynamisches Warnsystem mit blauer Flagge für Rennen mit mehreren Klassen. Es vergleicht die geschätzten Rundenzeiten der umliegenden Autos mit Ihren. Wenn sich ein Auto einer schnelleren Klasse innerhalb eines kritischen Zeitfensters von hinten nähert, wird eine progressiv leuchtende Benutzeroberfläche ausgelöst, die intensiv blau/weiß blinkt, um Sie zu warnen, ohne Ihre Sicht zu blockieren.

![traffic](../../screenshot_placeholder_traffic.png)

### *Head-to-Head (NEU)*
Zeigt Echtzeit-Vergleiche mit den Fahrern direkt vor und hinter Ihnen. Zeigt Position, Name, Abstand, Rundenzeiten und Sektorzeiten (S1, S2, S3) der zuletzt absolvierten Runde.
* Äußerst nützlich, um zu überwachen, wo Sie im Vergleich zu Ihren direkten Konkurrenten Zeit verlieren oder gewinnen.
* Bietet eine auffällige Hervorhebung der eigenen Zeile.

### *Bomb Avenge (NEU)*
Zeigt Echtzeit-Tracking-Informationen des Fahrers an, der Sie gerammt hat.
* Wird automatisch ausgelöst, wenn eine Kollision Ihre Vorfallspunkte (Incidents) erhöht.
* Zeigt den Namen des Verursachers, seine aktuelle Rennposition und den Echtzeit-Abstand in Metern.
* Im *Relative*-Overlay pulsiert die Zeile des verursachenden Fahrers rot, der Hintergrund seiner Startnummer wird rot und vor seinem Namen wird das Präfix `[BOMB]` angezeigt.

---

## 🚀 Installation & Ausführung

Die App erfordert keine Installation. Kopieren Sie einfach die ausführbare Datei (`.exe`) in einen Ordner Ihrer Wahl.

Um sie zu verwenden, doppelklicken Sie einfach auf die ausführbare Datei. Dabei ist es egal, ob Sie dies vor oder nach dem Start von iRacing tun. Es öffnet sich ein Konsolenfenster, das anzeigt, dass iRon läuft. Sobald Sie in iRacing im Auto sitzen, sollten die Overlays erscheinen. Wir empfehlen dringend, iRacing im Modus **Rahmenloses Fenster** (Borderless Window) auszuführen.

---

## ⚙️ Konfiguration

Um die Overlays zu platzieren und in der Größe anzupassen, drücken Sie **ALT-J**. Dadurch wird ein Layout-Bearbeitungsmodus aktiviert, in dem Sie die Overlays mit der Maus verschieben und durch Ziehen an der unteren rechten Ecke vergrößern oder verkleinern können. Drücken Sie erneut **ALT-J**, um in den normalen Modus zurückzukehren.

Overlays können während des Betriebs über die beim Start angezeigten Hotkeys ein- und ausgeschaltet werden. Alle Hotkeys sind konfigurierbar.

Ihr Layout und Ihre Einstellungen werden automatisch und global unter folgendem Pfad gespeichert:
`Documents\iRon_Advanced\config.json`

### Standard-Hotkeys:
* **ALT-J**: Verschiebungs- und Größenänderungsmodus (Layout-Bearbeitung)
* **Ctrl-Space**: Tabelle (Standings) ein-/ausblenden
* **Ctrl-1**: DDU (Dashboard) ein-/ausblenden
* **Ctrl-2**: Eingaben (Pedal-Diagramm) ein-/ausblenden
* **Ctrl-3**: Relative-Box ein-/ausblenden
* **Ctrl-4**: Abdeckungs-Box (Cover Box) ein-/ausblenden
* **Ctrl-5**: Spotter ein-/ausblenden (links/rechts synchronisiert)
* **Ctrl-6**: Abstandsradar ein-/ausblenden
* **Ctrl-7**: Vorfallswarnung ein-/ausblenden
* **Ctrl-8**: Reifen-Dashboard ein-/ausblenden
* **Ctrl-9**: Head-to-Head-Widget ein-/ausblenden
* **Ctrl-0**: Bomb-Avenge-Widget ein-/ausblenden
* **Ctrl-Shift-D**: Globalen Anzeigemodus umschalten (Nur Rennen / Nur Replay / Beides)

---

## 🛠️ Kompilieren aus dem Quellcode

Diese App wurde mit Visual Studio 2022 entwickelt. Die kostenlose Version (Community) sollte ausreichen, obwohl wir dies nicht überprüft haben. Die Projekt- und Projektmappendateien (Solution Files) sollten direkt funktionieren. Je nach Ihrer Visual Studio-Konfiguration müssen Sie möglicherweise zusätzliche Voraussetzungen (statische Bibliotheken) installieren, die für die Erstellung von DirectX-Anwendungen erforderlich sind.

---

## 📦 Abhängigkeiten

Es gibt keine Laufzeitabhängigkeiten außer Standard-Windows-Komponenten wie DirectX. Diese sollten bereits auf den meisten, wenn nicht auf allen Systemen vorhanden sein, auf denen iRacing ausgeführt werden kann. Die Build-Abhängigkeiten (insbesondere das iRacing SDK und picojson) sind auf ein Minimum reduziert und im Repository enthalten.
