#include<io.h>
#include<stdio.h>
#include<winsock2.h>
#include "Server_lib.c"
#pragma comment(lib,"ws2_32.lib") //Winsock Library

    int main(int argc , char *argv[]){
        printf("\nInitialisation de la socket ");
        if (WSAStartup(MAKEWORD(2,2),&wsa) != 0){
            printf("Failed. Error Code : %d",WSAGetLastError());
            return 1;
        }
        printf("Socket initialisée\n");

        if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET){
            printf("Could not create socket : %d" , WSAGetLastError());
        }

        printf("Socket creée\n");
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = inet_addr ("127.0.0.1");
        server.sin_port = htons(8888);

        if( bind(s ,(struct sockaddr *)&server , sizeof(server)) == SOCKET_ERROR){
            printf("Bind failed with error code : %d" , WSAGetLastError());
        }

        puts("\nBind done\n");
        listen(s , 3);

        while (1){
            puts("En atente de connection  ...");
            c = sizeof(struct sockaddr_in);
            client_socket = accept(s , (struct sockaddr *)&client, &c);   /* en attente d'une socket client */
            if (client_socket == INVALID_SOCKET){
                printf("accept failed with error code : %d" , WSAGetLastError());
            }
            else{
                puts("Connection acceptee");
                if((recv_size = recv(client_socket , client_reply , 2000 , 0)) == SOCKET_ERROR)
                    puts("Pas de reponse du client");
                else{
                        client_reply[recv_size] = '\0';
                }

                char temp[2];
                strncpy(temp, client_reply, 1);
                choice = atoi(temp);
                switch( choice){
                    case 1 :
                            getComp();
                            break;
                    case 2 :
                            addComp();
                            break ;
                    case 3 :
                            deleteComp();
                            break ;
                    case 4 :
                            listComp();
                            break;
                    case 5 :
                            setComp();
                            break;
                    case 6 :
                            checkCompStock();
                            break;
                    case 7 :
                            addStockComp();
                            break;
                    case 8 :
                            saleComp();
                            break;
                    case 9 :
                            quit();
                            break;
                }
            }

            close(client_socket);
            puts("Connection terminee");
        }
        return 0;
    }
