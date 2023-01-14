#include "header.h"
#include "entidad.h"
int contador = 0;

map<string,int>entitynames;
vector<string> dataTypes = {"INT","VARCHAR","FLOAT","DATE"};

void menu()
{

    cout << " \n |--------------------------------------------| ";
    cout << " \n |     - CALCULADORA ALGEBRA RELACIONAL -     | ";
    cout << " \n |-----------------------|--------------------| ";
    cout << " \n | 1. CREAR ENTIDAD      | 2. PROYECCION      | ";
    cout << " \n | 3. SELECCION          | 4. PRODUCTO CRUZ   | ";
    cout << " \n | 5. UNION              | 6. INTERSECCION    | ";
    cout << " \n | 7. RESTA              | 8. SALIR           | ";
    cout << " \n |-----------------------|--------------------| ";
    cout << " \n ";
    puts(" \n Selecciona una opcion: ");
}


int menuTipoDatos(string dato)
{
    int opcion;
    cout << " \n |--------------------------------------------| ";
    cout << " \n |    - TIPO DE DATOS ALGEBRA RELACIONAL -    | ";
    cout << " \n |-----------------------|--------------------| ";
    cout << " \n | 1. INT                | 2. VARCHAR         | ";
    cout << " \n | 3. FLOAT              | 4. DATE            | ";
    cout << " \n |-----------------------|--------------------| ";
    cout<<" \n Selecciona una opcion para "<<dato<<": ";
    cin >> opcion;
    return opcion;
}

//  tuplas : filas,  5            atributos: columnas,    4              tabla: relacion
void selectionOption(int opcion)
{
    vector<entidad> listaEntidades;
    vector<string> tipoDatos;
    int tuplas, atributos, auxTuplas, auxAtributos, tamimpresion = 0;
    string nombreEntidad;

    switch (opcion)
    {

    case 1:

        cout << " \n Nombre de la entidad: ";
        cin >> nombreEntidad;
        transform(nombreEntidad.begin(), nombreEntidad.end(), nombreEntidad.begin(), ::toupper);

        if (entitynames.count(nombreEntidad) == 0)
        {
            entitynames.insert({nombreEntidad,contador});
            contador++;
            cout << " \n Cantidad de tuplas: ";
            cin >> tuplas;
            tuplas++;
            cout << " \n Cantidad de atributos: ";
            cin >> atributos;
            auxAtributos = atributos;
            auxTuplas = tuplas;

            // llenar la entidad
            vector<vector<string>> aux;
            vector<string> filaAtributos;

            for (int i = 0; i < tuplas; i++)
            {
                vector<string> fila;
                for (int j = 0; j < atributos; j++)
                {
                    string dato;
                    __fpurge(stdin);
                    if (auxAtributos != 0)
                    {
                        cout << " \n Nombre del atributo: ";
                        getline(cin, dato);
                        transform(dato.begin(), dato.end(), dato.begin(), ::toupper);
                        tipoDatos.pb(dataTypes[menuTipoDatos(dato) - 1]);
                        filaAtributos.pb(dato);
                        fila.pb(dato);
                        auxAtributos--;
                        tamimpresion = max(dato.size(), tamimpresion);
                        system("clear");
                    }
                    else
                    {
                        do{                        
                        cout << " \n" + filaAtributos[j] + " : ";
                        getline(cin, dato);
                        transform(dato.begin(), dato.end(), dato.begin(), ::toupper);
                        
                        }while(!flagisvalidType(dato,tipoDatos[j]));


                        fila.pb(dato);
                        tamimpresion = max(dato.size(), tamimpresion);
                        system("clear");
                    }
                }

/*
   std::string s = "10";
 
    try {
        int i = std::stoi(s);
        std::cout << i << std::endl;
    }
    catch (std::invalid_argument const &e) {
        std::cout << "Bad input: std::invalid_argument thrown" << std::endl;
    }
    catch (std::out_of_range const &e) {
        std::cout << "Integer overflow: std::out_of_range thrown" << std::endl;
    }
*/
                aux.pb(fila);

            }
            entidad ent = entidad(aux, nombreEntidad, tipoDatos);
            system("clear");
            cout << "\n";
            listaEntidades.pb(ent);


            // imprimimos las entidades
            for (int i = 0; i < listaEntidades.size(); i++)
            {
                string aux = listaEntidades[i].getNombreEntidad();
                cout << "\n\t\tNombre de la entidad: " << i + 1 << "  " << aux << endl;

                listaEntidades[i].imprimir(tamimpresion);
            }
            aux.clear();
            filaAtributos.clear();
            tipoDatos.clear();
        }
        else
        {
            cout << " \n Ya existe una entidad con ese nombre";
        }


        break;

        // listaEntidades.pb(entidad(tuplas, atributos));
    }
}

bool flagisvalidType(string dato, string tipoDatos){

    if(tipoDatos == "INT"){
        try {
            int i = stoi(dato);
            return true;
        }
        catch (invalid_argument const &e) {
            cout << " \n Bad input: std::invalid_argument thrown" <<endl;
            return false;
        }
        catch (out_of_range const &e) {
            cout << " \n Integer overflow: std::out_of_range thrown" << endl;
            return false;
        }
    }
    else if(tipoDatos == "FLOAT"){
        try {
            float i = stof(dato);
            return true;
        }
        catch (invalid_argument const &e) {
            cout << " \n Bad input: std::invalid_argument thrown" << endl;
            return false;
        }
        catch (out_of_range const &e) {
            cout << " \n Integer overflow: std::out_of_range thrown" << endl;
            return false;
        }
    }
    else if(tipoDatos == "VARCHAR"){
        return true;
    }
    else if(tipoDatos == "DATE"){
        //TO DO: USAR REGEX PARA VALIDAR FECHA
        // expresion regular para validar fecha
       const regex expRegular  ("\\d{2}[/]\\d{2}[/]\\d{4}");
       return regex_match(dato, expRegular);

    }else{
        return false;
    }
}

// Metodos de la clase entidad

entidad::entidad(vector<vector<string>> _e, string _nombre, vector<string> _tipoDatos)
{
    e = _e;
    nombreEntidad = _nombre;
    tipoDatos = _tipoDatos;
}

void entidad::imprimir(int t)
{
    
    cout << "\n";

    for (int i = 0; i < e.size(); i++)
    {

        for (int j = 0; j < e[i].size(); j++)
        {
            cout << e[i][j];
            for (int k = 0; k < 1 + (t - e[i][j].size()); k++)
            {
                cout << " ";
            }
        }
        cout << "\n";
    }
    //imprimimos los tipos de datos de la entidad
    cout << "\n";
    for (int i = 0; i < tipoDatos.size(); i++)
    {
        cout << tipoDatos[i];
        for (int k = 0; k < t - tipoDatos[i].size(); k++)
        {
            cout << " ";
        }
    }
    cout << "\n";

}

void entidad::setNombreEntidad(string _nombreEntidad)
{
    nombreEntidad = _nombreEntidad;
}

string entidad::getNombreEntidad()
{
    return nombreEntidad;
}
