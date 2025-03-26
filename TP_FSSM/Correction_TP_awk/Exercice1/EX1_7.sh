#!/bin/bash
#1.7. Affiche les lignes où la date est 2025-01-03
awk '{if($3 == "2025-01-03" ) print $0}' fichier.txt

