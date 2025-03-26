#!/bin/bash
#Affichez le numéro de ligne suivi du nom d’utilisateur dans /etc/passwd.
awk ' BEGIN{FS=":"}
      {print  NR ,$1} ' /etc/passwd
