#!/bin/bash
#3.2. Calcule le total des montants pour chaque utilisateur.

echo "Veuillez saisir le nom de l'utilisateur :"
read user

awk -v user="$user" '
  BEGIN {
    somme = 0;
    utilisateur_trouve = 0;  # Flag pour savoir si l'utilisateur a été trouvé
  }

  $2 == user {
    somme += $5;
    utilisateur_trouve = 1;  # Si on trouve l'utilisateur, on met à 1
  }

  END {
    if (utilisateur_trouve == 0) {
      print "Je ne connais pas cet utilisateur !!";
    } else {
      print "La somme des montants de l'utilisateur", user, "est", somme;
    }
  }
' fichier.txt

