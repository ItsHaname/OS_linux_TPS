#!/bin/bash
#1.5. Affiche la deuxième colonne et la quatrième colonne uniquement.
awk 'BEGIN{OFS=" \t "}{
    
print $2,$4
 }' fichier.txt


