#!/bin/bash
#2.3. Remplace "Bob" par "Robert" uniquement dans le nom de l’utilisateur.
awk '{gsub( /Bob/, "Rober" , $2 );print $0}' fichier.txt
