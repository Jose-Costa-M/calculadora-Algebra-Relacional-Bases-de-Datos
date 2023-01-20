#include "header.h"

int main(){

//vector de entidades
vector<entidad> listaEntidades;
 int opcion;
   
   do{
    
    
    menu();
    cin >> opcion;
    selectionOption(opcion, listaEntidades);

   }while(opcion != 8);    
    
    
    
    /*list<vector< vector<string> > entidad;> entidades;
       clase entidad: vector< vector<string> > entidad;
       list<entidad> entidades;
     */

    return 0;
}
