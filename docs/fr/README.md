<div align="center">

<h1>iRon-Advanced</h1>
Overlays légers, puissants et enrichis pour iRacing<br><br>

[**English**](../../README.md) | [**English (UK)**](../en-GB/README.md) | [**한국어**](../ko/README.md) | [**日本語**](../ja/README.md) | [**简体中文**](../zh/README.md) | [**Deutsch**](../de/README.md) | **Français** | [**Italiano**](../it/README.md) | [**Português**](../pt/README.md) | [**Русский**](../ru/README.md)

</div>

---

Ce projet est une version largement enrichie de l'overlay original `iRon`. Tout en préservant la philosophie fondamentale du projet d'origine — à savoir rester extrêmement léger et sans dépendances d'exécution externes —, il ajoute des fonctionnalités puissantes et indispensables pour les joueurs d'iRacing.

> **Basé sur le projet iRon original (par lespalt) :** [https://github.com/lespalt/iRon](https://github.com/lespalt/iRon)

<br>

### ✨ Qu'est-ce qui change par rapport à l'iRon original ?

**1. 💾 Sauvegarde automatique de la disposition globale (Layout)**
* Avec l'iRon original, la position des fenêtres se réinitialisait à chaque redémarrage de l'application.
* **iRon-Advanced** sauvegarde les coordonnées de disposition à l'écran, la taille des fenêtres et l'état d'activation des overlays (Activé/Désactivé) dans le dossier Windows `Documents\iRon_Advanced\config.json`. Lors du redémarrage, votre dernière disposition est parfaitement restaurée !

**2. 📊 Classements et télémétrie améliorés**
* Ajout d'un **badge à 3 lettres pour les initiales de pays** (ex. : `[KOR]`, `[USA]`) juste avant le nom des pilotes dans l'overlay Standings, afin d'identifier rapidement l'origine de vos concurrents.
* Nettoyage des textes redondants sur les modèles de voitures pour un rendu extrêmement professionnel et épuré.
* Ajout direct dans l'overlay Relative de la **variation estimée de l'iRating en temps réel (+/-)**, calculée selon le système de classement Elo.

**3. 🚀 Nouveaux overlays ajoutés :**
* **Spotter visuel gauche et droit (NOUVEAU) :** Alertes visuelles pour les angles morts. Les panneaux gauche et droit sont séparés et peuvent être déplacés/redimensionnés indépendamment ! Ils clignotent en **Jaune** ou en **Rouge** selon la distance réelle des voitures à vos côtés, et restent 100 % transparents lorsque la voie est libre.
* **Radar (Radar de proximité) :** Un radar de proximité en vue de dessus qui reste complètement transparent lorsqu'aucune voiture n'est à proximité afin de ne pas encombrer votre champ de vision.
* **Alerte d'incident (Smart Incident) :** Bannière d'avertissement clignotante et affichage de la distance exacte pour les accidents survenant dans un rayon de 150 m devant vous.
* **Trafic (Multiclass Traffic) :** Interface dynamique de drapeau bleu basée sur les différences de rythme au tour lorsque des catégories plus rapides approchent par l'arrière.

---

# Sommaire

- [Où télécharger](#-où-télécharger)
- [Overlays](#-overlays)
  - [*Relative*](#relative)
  - [*DDU*](#ddu)
  - [*Inputs*](#inputs)
  - [*Standings*](#standings)
  - [*Cover*](#cover)
  - [*Spotter (NOUVEAU)*](#spotter-nouveau)
  - [*Radar (NOUVEAU)*](#radar-nouveau)
  - [*Incident Warning (NOUVEAU)*](#incident-warning-nouveau)
  - [*Multiclass Traffic (NOUVEAU)*](#multiclass-traffic-nouveau)
  - [*Head to Head (NOUVEAU)*](#head-to-head-nouveau)
  - [*Bomb Avenge (NOUVEAU)*](#bomb-avenge-nouveau)
- [Installation et exécution](#-installation-et-exécution)
- [Configuration](#️-configuration)
- [Compilation depuis les sources](#️-compilation-depuis-les-sources)
- [Dépendances](#-dépendances)

---

## 📥 Où télécharger

La dernière version binaire compilée est disponible [ici](https://github.com/grandff/iRon-advanced/releases/latest).

<br>

## 📺 Overlays

### *Relative*
Semblable à l'encadré *Relative* d'iRacing, mais avec des informations supplémentaires telles que la licence, l'iRating, le nombre de tours effectués depuis le dernier arrêt aux stands, et les **variations estimées d'iRating en temps réel** pour les participants de la catégorie actuelle. Vous pouvez également mettre en évidence vos amis en ajoutant leurs noms à une liste de favoris (buddy list).
Une mini-carte optionnelle est affichée en haut. Elle peut être configurée soit en mode relatif (votre voiture reste fixée au centre), soit en mode absolu (la ligne de départ/arrivée reste fixée au centre).

![relative](https://github.com/lespalt/iRon/blob/main/relative.png?raw=true)

### *DDU*
Un tableau de bord (Dashboard) qui regroupe les informations importantes pour lesquelles vous devriez autrement faire défiler différents encadrés dans iRacing.
Le calculateur de carburant affiche l'estimation des tours restants, la quantité de carburant restante, la consommation de carburant estimée par tour, le carburant _supplémentaire_ estimé nécessaire pour terminer la course, ainsi que la quantité de carburant prévue pour être ajoutée lors du prochain arrêt aux stands.

![ddu](https://github.com/lespalt/iRon/blob/main/ddu.png?raw=true)

### *Inputs*
Affiche l'accélérateur/frein/direction sous forme de graphique dynamique. Extrêmement utile pour s'entraîner à un trail braking régulier.

![inputs](https://github.com/lespalt/iRon/blob/main/inputs.png?raw=true)

### *Standings*
Affiche le classement de l'ensemble des pilotes, y compris le safety rating, l'iRating, le nombre de tours depuis le dernier arrêt aux stands ("pit age"), et un **badge d'initiales de pays** épuré à gauche du nom de chaque pilote. Principalement utile pendant les périodes de neutralisation (safety car) ou avant la course pour évaluer le niveau de la compétition.

![standings](https://github.com/lespalt/iRon/blob/main/standings.png?raw=true)

### *Cover*
Nous faisons l'impasse sur la capture d'écran pour celui-ci. Il s'agit d'un simple rectangle noir vide, utile pour masquer les tableaux de bord en jeu distrayants, comme celui de la NASCAR Next Gen.

### *Spotter (NOUVEAU)*
Un spotter visuel qui dessine des rectangles colorés sur les côtés gauche et droit de votre écran lorsqu'une voiture se trouve dans votre angle mort.
* Les panneaux gauche et droit sont **configurables, mobiles et redimensionnables de manière indépendante**.
* Affiche une barre d'avertissement **Jaune** pour les voitures proches, qui devient une barre d'alerte **Rouge** vif si une voiture s'approche dangereusement (<= 2,2 m).
* Complètement transparent par défaut, devenant semi-transparent uniquement lorsque le mode d'édition de la disposition est activé.

![spotter](../../screenshot_placeholder_spotter.png)

### *Radar (NOUVEAU)*
Un radar de proximité affichant une vue de dessus des voitures autour de vous.
* Reste transparent à 100 % par défaut lorsqu'aucune voiture n'est à proximité afin de préserver la clarté de l'écran.
* S'active et affiche une vue de dessus des véhicules environnants dès qu'ils entrent dans un rayon proche.

![radar](../../screenshot_placeholder_radar.png)

### *Incident Warning (NOUVEAU)*
Un système intelligent d'alerte d'incident. Au lieu d'afficher simplement une bannière générique de drapeau jaune, cet overlay calcule si une voiture devant vous est sortie de la piste lors d'une neutralisation. Si une voiture accidentée ou hors piste est détectée dans un rayon de 150 mètres devant vous, l'overlay affiche une bannière d'avertissement clignotante bien visible indiquant la distance de l'accident.

![incident](../../screenshot_placeholder_incident.png)

### *Multiclass Traffic (NOUVEAU)*
Un système dynamique d'alerte de drapeau bleu pour les courses multicatégories. Il compare les temps au tour estimés des voitures environnantes aux vôtres. Si une voiture d'une catégorie plus rapide approche par l'arrière sous un certain écart de temps critique, cela déclenche un halo lumineux progressif qui clignote intensément en bleu et blanc pour vous avertir sans masquer votre champ de vision.

![traffic](../../screenshot_placeholder_traffic.png)

### *Head to Head (NOUVEAU)*
Affiche des comparaisons en temps réel avec les pilotes immédiatement devant et derrière vous. Affiche la position, le nom, l'écart, les temps au tour et les temps de secteur (S1, S2, S3) du dernier tour complété.
* Très utile pour surveiller les secteurs où vous perdez ou gagnez du temps par rapport à vos rivaux directs.
* Comporte une bande de surbrillance bien visible pour votre propre ligne.

### *Bomb Avenge (NOUVEAU)*
Affiche des informations de suivi en temps réel du pilote qui vous a percuté.
* Se déclenche automatiquement lorsqu'une collision augmente votre nombre d'incidents.
* Affiche le nom du coupable, sa position actuelle en course et l'écart de distance en temps réel en mètres.
* Dans l'overlay *Relative*, la ligne du pilote fautif clignote en rouge, l'arrière-plan de son numéro de voiture devient rouge et son nom est précédé du préfixe `[BOMB]`.

---

## 🚀 Installation et exécution

L'application ne nécessite pas d'installation. Copiez simplement l'exécutable (`.exe`) dans le dossier de votre choix.

Pour l'utiliser, double-cliquez simplement sur l'exécutable. Peu importe que vous le fassiez avant ou après le lancement d'iRacing. Une fenêtre de console apparaîtra, indiquant que iRon est en cours d'exécution. Une fois que vous êtes dans la voiture dans iRacing, les overlays devraient s'afficher. Nous vous recommandons vivement de lancer iRacing en mode **Fenêtré sans bordure** (Borderless Window).

---

## ⚙️ Configuration

Pour positionner et redimensionner les overlays, appuyez sur **ALT-J**. Vous entrerez ainsi dans le mode d'édition de la disposition où vous pourrez déplacer les overlays avec la souris et les redimensionner en faisant glisser leur coin inférieur droit. Appuyez de nouveau sur **ALT-J** pour revenir au mode normal.

Les overlays peuvent être activés ou désactivés en cours d'exécution à l'aide des raccourcis clavier affichés au démarrage. Tous les raccourcis sont configurables.

Votre disposition et vos paramètres sont automatiquement et globalement sauvegardés dans :
`Documents\iRon_Advanced\config.json`

### Raccourcis clavier par défaut :
* **ALT-J** : Mode Déplacement et Redimensionnement (Édition de disposition)
* **Ctrl-Space** : Activer/Désactiver le classement (Standings)
* **Ctrl-1** : Activer/Désactiver le DDU (Tableau de bord)
* **Ctrl-2** : Activer/Désactiver les entrées (Graphique des pédales)
* **Ctrl-3** : Activer/Désactiver l'encadré Relative
* **Ctrl-4** : Activer/Désactiver l'encadré de masquage (Cover)
* **Ctrl-5** : Activer/Désactiver les Spotters (Gauche/Droite synchronisés)
* **Ctrl-6** : Activer/Désactiver le radar de proximité
* **Ctrl-7** : Activer/Désactiver l'alerte d'incident
* **Ctrl-8** : Activer/Désactiver le tableau de bord des pneus (Tire Dash)
* **Ctrl-9** : Activer/Désactiver le widget Head to Head
* **Ctrl-0** : Activer/Désactiver le widget Bomb Avenge
* **Ctrl-Shift-D** : Basculer entre les modes d'affichage globaux (Course uniquement / Replay uniquement / Les deux)

---

## 🛠️ Compilation depuis les sources

Cette application est développée avec Visual Studio 2022. La version gratuite (Community) devrait suffire, bien que nous ne l'ayons pas vérifié. Les fichiers de projet/solution devraient fonctionner directement. Selon votre configuration de Visual Studio, il se peut que vous deviez installer des prérequis supplémentaires (bibliothèques statiques) nécessaires à la compilation d'applications DirectX.

---

## 📦 Dépendances

Il n'y a aucune dépendance d'exécution autre que les composants standard de Windows tels que DirectX. Ceux-ci devraient déjà être présents sur la plupart, voire la totalité, des systèmes capables de faire tourner iRacing. Les dépendances de compilation (notamment l'iRacing SDK et picojson) sont réduites au minimum et sont incluses dans le dépôt.
