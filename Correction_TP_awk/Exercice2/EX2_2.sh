#!/bin/bash
#2.2. Remplace "Logout" par "Disconnected" uniquement dans la colonne Action.
awk '{gsub(/Logout/,"Disconnected",$4);print $0}' fichier.txt
