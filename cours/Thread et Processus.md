<h1 align=center> Thread et Processus </h1>

## 1) Thread :
<hr><hr>
    
## 🔹 Qu'est-ce qu'un thread sous Linux ?

Un **thread** est une petite unité d'exécution qui fait partie d'un processus.

➡ **Sous Linux, un thread fonctionne à l'intérieur d'un processus** et peut exécuter une tâche en parallèle avec d'autres threads du même processus.

---

### 📌 Plusieurs threads dans un même processus ?

Quand un programme (**processus**) démarre, il a **au moins un thread principal**. Mais il peut en créer plusieurs autres pour exécuter des tâches simultanément.

➡ **Exemple** :  
Imagine que tu ouvres un **navigateur web** (*Firefox, Chrome, etc.*).  
Ce navigateur est **un seul processus**, mais il utilise plusieurs threads pour :  

✅ **Afficher l'interface utilisateur**  
✅ **Télécharger des images en arrière-plan**  
✅ **Exécuter du JavaScript sur la page**  
✅ **Lire des vidéos**  

Tous ces **threads travaillent ensemble en partageant la mémoire** du navigateur ! 🚀  

---

### 🔹 Que partagent les threads d'un même processus ?  

#### ✅ **La mémoire** :
Tous les threads peuvent accéder aux **mêmes variables globales** et aux **données du programme**.

> **Exemple** :  
> Un éditeur de texte (*comme Word*) peut avoir un **thread pour la correction orthographique** et un autre pour **l'auto-sauvegarde**.  
> 📝 Ils partagent le **même document en mémoire**.

#### ✅ **Le code** :
Tous les threads peuvent exécuter les **mêmes fonctions** du programme.

> **Exemple** :  
> Un **jeu vidéo** peut avoir un thread pour les **graphismes** et un autre pour la **gestion du son**.  
> 🎮 Les deux utilisent le **même moteur du jeu**.

#### ✅ **Les fichiers ouverts** :
Un thread peut **lire ou écrire dans un fichier** ouvert par un autre thread.

> **Exemple** :  
> Un **lecteur multimédia** peut avoir un **thread pour charger la vidéo** et un autre **pour l’afficher**. 🎬  

---

### 🎯 Pourquoi utiliser plusieurs threads ?  

✔ **Optimiser la performance** : Un programme peut faire plusieurs tâches en parallèle.  
✔ **Améliorer la réactivité** : Une interface utilisateur reste fluide pendant que d'autres threads travaillent en arrière-plan.  
✔ **Mieux utiliser les processeurs multi-cœurs** : Chaque thread peut tourner sur un **cœur différent** du processeur.  

---

### 🔥 Résumé

Un thread est une tâche qui s'exécute dans un processus.

Un processus peut contenir plusieurs threads, qui partagent la mémoire, le code et les fichiers ouverts.

Cela permet aux programmes d’être plus rapides et plus réactifs.
---
<hr><hr>
  
### 🔹 Différence entre un processus et un thread

| Critère               | Processus 🖥                          | Thread ⚡                           |
|-----------------------|--------------------------------------|------------------------------------|
| **Définition**         | Un programme en cours d'exécution    | Une tâche à l'intérieur d'un processus |
| **Mémoire**            | A sa propre mémoire (isolée)         | Partage la mémoire avec d'autres threads du même processus |
| **Indépendance**       | Indépendant des autres processus     | Dépendant des autres threads du même processus |
| **Création**           | Lente ⏳ (besoin d'allouer de la mémoire, charger du code, etc.) | Rapide 🚀 (utilise la mémoire du processus) |
| **Communication**      | Difficile 🛑 (nécessite des mécanismes comme IPC) | Facile ✅ (puisque les threads partagent la mémoire) |
| **Exécution**          | Chaque processus a son propre espace d’exécution | Plusieurs threads peuvent s’exécuter en parallèle dans un même processus |

### 🎯 Exemple concret : Navigateur Web (comme Chrome)

🔵 **Processus** :

Lorsque tu ouvres Google Chrome, un nouveau processus est créé.  
Chaque onglet ouvert peut être un processus séparé.  
➡ Si un onglet plante, les autres continuent de fonctionner.

🟢 **Threads** :

À l'intérieur de chaque processus (onglet Chrome), il y a plusieurs threads :

- Un thread pour l'affichage de l'interface utilisateur
- Un thread pour le téléchargement des pages
- Un thread pour exécuter JavaScript
- Un thread pour jouer une vidéo YouTube

➡ Si un thread plante (par exemple, celui qui charge une image), l'onglet peut encore fonctionner grâce aux autres threads !

💡 **Résumé en une phrase**

Un processus est un programme en cours d’exécution avec sa propre mémoire.

Un thread est une tâche exécutée dans un processus, qui partage la mémoire et les ressources avec les autres threads du même processus.

# 📌 Threads : Exemples concrets  

Un **thread** est une tâche qui s'exécute à l'intérieur d'un processus.  
Plusieurs threads d'un même processus peuvent fonctionner en parallèle et partager la mémoire du programme.  

---

## 🖥 Exemple 1 : Navigateur Web (Chrome, Firefox, etc.)  

Dans un **navigateur web**, plusieurs threads travaillent ensemble pour offrir une **navigation fluide** :  

- 🖥 **Thread de l'interface utilisateur (UI)** :  
  → Gère l'affichage de la fenêtre du navigateur, les boutons, les menus et la saisie utilisateur.  

- 🎨 **Threads de rendu** :  
  → Un thread analyse le **HTML**, un autre applique les **styles CSS**, et un autre dessine la page à l'écran.  

- 🌐 **Thread de réseau** :  
  → Télécharge les **pages web, images et vidéos** en arrière-plan.  

- ⚡ **Threads de traitement JavaScript (Web Workers)** :  
  → Exécutent du **code JavaScript** en arrière-plan pour éviter de **bloquer l’interface**.  

- 📺 **Threads pour la lecture vidéo** :  
  → Gèrent le **chargement et la lecture des vidéos** sans ralentir le reste de la page.  

- 🛡 **Thread de sécurité et de sandboxing** :  
  → Exécute du **code isolé** pour empêcher les **scripts malveillants** d'affecter le système.  

### 💡 Pourquoi utiliser plusieurs threads ?  
➡ Cela permet de **ne pas bloquer l'affichage** du navigateur lorsqu’une page se charge ou qu’une vidéo est en cours de lecture.  

---

## 📝 Exemple 2 : Éditeur de texte (Microsoft Word, Google Docs)  

Dans un **éditeur de texte**, plusieurs threads assurent une expérience **fluide et réactive** :  

- 🖥 **Thread de l'interface utilisateur (UI)** :  
  → Gère l'affichage des **menus, boutons et la zone de texte**.  

- 💾 **Thread d’auto-sauvegarde** :  
  → Sauvegarde **automatiquement le document** toutes les quelques secondes pour éviter les pertes de données.  

- 📝 **Thread de correction orthographique et grammaticale** :  
  → Vérifie **l’orthographe et la grammaire** en temps réel pendant la saisie.  

- 📄 **Thread de rendu et mise en page dynamique** :  
  → Recalcule la **mise en page** lorsque l'on insère **des images, tableaux ou que l'on modifie les marges**.  

### 💡 Pourquoi plusieurs threads ?  
➡ **Imagine que Word faisait tout dans un seul thread** :  

- Si la **vérification orthographique** prenait du temps, **tu ne pourrais plus écrire**.  
- Si la **mise en page** se recalculait, **l’interface se figerait**.  
- Grâce aux **threads**, tout fonctionne en **même temps sans blocage** !  

---

## ✅ Résumé  

- Un **thread** est une **tâche** à l'intérieur d'un programme (**processus**).  
- Un **navigateur web** utilise plusieurs threads pour **charger et afficher les pages sans ralentir**.  
- Un **éditeur de texte** utilise plusieurs threads pour **éviter les blocages** lors de la correction, la sauvegarde et l'affichage du document.  

🚀 **Utiliser plusieurs threads améliore les performances et la fluidité des logiciels !**  
# 📌 Organisation de la Mémoire d'un Processus

Lorsqu’un programme s’exécute, il utilise de la mémoire qui est organisée en différentes sections. Chaque partie a un rôle précis pour que tout fonctionne correctement.

💡 **Sections de la mémoire d'un processus :**

- **Code du programme :**
  - Contient les instructions machine (le code que le processeur exécute).
  - Lecture seule : pour éviter toute modification accidentelle pendant l'exécution.

- **Variables globales et statiques :**
  - Les variables globales et statiques du programme sont stockées ici.
  - **BSS** : Stocke les variables non initialisées.
  - **DATA** : Stocke les variables initialisées.

- **Allocation dynamique :**
  - Utilise des fonctions comme `malloc` ou `new` pour allouer de la mémoire pendant l’exécution du programme.
  - Cette mémoire est appelée **tas (heap)**.

- **Mémoire partagée entre les threads :**
  - Tous les threads d’un processus partagent cette mémoire (sauf la pile de chaque thread).

---

## 📂 Mémoire d'un Processus : Tas et Pile

Deux parties de la mémoire sont particulièrement importantes : la **pile** et le **tas**.

### 🔼 La Pile (Stack)

- Chaque thread a sa propre pile qui lui est allouée lors de sa création.
- Utilisée pour stocker :
  - Variables locales du thread.
  - Adresses de retour des fonctions.
  - Paramètres passés aux fonctions.
- **Limite de taille** : La pile a une taille limitée, souvent environ 8 Mo par thread sous Linux.
- **Fonctionnement** :
  - La pile est organisée de façon à ce que les données les plus récentes soient ajoutées en haut.
  - **SP (Stack Pointer)** : C’est un pointeur qui garde l'adresse du sommet de la pile (l’endroit où la prochaine donnée sera ajoutée ou retirée).

### 📦 Le Tas (Heap)

- Partagé entre tous les threads du même processus.
- Utilisé pour stocker des objets et des données dynamiques qui sont allouées pendant l'exécution du programme (par exemple avec `malloc` ou `new`).
- **Accès synchronisé** : Puisque tous les threads y ont accès, il faut veiller à synchroniser l’accès pour éviter des problèmes de course (conditions de course où plusieurs threads essaient de modifier la même donnée en même temps).

---

## ⚖️ Différence entre Pile et Tas :

| **Caractéristique**     | **Pile (Stack)**                        | **Tas (Heap)**                       |
|-------------------------|----------------------------------------|--------------------------------------|
| **Propriétaire**         | Chaque thread a sa propre pile.        | Partagé entre tous les threads du même processus. |
| **Utilisation**          | Variables locales, adresses de retour des fonctions, paramètres. | Objets et données dynamiques. |
| **Taille**               | Limitée, souvent 8 Mo par thread sous Linux. | Pas de limite stricte, dépend de la mémoire disponible. |
| **Organisation**         | Structure LIFO (Last In, First Out).   | Pas de structure particulière, allocation dynamique. |
| **Accès concurrent**     | Aucun problème d’accès (chaque thread a sa propre pile). | Nécessite une synchronisation pour éviter des problèmes de race. |

---

## 🚀 Conclusion

Les options permettent de personnaliser ce que tu veux afficher. Par exemple, tu peux afficher tous les processus, filtrer par utilisateur ou les afficher sous forme d'arbre.

---
# 📌 La commande `ps` - Afficher les processus en cours  

La commande **ps** permet de voir quels processus sont en cours d'exécution sur un système Linux ou Unix. Cela t'aide à surveiller l'état des processus et à obtenir des informations sur leur comportement.

---

## 1) **Syntaxe de la commande `ps`**  
```
ps [option]
```

## 2) **Options principales**  

### 🔹 Options BSD (Linux, BSD)
- **`a`** : Affiche les processus de tous les utilisateurs, pas seulement ceux de ton terminal.
- **`u`** : Affiche les processus avec des détails supplémentaires comme l'utilisateur et l'utilisation mémoire.
- **`x`** : Affiche les processus en arrière-plan, même ceux qui ne sont pas associés à un terminal.

### 🔹 Options UNIX  
- **`-e` ou `-A`** : Affiche tous les processus du système.  
- **`-f`** : Affiche les détails complets du processus (ex : processus parent).  
- **`-u <utilisateur>`** : Filtre les processus d’un utilisateur spécifique.  
- **`-p <PID>`** : Affiche les informations d’un processus spécifique avec son PID.  

### 🔹 Options GNU/Linux  
- **`--forest`** : Affiche les processus sous forme d'arbre.  
- **`--sort=<champ>`** : Trie les processus selon un critère (`%cpu`, `%mem`, `pid`).  
- **`--no-header`** : Supprime l'en-tête des colonnes pour une sortie plus claire.  

---

## 3) **Colonnes courantes affichées par `ps`**  

Voici les informations les plus courantes que tu verras avec la commande `ps` :

| 🏷 **Nom de la colonne** | 📝 **Description** |
|----------------|----------------|
| **USER** | L'utilisateur qui a lancé le processus. |
| **PID** | L'identifiant du processus. |
| **%CPU** | La quantité de CPU utilisée par le processus. |
| **%MEM** | La quantité de mémoire utilisée. |
| **TTY** | Le terminal associé au processus. |
| **STAT** | L'état du processus (`R` = Running, `S` = Sleeping, etc.). |
| **COMMAND** | La commande qui a lancé le processus. |

---

## 4) **Exemples pratiques**  

### 🔍 Afficher tous les processus :
```bash
ps -e
```
👤 Afficher les processus d'un utilisateur spécifique :
```
ps -u nom_utilisateur
```
🌳 Afficher les processus sous forme d'arbre :
```
ps --forest
```
📊 Trier les processus par utilisation de la mémoire :
```
ps aux --sort=-%mem
```
🔢 Afficher des colonnes personnalisées :
```
ps -eo pid,ppid,%cpu,%mem,comm --sort=-%cpu
```
🎯 Afficher un processus spécifique avec son PID :
```
ps -p 1234
```
5) Astuce supplémentaire

🔍 Utiliser ps avec grep pour rechercher un processus spécifique

Si tu cherches un processus en particulier, tu peux utiliser ps avec grep.
Par exemple, pour trouver tous les processus contenant "firefox" :
```
ps aux | grep firefox
```
📌 Afficher les threads d'un processus spécifique (PID 1234) :
```
ps -T -p 1234
```
📜 Afficher les processus avec une meilleure lisibilité :
```
ps aux | less
```
6) Conclusion

La commande ps est essentielle pour gérer les processus sur ton système. Elle te permet de :

✅ Voir quels processus sont en cours d'exécution.

✅ Obtenir des informations détaillées sur les processus.

✅ Filtrer et trier les résultats pour mieux comprendre ce qui se passe sur ton système

- La pile est utilisée pour des données temporaires et locales à chaque thread, et est donc limitée.
- Le tas est utilisé pour les données dynamiques et partagées entre les threads, ce qui nécessite une synchronisation pour éviter les erreurs.







