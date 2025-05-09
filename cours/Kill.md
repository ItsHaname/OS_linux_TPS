# La commande `kill` sous Linux 🛑

## 📌 Définition  
La commande `kill` est utilisée dans les systèmes Unix/Linux pour envoyer des signaux aux processus en cours d'exécution, généralement pour les arrêter.

## 📌 Syntaxe de base  
```sh
kill [options] PID
```
- `PID` : Identifiant unique du processus cible.  
- `options` : Spécifient le type de signal ou d'action.

---

## 📌 Qu'est-ce qu'un signal ? ⚡
Un **signal** est un message envoyé à un processus pour lui notifier un événement (arrêt, pause, redémarrage...).

🔹 Envoyé par le noyau, un utilisateur ou un autre processus.  
🔹 Chaque signal a un numéro et un nom.

### 🔢 Liste des signaux courants

| Numéro | Nom     | Description |
|--------|--------|-------------|
| 1      | SIGHUP  | Ferme ou redémarre un processus. |
| 2      | SIGINT  | Interrompt un processus (équivalent à `Ctrl + C`). |
| 9      | SIGKILL | Tue immédiatement un processus. |
| 15     | SIGTERM | Demande à un processus de se terminer proprement. |
| 19     | SIGSTOP | Met un processus en pause. |
| 18     | SIGCONT | Relance un processus mis en pause. |
| 17     | SIGCHLD | Envoyé à un processus parent lorsqu'un de ses processus enfants se termine. |

📌 Liste complète des signaux :  
```sh
kill -l
```

---

## 📌 Considérations supplémentaires 🚨

### ⚠️ Prudence avec `kill -9` (SIGKILL)  
Le signal SIGKILL (`-9`) force l'arrêt immédiat d'un processus **sans** lui laisser le temps d'effectuer des actions de nettoyage (fermeture des fichiers, sauvegarde des données, libération de mémoire, etc.).

### 🔑 Permissions nécessaires  
Par défaut, un utilisateur **ne peut pas** tuer un processus appartenant à un autre utilisateur, sauf si :
- Il est **root** (`sudo` est nécessaire).
- Il a des permissions spécifiques.

---

## 📌 Utilisation de `kill` avec des signaux 🎯

### 🛑 Envoyer un signal à un processus
```sh
kill -<signal> <PID>
```
**Exemples :**
```sh
kill -KILL 5678  # Tue immédiatement le processus 5678
kill -9 5678     # Équivalent à SIGKILL
kill -TERM 5678  # Demande à un processus de se terminer proprement
```

### 🔍 Trouver un PID avec `pgrep`
```sh
pgrep nom_du_processus
```
**Exemple :**
```sh
pgrep gedit  # Trouve le PID de l'éditeur de texte gedit
```

---

## 📌 Exemples pratiques 🚀

### 1️⃣ Terminer un processus `top`
```sh
# Ouvrir `top`
top
```
Dans un **autre terminal**, trouver son PID :
```sh
pgrep top
```
Puis envoyer un signal :
```sh
kill -TERM 1234  # Remplacez 1234 par le PID de `top`
```
Si `top` ne s'arrête pas, forcer l'arrêt :
```sh
kill -KILL 1234
```

### 2️⃣ Suspendre et relancer un processus
```sh
# Suspendre un processus
tkill -STOP <PID>

# Reprendre un processus
tkill -CONT <PID>
```
**Exemple :**
```sh
ping google.com  # Lance un ping
pgrep ping       # Trouver le PID
tkill -STOP 5678  # Suspendre `ping`
kill -CONT 5678  # Relancer `ping`
```

---

## 📌 `killall` : Terminer plusieurs processus

La commande `killall` arrête **tous** les processus portant le même nom :
```sh
killall firefox
```
---

## 📌 Arguments en ligne de commande 🖥️
Un **argument** est une valeur transmise à un programme lors de son exécution en ligne de commande.

### Exemple :
```sh
./mon_programme arg1 option1
```
- `./mon_programme` est le nom de l’exécutable.
- `arg1` et `option1` sont des arguments passés au programme.

### Syntaxe en C :
```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Nombre d'arguments : %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("Argument %d : %s\n", i, argv[i]);
    }
    return 0;
}
```

### Explication :
- `argc` (**Argument Count**) : Nombre d'arguments passés au programme.
- `argv[]` (**Argument Vector**) : Tableau contenant les arguments.
  - `argv[0]` : Nom du programme.
  - `argv[1]`, `argv[2]`... : Arguments fournis par l'utilisateur.

### Exemple d'exécution :
```sh
./mon_programme hello world
```
**Sortie :**
```
Nombre d'arguments : 3
Argument 0 : ./mon_programme
Argument 1 : hello
Argument 2 : world
```
Cela montre que `argv[0]` est toujours le nom du programme, et les arguments commencent à `argv[1]`.

---

🚀 **Bravo !** Tu connais maintenant les bases de `kill` et la gestion des processus sous Linux ! 🎉
