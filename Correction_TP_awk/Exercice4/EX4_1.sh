#!/bin/bash
#4.1. Ajoute une nouvelle colonne "Status" qui contient "Success" si le montant est supérieur à 20 et "Failure" sinon.
awk '{if($5>20){
          print $0 ; "success"
}else{
       print $0 ; "Failure"
}
} ' fichier.txt
     
