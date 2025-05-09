# 📘 Mémoire Principale : Allocation Contiguë Dynamique

Ce document explique de manière simple le concept de **mémoire principale** et l'**allocation contiguë dynamique**, en se basant sur des exemples et des algorithmes classiques.

## 🧠 Qu'est-ce que l'allocation contiguë dynamique ?

Lorsqu'un programme (ou "processus") a besoin de mémoire pour s'exécuter, le système d'exploitation lui réserve un **espace contigu** (c'est-à-dire collé sans interruption) dans la mémoire principale (RAM).

### Exemple de mémoire disponible :

Imaginons qu'on a 3 "trous" (espaces libres) en mémoire :

- T1 : 200 Ko  
- T2 : 400 Ko  
- T3 : 100 Ko  

Un processus **P** a besoin de **80 Ko** de mémoire.

Selon la stratégie d'allocation, le système choisira un trou différent :

### 🔢 Algorithmes d’allocation

- **First-Fit** (Premier trou adapté) :  
  → Le système choisit le **premier** trou qui est assez grand.  
  ✅ Ici, ce sera **T1 (200 Ko)**.

- **Best-Fit** (Meilleur ajustement) :  
  → Le système choisit le **plus petit trou possible** qui peut contenir le processus.  
  ✅ Ici, ce sera **T3 (100 Ko)**.

- **Worst-Fit** (Pire ajustement) :  
  → Le système choisit le **plus grand trou disponible** pour garder les petits pour plus tard.  
  ✅ Ici, ce sera **T2 (400 Ko)**.

---

## 💡 Mémoire virtuelle : c’est quoi ?

La **mémoire virtuelle** permet de faire tourner un programme même s’il est **plus gros que la mémoire disponible**.

### Comment ça marche ?

- Le programme est découpé en **blocs** (appelés **pages**).
- Seules les pages **utiles en ce moment** sont chargées en mémoire.
- Le reste reste sur le disque dur (dans un espace appelé **swap**).
- Cela donne **l’illusion** que la mémoire est plus grande qu’elle ne l’est vraiment.

---

## ❓ Pourquoi utiliser la mémoire virtuelle si on a déjà les algorithmes First-Fit, Best-Fit et Worst-Fit ?

### 🧠 Rappel : les algorithmes (First-Fit, etc.)

Ces algorithmes aident à **placer un programme dans la mémoire**…  
**Mais seulement si la mémoire centrale (RAM) a assez de place !**

---

### 🚨 Problème :

Et si un programme est **plus gros que la RAM disponible** ?  
Ou si **tous les trous sont trop petits**, même en les combinant ?

🤔 Exemple :

- Programme P : 600K
- Mémoire libre :  
  - T1 : 200K  
  - T2 : 250K  
  - T3 : 100K  

Total libre = 550K → **pas assez pour 600K**, même si on combine tout.

👉 **Aucun algorithme (First-Fit, Best-Fit, etc.) ne pourra aider** ici.

---

## ✅ Solution : La mémoire virtuelle

La **mémoire virtuelle** est une astuce géniale utilisée par le système d’exploitation.

### 🧩 Idée principale :

> Simuler une mémoire **plus grande que la RAM réelle**  
> en utilisant une partie du **disque dur** (appelée *swap*).

---

### 🔁 Comment ça fonctionne ?

1. Le programme est **divisé en pages** (petits blocs).
2. Seules les pages **actuellement utilisées** sont chargées en mémoire.
3. Les autres restent sur le disque (*swap*).
4. Quand une page non présente est nécessaire → **le système l'échange (swap)** avec une autre.

---

### 📐 Schéma explicatif

<img src="https://github.com/ItsHaname/OS_linux_TPS/raw/main/img/ChatGPT%20Image%20May%209%2C%202025%2C%2004_30_56%20AM.png" alt="Description de l'image" width="600" height="400">

# 🔄 La mémoire virtuelle et le Swapping : Va-et-vient des pages

Quand la mémoire RAM est **trop petite**, le système d'exploitation utilise le disque dur (SWAP) pour stocker temporairement des parties de programmes. Ce mécanisme est appelé **Swapping** (ou va-et-vient).

---

### 🧠 Rappel : ce qu’on sait déjà

- Un programme est **découpé en pages** (souvent 4 Ko ou 8 Ko chacune).
- Le système charge en RAM **seulement les pages utiles à l’exécution immédiate**.
- Les autres pages restent sur le **disque dur (swap)**.
## 🧪 Comment le système choisit quelles pages vont dans la RAM ou sur le disque ?

Il utilise des **algorithmes de remplacement de pages**.

### 🔧 Exemples d’algorithmes :

| Nom              | Description simple                                                |
|------------------|--------------------------------------------------------------------|
| FIFO (First-In First-Out) | La page qui est en RAM depuis le plus longtemps est remplacée. |
| LRU (Least Recently Used) | On remplace la page **la moins utilisée récemment**.              |
| LFU (Least Frequently Used) | On remplace la page **la moins souvent utilisée**.               |
| Clock (algorithme circulaire) | Variante optimisée de LRU avec une "aiguille" qui tourne

### ⚠️ Cas : Le programme a besoin d’une page qui est sur le disque (pas dans la RAM)

1. **Page Fault** (erreur de page) se produit.
2. Le système choisit une page actuelle de la RAM à **évacuer** vers le disque.
3. Il **charge la page demandée** depuis le disque vers la RAM.
4. Le programme peut maintenant continuer.
## 📉 Est-ce que ça ralentit l’exécution ?

🛑 **Oui.**
L'accès à la RAM est **1000x plus rapide** qu’un accès au disque dur.

> ⚠️ Trop de swaps = programme ralenti fortement  
> (ce phénomène s’appelle le **thrashing**)
### Étapes du swapping :

1. RAM : [A, B]  
2. Besoin d’exécuter C → on swap B vers disque
 ### ✴️ C’est ça le **swap out** : 
   → RAM : [A, C] | Disque : [B]
4. Besoin d’exécuter D → on swap A vers disque  
   → RAM : [C, D] | Disque : [A, B]
5. Re-besoin de A → on swap C ou D pour le faire revenir...
### ✴️ C’est ça le **swap in** :  

| Terme     | Signification |
|-----------|----------------|
| **Swap Out** | On **retire un programme de la RAM** pour le mettre sur le disque (on libère de la mémoire). |
| **Swap In**  | On **ramène un programme du disque vers la RAM** pour pouvoir l’utiliser. |


👉 Ce **va-et-vient** optimise l’utilisation de la mémoire **mais ralentit si trop fréquent**.

---

## ✅ En résumé

- Le système choisit les pages à swapper selon un **algorithme de remplacement**.
- L’échange disque/RAM est **automatique**, mais **lent**.
- Trop de swapping = programme **très ralenti** (thrashing).

  ----
  # 🧠 Gestion de la Mémoire Virtuelle (avec MMU et TLB)

La mémoire virtuelle est gérée par un composant du processeur appelé **MMU** : Memory Management Unit (Unité de gestion de la mémoire).  
Ce composant travaille **en cachette**, pour que le processeur puisse **utiliser des adresses virtuelles** au lieu de gérer les vraies adresses physiques.

---

## 🛠️ Étapes de fonctionnement de la gestion mémoire

---

### 1. Création du processus

> ➕ Quand un programme démarre, le système d’exploitation lui crée un **espace mémoire virtuel**.

- Cet espace est **faux**, mais le programme croit que toute la mémoire est à lui.
- Exemple : le programme pense qu’il peut utiliser de 0 à 4 Go, même si la RAM réelle est de 8 Go pour tout le système.

---

### 2. Adresses virtuelles

> 🧭 Chaque instruction et chaque donnée du programme utilise une **adresse virtuelle** (pas une adresse physique réelle).

- Ces adresses sont uniquement valables pour ce processus.

---

### 3. Demande du processeur

> 📥 Quand le processeur veut lire ou écrire une donnée, il utilise l’adresse **virtuelle**.

---

### 4. Rôle du MMU (Memory Management Unit)

> 🔄 La MMU intercepte l’adresse virtuelle et la **traduit en adresse physique**.

- Elle utilise une table spéciale pour savoir **où est rangée chaque page** du programme dans la mémoire physique.
- Cette table de correspondance est appelée **table des pages**.

---

### 5. Traduction d’adresse : UCT

> 🧰 Cette traduction est gérée par l'**UCT** (Unité de Contrôle de Traduction), un circuit dans la MMU.

- C’est comme un **GPS** qui transforme une "adresse virtuelle" en une "adresse réelle" dans la RAM.

---

### 6. Accès à la mémoire réelle

> 📤 Une fois qu'on a l’adresse physique, on peut **aller chercher la donnée dans la RAM**.

- La donnée (ou instruction) est renvoyée au processeur.

---

## ⚡ Optimisation avec la TLB (Translation Lookaside Buffer)

> 💾 Comme traduire une adresse prend du temps, la MMU utilise une **mini-cache ultra rapide** appelée **TLB**.

- La TLB garde en mémoire les dernières traductions déjà faites.
- Si la MMU a besoin d’une adresse déjà traduite : **✅ elle la trouve dans la TLB = super rapide**.
- Sinon : **❌ elle doit consulter la table des pages (plus lent)**.

---

# 🧠 Comprendre la Mémoire Virtuelle, les Adresses, et le Rôle de l'OS pas à pas

## 🧩 INTRODUCTION : Le Problème à Résoudre

Imagine que tu écris un programme (comme un jeu ou une appli), et tu veux qu’il fonctionne **sans jamais se soucier de l’endroit réel où il va être placé dans la mémoire RAM**.

Mais la mémoire de l’ordinateur est **partagée avec d'autres programmes**.  
Donc, tu ne peux **pas prédire à l'avance** l'endroit réel où ton programme sera placé.

💡 **Solution inventée : les adresses virtuelles**  
👉 Ton programme aura l’impression d’être seul, dans un espace mémoire **fictif mais organisé**.

---

## 🛠️ 1. Compilation du programme

Quand tu écris du code en C, Python compilé, ou C++, ce code est **transformé** par le **compilateur** en **fichier exécutable**.

Exemples de fichiers exécutables : `monprogramme.exe`, `monprogramme.elf`, etc.

📦 Ce fichier contient :
- Du **code machine** (les instructions à exécuter)
- Des **données** (valeurs, variables, etc.)
- Et... des **adresses VIRTUELLES**.

> Ces adresses sont **fictives**.  
> Elles sont dites **"relatives"** car elles ne sont valables **que dans l’univers du programme**.

**Exemple :**
Le programme pense que la fonction `main()` est à l’adresse `0x00400000`.  
Mais dans la vraie RAM, on ne sait pas encore **où ça ira vraiment**.

---

## 📀 2. Le fichier est stocké sur le disque

Ton programme reste **sur le disque dur**.  
Rien n’est encore en mémoire RAM.  
Mais dans ce fichier, il y a déjà des **instructions et des adresses virtuelles prêtes à être utilisées.**

---

## 🚀 3. Le jour où tu lances le programme...

### A. L’OS reçoit la demande de lancement.

- Il crée un **nouveau processus**.
- Il lui donne un **espace mémoire VIRTUEL vide et propre.**
  - Exemple : de `0x00000000` à `0xFFFFFFFF`.

Chaque programme a son propre **univers de mémoire virtuelle.**
C’est comme si chacun vivait dans une **maison imaginaire à lui.**

---

## 📦 4. L’OS lit le fichier exécutable

Il regarde ce que le programme demande :

- Le code veut aller à `0x00400000`
- Les données à `0x00600000`
- La pile à la fin, vers `0xFFFF0000`

Mais... **tout ça, ce sont des adresses virtuelles.**

Alors l’OS va **préparer des zones dans la mémoire physique (la vraie RAM)**  
Mais il ne charge **rien tout de suite**. Il crée juste les **liens** entre les zones virtuelles et leur position potentielle en RAM.

> Ce travail de correspondance s’appelle le **mapping mémoire**.

---

## 🧠 5. Et quand le programme commence à s’exécuter ?

Le processeur lit la **première instruction** du programme.  
Exemple : `JMP 0x00400010` (sauter à l’adresse 0x00400010)

⚠️ Problème : le processeur ne comprend que les **adresses physiques**, pas virtuelles.

---

## 🧭 6. La MMU entre en jeu

🧠 La **MMU (Memory Management Unit)** est une **partie du processeur** qui fait une chose très importante :

> Elle **traduit les adresses virtuelles** (comme `0x00400010`)  
> en **adresses physiques réelles** dans la RAM.

Mais comment elle sait quoi traduire ? Grâce à :

- Une **table de pages** (une sorte de dictionnaire virtuel → physique)
- Et une **petite mémoire rapide appelée TLB** pour aller encore plus vite

---

## 🛑 7. Et si la page demandée n’est pas encore en RAM ?

👉 Ça provoque ce qu’on appelle un **"Page Fault"** (erreur de page)

- L’OS va chercher la **page** (extrait) dans le fichier sur le disque
- Il la **copie dans une zone libre de la RAM**
- Il **met à jour la table de pages**
- Puis il **relance** l’instruction demandée

---
# La Pagination et la Traduction d'Adresse

La **pagination** est un mécanisme utilisé dans les systèmes d’exploitation pour gérer la mémoire de manière flexible et efficace. Elle permet de diviser la mémoire virtuelle et la mémoire physique en petites unités de taille fixe appelées **pages** et **cadres**. Ce mécanisme évite la nécessité d’allouer des blocs contigus de mémoire, ce qui simplifie la gestion et optimise l’utilisation de la mémoire.

Ce document présente une explication détaillée et simple du concept de **pagination** et du processus de **traduction d'adresse**.

---

## 1. L'Espace Mémoire Virtuel et Physique

### L’espace mémoire virtuel du processus
L'espace mémoire virtuel est l'espace d’adressage que le processus utilise pour accéder à la mémoire. C'est une abstraction qui permet au processus d’utiliser un grand espace d’adresses, indépendamment de l’espace mémoire réel (physique) disponible.

### L’espace mémoire physique
La mémoire physique, souvent appelée **RAM**, est l’espace réel où les données sont stockées. Elle est également découpée en **cadres** (frames) de taille fixe, identiques à la taille des pages de l’espace virtuel.

### Le Swap
Le **swap** est un espace sur disque qui permet de stocker temporairement des pages de la mémoire virtuelle lorsque la RAM est saturée. Cela permet de libérer de l'espace en mémoire physique pour de nouvelles données.

---

## 2. Découpage en Pages et Cadres

- **Pages** : L'espace mémoire virtuel du processus est divisé en unités de taille fixe appelées pages (par exemple, 4 Ko). Chaque page est identifiée par un **numéro de page**.
  
- **Cadres (frames)** : La mémoire physique est également divisée en **cadres** de taille identique (par exemple, 4 Ko).

- Chaque **page virtuelle** peut être placée dans n'importe quel **cadre libre** de la mémoire physique.

---

## 3. Fonctionnement de la Pagination

### Lorsque le processus est créé :
1. Le système d’exploitation réserve de la mémoire pour la **table des pages**.
2. La table des pages est initialement vide, c'est-à-dire que toutes les entrées sont invalides, avec un **bit de présence** (P) à 0. Cela signifie qu'aucune page n'est encore chargée en mémoire.

### Lorsqu'un processus accède à une page pour la première fois :
- **MMU (Memory Management Unit)** : C’est un composant matériel qui traduit les adresses virtuelles en adresses physiques.
- La **table des pages** est utilisée pour trouver la correspondance entre une page virtuelle et un cadre physique en mémoire.

---

## 4. Détails du Processus de Traduction d'Adresse

Lorsque le processeur doit accéder à une adresse virtuelle, la **MMU** prend en charge la traduction de cette adresse virtuelle en une adresse physique correspondante dans la RAM.

### Etapes de la Traduction d’Adresse :

#### 1. Génération de l'Adresse Virtuelle
- Le processeur génère une **adresse virtuelle** qui contient deux parties : 
  - **Numéro de page** : qui identifie la page.
  - **Offset (ou déplacement)** : qui indique la position précise dans la page.
  
#### Exemple :
- Si la **page** est identifiée par `9` et l'**offset** par `425`, l’adresse virtuelle est calculée comme suit :
  
  **Adresse Virtuelle = (Numéro de page × Taille de la page) + Offset**
  
  En prenant un exemple avec une page de 4096 octets (4 KiB) :
  \[
  Adresse \, Virtuelle = (9 \times 4096) + 425 = 37289
  \]

#### 2. Consultation de la Table des Pages
- **MMU** utilise un **registre de la table des pages** (Page Table Register - PTR) qui contient l’adresse de la **table des pages**.
- Le processeur utilise le **numéro de page** pour localiser l’entrée correspondante dans la table des pages.

#### 3. Accès à l'Entrée de la Table des Pages
- L’entrée dans la table des pages contient des informations importantes :
  - **Bit de validité** (P) : Indique si la page est présente en mémoire.
  - **Numéro de frame** : Le cadre physique où la page est stockée en mémoire physique.

#### 4. Construction de l'Adresse Physique
- **MMU** remplace le **numéro de page** de l’adresse virtuelle par le **numéro de frame** trouvé dans la table des pages.
- Le **déplacement (offset)** reste inchangé, car il pointe toujours à la même position à l’intérieur du cadre de mémoire.
  
Ainsi, l’adresse virtuelle est transformée en une adresse physique dans la RAM.

---

## 5. Les Bits de Contrôle

Les entrées de la table des pages contiennent des bits de contrôle qui aident à gérer la mémoire efficacement.

- **Bit de présence (P)** : 
  - S'il est à `1`, la page est présente en mémoire.
  - S'il est à `0`, il y a une **exception (page fault)**. Cela signifie que la page n’est pas en mémoire et qu’elle doit être chargée depuis le disque dur (le swap).

- **Bit de modification (M)** : 
  - Mis à `1` si la page a été modifiée (écriture).
  
- **Bit de référencement (R)** : 
  - Mis à `1` si la page a été lue ou écrite.
  
---

## 6. Gestion des Exceptions et du Swap

Lorsqu’un processus tente d'accéder à une page qui n'est pas encore en mémoire (c'est-à-dire que le **bit de présence** est `0`), un **page fault** se produit. Le système d’exploitation intervient alors pour charger la page manquante depuis le disque dur (swap) vers un cadre libre en mémoire physique.

---

## 7. Exemple Pratique

Prenons un exemple simple avec un espace mémoire virtuel de 16 pages et un espace mémoire physique de 8 cadres.

1. L’adresse virtuelle `37289` (calculée dans l’exemple précédent) est décomposée :
   - **Numéro de page** = 9
   - **Offset** = 425

2. La **table des pages** indique que la page 9 est en mémoire et correspond au cadre physique `23` (en binaire : `0b10011`).

3. La MMU traduit l’adresse virtuelle en adresse physique :
   - Numéro de page 9 devient numéro de cadre 23.
   - L’adresse physique devient donc :
     \[
     Adresse \, Physique = (23 \times 4096) + 425 = 94473
     \]

---

## Conclusion

La **pagination** permet une gestion flexible et efficace de la mémoire, en découpant l’espace mémoire en petites unités appelées pages et cadres. Le système d’exploitation, à travers la MMU, utilise la **table des pages** pour traduire les adresses virtuelles en adresses physiques. Cette approche permet de gérer la mémoire de manière non contiguë et de réduire le gaspillage d’espace, tout en permettant l’utilisation du swap pour gérer les situations où la RAM est insuffisante.

  
