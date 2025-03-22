#!/bin/bash
#1.3. Affiche les lignes où le nom est Alice.

awk '{if ($2 == "Alice" )print $0}' fichier.txt
# ou bien sans utuliser if awk '$0~ /Alice/ {print $0}' fichier.txt

