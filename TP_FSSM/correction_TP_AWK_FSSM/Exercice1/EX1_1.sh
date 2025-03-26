#!/bin/bash
#Affichez toutes les lignes du fichier /etc/passwd en utilisant AWK.
awk ' {print} ' /etc/passwd
#ou bien  awk '{ print $0 } ' /etc/passwd
