<h1 align=cnter># 🛠️ Manipulation de texte avec `awk`</h1>
<hr><hr>
<h2>📌 Ce que fait AWK :</h2>

  <p>Découpe chaque ligne en plusieurs morceaux appelés champs 🏷️.</p>

  Applique des règles pour afficher, modifier ou filtrer les données 🔍✨.

  Automatise certaines tâches comme le calcul de sommes, la recherche de mots, etc. 🧮🤖.
  📌 Principes de base d'AWK
<hr>
<h2> 1)- Les données sont organisées en deux niveaux :</h2>

1️⃣ Enregistrement = Une ligne de texte 📄 (par défaut, chaque ligne est un enregistrement).

2️⃣ Champ = Une partie de la ligne séparée par un espace ou un autre caractère ✂️📊.

🔍 Exemple :
Si on a ce fichier data.txt :
```
Alice 25 Informatique

Bob 30 Mathématiques

Charlie 22 Physique
```
👉 AWK voit ça comme :
<table border="1">
    <tr>
        <th>Enregistrement (ligne) ($0)</th>
        <th>Champ 1 ($1)</th>
        <th>Champ 2 ($2)</th>
        <th>Champ 3 ($3)</th>
    </tr>
    <tr>
        <td>Alice 25 Informatique</td>
        <td>Alice</td>
        <td>25</td>
        <td>Informatique</td>
    </tr>
    <tr>
        <td>Bob 30 Mathématiques</td>
        <td>Bob</td>
        <td>30</td>
        <td>Mathématiques</td>
    </tr>
    <tr>
        <td>Charlie 22 Physique</td>
        <td>Charlie</td>
        <td>22</td>
        <td>Physique</td>
    </tr>
</table>

<hr>
<h2> 2)-🔹 Variables Principales en AWK 🔹</h2>

AWK possède des variables intégrées qui aident à gérer et analyser les données facilement. Elles permettent de naviguer entre les lignes et les colonnes d’un fichier ou d’un flux de données. 📄➡️📊

💡 En gros : Ces variables te permettent de trouver, compter et organiser les infos dans tes fichiers ! 🚀
<h2>variables Associées aux Enregistrements :</h2>
<table border="1">
    <tr>
        <th>🏷️ Variable</th>
        <th>📝 Rôle</th>
    </tr>
    <tr>
        <td><b>RS :Record separator</b></td>
        <td>Séparateur de lignes (par défaut : <code>\n</code> ➡️ nouvelle ligne)</td>
    </tr>
    <tr>
        <td><b>NR:Number of recored</b></td>
        <td>Numéro de la ligne en cours (compteur 📊)</td>
    </tr>
    <tr>
        <td><b>ORS:output of recored</b></td>
        <td>Séparateur de lignes pour la sortie (par défaut : <code>\n</code>)</td>
    </tr>
</table>
<br>
  <h2>Variables Associées aux Champs :</h2>
<table border="1">
    <tr>
        <th>🏷️ Variable</th>
        <th>📝 Rôle</th>
    </tr>
    <tr>
        <td><b>FS:Field separator</b></td>
        <td>Séparateur des champs en entrée (par défaut : espace blanc)</td>
    </tr>
    <tr>
        <td><b>OFS:output field</b></td>
        <td>Séparateur des champs pour la sortie (par défaut : espace blanc)</td>
    </tr>
    <tr>
        <td><b>NF:Number of field</b></td>
        <td>Nombre total de champs dans la ligne actuelle 📊</td>
    </tr>
</table>
    <h2>Variables Associées au Contenu :</h2>
<table border="1">
    <tr>
        <th>🏷️ Variable</th>
        <th>📝 Rôle</th>
    </tr>
    <tr>
        <td><b>$0</b></td>
        <td>La ligne complète en cours 📜</td>
    </tr>
    <tr>
        <td><b>$1, $2, ...</b></td>
        <td>Les champs individuels (séparés par FS) 🔢</td>
    </tr>
</table>
<hr>
<h2>3)-🔍 Comparaison avec awk – Explication Simple</h2>
En AWK, les comparaisons servent à vérifier des conditions dans les données 📊.

✅ Pourquoi les utiliser ?

   🔎 Filtrer certaines lignes.

  ➕ Faire des calculs conditionnels.

  🎯 Définir des règles pour le traitement des données.
  <table border="1">
    <tr>
        <th>⚡ Type</th>
        <th>🏷️ Opérateur</th>
        <th>🔍 Exemple</th>
        <th>✨ Explication</th>
    </tr>
    <tr>
        <td><b>Égalité</b></td>
        <td>==</td>
        <td>$1 == "Hanane"</td>
        <td>Vrai si le champ 1 est <b>"Hanane"</b> 👩</td>
    </tr>
    <tr>
        <td><b>Différence</b></td>
        <td>!=</td>
        <td>$3 != 0</td>
        <td>Vrai si le champ 3 <b>n'est pas 0</b> 🔢❌</td>
    </tr>
    <tr>
        <td><b>Supérieur</b></td>
        <td>></td>
        <td>$2 > 100</td>
        <td>Vrai si le champ 2 est <b>plus grand que 100</b> 📈</td>
    </tr>
    <tr>
        <td><b>Inférieur</b></td>
        <td><</td>
        <td>$4 < 50</td>
        <td>Vrai si le champ 4 est <b>plus petit que 50</b> 📉</td>
    </tr>
    <tr>
        <td><b>Supérieur ou égal</b></td>
        <td>>=</td>
        <td>$2 >= 100</td>
        <td>Vrai si le champ 2 est <b>100 ou plus</b> 📊</td>
    </tr>
    <tr>
        <td><b>Inférieur ou égal</b></td>
        <td><=</td>
        <td>$5 <= 20</td>
        <td>Vrai si le champ 5 est <b>20 ou moins</b> 📌</td>
    </tr>
    <tr>
        <td><b>Regex (motif)</b></td>
        <td>~</td>
        <td>$1 ~ /motif/</td>
        <td>Vrai si le champ 1 <b>contient un certain mot</b> 🔤🔍</td>
    </tr>
    <tr>
        <td><b>Non-regex</b></td>
        <td>!~</td>
        <td>$1 !~ /^[A-B-0-9]/</td>
        <td>Vrai si le champ 1 <b>ne commence pas</b> par A, B ou un chiffre 🔢🚫</td>
    </tr>
</table>
EXEMPLE 
 Fichier data.txt :''
          Hanane 19 Informatique





































