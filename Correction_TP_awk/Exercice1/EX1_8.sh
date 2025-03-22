#!/bin/bash
#1.8. Affiche les lignes où le montant est supérieur à 10 et l’action est Logout.
awk '{if($5 >= 10 && $4 == "Logout") print $0}' fichier.txt
