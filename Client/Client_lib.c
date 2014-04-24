#include <stdio.h>
#include <conio.h>
#include <winsock2.h>
#include <time.h>
#include "Client_lib.h"
#pragma comment (lib, "ws2_32.lib")

/** Imad BOUHAMIDI et Driss BERRADA Gouzi **/
/*** Fichier Client_lib.c contient les prototypes des fonctions qui sont declarer dans le fichier Client_lib.h ***/

    WSADATA wsa;
    SOCKET sck;
    struct sockaddr_in ip_info;
    char server_reply[2000];
    char msg[2000];
    int recv_size;

    /** Code source de la fonction Menu **/
    void Menu(){
        system("cls"); //clear screen
        printf("\n");
        printf("\t1) Consulter un composant \n");
        printf("\t2) Ajouter un composant \n");
        printf("\t3) Supprimer un composant \n");
        printf("\t4) Ajouter une liste de composant\n");
        printf("\t5) Modifier un composant \n");
        printf("\t6) Consulter le stock d'un composant \n");
        printf("\t7) Ajouter le stock d'un composant\n");
        printf("\t8) Vendre un composant \n");
        printf("\t9) Quitter \n\n\n");
        printf("\t\t\t\n");
        printf("\t\t\t\n");
        printf("\t\t\t veillez saisir un choix  : \t");
    }

    /** Code source de la fonction setConnection**/
    //make client connect to the local host and listen in port 8888
    void setConnection(){
        if (WSAStartup (MAKEWORD (2,2), &wsa) == INVALID_SOCKET)
            printf ("WSA error\n");
        else
            if ((sck = socket (AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
                printf ("Socket error\n");
            else{
                ip_info.sin_addr.s_addr = inet_addr("127.0.0.1");
                ip_info.sin_family = AF_INET;
                ip_info.sin_port = htons (8888);
            }
    }

    /** Code source de la fonction socketConnection **/
    int  socketConnection(){
        if (connect (sck, (struct sockaddr *)&ip_info, sizeof (ip_info)) < 0){
                printf ("\nPas de connexion\n");
                return 0;
        }
        else
            printf ("\nSocket connectée\n");
    }

    /** Code source de la fonction getComp **/
    void getComp(){
        system("cls"); //clear screen
        char compInfo[100];
        printf("\nEntrez le code du composant a consulter\t");
        scanf("%s", &compInfo);
        strcpy(msg, "1_");
        strcat(msg, compInfo);
        send(sck, msg, strlen(msg), 0);

        /* socket connectée : en attente de réception du message du serveur */
        if((recv_size = recv(sck , server_reply , 2000 , 0)) == SOCKET_ERROR)
            puts("Pas de reponse du serveur");
        else {
            server_reply[recv_size] = '\0'; /* Afficher le message du serveur */
            puts(server_reply);
        }
        system("pause");
    }

    /** Code source de la fonction addComp **/
    void addComp(){
        system("cls"); //clear screen
        char compInfo[100];
        printf("Entrer les informations du nouveau composant en respectant cette forme : \n");
        printf("code_description_famille_prix_qStock_qVendu\n");
        scanf("%s", &compInfo);
        strcpy(msg, "2_");
        strcat(msg, compInfo);
        send(sck , msg , strlen(msg) , 0);

        /* socket connectée : en attente de réception du message du serveur */
        if((recv_size = recv(sck , server_reply , 2000 , 0)) == SOCKET_ERROR)
            puts("Pas de reponse du serveur");
        else {
            server_reply[recv_size] = '\0'; /* Afficher le message du serveur */
            puts(server_reply);
        }
        system("pause");
    }

    /** Code source de la fonction deleteComp **/
    void deleteComp(){
        system("cls"); //clear screen
        char compInfo[100];
        printf("veillez entrer le code du composant a suprimer\n");
        scanf("%s", &compInfo);
        strcpy(msg, "3_");
        strcat(msg, compInfo);
        send(sck , msg , strlen(msg) , 0);

        /* socket connectée : en attente de réception du message du serveur */
        if((recv_size = recv(sck , server_reply , 2000 , 0)) == SOCKET_ERROR)
            puts("Pas de reponse du serveur");
        else {
            server_reply[recv_size] = '\0'; /* Afficher le message du serveur */
            puts(server_reply);
        }
        system("pause");
    }

    /** Code source de la fonction listComp **/
    void listComp(){
        system("cls"); //clear screen
        char compInfo[1000], temp[1000];
        int k = 0, i;
        temp[0] = '\0';
        printf("entrer le nombre de composant a saisire\n");
        scanf("%s", &compInfo);
        k = atoi(compInfo);
        strcpy(msg,"4_");
        for (i = 0; i < k; i++){
           printf("Entrer le  composant %d avec cette structure\n", i+1);
           printf("code_description_famille_prix_qStock_qVendu\n");
           scanf("%s", &compInfo);
           strcat(compInfo, "_");
           strcat(temp, compInfo);
        }
        strcat(msg, temp);
        send(sck , msg , strlen(msg) , 0);


        /* socket connectée : en attente de réception du message du serveur */
        if((recv_size = recv(sck , server_reply , 2000 , 0)) == SOCKET_ERROR)
            puts("Pas de réponse du serveur");
        else {
            server_reply[recv_size] = '\0'; /* Afficher le message du serveur */
            puts(server_reply);
        }
            system("pause");
    }

    /** Code source de la fonction setComp **/
    void setComp(){
        system("cls"); //clear screen
        char compInfo[100];
        printf("entrer le code du composant a modifier\n");
        printf("suivi de la modification sous la forme de cette forme\n");
        printf("ancien code_code m_description m_famille m_prix m_qStock m_qVendu m\n");
        scanf("%s", &compInfo);

        strcpy(msg, "5_");
        strcat(msg, compInfo);
        send(sck , msg , strlen(msg) , 0);

        /* socket connectée : en attente de réception du message du serveur */
        if((recv_size = recv(sck , server_reply , 2000 , 0)) == SOCKET_ERROR)
            puts("Pas de reponse du serveur");
        else {
            server_reply[recv_size] = '\0'; /* Afficher le message du serveur */
            puts(server_reply);
        }
        system("pause");
    }

    /** Code source de la fonction checkCompStock **/
    void checkCompStock(){
        system("cls"); //clear screen
        char compInfo[100];
        printf("Entrer le code du composant a consulter son stock \n");
        scanf("%s", &compInfo);
        strcpy(msg, "6_");
        strcat(msg, compInfo);
        send(sck , msg , strlen(msg) , 0);

        /* socket connectée : en attente de réception du message du serveur */
        if((recv_size = recv(sck , server_reply , 2000 , 0)) == SOCKET_ERROR)
            puts("Pas de reponse du serveur");
        else {
            server_reply[recv_size] = '\0'; /* Afficher le message du serveur */
            puts(server_reply);
        }
        system("pause");
    }

    /** Code source de la fonction addStockComp **/
    void addStockComp(){
        system("cls"); //clear screen
        char compInfo[100];
        printf("entrer le code du composant suivi du stock \n");
        printf("sous la forme\n code_stock \n");
        scanf("%s", &compInfo);
        strcpy(msg, "7_");
        strcat(msg, compInfo);
        send(sck , msg , strlen(msg) , 0);

        /* socket connectée : en attente de réception du message du serveur */
        if((recv_size = recv(sck , server_reply , 2000 , 0)) == SOCKET_ERROR)
            puts("Pas de reponse du serveur");
        else {
            server_reply[recv_size] = '\0'; /* Afficher le message du serveur */
            puts(server_reply);
        }
        system("pause");
    }

    /** Code source de la fonction saleComp **/
    void saleComp(){
        system("cls"); //clear screen
        char compInfo[100];
        printf("Entrer le code du composant a vendre \n");
        printf("suivi du quantite a vendre \n");
        printf("sous la forme\n code_qVendue \n");
        scanf("%s", &compInfo);
        strcpy(msg, "8_");
        strcat(msg, compInfo);
        send(sck , msg , strlen(msg) , 0);

        /* socket connectée : en attente de réception du message du serveur */
        if((recv_size = recv(sck , server_reply , 2000 , 0)) == SOCKET_ERROR)
            puts("Pas de reponse du serveur");
        else {
            server_reply[recv_size] = '\0'; /* Afficher le message du serveur */
            puts(server_reply);
        }
        system("pause");
    }

    /** Code source de la fonction quit **/
    void quit(){
        system("cls");
        strcpy(msg, "9");
        send(sck , msg , strlen(msg) , 0);
        system("pause");
    }
