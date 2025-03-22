#!/bin/bash
#Changez le séparateur de sortie pour afficher les champs $1, $3 et $6 avec -> comme délimiteur.
awk 'BEGIN {OFS="->"} {print $1,$3,$6}' /etc/passwd

