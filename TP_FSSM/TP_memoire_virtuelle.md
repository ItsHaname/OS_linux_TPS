![image](https://github.com/user-attachments/assets/d47ea656-6405-4bd3-bee1-8e82171f5132)
# Exercice 1 - Gestion Mémoire
- Question : Pour un processus P demandant 80K, quel trou (T1/T2/T3) est choisi par :
  
  • First-fit ?
  
  • Best-fit ?
  
  • Worst-fit ?
  éponse Logique :

# 🔴<span style="color:red; font-size:32px">CORRECTION🔴</span>

    On suppose que les tailles des trous sont :

        T1 : 300K (700-400)

        T2 : 100K (1000-900)

        T3 : 600K (2000-1400)

    Le processus demande 80K.

Analyse par algorithme :

    First-fit (Premier trou adapté)

        Parcourt la mémoire du début jusqu'à trouver le premier espace libre ≥ 80K

        Séquence : T1 (300K) → trouvé dès le premier trou

        Choix : T1

    Best-fit (Meilleure adaptation)

        Cherche le plus petit trou ≥ 80K (pour minimiser le gaspillage)

        Comparaison :

            T1 : 300K

            T2 : 100K

            T3 : 600K

        Le plus petit trou suffisant est T2 (100K)

        Choix : T2

    Worst-fit (Pire adaptation)

        Cherche le plus grand trou ≥ 80K (pour laisser le maximum d'espace restant)

        Comparaison :

            T1 : 300K

            T2 : 100K

            T3 : 600K

        Le plus grand trou est T3 (600K)

        Choix : T3


  ![image](https://github.com/user-attachments/assets/8b89e9c9-4d7c-48cb-a455-beb342a793c3)
# 🧠 Correction : Algorithmes de Remplacement de Pages

## 📌 Énoncé
**Système :**
- 3 cadres de pages physiques
- Séquence de référence : `7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1`

**À calculer :**
- Nombre de défauts de page pour FIFO
- Nombre de défauts de page pour LRU

---

## 🔄 Méthode FIFO (First-In-First-Out)

### Principe :
La page la **plus ancienne** (première entrée) est remplacée.

### Exécution pas à pas :

| Référence | Cadre 1 | Cadre 2 | Cadre 3 | Défaut ? | Pages en mémoire (ordre d'arrivée) |
|-----------|---------|---------|---------|----------|------------------------------------|
| 7         | 7       | -       | -       | ✔️       | [7]                                |
| 0         | 7       | 0       | -       | ✔️       | [7, 0]                             |
| 1         | 7       | 0       | 1       | ✔️       | [7, 0, 1]                          |
| 2         | **2**   | 0       | 1       | ✔️ (Remplaçe 7) | [0, 1, 2]                     |
| 0         | 2       | 0       | 1       | ✖️       | [0, 1, 2]                          |
| 3         | **3**   | 0       | 1       | ✔️ (Remplaçe 2) | [0, 1, 3]                     |
| ...       | ...     | ...     | ...     | ...      | ...                                |

**Total défauts FIFO :** 12/20

---

## 🔄 Méthode LRU (Least Recently Used)

### Principe :
La page **la moins récemment utilisée** est remplacée.

### Exécution pas à pas :

| Référence | Cadre 1 | Cadre 2 | Cadre 3 | Défaut ? | Ordre d'utilisation (récent → ancien) |
|-----------|---------|---------|---------|----------|----------------------------------------|
| 7         | 7       | -       | -       | ✔️       | [7]                                    |
| 0         | 7       | 0       | -       | ✔️       | [0, 7]                                 |
| 1         | 7       | 0       | 1       | ✔️       | [1, 0, 7]                              |
| 2         | **2**   | 0       | 1       | ✔️ (Remplaçe 7) | [2, 1, 0]                         |
| 0         | 2       | 0       | 1       | ✖️       | [0, 2, 1]                              |
| ...       | ...     | ...     | ...     | ...      | ...                                    |

**Total défauts LRU :** 9/20

---

## 📊 Comparaison des Résultats

| Algorithme | Défauts de page | Taux de défauts |
|------------|-----------------|-----------------|
| FIFO       | 12              | 60%             |
| LRU        | 9               | 45%             |

---

## 💡 Explications Clés

1. **Défaut de page** = ✔️ quand la page n'est pas déjà en mémoire
2. **FIFO** :
   - Conserve l'ordre d'arrivée
   - "Première entrée, première sortie"
   - Souffre du problème de Belady (peut augmenter les défauts avec plus de cadres)

3. **LRU** :
   - Optimal pour 3 cadres dans ce cas
   - Nécessite un suivi de l'historique d'utilisation
   - Meilleure performance que FIFO ici

---

## 🖥️ Simulation Complète (Extrait)

**Séquence complète FIFO :**






  
