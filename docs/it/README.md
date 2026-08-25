<div align="center">

<h1>iRon-Advanced</h1>
Overlay estesi leggeri e potenti per iRacing<br><br>

[**English**](../../README.md) | [**English (UK)**](../en-GB/README.md) | [**한국어**](../ko/README.md) | [**日本語**](../ja/README.md) | [**简体中文**](../zh/README.md) | [**Deutsch**](../de/README.md) | [**Français**](../fr/README.md) | **Italiano** | [**Português**](../pt/README.md) | [**Русский**](../ru/README.md)

</div>

---

Questo progetto è una versione notevolmente ampliata dell'overlay `iRon` originale. Pur preservando la filosofia di base del progetto originale — essere estremamente leggero e privo di dipendenze esterne a runtime — aggiunge funzionalità potenti e indispensabili per i giocatori di iRacing.

> **Basato sul progetto iRon originale (di lespalt):** [https://github.com/lespalt/iRon](https://github.com/lespalt/iRon)

<br>

### ✨ Cosa c'è di diverso rispetto all'iRon originale?

**1. 💾 Salvataggio automatico del layout globale**
* L'iRon originale soffriva del ripristino delle posizioni delle finestre a ogni riavvio dell'applicazione.
* **iRon-Advanced** salva il layout delle coordinate dello schermo, le dimensioni delle finestre e gli stati di attivazione degli overlay (On/Off) nel percorso di Windows `Documents\iRon_Advanced\config.json`. Al riavvio successivo, l'ultimo layout viene ripristinato perfettamente!

**2. 📊 Classifiche e telemetria avanzate**
* Aggiunto un **badge con la sigla del paese a 3 lettere** (es. `[KOR]`, `[USA]`) subito prima dei nomi dei piloti nell'overlay Standings, per riconoscere rapidamente la provenienza degli avversari.
* Puliti i testi ridondanti dei modelli di auto per un look estremamente professionale e ordinato.
* Aggiunte le **variazioni dell'iRating previsto in tempo reale (+/-)** basate sul sistema di punteggio Elo direttamente nell'overlay Relative.

**3. 🚀 Nuovissimi overlay aggiunti:**
* **Left & Right Visual Spotter (NUOVO):** Avvisi visivi per i punti ciechi. I pannelli sinistro e destro sono separati e possono essere trascinati/ridimensionati in modo indipendente! Lampeggiano in **Giallo** o **Rosso** in base alla distanza effettiva di prossimità delle auto al tuo fianco, e rimangono trasparenti al 100% quando la pista è libera.
* **Radar (Radar di prossimità):** Un radar di prossimità con vista dall'alto che rimane completamente trasparente quando non ci sono auto nelle vicinanze per evitare di ostruire la visuale.
* **Incident Warning (Incidente smart):** Banner di avviso lampeggiante e visualizzazione della distanza esatta per gli incidenti entro 150 m davanti a te.
* **Traffic (Traffico multiclasse):** UI dinamica per la bandiera blu basata sulle differenze di passo sul tempo sul giro quando le classi più veloci si avvicinano da dietro.

---

# Contenuti

- [Dove scaricare](#-dove-scaricare)
- [Overlay](#-overlay)
  - [*Relative*](#relative)
  - [*DDU*](#ddu)
  - [*Inputs*](#inputs)
  - [*Standings*](#standings)
  - [*Cover*](#cover)
  - [*Spotter (NUOVO)*](#spotter-nuovo)
  - [*Radar (NUOVO)*](#radar-nuovo)
  - [*Incident Warning (NUOVO)*](#incident-warning-nuovo)
  - [*Multiclass Traffic (NUOVO)*](#multiclass-traffic-nuovo)
  - [*Head to Head (NUOVO)*](#head-to-head-nuovo)
  - [*Bomb Avenge (NUOVO)*](#bomb-avenge-nuovo)
- [Installazione e avvio](#-installazione-e-avvio)
- [Configurazione](#️-configurazione)
- [Compilazione da codice sorgente](#️-compilazione-da-codice-sorgente)
- [Dipendenze](#-dipendenze)

---

## 📥 Dove scaricare

L'ultima versione binaria rilasciata è disponibile [qui](https://github.com/grandff/iRon-advanced/releases/latest).

<br>

## 📺 Overlay

### *Relative*
Come il box *Relative* in iRacing, ma con informazioni aggiuntive come licenza, iRating, giri percorsi dall'ultima sosta ai box e **variazioni dell'iRating previsto in tempo reale** per i partecipanti alla classe corrente. Puoi anche evidenziare i tuoi amici aggiungendo i loro nomi a una lista amici (buddy list).
In alto c'è una minimappa opzionale. Può essere impostata in modalità relativa (la propria auto è fissa al centro) o in modalità assoluta (la linea di partenza/arrivo è fissa al centro).

![relative](https://github.com/lespalt/iRon/blob/main/relative.png?raw=true)

### *DDU*
Una dashboard che concentra informazioni importanti per le quali altrimenti dovresti scorrere vari box in iRacing.
Il calcolatore del carburante mostra i giri stimati rimanenti, la quantità di carburante rimasta, il carburante stimato utilizzato per giro, il carburante _aggiuntivo_ stimato richiesto per terminare la gara e la quantità di carburante programmata per essere aggiunta alla sosta ai box successiva.

![ddu](https://github.com/lespalt/iRon/blob/main/ddu.png?raw=true)

### *Inputs*
Mostra acceleratore/freno/sterzo in un grafico in movimento. Estremamente utile per esercitarsi in un trail braking costante.

![inputs](https://github.com/lespalt/iRon/blob/main/inputs.png?raw=true)

### *Standings*
Mostra la classifica dell'intero schieramento, inclusi safety rating, iRating, numero di giri dall'ultima sosta ai box ("pit age") e un pulito **badge con la sigla del paese** a sinistra del nome di ogni pilota. Utile soprattutto durante i periodi di caution o prima della gara per farsi un'idea del livello di competitività.

![standings](https://github.com/lespalt/iRon/blob/main/standings.png?raw=true)

### *Cover*
Saltiamo lo screenshot per questo overlay. Si tratta di un semplice rettangolo nero vuoto, utile per coprire le dashboard di gioco che distraggono, come quella della NASCAR Next Gen.

### *Spotter (NUOVO)*
Uno spotter visivo che disegna rettangoli colorati sul lato sinistro e destro dello schermo quando un'auto si trova nel tuo angolo cieco.
* I pannelli sinistro e destro sono **configurabili, mobili e ridimensionabili in modo indipendente**.
* Mostra una barra di avviso **Gialla** per le auto vicine e passa a una barra di allerta **Rossa** brillante se un'auto si avvicina pericolosamente (<= 2,2 m).
* Completamente trasparente per impostazione predefinita, diventa semitrasparente solo quando è attiva la modifica del layout.

![spotter](../../screenshot_placeholder_spotter.png)

### *Radar (NUOVO)*
Un radar di prossimità che mostra una vista dall'alto delle auto intorno a te.
* Rimane trasparente al 100% per impostazione predefinita quando non ci sono auto nelle vicinanze per mantenere lo schermo pulito.
* Si attiva e mostra una vista dall'alto dei veicoli circostanti una volta che questi entrano a distanza ravvicinata.

![radar](../../screenshot_placeholder_radar.png)

### *Incident Warning (NUOVO)*
Un sistema intelligente di avviso di incidente. Invece di mostrare solo un banner generico di bandiera gialla, questo overlay calcola se un'auto davanti a te è andata fuori pista durante una caution. Se viene rilevata un'auto incidentata o fuori pista entro 150 metri davanti a te, mostra un vistoso banner di avviso lampeggiante che specifica la distanza dall'incidente.

![incident](../../screenshot_placeholder_incident.png)

### *Multiclass Traffic (NUOVO)*
Un sistema dinamico di avviso di bandiera blu per le corse multiclasse. Confronta i tempi sul giro stimati delle auto circostanti con i tuoi. Se un'auto di classe più veloce si avvicina da dietro entro un intervallo di tempo critico, attiva un'interfaccia con un alone luminoso progressivo che lampeggia intensamente in blu/bianco per avvisarti senza ostruire la visuale.

![traffic](../../screenshot_placeholder_traffic.png)

### *Head to Head (NUOVO)*
Mostra confronti in tempo reale con i piloti immediatamente davanti e dietro di te. Mostra la posizione, il nome, il distacco, i tempi sul giro e i tempi dei settori (S1, S2, S3) dell'ultimo giro completato.
* Estremamente utile per monitorare dove stai perdendo o guadagnando tempo rispetto ai tuoi diretti rivali.
* Presenta una vistosa fascia evidenziata per la tua riga.

### *Bomb Avenge (NUOVO)*
Mostra informazioni di tracciamento in tempo reale sul pilota che ti ha colpito.
* Si attiva automaticamente quando una collisione aumenta il tuo conteggio degli incidenti.
* Mostra il nome dell'autore dell'infrazione, la sua attuale posizione in gara e il distacco in metri in tempo reale.
* Nell'overlay *Relative*, la riga del pilota responsabile lampeggerà in rosso, lo sfondo del suo numero di gara diventerà rosso e il suo nome sarà preceduto dal prefisso `[BOMB]`.

---

## 🚀 Installazione e avvio

L'applicazione non richiede installazione. Basta copiare l'eseguibile (`.exe`) in una cartella a tua scelta.

Per utilizzarla, fai semplicemente doppio clic sull'eseguibile. Non importa se lo fai prima o dopo aver avviato iRacing. Apparirà una finestra della console per indicare che iRon è in esecuzione. Una volta salito in macchina su iRacing, gli overlay dovrebbero apparire. Consigliamo vivamente di eseguire iRacing in modalità **Finestra senza bordi** (Borderless Window).

---

## ⚙️ Configurazione

Per posizionare e ridimensionare gli overlay, premi **ALT-J**. In questo modo entrerai in una modalità di modifica del layout in cui potrai spostare gli overlay con il mouse e ridimensionarli trascinando l'angolo in basso a destra. Premi nuovamente **ALT-J** per tornare alla modalità normale.

Gli overlay possono essere attivati e disattivati durante l'esecuzione utilizzando i tasti di scelta rapida (hotkey) mostrati all'avvio. Tutti i tasti di scelta rapida sono configurabili.

Il layout e le impostazioni vengono salvati automaticamente e globalmente in:
`Documents\iRon_Advanced\config.json`

### Mappa dei tasti di scelta rapida predefiniti:
* **ALT-J**: Modalità sposta e ridimensiona (Modifica del layout)
* **Ctrl-Space**: Attiva/disattiva classifica (Standings)
* **Ctrl-1**: Attiva/disattiva DDU (Dashboard)
* **Ctrl-2**: Attiva/disattiva input (Grafico dei pedali)
* **Ctrl-3**: Attiva/disattiva Relative Box
* **Ctrl-4**: Attiva/disattiva Cover Box
* **Ctrl-5**: Attiva/disattiva Spotter (destro/sinistro sincronizzati)
* **Ctrl-6**: Attiva/disattiva Radar di prossimità
* **Ctrl-7**: Attiva/disattiva Avviso incidenti
* **Ctrl-8**: Attiva/disattiva Dashboard degli pneumatici (Tire Dash)
* **Ctrl-9**: Attiva/disattiva Widget Head to Head
* **Ctrl-0**: Attiva/disattiva Widget Bomb Avenge
* **Ctrl-Shift-D**: Cambia modalità di visualizzazione globale (Solo gara / Solo replay / Entrambi)

---

## 🛠️ Compilazione da codice sorgente

Questa applicazione è compilata con Visual Studio 2022. La versione gratuita dovrebbe essere sufficiente, anche se non l'abbiamo verificato. I file di progetto/soluzione dovrebbero funzionare da subito. A seconda della configurazione di Visual Studio, potrebbe essere necessario installare prerequisiti aggiuntivi (librerie statiche) richiesti per compilare applicazioni DirectX.

---

## 📦 Dipendenze

Non ci sono dipendenze a runtime oltre ai componenti standard di Windows come DirectX. Questi dovrebbero essere già presenti sulla maggior parte, se non su tutti, i sistemi in grado di eseguire iRacing. Le dipendenze per la compilazione (in particolare l'SDK di iRacing e picojson) sono ridotte al minimo e sono incluse nel repository.
