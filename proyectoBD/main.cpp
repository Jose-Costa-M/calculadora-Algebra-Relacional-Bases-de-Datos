#include "header.h"
#include "entidad.h"

int main(){

 int opcion;
   
   do{

    menu();
    cin >> opcion;
    selectionOption(opcion);

   }while(opcion != 8);    
    
    
    
    /*list<vector< vector<string> > entidad;> entidades;
       clase entidad: vector< vector<string> > entidad;
       list<entidad> entidades;
     */

    return 0;
}