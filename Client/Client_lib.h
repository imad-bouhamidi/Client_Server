#ifndef CLIENT_LIB_H_INCLUDED
#define CLIENT_LIB_H_INCLUDED

/*** Fichier Client_lib.h contient les prototypes des fonctions qui sont implementer dans le fichier Client_lib.c ***/


/**Prototype de la fonciton Menu**/
void Menu();

/**Prototype de la fonction setConnection**/
void setConnection();

/**Prototype de la fonciton socketConnection**/
int  socketConnection();

/**Prototype de la fonction consulter composant**/
void getComp();

/**Prototype de la fonction ajouter composant**/
void addComp();

/**Prototype de la fonction supprimer composant**/
void deleteComp();

/**Prototype de la fonction ajouter une liste de composant**/
void listComp();

/**Prototype de la fonction modifier un composant**/
void setComp();

/**Prototype de la fonction consulter le stock d'un composant**/
void checkCompStock();

/**Prototype de la fonction ajouter le stock d'un composant**/
void addStockComp();

/**Prototype de la fonction vendre un composant**/
void saleComp();

/**Prototype de la fonction quitter le programme**/
void quit();

#endif // CLIENT_LIB_H_INCLUDED
