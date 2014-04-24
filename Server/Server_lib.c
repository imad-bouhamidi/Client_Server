#include<io.h>
#include<stdio.h>
#include<winsock2.h>
#include "Server_lib.h"
#pragma comment(lib,"ws2_32.lib") //Winsock Library

/** Imad BOUHAMIDI et Driss BERRADA Gouzi **/
/*** Fichier Client_lib.c contient les prototypes des fonctions qui sont declarer dans le fichier Client_lib.h ***/

    WSADATA wsa ;
    SOCKET s , client_socket;
    struct sockaddr_in server , client;
    int c, cnt;
    char msg [2000];
    int recv_size;
    char client_reply[2000];
    int choice;
    composant compArray[10];
    int j;

    /** Code source de la fonction getComp **/
    void getComp(){
        system("cls"); //clear screen
        int i;
        char *tempPointer;
        char *separator = { "_" };
        char *tempBuf;
        tempBuf = strdup (client_reply);
        tempPointer = strtok( tempBuf, separator  );// premier appel,
        while( tempPointer != NULL ){
            tempPointer = strtok( NULL, separator  );// Cherche les autres separator
            if ( tempPointer != NULL ){
                for(i=0;i<10;i++){
                    if (atoi(tempPointer) == compArray[i].code){
                        sprintf(msg,"\n Le composant est: %s de %s son prix est %.2f dh ", compArray[i].famille, compArray[i].description, compArray[i].prix);
                        break;
                    }
                    else sprintf(msg,"\n Le composant n'existe pas ");
                }
            }
        }

        send(client_socket , msg , strlen(msg) , 0);
        char date [70];
        char heure [80];
        _strtime(heure);
        _strdate(date);
        printf("\n\n\n\t***** %s %s : Client %s connecte \n", date, heure, inet_ntoa(server.sin_addr));
        printf("\t*****   *******consulter un composant****** \n");
    }

    /** Code source de la fonction addComp **/
    void addComp(){
        system("cls"); //clear screen
        j++;
        int i=0;
        char *tempPointer;
        char *separator = { "_" };
        char *tempBuf;
        tempBuf = strdup (client_reply);
        tempPointer = strtok( tempBuf, separator  ); /** to separate the string received from the client by the function strtok **/
        while( tempPointer != NULL ){
             tempPointer = strtok( NULL, separator );
             if ( tempPointer != NULL ){
                i++;
                switch(i){
                    case 1 : compArray[j].code = atoi(tempPointer);
                    case 2 : strcpy(compArray[j].description, tempPointer);
                    case 3 : strcpy(compArray[j].famille, tempPointer);
                    case 4 : compArray[j].prix = atoi(tempPointer);
                    case 5 : compArray[j].qStock = atoi(tempPointer);
                    case 6 : compArray[j].qVendu = atoi(tempPointer);
                }
             }
        }

        sprintf(msg,"\n composant ajoute avec succes  ");
        send(client_socket , msg , strlen(msg) , 0);
        char date [70];
        char heure [80];
        _strtime(heure);
        _strdate(date);
        printf("\n\n\n\t***** %s %s : Client %s connecte \n",date,heure,inet_ntoa(server.sin_addr));
        printf("\t***** ********ajouter un composant *******\n");
    }

    /** Code source de la fonction deleteComp **/
    void deleteComp(){
        system("cls"); //clear screen
        int i;
        char *tempPointer;
        char *separator = { "_" };
        char *tempBuf;
        tempBuf = strdup (client_reply);
        tempPointer = strtok( tempBuf, separator  );
        while( tempPointer != NULL ){
            tempPointer = strtok( NULL, separator  );
            if ( tempPointer != NULL ){
                for(i=0;i<10;i++){
                    if (atoi(tempPointer) == compArray[i].code){
                        compArray[i].code = '\0';
                        sprintf(msg,"\nle composant a bien ete suprimer ");
                    }
                }
            }
        }

        send(client_socket , msg , strlen(msg) , 0);

        char date [70];
        char heure [80];
        _strtime(heure);
        _strdate(date);
        printf("\n\n\n\t***** %s %s : Client %s connecte \n",date,heure,inet_ntoa(server.sin_addr));
        printf("\t***** *******consulter un composant******* \n");
    }

    /** Code source de la fonction listComp **/
    void listComp(){
        j++;
        system("cls"); //clear screen
        int i=0;
        char *tempPointer;
        char *separator = { "_" };
        char *tempBuf;
        tempBuf = strdup (client_reply);
        tempPointer = strtok( tempBuf, separator  );// premier appel,
        while( tempPointer != NULL ){
            tempPointer = strtok( NULL, separator  );// Cherche les autres separator
            if ( tempPointer != NULL ){
               i++;
               switch(i){
                 case 1 :
                        compArray[j].code = atoi(tempPointer);
                        break;
                 case 2 :
                        strcpy(compArray[j].description, tempPointer);
                        break;
                 case 3 :
                        strcpy(compArray[j].famille, tempPointer);
                        break;
                 case 4 :
                        compArray[j].prix = atoi(tempPointer);
                        break;
                 case 5 :
                        compArray[j].qStock = atoi(tempPointer);
                        break;
                 case 6 :
                        compArray[j].qVendu = atoi(tempPointer);
                        i=0;
                        j++;
                        break;
               }
             }
         }
                   //envoie du message
        sprintf(msg,"\n les composants sont ajoutes avec succes ");
        send(client_socket , msg , strlen(msg) , 0);

        //affichage du serveur
        char date [70];
        char heure [80];
        _strtime(heure);
        _strdate(date);
        printf("\n\n\n\t***** %s %s : Client %s connecte, \n", date, heure, inet_ntoa(server.sin_addr));
        printf("\t*****requete demandee : ajouter une liste de composant \n");
    }

    /** Code source de la fonction setComp **/
    void setComp(){
        system("cls"); //clear screen
        int i;
        char *tempPointer;
        char *separator = { "_" };
        char *tempBuf;
        tempBuf = strdup (client_reply);
        tempPointer = strtok( tempBuf, separator  );// premier appel,
        tempPointer = strtok( NULL, separator  );
        for(i = 0; i < 20; i++){
          if (atoi(tempPointer) == compArray[i].code)
             break;
        }
        if(i == 20)
        sprintf(msg, "\nle composant n'existe pas ");
        else{
           i = 0;
           while( tempPointer != NULL ){
                tempPointer = strtok( NULL, separator  );// Cherche les autres separator
                if ( tempPointer != NULL ){
                   i++;
                   switch(i){
                         case 1 :
                                compArray[j].code = atoi(tempPointer);
                                break;
                         case 2 :
                                strcpy(compArray[j].description, tempPointer);
                                break;
                         case 3 :
                                strcpy(compArray[j].famille, tempPointer);
                                break;
                         case 4 :
                                compArray[j].prix = atoi(tempPointer);
                                break;
                         case 5 :
                                compArray[j].qStock = atoi(tempPointer);
                                break;
                         case 6 :
                                compArray[j].qVendu = atoi(tempPointer);
                                sprintf(msg, "\nle composant est modifie ");
                                break;
                    }
                }
            }
        }
        //envoie du message
        send(client_socket , msg , strlen(msg) , 0);

        //affichage du serveur
        char date [70];
        char heure [80];
        _strtime(heure);
        _strdate(date);
        printf("\n\n\t***** %s %s : Client %s connecte, \n", date, heure, inet_ntoa(server.sin_addr));
        printf("\t*****requete demandee : modifier un composant \n");
    }

    /** Code source de la fonction checkCompStock **/
    void checkCompStock(){
        system("cls"); //clear screen
        int i;
        char *tempPointer;
        char *separator = { "_" };
        char *tempBuf;
        tempBuf = strdup (client_reply);
        tempPointer = strtok( tempBuf, separator  );// premier appel,
        while( tempPointer != NULL ) {
           tempPointer = strtok( NULL, separator  );// Cherche les autres separator
           if ( tempPointer != NULL ){
               for(i = 0; i < 20; i++){
                  if (atoi(tempPointer) == compArray[i].code){
                    int d;
                    d = compArray[i].qStock - compArray[i].qVendu;
                    sprintf(msg, "\nle stock du composant est %d ",d);
                    break;
                  }
                  else sprintf(msg, "\nle composant n'existe pas ");
               }
           }
        }
            //envoie du message
        send(client_socket , msg , strlen(msg) , 0);

        //affichage du serveur
        char date [70];
        char heure [80];
        _strtime(heure);
        _strdate(date);
        printf("\n\n\t***** %s %s : Client %s connecte, \n", date, heure, inet_ntoa(server.sin_addr));
        printf("\t*****requete demandee : consulter le stock d'un composant \n");
     }

    /** Code source de la fonction addStockComp **/
    void addStockComp(){
        system("cls"); //clear screen
        int i;
        char *tempPointer;
        char *separator = { "_" };
        char  *tempBuf;
        tempBuf = strdup (client_reply);
        tempPointer = strtok( tempBuf, separator  );// premier appel,
        tempPointer = strtok( NULL, separator  );
        for(i = 0; i < 20; i++){
          if (atoi(tempPointer) == compArray[i].code)
             break;
        }
        if (i == 20)
        sprintf(msg, "\nle composant n'existe pas ");
        else{
            tempPointer = strtok( NULL, separator  );
            compArray[i].qStock = compArray[i].qStock + atoi(tempPointer);
            sprintf(msg,"\nle stock est ajouté ");
        }

        //envoie du message
        send(client_socket , msg , strlen(msg) , 0);

        //affichage du serveur
        char date [70];
        char heure [80];
        _strtime(heure);
        _strdate(date);
        printf("\n\n\t***** %s %s : Client %s connecte, \n", date, heure, inet_ntoa(server.sin_addr));
        printf("\t*****requete demandee : ajouter le stock d'un composant \n");
    }

    /** Code source de la fonction saleComp **/
    void saleComp(){
        system("cls"); //clear screen
        int i;
        char *tempPointer;
        char *separator = { "_" };
        char *tempBuf;
        char *receivedString = client_reply;
        tempBuf = strdup (receivedString);
        tempPointer = strtok( tempBuf, separator  );// premier appel,
        tempPointer = strtok( NULL, separator  );
        for(i = 0; i < 20; i++){
          if (atoi(tempPointer) == compArray[i].code)
             break;
        }
        if (i==20)
            sprintf(msg, "\nle composant n'existe pas ");
        else{
            tempPointer = strtok( NULL, separator  );
            compArray[i].qVendu = compArray[i].qVendu + atoi(tempPointer);
            sprintf(msg,"\nle composant est vendu ");
        }

        //envoi message
        send(client_socket , msg , strlen(msg) , 0);

        //affichage du serveur
        char date [70];
        char heure [80];
        _strtime(heure);
        _strdate(date);
        printf("\n\n\t***** %s %s : Client %s connecte, \n", date, heure, inet_ntoa(server.sin_addr));
        printf("\t*****requete demandee : vendre un composant \n");
    }

    /** Code source de la fonction quit **/
    void quit(){
        system("cls");
        printf("\n\n\tclient deconecte\t");
    }
