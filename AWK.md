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
        <td> $1 == "Hanane"</td>
        <td>Vrai si le champ 1 est <b>"Hanane"</b> 👩</td>
    </tr>
    <tr>
        <td><b>Différence</b></td>
        <td>!=</td>
        <td> $3 != 0 </td>
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
<h3>🔹 Condition IF en <code>awk</code></h3>
<p>En <code>awk</code>, on peut exécuter une action seulement si une <strong>condition</strong> est vraie.</p>

<h4>📌 Syntaxe :</h4>
<pre>
if (condition) {
   action
} else if (autre_condition) {
   autre_action
} else {
   action_par_defaut
}
</pre>

<h4>🔹 Exemple avec <code>awk</code> :</h4>
<p><strong>Commande :</strong></p>
<pre>
awk '{if ($2 > 50) print $0}' fichier.txt
</pre>

<h4>📝 Exemple de fichier :</h4>
<pre>
Alice 45
Bob 60
Charlie 30
David 80
</pre>

<h4>🖥 Résultat :</h4>
<pre>
Bob 60
David 80
</pre>

<p>✅ Bob (60) et David (80) sont affichés car leur 2ᵉ valeur est &gt; 50.</p>
<p>❌ Alice (45) et Charlie (30) ne sont pas affichés car leur 2ᵉ valeur est ≤ 50.</p>
<hr><hr><hr>
    <h2>Syntaxe générale de awk</h2>

<p><code>awk [options] '[BEGIN {init_actions}] [pattern {main_actions}] [END {final_actions}]' fichier</code></p>

<ul>
  <li><strong>BEGIN {init_actions}</strong> : Actions exécutées avant de lire les données.</li>
  <li><strong>pattern {main_actions}</strong> : Conditions et actions principales appliquées sur chaque ligne.</li>
  <li><strong>END {final_actions}</strong> : Actions exécutées après le traitement des lignes.</li>
  <li><strong>fichier</strong> : Nom du fichier d’entrée à traiter.</li>
</ul>

<h2>Options principales de awk</h2>

<table>
  <thead>
    <tr>
      <th>Option</th>
      <th>Description</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>-F "&lt;séparateur&gt;"</code></td>
      <td>
        <ol>
          <li>Spécifie le caractère ou la chaîne utilisée comme séparateur pour diviser une ligne en champs.</li>
          <li>La variable <code>FS</code> peut être utilisée à la place de l'option <code>-F</code> pour définir le séparateur des champs dans awk.</li>
        </ol>
      </td>
    </tr>
  </tbody>
</table>
<hr><<nr>


  <h2>Explications supplémentaires :</h2>
    <p>
        - <strong>BEGIN</strong> : Exécute des actions avant de lire les données. Par exemple, il peut être utilisé pour initialiser une variable ou afficher un message d'introduction.
    </p>
    <p>
        - <strong>END</strong> : Exécute des actions après avoir traité toutes les lignes de données. Ce bloc est souvent utilisé pour afficher un résumé ou effectuer des calculs sur les données lues.
    </p>
    <p>
        <strong>Exemple complet :</strong> 
        <code>awk 'BEGIN {print "Début du traitement"; somme=0} {somme += $2} END {print "Somme totale:", somme; print "Fin du traitement"}' fichier.txt</code>
    </p>


<hr><hr>
<title>Explications de la commande awk - BEGIN et END</title>
</head>
<body>
    <h1>Explications sur les blocs BEGIN et END en awk</h1>

   <h2>1. Bloc BEGIN</h2>
    <p>
        Le bloc <strong>BEGIN</strong> est exécuté avant de commencer à traiter les données. Il permet de faire des préparations comme :
        <ul>
            <li>Initialiser des variables.</li>
            <li>Définir des séparateurs (ex. : FS pour l'entrée, OFS pour la sortie).</li>
            <li>Afficher un message d'introduction ou effectuer des préparations nécessaires.</li>
        </ul>
    </p>

  <h3>Exemples :</h3>
    <ul>
        <li>
            <strong>Exemple 1 : Message d’introduction</strong><br>
            <code>awk 'BEGIN {print "Début du traitement"} {print $1}' fichier.txt</code><br>
            <strong>Résultat</strong> : Avant de lire les données, affiche le message "Début du traitement".
        </li>
        <li>
            <strong>Exemple 2 : Définir un séparateur</strong><br>
            <code>awk 'BEGIN {FS=","} {print $1, $2}' fichier.csv</code><br>
            <strong>Résultat</strong> : Définit la virgule comme séparateur pour un fichier CSV et affiche les 1er et 2ᵉ champs.
        </li>
    </ul>

   
  <h2>2. Bloc END</h2>
    <p>
        Le bloc <strong>END</strong> est exécuté après avoir traité toutes les lignes des données. Il est utile pour :
        <ul>
            <li>Calculer et afficher des totaux ou des moyennes.</li>
            <li>Afficher un message de clôture.</li>
            <li>Résumer les résultats du traitement.</li>
        </ul>
    </p>

  <h3>Exemple complet avec BEGIN et END :</h3>
    <code>
        awk 'BEGIN {print "Début du traitement"; somme=0} <br>
        {somme += $2} <br>
        END {print "Somme totale :", somme; print "Fin du traitement"}' fichier.txt
    </code>
    <p><strong>Explication :</strong> 
        <ul>
            <li>Avant de commencer le traitement des données, le bloc <code>BEGIN</code> affiche "Début du traitement" et initialise la variable <code>somme</code> à 0.</li>
            <li>Lors du traitement des lignes du fichier, le <code>somme</code> est mis à jour en ajoutant les valeurs du 2ᵉ champ de chaque ligne.</li>
            <li>Une fois le fichier traité, le bloc <code>END</code> affiche la somme totale des valeurs et "Fin du traitement".</li>
        </ul>
    </p>
    <hr><hr><hr>
    <h1>Actions Principales et Patterns d'AWK</h1>

<h2>1. Lecture 📖</h2>
<p>La lecture avec AWK consiste à parcourir chaque ligne d'un fichier sans sélectionner de parties spécifiques.</p>
<p>Syntaxe : <code>awk '{print $0}' <fichier></code></p>
<p><b>Exemple 1 :</b></p>
<pre><code>awk '{print $0}' fichier.txt</code></pre>
<p>Résultat : Affiche chaque ligne du fichier sans modification.</p>
<p><b>Exemple 2 :</b></p>
<pre><code>awk '{print NR, $0}' fichier.txt</code></pre>
<p>Résultat : Affiche chaque ligne du fichier avec sa numérotation (NR = numéro de ligne).</p>

<h2>2. Extraction de Colonnes 🧑‍💻</h2>
<p>Cette action permet d'extraire des champs spécifiques d'une ligne dans un fichier.</p>
<p>Syntaxe : <code>awk '{print $1, $2}' <fichier></code> pour afficher les premiers champs par exemple.</p>
<p><b>Exemple 1 :</b></p>
<pre><code>awk '{print $1, $3}' fichier.txt</code></pre>
<p>Résultat : Affiche le premier et le troisième champ des lignes.</p>
<p><b>Exemple 2 :</b></p>
<pre><code>awk '{a = $1; b = $3; resultat = a + b; print resultat}' fichier.txt</code></pre>
<p>Résultat : Additionne le premier et le troisième champ, puis affiche le résultat.</p>

<h2>3. Extraction de Lignes 🚀</h2>
<p>Cette commande permet de filtrer les lignes qui répondent à des critères spécifiques.</p>
<p>Syntaxe : <code>awk '<condition> {action}' <fichier></code></p>
<p><b>Exemple 1 : Recherche par Motif 🕵️‍♂️</b></p>
<pre><code>awk '/motif/' fichier.txt</code></pre>
<p>Résultat : Affiche toutes les lignes contenant le motif "motif".</p>

<p><b>Exemple 2 : Condition numérique ⚖️</b></p>
<pre><code>awk '$3 > 100 {print $0}' fichier.txt</code></pre>
<p>Résultat : Affiche les lignes où la valeur du 3ᵉ champ est supérieure à 100.</p>

<p><b>Exemple 3 : Plage de lignes 📅</b></p>
<pre><code>awk 'NR >= 2 && NR <= 5 {print $0}' fichier.txt</code></pre>
<p>Résultat : Affiche les lignes entre la deuxième et la cinquième.</p>

<h2>4. Utilisation des Séparateurs 🔄</h2>
<p>Les séparateurs définissent comment les champs dans chaque ligne sont divisés (par exemple, les virgules pour les fichiers CSV).</p>
<p>Syntaxe avec variables : <code>awk 'BEGIN {FS=","} {print $1}' fichier.csv</code></p>
<p><b>Exemple 1 : Séparateurs personnalisés 🛠️</b></p>
<pre><code>awk 'BEGIN {FS=","; OFS=":"} {print $1, $2}' data.csv</code></pre>
<p>Résultat : Sépare les champs avec une virgule et affiche les résultats avec un séparateur de deux-points.</p>

<p><b>Exemple 2 : Utilisation du séparateur `|` 📊</b></p>
<pre><code>awk 'BEGIN {FS="|"} {print $1, $2}' fichier.txt</code></pre>
<p>Résultat : Sépare les champs avec la barre verticale et affiche les premiers champs.</p>

<h2>5. Recherche et Filtrage 🔍</h2>
<p>AWK permet de rechercher et de filtrer les lignes d'un fichier selon des motifs ou des conditions définies.</p>

<h3>5.1 Recherche par Motifs (Regex) 🧩</h3>
<p>Syntaxe : <code>awk '/<motif>/' fichier</code></p>
<p><b>Exemple :</b></p>
<pre><code>awk '/Hanane/' fichier.txt</code></pre>
<p>Résultat : Sélectionne toutes les lignes où le mot "Hanane" apparaît.</p>

<h3>5.2 Filtrage avec Conditions ⚙️</h3>
<p>Syntaxe : <code>awk '$1 ~ /[A-Z]/ && $3 > 50 {print $0}' fichier.txt</code></p>
<p><b>Exemple 1 : Filtrage avec plusieurs conditions 🧑‍🔬</b></p>
<pre><code>awk '$1 ~ /^[A-Z]/ && $3 > 50 {print $0}' fichier.txt</code></pre>
<p>Résultat : Affiche les lignes où le premier champ commence par une lettre majuscule ET le troisième champ est supérieur à 50.</p>

<p><b>Exemple 2 : Exclure certains mots 🛑</b></p>
<pre><code>awk '$2 !~ /Developer/ && $3 > 75 {print $1, $2}' data.txt</code></pre>
<p>Résultat : Affiche les lignes où le deuxième champ ne contient pas "Developer" et où le troisième champ est supérieur à 75.</p>

<h1>6.4.6 Substitution et Manipulation de Contenu (<code>gsub</code>)</h1>

   <h2>6.4.6.1 Description 📝</h2>
    <p><strong>awk</strong> permet de <strong>remplacer</strong> des motifs spécifiques dans un fichier, de <strong>modifier</strong> des séparateurs, ou de <strong>transformer</strong> des lignes grâce à la fonction <code>gsub</code>. Cette fonction est similaire à celle de <code>sed</code> pour faire des remplacements globaux.</p>

  <h2>6.4.6.2 Syntaxe 🔧</h2>
    <pre><code>gsub(/&lt;motif&gt;/, "&lt;remplacement&gt;", [&lt;variable&gt;])</code></pre>
    <ul>
        <li><strong>/&lt;motif&gt;/</strong> : C'est l'expression régulière ou le motif que vous voulez remplacer.</li>
        <li><strong>"&lt;remplacement&gt;"</strong> : C'est ce qui va remplacer le motif dans la ligne ou dans une variable.</li>
        <li><strong>&lt;variable&gt;</strong> : La variable où faire le remplacement. Par défaut, c'est <code>$0</code> (la ligne entière), mais vous pouvez spécifier un champ particulier comme <code>$1</code>, <code>$2</code>, etc.</li>
    </ul>

   <h2>6.4.6.3 Exemple 1 🔄</h2>
    <p><strong>Commande :</strong></p>
    <pre><code>awk '$2 == "S3" {gsub(/MIP/, "INFO", $3); print $0}' fichier.txt</code></pre>
    <p><strong>Explication :</strong></p>
    <ul>
        <li>Cette commande remplace toutes les occurrences de <code>"MIP"</code> par <code>"INFO"</code> dans le <strong>troisième champ</strong> (<code>$3</code>) des lignes où le <strong>deuxième champ</strong> (<code>$2</code>) est égal à <code>"S3"</code>.</li>
        <li><strong>Résultat</strong> : Si une ligne dans le fichier contient <code>S3</code> dans le deuxième champ et <code>MIP</code> dans le troisième champ, cette ligne verra <code>"MIP"</code> remplacé par <code>"INFO"</code>.</li>
    </ul>
    <p><strong>Exemple de résultat :</strong></p>
    <pre><code>ID1 S3 INFO data1
ID2 S3 INFO data2</code></pre>

  <h2>6.4.7 Transformation de Texte 🔄</h2>

   <h3>6.4.7.1 Principales Fonctions de Transformation 🧑‍💻</h3>

   <p><strong>1. <code>toupper()</code> - Convertir en majuscules 🌟</strong></p>
    <p>Cette fonction convertit une chaîne ou un champ en <strong>majuscule</strong>.</p>
    <pre><code>awk '{print toupper($1)}' fichier.txt</code></pre>
    <p><strong>Explication :</strong> Cette commande affiche le <strong>premier champ</strong> de chaque ligne en majuscules.</p>

   <p><strong>2. <code>tolower()</code> - Convertir en minuscules 🔡</strong></p>
    <p>Convertit une chaîne ou un champ en <strong>minuscule</strong>.</p>
    <pre><code>awk '{print tolower($2)}' fichier.txt</code></pre>
    <p><strong>Explication :</strong> Cette commande affiche le <strong>deuxième champ</strong> de chaque ligne en minuscules.</p>

   <p><strong>3. <code>length()</code> - Longueur d'une chaîne 📏</strong></p>
    <p>Retourne la <strong>longueur</strong> d'une chaîne ou d'un champ.</p>
    <pre><code>awk '{print $1, length($1)}' fichier.txt</code></pre>
    <p><strong>Explication :</strong> Cette commande affiche le <strong>premier champ</strong> suivi de sa <strong>longueur</strong>.</p>

  <h3>6.4.7.2 Opérations Arithmétiques 🔢</h3>
    <p><strong>awk</strong> peut aussi faire des <strong>calculs arithmétiques</strong> sur des données textuelles, ce qui permet de réaliser des opérations comme la somme, la multiplication, etc.</p>

   <h4>Opérateurs de Calcul 💡</h4>
    <table border="1">
        <thead>
            <tr>
                <th><strong>Opérateur</strong></th>
                <th><strong>Description</strong></th>
                <th><strong>Exemple</strong></th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td>+</td>
                <td>Addition</td>
                <td><code>$1 + $6</code></td>
            </tr>
            <tr>
                <td>-</td>
                <td>Soustraction</td>
                <td><code>$2 - $4</code></td>
            </tr>
            <tr>
                <td>*</td>
                <td>Multiplication</td>
                <td><code>$1 * $3</code></td>
            </tr>
            <tr>
                <td>/</td>
                <td>Division</td>
                <td><code>$5 / $2</code></td>
            </tr>
            <tr>
                <td>%</td>
                <td>Modulo</td>
                <td><code>$1 % $3</code></td>
            </tr>
        </tbody>
    </table>

  <h3>6.4.7.3 Exemple 2 🔢</h3>
    <p><strong>Commande :</strong></p>
    <pre><code>awk '{somme += $2} END {print "Somme totale :", somme}' fichier.txt</code></pre>
    <p><strong>Explication :</strong></p>
    <ul>
        <li>Cette commande calcule la <strong>somme</strong> de toutes les valeurs dans le <strong>deuxième champ</strong> de chaque ligne.</li>
        <li>La variable <code>somme</code> accumule les valeurs au fur et à mesure.</li>
        <li><strong>Bloc END</strong> : Quand toutes les lignes sont traitées, le total est affiché.</li>
    </ul>
    <p><strong>Exemple de résultat :</strong></p>
    <pre><code>Somme totale : 1234</code></pre>
<h1>6.5 Exemples Pratiques de Awk</h1>

    <h2>6.5.1 Fichier d’entrée data.txt 📋</h2>
    <pre><code>Nom,Age,Rôle,Salaire
Ali,25,Developer,5000
Omar,30,Designer,4000
Hamza,22,Analyst,4500
Mehdi,35,Manager,6000
Hassan,28,Developer,5500</code></pre>

    <h2>6.5.2 Commande awk 🖥️</h2>
    <pre><code>awk 'BEGIN {
FS = ","; OFS = "\t";
print "Nom", "Rôle", "Salaire (avec Bonus)", "Statut"
}
NR > 1 {
bonus = ($3 == "Developer") ? $4 * 0.1 : 0;
new_salary = $4 + bonus;
statut = ($4 > 5000 || bonus > 0) ? "Eligible" : "Non Eligible";
print toupper($1), $3, new_salary, statut
}
END {
print "Traitement des données terminé."
}' data.txt</code></pre>

  <h2>6.5.3 Explications 📝</h2>

   <h3>a. Bloc BEGIN 🔧</h3>
    <p>Dans ce bloc, on prépare le traitement des données :</p>
    <ul>
        <li><strong>FS</strong> : Définit le séparateur d'entrée comme une virgule (,).</li>
        <li><strong>OFS</strong> : Définit le séparateur de sortie comme une tabulation (\t).</li>
        <li><strong>Affichage des en-têtes</strong> : On affiche les noms des colonnes (Nom, Rôle, Salaire (avec Bonus), Statut).</li>
    </ul>

  <h3>b. Traitement principal 🔄</h3>
    <ul>
        <li><strong>Condition 1</strong> : Si le rôle (<code>$3</code>) est "Developer", un bonus de 10 % du salaire (<code>$4</code>) est ajouté.</li>
        <li><strong>Condition 2</strong> : Le statut est déterminé. Si le salaire est supérieur à 5000 ou s'il y a un bonus, la personne est "Eligible", sinon "Non Eligible".</li>
    </ul>

   <h3>c. Bloc END 🔚</h3>
    <p>À la fin, un message est affiché pour indiquer la fin du traitement des données.</p>

  <h2>6.5.4 Résultat 📊</h2>
    <pre><code>Nom       Rôle      Salaire (avec Bonus)    Statut
ALI       Developer  5500.0                    Eligible
OMAR      Designer   4000.0                    Non Eligible
HAMZA     Analyst    4500.0                    Non Eligible
MEHDI     Manager    6000.0                    Eligible
HASSAN    Developer  6050.0                    Eligible
Traitement des données terminé</code></pre>


































