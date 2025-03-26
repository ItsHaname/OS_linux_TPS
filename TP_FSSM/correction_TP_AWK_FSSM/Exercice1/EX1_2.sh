#!/bin/bash
#Affichez uniquement la première colonne (nom d’utilisateur) du 
#fichier /etc/passwd
awk ' {print $1}' /etc/passwd
