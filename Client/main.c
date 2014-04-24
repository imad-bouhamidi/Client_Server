#include <stdio.h>
#include <conio.h>
#include <winsock2.h>
#include <time.h>
#include "Client_lib.c"
#pragma comment (lib, "ws2_32.lib")

    int main (int argc, char *argv []){
        int choice;
        do{
           Menu();
           scanf("%d", &choice);
           switch(choice){
                    case 1 :
                            setConnection();
                            socketConnection();
                            getComp();
                            break ;
                    case 2 :
                            setConnection();
                            socketConnection();
                            addComp();
                            break ;
                    case 3 :
                            setConnection();
                            socketConnection();
                            deleteComp();
                            break ;
                    case 4 :
                            setConnection();
                            socketConnection();
                            listComp();
                            break ;
                    case 5 :
                            setConnection();
                            socketConnection();
                            setComp();
                            break ;
                    case 6 :
                            setConnection();
                            socketConnection();
                            checkCompStock();
                            break ;
                    case 7 :
                            setConnection();
                            socketConnection();
                            addStockComp();
                            break;
                    case 8 :
                            setConnection();
                            socketConnection();
                            saleComp();
                            break ;
                    case 9 :
                            setConnection();
                            socketConnection();
                            quit();
                            close(sck);
                            printf("Merci!");
                            break ;
                    default : printf(" veuillez choisir un numero parmi ceux affichés \n");
                    getchar();
                    system("PAUSE");
            }

        }while(choice != 9);


         printf("Connexion etablie et terminee");
         getch();
    }
