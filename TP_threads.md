# 🖥️ TP : Analyse des processus et gestion des threads avec `ps`  

## 🎯 Objectif  

Ce TP a pour objectif d'apprendre à utiliser la commande **ps** sous Linux pour :  
- Lister, trier et analyser les processus en cours d'exécution.  
- Travailler avec les threads associés aux processus.  
- Répondre à des questions spécifiques à l'aide de commandes précises.  

---

## 📌 Prérequis  

Avant de commencer, assurez-vous d'avoir :  
- Des connaissances de base en ligne de commande sous Linux.  
- Un terminal pour exécuter les commandes.  
- Une compréhension des concepts de processus et threads.  

---

## 📝 Exercices  

### Exercice 1 : Lister les processus en cours d'exécution  

- Utilisez la commande `ps aux` pour afficher tous les processus en cours d'exécution sur votre système.  
- Ajoutez la commande `| less` pour paginer les résultats.  
- Identifiez les colonnes principales dans la sortie (`USER`, `PID`, `%CPU`, `%MEM`, etc.) et expliquez leur rôle.  

---

### Exercice 2 : Trier les processus par utilisation de la mémoire  

- Utilisez la commande `ps aux --sort=-%mem` pour trier les processus par utilisation de la mémoire (ordre décroissant).  
- Identifiez les processus qui consomment le plus de mémoire.  
- Donnez un exemple de processus avec sa consommation mémoire.  

---

### Exercice 3 : Lister les processus par utilisateur  

- Utilisez la commande `ps -u <nom_utilisateur>` pour lister les processus d'un utilisateur spécifique.  
- Remplacez `<nom_utilisateur>` par votre propre nom d'utilisateur et expliquez les résultats.  

---

### Exercice 4 : Affichage d'une hiérarchie de processus  

- Utilisez l'option `-f` avec `ps` pour afficher une hiérarchie des processus.  
- Interprétez les informations données sur les relations parent/enfant des processus.  

---

### Exercice 5 : Rechercher un processus spécifique  

- Utilisez `ps -ef | grep <nom_processus>` pour rechercher un processus par son nom.  
- Remplacez `<nom_processus>` par un processus comme `firefox` ou `bash`.  
- Expliquez le résultat et comment identifier le PID du processus recherché.  

---

### Exercice 6 : Analyser les threads d'un processus  

- Utilisez `ps -T -p <PID>` pour lister les threads associés à un processus spécifique.  
- Remplacez `<PID>` par un identifiant de processus valide (exemple : `ps -T -p 1793`).  
- Expliquez les informations sur les threads qui apparaissent dans la sortie.  

---

### Exercice 7 : Utilisation de `top` pour voir les threads  

- Utilisez la commande `top -H -p <PID>` pour afficher les threads d'un processus.  
- Remplacez `<PID>` par un PID valide et expliquez les informations présentées.  

---

### Exercice 8 : Trouver le nombre de threads d'un processus  

- Utilisez `ps -eLo tid,cmd | grep <nom_processus> | wc -l` pour compter le nombre de threads associés à un processus comme `firefox`.  
- Interprétez le nombre de threads pour ce processus.  

---

## ❓ Questions  

1. Quelle est la différence entre les commandes `ps aux` et `ps -ef` ?  
2. Quelles options de `ps` permettent d'afficher les processus en hiérarchie ?  
3. Que signifie le statut `S` dans la colonne `STAT` de la commande `ps` ?  
4. Comment pouvez-vous afficher les processus en fonction de leur utilisation CPU ?  
5. Expliquez l'usage de l'option `-o` avec la commande `ps`. Donnez un exemple d'utilisation.  
6. Comment filtrer les processus dont le nom de commande contient un ou plusieurs "p" ?  

---

## 🎯 Résultats attendus  

À la fin de ce TP, vous devez être capable de :  
- Utiliser la commande `ps` pour lister, trier et filtrer les processus selon différents critères.  
- Comprendre comment `ps` permet d’analyser les threads associés à un processus.  
- Répondre aux questions théoriques sur les processus et leur gestion sous Linux.  

🚀 **Bon apprentissage !** 😃  
