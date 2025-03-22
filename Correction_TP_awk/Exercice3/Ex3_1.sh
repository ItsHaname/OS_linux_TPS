#!/bin/bash
#3.1. Calcule la somme des montants pour chaque action (Login/Logout).
## la somme  des montants des Login
awk 'BEGIN{
     printf "la somme des montants des login et logout \n";
         sommeIN=0;
         sommeOUT=0;
    } 
           #pattern
{ 
         if ($4 == "Login"){
          sommeIN += $5;
       }else if($4 == "Logout" ){  
            sommeOUT += $5;
    } 
    
}
     END{
      print"la somme des montatnt des login",sommeIN;
      print"la somme des montatnt des logout" ,sommeOUT;
  } 
    ' fichier.txt
