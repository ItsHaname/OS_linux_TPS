#!/bin/bash
#2.5. Remplace "MIP" par "INFO" dans toute la ligne. (Bien que "MIP" ne soit pas présent, essaye de l’imaginer dans un autre fichier).
awk '{gsub(/MIP/,"INFO",$2) ; print $0}' fichier
