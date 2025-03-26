#!/bin/bash
#4.2. Modifie la colonne Montant pour ajouter 5 à chaque valeur.
awk '{ $5 = $5+5 ; print$0} ' fichier.txt
