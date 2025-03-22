#!/bin/bash
#1.6. Affiche les lignes où le montant est supérieur à 20.
awk '{if($5 > 20) print $0}' fichier.txt

