# 🚀 **TP : Maîtriser AWK - De débutant à expert**

Bienvenue dans ce TP complet pour maîtriser **AWK** de A à Z. Dans ce TP, tu vas être guidé à travers 50 exercices qui te permettront de comprendre et d’appliquer les concepts d'AWK dans divers contextes. Ces exercices vont t'aider à devenir un expert en AWK, de l'analyse de texte à la manipulation avancée de données.

📄 **Fichier d'entrée** (`fichier.txt`)

Voici le fichier `fichier.txt` que tu vas utiliser dans plusieurs exercices. Il contient des informations sur les actions des utilisateurs :

```
ID      Nom     Date       Action  Montant
1    Alice   2025-01-01 Login       0
2    Bob     2025-01-02 Logout     10
3    Charlie 2025-01-03 Login      20
4    Alice   2025-01-04 Logout     30
5    Bob     2025-01-05 Login      40
6    Charlie 2025-01-06 Logout    50
```

---

## 💡 **Exercices de base**
  <h1>Exercice1</h1>

### 1️⃣ **Manipulation de lignes et de champs**

1.1. Affiche toutes les lignes du fichier.  
1.2. Affiche uniquement la première colonne du fichier.  
1.3. Affiche les lignes où le nom est **Alice**.  
1.4. Affiche les lignes où l’action est **Login**.  
1.5. Affiche la deuxième colonne et la quatrième colonne uniquement.  
1.6. Affiche les lignes où le montant est supérieur à 20.  
1.7. Affiche les lignes où la date est **2025-01-03**.  
1.8. Affiche les lignes où le montant est supérieur à 10 et l’action est **Logout**.  
1.9. Affiche les lignes où le montant est exactement égal à **30**.

---
  <h1>Exercice2</h1> 
   
### 2️⃣ **Utilisation de `gsub` pour remplacer du texte**

2.1. Remplace **"Login"** par **"Connected"** dans toute la ligne.  
2.2. Remplace **"Logout"** par **"Disconnected"** uniquement dans la colonne **Action**.  
2.3. Remplace **"Bob"** par **"Robert"** uniquement dans le nom de l’utilisateur.  
2.4. Remplace **"2025-01-03"** par **"2025-02-01"** dans la date.  
2.5. Remplace **"MIP"** par **"INFO"** dans toute la ligne. (Bien que "MIP" ne soit pas présent, essaye de l’imaginer dans un autre fichier).

---
 <h1>Exercice3</h1>

### 3️⃣ **Calculs et agrégations**

3.1. Calcule la somme des montants pour chaque action (Login/Logout).  
3.2. Calcule le total des montants pour chaque utilisateur.  
3.3. Calcule le montant total pour toutes les lignes.  
3.4. Affiche le montant moyen des transactions.  
3.5. Affiche l’utilisateur qui a dépensé le plus d'argent (basé sur le montant total).  
3.6. Affiche la ligne où l'utilisateur a le montant total le plus élevé.  
3.7. Affiche la somme des montants uniquement pour les utilisateurs "Bob".  
3.8. Affiche le nombre d'occurrences de l’action **Login** dans le fichier.  
3.9. Calcule le montant total pour les actions **Login** effectuées par Alice.

---
 <h1>Exercice4</h1>
## 🔧 **Manipulation avancée des champs**

### 4️⃣ **Modification des champs**

4.1. Ajoute une nouvelle colonne **"Status"** qui contient "Success" si le montant est supérieur à 20 et "Failure" sinon.  
4.2. Modifie la colonne **Montant** pour ajouter 5 à chaque valeur.  
4.3. Ajoute une colonne **"Action Date"** en combinant les colonnes **Action** et **Date**.  
4.4. Réorganise les colonnes pour que **Nom**, **Montant**, **Action**, **Date**, **ID** apparaissent dans cet ordre.  
4.5. Ajoute un compteur de ligne au début de chaque ligne (une nouvelle première colonne).

---
 <h1>Exercice5</h1>
### 5️⃣ **Conditions complexes**

5.1. Affiche les lignes où l’action est **Login** ET le montant est supérieur à 30.  
5.2. Affiche les lignes où le montant est **inférieur à 20 ou supérieur à 50**.  
5.3. Affiche les lignes où **le nom commence par "A"**.  
5.4. Affiche les lignes où **le nom contient "e"** et l’action est **Logout**.  
5.5. Affiche les lignes où **l’action est "Login" et l’utilisateur est soit "Alice" soit "Charlie"**.  
5.6. Affiche les lignes où **le montant est supérieur à 10 et la date est après le 2025-01-02**.

---
 <h1>Exercice6</h1>
## 🛠️ **Manipulation de fichiers externes**

### 6️⃣ **Fusion de fichiers avec AWK**

6.1. Crée un fichier `utilisateurs.txt` contenant les noms et niveaux d’accès des utilisateurs (Alice, Bob, Charlie).  
6.2. Utilise **AWK** pour lier les données des utilisateurs du fichier `fichier.txt` avec leurs niveaux d'accès du fichier `utilisateurs.txt`.  
6.3. Affiche le nom et le niveau d'accès de chaque utilisateur dans `fichier.txt`.  
6.4. Ajoute le niveau d’accès de chaque utilisateur à la fin de chaque ligne dans `fichier.txt`.  
6.5. Affiche uniquement les utilisateurs ayant un niveau d’accès **"Admin"**.

---
  <h1>Exercice7</h1>
## 🧑‍💻 **Exercices sur les tableaux**

### 7️⃣ **Travail avec les tableaux**

7.1. Crée un tableau associatif pour enregistrer le nombre de fois que chaque action est effectuée.  
7.2. Crée un tableau associatif pour enregistrer la somme des montants pour chaque utilisateur.  
7.3. Affiche la somme des montants pour chaque utilisateur, triée par ordre décroissant.  
7.4. Affiche le nombre d’actions effectuées par chaque utilisateur.  
7.5. Affiche l'utilisateur ayant effectué le plus grand nombre d'actions.  
7.6. Affiche le nombre de fois où l’action **Logout** a été effectuée pour chaque utilisateur.

---

## ⚙️ **Filtres et expressions régulières**

### 8️⃣ **Utilisation des expressions régulières**

8.1. Affiche toutes les lignes où l'action commence par **"L"** (Login ou Logout).  
8.2. Affiche les lignes où **le nom de l'utilisateur contient "a"**.  
8.3. Affiche les lignes où le montant est **composé de 2 chiffres**.  
8.4. Affiche les lignes où la date commence par **"2025-01"**.  
8.5. Affiche toutes les lignes où l’action est **"Login"** et l’utilisateur est **"Alice"** ou **"Bob"**.

---

## 🔎 **Analyse de données**

### 9️⃣ **Création de rapports et analyses**

9.1. Affiche le total des montants pour chaque utilisateur, trié par ordre décroissant.  
9.2. Affiche le nombre total de **Logins** effectués par chaque utilisateur.  
9.3. Crée un rapport affichant le nombre total de transactions pour chaque utilisateur, trié par montant décroissant.  
9.4. Crée un rapport affichant la date, le montant et l’action de chaque transaction **Login** effectuée après **2025-01-02**.  
9.5. Crée un rapport affichant l'utilisateur, la date et l’action de chaque **Login** effectué avant **2025-01-04**.

---

## 🌐 **Avancé : Optimisation et automatisation**

### 🔟 **Automatisation et scripts**

10.1. Crée un script AWK pour ajouter un identifiant unique à chaque ligne (en utilisant `NR` pour numéro de ligne).  
10.2. Crée un script AWK qui filtre et remplace tous les montants supérieurs à 30 par **"Dépense élevée"** dans toute la ligne.  
10.3. Crée un script AWK pour trier les utilisateurs par ordre alphabétique croissant.  
10.4. Crée un script AWK qui génère un fichier de sortie contenant uniquement les utilisateurs avec un montant supérieur à 20.  
10.5. Crée un script AWK qui génère un rapport dans lequel chaque ligne contient le nom, l’action et la somme des montants effectués par l'utilisateur, trié par utilisateur.

---

## 🎉 **Bonus : Défis supplémentaires**

### 🔟 **Exercices avancés**

10.1. Utilise des fonctions personnalisées en AWK pour automatiser le calcul des montants totaux.  
10.2. Crée un tableau multidimensionnel en AWK pour associer chaque utilisateur avec ses actions et montants.  
10.3. Crée un rapport détaillant la somme des montants par date et action.  
10.4. Crée une fonction AWK permettant de vérifier si une chaîne donnée correspond à un format de date valide (YYYY-MM-DD).  
10.5. Crée une fonction AWK qui transforme chaque montant dans un format monétaire (par exemple, **$20.00**).

---

## 📂 **Livrables**

- Résous chaque exercice ci-dessus en utilisant AWK.
- Pour chaque exercice, ajoute des commentaires expliquant ta logique.
- Crée des scripts AWK (ex. `exercice1.awk`, `exercice2.awk`, etc.) et place-les dans un dossier `scripts` sur ton dépôt GitHub.
- Pousse ton travail sur GitHub avec une présentation claire dans le `README.md` de ton dépôt.

---

## 🔥 **Conseils**

- 💡 *N’hésite pas à tester tes scripts sur différentes données d’entrée pour voir comment ils réagissent !*
- ✨ *Utilise les fonctionnalités avancées d’AWK pour optimiser ton code et le rendre plus modulable.*

---

### **Bonne chance !** 👨‍💻🎉

Ce TP te guidera tout au long de ton apprentissage et te permettra d’acquérir des compétences solides en AWK. Une fois résolu, tu seras capable de résoudre de nombreux problèmes complexes de manipulation de données et de génération de rapports.
