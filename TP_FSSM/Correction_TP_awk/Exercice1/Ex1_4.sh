#!/bin/bash
#1.4. Affiche les lignes où l’action est Login
awk '{if($4=="Login") print  $0}' fichier.txt

###ou bien awk '$4 ~ /Login/ { print  $0}' fichier.txt###
