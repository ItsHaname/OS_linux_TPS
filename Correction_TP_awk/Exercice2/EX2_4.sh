#!/bin/bash
#2.4. Remplace "2025-01-03" par "2025-02-01" dans la date.
awk '{gsub(/2025-01-03/, "2025-02-01",$3) ;print $0 }' fichier.txt
