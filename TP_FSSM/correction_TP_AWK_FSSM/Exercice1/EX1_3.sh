#!/bin/bash
#Affichez le nombre total de champs dans chaque ligne du fichier /etc/passwd.
awk 'BEGIN{ FS= ":" }
     { somme+=NF }
  END { print "la somme total de champs est :",somme} ' /etc/passwd

