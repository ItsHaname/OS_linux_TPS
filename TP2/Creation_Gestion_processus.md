# 🖥️ **Création et Gestion des Processus en C** 💻

## Introduction
Le **processeur (CPU)** est l'unité centrale de traitement d'un ordinateur. Il exécute les instructions des programmes en effectuant des opérations arithmétiques et logiques. Les systèmes modernes utilisent des processeurs **monocœurs** ou **multicœurs**.

## 🧑‍💻 Bibliothèque `<unistd.h>` 
En programmation C sur des systèmes Unix (comme Linux ou macOS), la bibliothèque `<unistd.h>` est essentielle pour la gestion des processus. Elle inclut des fonctions comme **getpid()**, **getppid()**, **fork()**, et bien d'autres qui sont couramment utilisées pour créer, manipuler et gérer des processus.

### Fonctions courantes dans `<unistd.h>`:
- **`getpid()`** : Retourne l'identifiant du processus appelant.  
- **`getppid()`** : Retourne l'identifiant du processus parent.  
- **`getuid()`** : Retourne l'identifiant de l'utilisateur effectif.  
- **`fork()`** : Crée un nouveau processus en dupliquant le processus appelant.  
- **`exec()`** : Permet d'exécuter un programme.  
- **`wait()`** et **`waitpid()`** : Attendent la terminaison d'un processus enfant.
  # 🏗️ **Structure d'un Processus**
Chaque processus possède sa propre structure en mémoire, souvent représentée par le **Process Control Block (PCB)**.

### Les éléments du PCB :
- **PID** : Identifiant du processus.
- **PPID** : Identifiant du processus parent.
- **État du processus** : Exécution, attente, ou suspension.
- **Compteur de programme** : Adresse de la prochaine instruction à exécuter.
- **Registres** : Contient les registres nécessaires à l'exécution.
- **Mémoire du processus** : Espaces alloués en mémoire pour ce processus.

---

## 🔄 **Cycle de Vie d’un Processus**
Le cycle de vie d'un processus inclut plusieurs états :

1. **Nouveau → Prêt** : Processus créé, prêt à être exécuté.
2. **Prêt → Élu** : Sélectionné par l'ordonnanceur pour être exécuté.
3. **Élu → Bloqué** : Le processus attend une ressource (ex. : lecture disque).
4. **Bloqué → Prêt** : Une fois la ressource disponible, le processus retourne dans la file.
5. **Élu → Terminé** : Processus terminé, libère les ressources.
# 👨‍👩‍👦 **Processus Père et Fils**

### Processus Père :
- Crée un ou plusieurs processus fils et attend leur fin.

### Processus Fils :
- Créé par un père, il peut créer d'autres processus et former une hiérarchie.

### Exemple de hiérarchie :
1. Un terminal lance **gcc** (le processus père).
2. **gcc** lance le programme compilé (**./mon_programme**), créant ainsi un processus fils.

---

# 🧟‍♂️ **Processus Zombies et Orphelins**

### Processus Zombies :
Un **processus zombie** survient quand un processus fils termine son exécution mais ne libère pas immédiatement ses ressources, car le processus parent n'a pas encore récupéré son statut de terminaison via **`wait()`**.

### Processus Orphelins :
Un **processus orphelin** se produit lorsque le parent se termine avant l'enfant. Le processus orphelin est alors réattribué à **`init`** (ou **`systemd`** sur certains systèmes).

---

# ⚙️ **Communication entre Processus**

Les processus peuvent communiquer entre eux via plusieurs méthodes :
- **Pipes** : Unidirectionnel, utilisé pour envoyer des données entre un processus père et son fils.
- **Signaux** : Notifications envoyées entre processus pour gérer des événements (ex. : interruption).
- **Mémoire partagée** : Permet à plusieurs processus d'accéder à une zone mémoire commune.
- **Sockets et Files de messages** : Utilisées pour des communications complexes, notamment entre machines.

---

# 📅 **Résumé et Concepts Clés**

- Un **processeur monocœur** exécute une seule instruction à la fois, tandis qu'un **processeur multicœur** permet l'exécution parallèle.
- Les processus sont créés avec **`fork()`** et peuvent être surveillés par le processus parent.
- **Les processus zombies** surviennent si le parent ne récupère pas le statut de terminaison du fils, et les **processus orphelins** sont réassignés à `init`.


## 👾 **PID, PPID, UID, GID**

- **PID** : Identifiant unique d’un processus. Chaque processus en exécution dans un système d'exploitation possède son propre **PID**.
- **PPID** : Identifiant du processus parent. Chaque processus, à l'exception du tout premier, a un parent.
- **UID** : Identifiant de l'utilisateur associé à un processus.
- **GID** : Identifiant du groupe associé à un processus.

### 🛠️ Types et Fonctions associées :
- **`pid_t`** : Type pour représenter un identifiant de processus.
- **`uid_t`** : Type pour l'ID utilisateur.

---

## 🔄 **La Fonction `fork()`**
La fonction **`fork()`** crée une copie exacte du processus appelant, permettant ainsi à deux programmes de s'exécuter indépendamment. Après un **`fork()`**, il existe deux processus :
- **Le processus parent** : Le processus original.
- **Le processus enfant** : La copie du processus parent.

```c
#include <unistd.h>
#include <stdio.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Code du processus enfant
        printf("C'est le processus enfant, mon PID est %d et le PPID est %d\n", getpid(), getppid());
    } else {
        // Code du processus parent
        printf("C'est le processus parent, mon PID est %d\n", getpid());
    }

    return 0;
}


