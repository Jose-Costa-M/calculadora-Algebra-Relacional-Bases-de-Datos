#include "header.h"

class entidad{

   //ATRIBUTOS
   private:
    vector<vector<string>> e;

   private:
   string nombreEntidad; 

   private:
   vector<string> tipoDatos;
   
   //METODOS
   public:
   entidad(vector<vector<string>> _e, string _nombre, vector<string> _tipoDatos);
   void imprimir(int t);
   void setNombreEntidad(string nombreEntidad);
   string getNombreEntidad();


};

