#!/bin/bash
#2.1. Remplace "Login" par "Connected" dans toute la ligne.
awk '{ gsub(/Login/,"Connected",$4 ); print $0}' fichier.txt
