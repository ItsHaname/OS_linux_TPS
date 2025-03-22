#!/bin/bash
#1.9. Affiche les lignes où le montant est exactement égal à 30.
awk '$5==30 {print $0}' fichier.txt
