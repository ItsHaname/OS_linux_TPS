<h1 align=center> Gestion  des processus </h1>
  <hr><hr><hr>


# 1)-Le Processeur :

Un **processeur** (ou **CPU** - Central Processing Unit) est le cerveau de l'ordinateur. 🧠💻 Il exécute les instructions des programmes en réalisant des opérations **arithmétiques** et **logiques**.

## 🔥 Types de Processeurs

Il existe principalement **deux types** de processeurs :

### 1-1)-Processeur Monocœur:

Un **processeur monocœur** possède **un seul cœur** (le moteur qui exécute les instructions). 🚗

✅ **Avantage** : Simple et efficace pour des tâches de base 📄  
❌ **Inconvénient** : Moins performant pour les tâches lourdes 🎮

📌 **Exemple** :
- Un vieux PC avec un processeur **Pentium 4** 👴💾
- Un microcontrôleur utilisé dans une **machine à laver** 🧺

### 1-2)- Processeur Multicœur

Un **processeur multicœur** contient **plusieurs cœurs** qui travaillent ensemble. Cela permet d'exécuter plusieurs tâches en **même temps** ! ⚡

✅ **Avantage** : Idéal pour le **multitâche** (jouer + streamer + coder) 🎮🎥💻  
❌ **Inconvénient** : Plus cher et consomme plus d'énergie 🔋

📌 **Exemple** :
- Un processeur **Intel Core i7** utilisé pour le gaming 🎮
- Les **processeurs des smartphones** 📱

---
 <hr>
 
## 2)- Les Processus et le Pseudo-Parallélisme

Un **processus** est une **tâche en cours d'exécution** sur un ordinateur. Cela inclut :
- 💾 **Les programmes des utilisateurs** (navigateur, jeu, logiciel...)
- 🔄 **Les entrées-sorties** (sauvegarde de fichiers, impression...)

Un **système d'exploitation** doit gérer plusieurs tâches en même temps. Mais comme il y a souvent **un seul processeur**, il doit **alterner** rapidement entre elles. C'est ce qu'on appelle le **pseudo-parallélisme** :

1. 🎯 Il exécute une tâche pendant un court instant
2. 🔄 Il s'arrête et passe à une autre tâche
3. ⏳ Il recommence très vite ce cycle

💡 **Au final ?** L'ordinateur **semble** exécuter plusieurs tâches **simultanément** alors qu'il les alterne en réalité !

📌 **Exemple concret** :
- Lorsque tu regardes une **vidéo YouTube** 🎥 tout en écoutant de la **musique en arrière-plan** 🎵

<hr><hr>

  ## 🔍 3)- Structure d'un Processus


Les **processus** sont des tâches en cours d'exécution dans un ordinateur. Chaque processus a sa propre **mémoire** et son propre **contexte**. Un processus est composé de 3 segments principaux : **le code**, **les données** et **la pile d'exécution**.

## 🔍 3-1). Les Segments d'un Processus

### 📜 Code
- Le **code** contient les **instructions** du programme à exécuter. C'est en quelque sorte le **plan** du programme.
  
### 💾 Données
- La zone **données** contient les **variables globales** et **statiques** utilisées par le programme, ainsi que les allocations **dynamiques** de mémoire. Ces données sont utilisées pendant l'exécution du programme.

### 🧳 Pile d'exécution
- La **pile d'exécution** est utilisée pour gérer les **appels de fonctions**. Quand une fonction est appelée, l'ordinateur doit savoir où il doit retourner après l'exécution de cette fonction. 🧠
  - **Exemple** : Imagine que tu es en train de cuisiner et que tu demandes à quelqu'un d'aller chercher un ingrédient. Quand il revient, tu dois savoir où en étais-tu dans ta recette. C'est un peu comme ce qui se passe avec la pile d'exécution.

  - **Fonctionnement de la pile** :
    - Lorsque tu appelles une fonction, son **adresse de retour** et ses **variables locales** sont ajoutées dans la pile.
    - Quand la fonction se termine, le programme reprend là où il s'est arrêté.

### 🔄 Le Contexte du Processus
Le **contexte** contient des informations essentielles pour que le système puisse savoir où en est un processus. Cela comprend le **compteur ordinal** et le **registre d'instruction** qui indiquent où se trouve le processus et ce qu'il doit faire.

#### 🗂️ Le Compteur Ordinal
- Le **compteur ordinal** garde la trace de l'adresse de la prochaine instruction à exécuter. 📍

#### 📝 Le Registre d'Instruction
- Le **registre d'instruction** contient l'instruction en cours d'exécution. C'est ce qui dit au processeur ce qu'il doit faire à chaque moment.

---

## 📝 Le Process Control Block (PCB)

Le **PCB** est un peu comme une **fiche d'identité** pour chaque processus. Il contient toutes les informations nécessaires pour **gérer et suivre l'exécution d'un processus**.

### 🔑 Éléments du PCB

1. **Pointeur vers le processus parent**  
   - Indique quel processus a **créé** ce processus.  
   - **Exemple** : Un programme peut lancer un processus pour chaque fenêtre de l'application qu'il ouvre. 

2. **Pointeur vers les processus enfants**  
   - Liste des processus créés par ce processus.  
   - **Exemple** : Si tu ouvres plusieurs fenêtres de navigateur, chaque fenêtre est un **processus enfant**.

3. **État du processus**  
   - Indique si le processus est **en cours d'exécution**, **en attente** ou **suspendu**.  
   - **Exemple** : Un processus peut être en attente si il attend des données d'un autre programme.

4. **Numéro d'identification du processus (PID)**  
   - Chaque processus a un **identifiant unique**.  
   - **Exemple** : Le **PID** du processus "Terminal" pourrait être 12345.

5. **Priorité du processus**  
   - Détermine l'**ordre d'exécution** des processus.  
   - **Exemple** : Le processus système a une **priorité plus élevée** que celui d'un utilisateur.

6. **Compteur de programme (Program Counter)**  
   - Contient l'adresse de la **prochaine instruction** à exécuter.

7. **Registres du processeur**  
   - Les registres qui contiennent les **données nécessaires** à l'exécution du processus.

8. **Pointeurs vers la mémoire**  
   - Les pointeurs indiquent où se trouvent les zones de mémoire utilisées par le processus.

9. **Limites de la mémoire**  
   - Définit **l'espace mémoire** auquel le processus a accès, garantissant l'**isolation** des processus.

10. **Liste des fichiers ouverts**  
    - Les fichiers ouverts par le processus (comme un fichier texte ou un fichier vidéo).

---

## 🖥️ Exemple Concret : Création d'un Processus

Lorsqu'un utilisateur ouvre un **terminal** sur un système, le système **crée un processus** pour exécuter ce terminal. Voici ce qui se passe :

1. Le système crée un **nouveau processus** avec son propre **PCB**.
2. Ce processus **ouvre des fichiers** (par exemple, les fichiers de configuration du terminal).
3. Le processus va être en **attente** ou en **exécution** en fonction de son état.

---

🎯 **Résumé** : Les processus sont des entités indépendantes en cours d'exécution, et chaque processus a sa propre structure en mémoire (code, données, pile) et son propre **PCB** pour permettre au système de le gérer.
<hr>

# 🧠 Commutation de Contexte (Context Switching)

Lorsqu'un **UCT** (Unité Centrale de Traitement) passe de l'exécution d'un processus à un autre, le système doit effectuer plusieurs actions pour assurer que l'exécution se poursuit correctement. Voici les étapes de cette transition :

1. **Mise à jour du PCB du processus en cours (Processus 0)**  
   Avant de changer de processus, le système met à jour le **Process Control Block (PCB)** du processus actuel, sauvegardant ainsi son état (compteur de programme, registres, etc.).

2. **Sauvegarde du PCB du processus en cours (Processus 0)**  
   Le **PCB** du processus en cours est sauvegardé afin qu'il puisse reprendre son exécution plus tard à partir de l'endroit exact où il s'est arrêté.

3. **Chargement du PCB du processus suivant (Processus 1)**  
   Le **PCB** du prochain processus à exécuter est restauré. Ce processus reprend son exécution là où il avait été suspendu.

4. **Restauration des registres et autres éléments de l'UCT**  
   Tous les **registres**, le **compteur de programme**, et les autres informations importantes pour l'exécution du processus sont restaurés à partir du **PCB** du processus suivant.

---

# 🛠️ L'Ordonnanceur

Un **ordonnanceur** est un programme du système d'exploitation qui décide de l'ordre dans lequel les processus doivent être exécutés. L'objectif est d'optimiser l'utilisation des ressources et d'assurer une exécution fluide des processus.

## Types d'Ordonnanceurs
Il existe trois types d'ordonnanceurs :

1. **À long terme** : Sélectionne les processus à charger en mémoire.
2. **À court terme** : Choisit le prochain processus à exécuter sur le processeur.
3. **À moyen terme** : Suspend temporairement certains processus pour libérer de la mémoire.

---

## Cycle de Vie d'un Processus

Le cycle de vie d'un processus comprend plusieurs étapes, chacune représentant un **état** du processus dans l'exécution.

### 1. Création
- **Après sa création**, le processus entre dans la file d'attente de l'ordonnanceur, prêt à être exécuté.

### 2. Exécution
- **Le processus est élu** par l'ordonnanceur pour être exécuté sur le processeur.

### 3. En cours d'exécution
- **Le processus s'exécute** sur le processeur.

### 4. Blocage
- **Le processus est suspendu** temporairement, souvent en attendant un événement comme la lecture/écriture de disque, une réponse réseau, ou une entrée utilisateur.

### 5. Retour dans la file
- **L'information attendue** est disponible, et le processus retourne dans la file d'attente de l'ordonnanceur.

### 6. Terminaison
- **Le processus termine** son exécution, ou est interrompu. Toutes les ressources qui lui étaient allouées sont libérées.

---

## 🔄 Transitions entre les États

Voici les différentes transitions entre les états d'un processus :

- **Nouveau → Prêt** : Le processus est créé et mis en attente d'un processeur.
- **Prêt → Élu** : L'ordonnanceur sélectionne le processus pour l'exécution sur le processeur.
- **Élu → Bloqué** : Si le processus doit attendre des ressources externes (disque, réseau, etc.), il passe en état **bloqué**.
- **Bloqué → Prêt** : Une fois la ressource disponible, le processus retourne dans la file d'attente de l'ordonnanceur.
- **Élu → Terminé** : Lorsque le processus termine son exécution, il passe à l'état **terminé**.
- **Terminaison anormale** : Un processus peut être interrompu ou terminé de façon inattendue depuis n'importe quel état sauf l'état **Nouveau**.

---

## ⚠️ Interruption

Une **interruption** est un signal envoyé au processeur pour indiquer qu'un événement nécessite une attention immédiate. Cela permet de gérer les événements en temps réel, comme un périphérique qui signale qu'il est prêt à transmettre des données.

---

# 💻 Processus Père et Fils

Les processus peuvent être liés sous forme de hiérarchies. Un **processus père** crée un ou plusieurs **processus fils**. Ces derniers peuvent à leur tour en créer d'autres, formant ainsi une structure en arbre.

### 1. Processus Père
- Un **processus père** est celui qui crée un ou plusieurs processus enfants. Il reste lié à eux et peut les surveiller ou attendre leur fin.

### 2. Processus Fils
- Un **processus fils** est créé par un processus père et hérite de certaines de ses caractéristiques. Il peut lui-même créer d'autres processus.
  
**Exemple :**  
Lorsqu'on tape `gcc mon_programme.c -o mon_programme && ./mon_programme`, le terminal (père) crée un processus fils pour **gcc**, puis un autre pour **./mon_programme**, et attend leur fin.

---

## 🆔 Identifiants de Processus

Chaque processus possède les identifiants suivants :

- **PID** (Process ID) : Identifiant unique du processus.
- **PPID** (Parent Process ID) : Identifiant du processus père.
- **UID** (User ID) : Identifiant de l'utilisateur qui a lancé le processus.
- **GID** (Group ID) : Identifiant du groupe auquel appartient le processus.

---

## 🛑 Processus Orphelins

Un **processus orphelin** est un processus dont le parent s'est terminé avant lui. Le système réattribue ce processus orphelin au processus **init** (ou **systemd** sur certains systèmes).

**Exemple :**  
Si tu lances un éditeur graphique depuis un terminal et que ce dernier se ferme, l'éditeur devient orphelin et est réattribué à un processus système comme **init** ou **systemd**.

---

## 💀 Processus Zombies

Un processus devient un **zombie** lorsque le **processus père** ne récupère pas son statut de terminaison. Cela arrive quand le processus fils se termine avant son père, mais que ce dernier n'appelle pas la fonction `wait()` pour récupérer son code de sortie.

**Exemple :**  
Si un terminal lance un éditeur de texte et que l'éditeur se ferme rapidement, mais que le terminal ne récupère pas le code de sortie du processus, le processus fils devient un zombie.

La fonction `wait()` permet au processus père de récupérer le statut de fin de son processus fils et ainsi d'éviter la création de processus zombies.

---

## 🔄 Communication entre Processus Père et Fils

Les processus peuvent communiquer entre eux de différentes manières :

### 1. **Pipes** :  
Les **pipes** sont des canaux unidirectionnels qui permettent à un processus père d'envoyer des données à son processus fils.

### 2. **Signaux** :  
Les **signaux** sont de petites notifications envoyées entre processus. Par exemple, le père peut envoyer un signal pour demander au fils d'exécuter une action.

### 3. **Mémoire partagée** :  
La **mémoire partagée** permet à plusieurs processus d'accéder à un espace mémoire commun pour échanger des données rapidement. Cela nécessite une gestion d'accès pour éviter les conflits.

### 4. **Sockets et files de messages** :  
Les **sockets** permettent des échanges de données complexes entre processus, même sur différentes machines. Les **files de messages** offrent une solution pour une communication asynchrone.



