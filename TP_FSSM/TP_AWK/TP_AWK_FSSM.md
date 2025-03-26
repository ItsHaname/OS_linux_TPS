# TP : Introduction à AWK sous Linux

## Objectif
Ce TP a pour but de vous familiariser avec la commande **AWK** en utilisant des fichiers texte et des commandes système.

---

## Exercice 1 : Affichage de contenu avec AWK

1. Affichez toutes les lignes du fichier `/etc/passwd` en utilisant AWK.
2. Affichez uniquement la première colonne (nom d’utilisateur) du fichier `/etc/passwd`.
3. Affichez le nombre total de champs dans chaque ligne du fichier `/etc/passwd`.

---

## Exercice 2 : Numérotation et modification du format de sortie

1. Affichez le numéro de ligne suivi du nom d’utilisateur dans `/etc/passwd`.
2. Changez le séparateur de sortie pour afficher les champs `$1`, `$3` et `$6` avec `->` comme délimiteur.

---

## Exercice 3 : Manipulation d’un fichier texte

Soit le fichier `fichier.txt` contenant :

```txt
Alice:25:1000:Engineer
Bob:30:1500:Doctor
Charlie:35:2000:Teacher
Diana:28:1800:Designer
Eve:40:2500:Manager
```
1)-Affichez uniquement la première colonne de chaque ligne.

2)-Affichez la première et la dernière colonne.

3)-Affichez toutes les lignes contenant "Bob".

4)-Affichez chaque ligne suivie du nombre total de champs.

5)-Calculez la somme des valeurs de la troisième colonne.

<h1>Exercice 4 : Options avancées de AWK</h1>
Utilisez l'option -Fpour définir :comme séparateur et afficher la première colonne de fichier.txt.

Utilisez l'option -vpour définir une variable AWK et afficher sa valeur.

Définissez OFScomme ->et affichez les colonnes $1, $3, et $6.

<h1>Exercice 5 : Filtrage des processus avec AWK</h1>
Affichez tous les processus sauf ceux contenant "firefox".

Affichez le processus contenant exactement deux fois la lettre "p" dans le nom de commande.

Listez les processus appartenant à "root" consommant moins de 10% de mémoire.

Affichez les processus dont le nom de commande ne commence pas par "/".

Affichez les 3 plus gros processus en termes de mémoire virtuelle (VSZ).


