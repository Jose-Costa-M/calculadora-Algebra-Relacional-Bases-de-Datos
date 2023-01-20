#include "header.h"

int contador = 0;

map<string, int> entitynames;
vector<string> dataTypes = {"INT", "VARCHAR", "FLOAT", "DATE"};

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
    cout << " \n Selecciona una opcion para " << dato << ": ";
    cin >> opcion;
    return opcion;
}

//  tuplas : filas,  5            atributos: columnas,    4              tabla: relacion
void selectionOption(int opcion, vector<entidad> &listaEntidades)
{

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
            entitynames.insert({nombreEntidad, contador});
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
                        do
                        {
                            cout << " \n" + filaAtributos[j] + " : ";
                            getline(cin, dato);
                            transform(dato.begin(), dato.end(), dato.begin(), ::toupper);

                        } while (!flagisvalidType(dato, tipoDatos[j]));

                        fila.pb(dato);
                        tamimpresion = max(dato.size(), tamimpresion);
                        system("clear");
                    }
                }

                aux.pb(fila);
            }
            
            // entidad ent = entidad(aux, nombreEntidad, tipoDatos);
            system("clear");
            cout << "\n";
            // listaEntidades.pb(ent);
            // guardamos la entidad
            listaEntidades.push_back(entidad(aux, nombreEntidad, tipoDatos, tamimpresion));

            // imprimimos las entidades
            cout << "EL tamnio de la lista de entidades es: " << listaEntidades.size() << endl;
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

    case 2:
        if (listaEntidades.size() != 0)
        {
            // PROYECION de la entidad
            cout << " \n Nombre de la entidad: ";
            cin >> nombreEntidad;
            transform(nombreEntidad.begin(), nombreEntidad.end(), nombreEntidad.begin(), ::toupper);
            auto it = entitynames.find(nombreEntidad);
            if (it != entitynames.end())
            {
                entidad ent = listaEntidades[it->second];
                vector<vector<string>> prueba = ent.proyeccion();
            }
            else
            {
                cout << " \n No existe la entidad";
            }
        }
        else
        {
            cout << " \n No hay entidades para realizar la proyeccion";
        }

    break;

    case 3:
        if (listaEntidades.size() != 0)
        {
            // PROYECION de la entidad
            cout << " \n Nombre de la entidad: ";
            cin >> nombreEntidad;
            transform(nombreEntidad.begin(), nombreEntidad.end(), nombreEntidad.begin(), ::toupper);
            auto it = entitynames.find(nombreEntidad);
            if (it != entitynames.end())
            {
                entidad ent = listaEntidades[it->second];
                vector<vector<string>> prueba = ent.proyeccion();
            }
            else
            {
                cout << " \n No existe la entidad";
            }
        }
        else
        {
            cout << " \n No hay entidades para realizar la proyeccion";
        }
    break;

    case 4:
        if (listaEntidades.size() != 0)
        {
            // producto cruz de la entidad
            cout << " \n Nombre de la entidad: ";
            cin >> nombreEntidad;
            transform(nombreEntidad.begin(), nombreEntidad.end(), nombreEntidad.begin(), ::toupper);
            auto it = entitynames.find(nombreEntidad);
            if (it != entitynames.end())
            {
                entidad ent1 = listaEntidades[it->second];
                cout << " \n Nombre de la entidad: ";
                cin >> nombreEntidad;
                transform(nombreEntidad.begin(), nombreEntidad.end(), nombreEntidad.begin(), ::toupper);
                auto it2 = entitynames.find(nombreEntidad);
                if (it2 != entitynames.end())
                {
                    entidad ent2 = listaEntidades[it2->second];
                    vector<vector<string>> prueba = ent1.productoCruz(ent2);
                }
                else
                {
                    cout << " \n No existe la entidad";
                }
            }
            else
            {
                cout << " \n No existe la entidad";
            }
        }
        else
        {
            cout << " \n No hay entidades para realizar el producto cruz";
        }

    break;
    case 5:
    //UNION
    if(listaEntidades.size() > 1){
        cout << " \n Nombre de la entidad: ";
        cin >> nombreEntidad;
        transform(nombreEntidad.begin(), nombreEntidad.end(), nombreEntidad.begin(), ::toupper);
        auto it = entitynames.find(nombreEntidad);
        if (it != entitynames.end())
        {
            entidad ent1 = listaEntidades[it->second];
            cout << " \n Nombre de la entidad: ";
            cin >> nombreEntidad;
            transform(nombreEntidad.begin(), nombreEntidad.end(), nombreEntidad.begin(), ::toupper);
            auto it2 = entitynames.find(nombreEntidad);
            if (it2 != entitynames.end())
            {
                entidad ent2 = listaEntidades[it2->second];
                vector<string> tipo1 = ent1.getTipoDatos();
                vector<string> tipo2 = ent2.getTipoDatos();
                for(int i = 0; i < tipo1.size(); i++){
                    if(tipo1[i] != tipo2[i]){
                        cout << " \n No se puede realizar la union de las entidades";
                        break;
                    }
                }
                vector<vector<string>> prueba = ent1.unionEntidades(ent2);
            }
            else
            {
                cout << " \n No existe la entidad";
            }
        }
        else
        {
            cout << " \n No existe la entidad";
        }
    }else{
        cout << " \n No hay entidades para realizar la union";
    }    
    
    break;

    case 6:
    //INTERSECCION
    if(listaEntidades.size() > 1){
        cout << " \n Nombre de la entidad: ";
        cin >> nombreEntidad;
        transform(nombreEntidad.begin(), nombreEntidad.end(), nombreEntidad.begin(), ::toupper);
        auto it = entitynames.find(nombreEntidad);
        if (it != entitynames.end())
        {
            entidad ent1 = listaEntidades[it->second];
            cout << " \n Nombre de la entidad: ";
            cin >> nombreEntidad;
            transform(nombreEntidad.begin(), nombreEntidad.end(), nombreEntidad.begin(), ::toupper);
            auto it2 = entitynames.find(nombreEntidad);
            if (it2 != entitynames.end())
            {
                entidad ent2 = listaEntidades[it2->second];
                vector<string> tipo1 = ent1.getTipoDatos();
                vector<string> tipo2 = ent2.getTipoDatos();
                for(int i = 0; i < tipo1.size(); i++){
                    if(tipo1[i] != tipo2[i]){
                        cout << " \n No se puede realizar la interseccion de las entidades";
                        break;
                    }
                }
                vector<vector<string>> prueba = ent1.interseccionEntidades(ent2);
            }else
            {
                cout << " \n No existe la entidad";
            }
        }
        else
        {
            cout << " \n No existe la entidad";
        }
    }else{
        cout << " \n No hay entidades para realizar la interseccion";
    }    
    

    break;

    case 7:
    //DIFERENCIA    

    if(listaEntidades.size() > 1){
        cout << " \n Nombre de la entidad: ";
        cin >> nombreEntidad;
        transform(nombreEntidad.begin(), nombreEntidad.end(), nombreEntidad.begin(), ::toupper);
        auto it = entitynames.find(nombreEntidad);
        if (it != entitynames.end())
        {
            entidad ent1 = listaEntidades[it->second];
            cout << " \n Nombre de la entidad: ";
            cin >> nombreEntidad;
            transform(nombreEntidad.begin(), nombreEntidad.end(), nombreEntidad.begin(), ::toupper);
            auto it2 = entitynames.find(nombreEntidad);
            if (it2 != entitynames.end())
            {
                entidad ent2 = listaEntidades[it2->second];
                vector<string> tipo1 = ent1.getTipoDatos();
                vector<string> tipo2 = ent2.getTipoDatos();
                for(int i = 0; i < tipo1.size(); i++){
                    if(tipo1[i] != tipo2[i]){
                        cout << " \n No se puede realizar la diferencia de las entidades";
                        break;
                    }
                }
                vector<vector<string>> prueba = ent1.diferenciaEntidades(ent2);
            }else
            {
                cout << " \n No existe la entidad";
            }
        }
        else
        {
            cout << " \n No existe la entidad";
        }
    }else{
        cout << " \n No hay entidades para realizar la diferencia";
    }
    break;


    default:
        cout << " \n Opcion no valida";

    }


    
}

void imprimirVectores(vector<vector<string>> prueba){
    // imprimir la prueba
    cout << " \n Proyeccion de la entidad:" << endl;
    for (int i = 0; i < prueba.size(); i++)
    {
        for (int j = 0; j < prueba[i].size(); j++)
        {
            cout << prueba[i][j] << " ";
        }
        cout << endl;
    }

}

bool flagisvalidType(string dato, string tipoDatos)
{

    if (tipoDatos == "INT")
    {
        try
        {
            int i = stoi(dato);
            return true;
        }
        catch (invalid_argument const &e)
        {
            cout << " \n Bad input: std::invalid_argument thrown" << endl;
            return false;
        }
        catch (out_of_range const &e)
        {
            cout << " \n Integer overflow: std::out_of_range thrown" << endl;
            return false;
        }
    }
    else if (tipoDatos == "FLOAT")
    {
        try
        {
            float i = stof(dato);
            return true;
        }
        catch (invalid_argument const &e)
        {
            cout << " \n Bad input: std::invalid_argument thrown" << endl;
            return false;
        }
        catch (out_of_range const &e)
        {
            cout << " \n Integer overflow: std::out_of_range thrown" << endl;
            return false;
        }
    }
    else if (tipoDatos == "VARCHAR")
    {
        return true;
    }
    else if (tipoDatos == "DATE")
    {
        // TO DO: USAR REGEX PARA VALIDAR FECHA
        //  expresion regular para validar fecha
        const regex expRegular("\\d{2}[/]\\d{2}[/]\\d{4}");
        return regex_match(dato, expRegular);
    }
    else
    {
        return false;
    }
}

// Metodos de la clase entidad

entidad::entidad(vector<vector<string>> _e, string _nombre, vector<string> _tipoDatos, int _tamimpresion)
{
    e = _e;
    nombreEntidad = _nombre;
    tipoDatos = _tipoDatos;
    tamano = _tamimpresion;
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
    // imprimimos los tipos de datos de la entidad
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

vector<vector<string>> entidad::proyeccion()
{

    vector<string> atributosProyeccion;
    vector<vector<string>> proyeccion;
    vector<int> posicionesAtributos;
    int aux;
    cout << " \n Cantidad de atributos a proyectar: ";
    cin >> aux;
    __fpurge(stdin);
    for (int i = 0; i < aux; i++)
    {
        string atributo;
        cout << " \n Nombre del atributo a proyectar: ";
        getline(cin, atributo);
        __fpurge(stdin);
        transform(atributo.begin(), atributo.end(), atributo.begin(), ::toupper);
        atributosProyeccion.pb(atributo);
    }

    cout << "\n";

    /*
       0.- IDALUMNO   APELLIDOA
       1.-
       2.-

    */
    // columnas
    vector<string> aux1;
    for (int j = 0; j < e[0].size(); j++)
    {

        if (find(atributosProyeccion.begin(), atributosProyeccion.end(), e[0][j]) != atributosProyeccion.end())
        {
            cout << e[0][j];
            aux1.pb(e[0][j]);
            posicionesAtributos.pb(j);
          
        }
    }
    proyeccion.pb(aux1);
    cout << "\n";

    // proyectamos los datos de la entidad con las posiciones de los atributos a proyectar
    for (int i = 1; i < e.size(); i++)
    {
        vector<string> aux2;
        for (int j = 0; j < posicionesAtributos.size(); j++)
        {
            cout << e[i][posicionesAtributos[j]];
            aux2.pb(e[i][posicionesAtributos[j]]);
            // guardamos los datos de la proyeccion
            // proyeccion[i].pb(e[i][posicionesAtributos[j]]);
            
        }
        proyeccion.pb(aux2);
        cout << "\n";
    }

    getchar();
    getchar();
    // imprimimos los tipos de datos de la entidad
    cout << "\n";
    for (int i = 0; i < tipoDatos.size(); i++)
    {
        cout << tipoDatos[i];
      
    }
    cout << "\n";

    return proyeccion;
}

vector<vector<string>> entidad::seleccion()
{

    vector<string> atributosSeleccion;
    vector<string> condiciones;
    vector<string> valores;
    vector<vector<string>> Seleccion;
    vector<int> posicionesAtributos;
    int aux;
    cout << " \n Cantidad de atriubutos para las condiciones: ";
    cin >> aux;
    __fpurge(stdin);
    for (int i = 0; i < aux; i++)
    {
        string atributo, condicion, valor;
        cout << " \n Nombre del atributo a seleccionar: ";
        getline(cin, atributo);
        __fpurge(stdin);
        transform(atributo.begin(), atributo.end(), atributo.begin(), ::toupper);
        atributosSeleccion.pb(atributo);
        cout << " \n Condicion: ";
        getline(cin, condicion);
        __fpurge(stdin);
        transform(condicion.begin(), condicion.end(), condicion.begin(), ::toupper);
        condiciones.pb(condicion);
        cout << " \n Valor: ";
        getline(cin, valor);
        __fpurge(stdin);
        transform(valor.begin(), valor.end(), valor.begin(), ::toupper);
        valores.pb(valor);
    }

    cout << "\n";

    return Seleccion;
}

vector<vector<string>> entidad::productoCruz(entidad e2)
{
    vector<vector<string>> productoCruz;
    vector<string> aux;
    for (int i = 0; i < e[0].size(); i++)
    {
        aux.pb(e[0][i]);
    }
    for (int i = 0; i < e2.e[0].size(); i++)
    {
        aux.pb(e2.e[0][i]);
    }
    productoCruz.pb(aux);

    for (int i = 1; i < e.size(); i++)
    {
        for (int j = 1; j < e2.e.size(); j++)
        {
            vector<string> aux2;
            for (int k = 0; k < e[i].size(); k++)
            {
                aux2.pb(e[i][k]);
            }
            for (int k = 0; k < e2.e[j].size(); k++)
            {
                aux2.pb(e2.e[j][k]);
            }
            productoCruz.pb(aux2);
        }
    }

    // imprimimos el producto cruz
    for (int i = 0; i < productoCruz[0].size(); i++)
    {
        cout << productoCruz[0][i];
        
    }
    cout << "\n";
    for (int i = 1; i < productoCruz.size(); i++)
    {
        for (int j = 0; j < productoCruz[i].size(); j++)
        {
            cout << productoCruz[i][j];
         
        }
        cout << "\n";
    }

    getchar();
    return productoCruz;
}

vector<string> entidad::getTipoDatos(){
    return tipoDatos;
}


vector< vector<string> > entidad::unionEntidades(entidad e2){
    vector<vector<string>> unionEntidades;
    vector<string> aux;
    if(e[0].size() != e2.e[0].size()){
        cout << "No se puede realizar la union de las entidades";
        return unionEntidades;
    }else{

    for (int i = 0; i < e[0].size(); i++)
    {
        aux.pb(e[0][i]);
    }
    unionEntidades.pb(aux);

    for (int i = 1; i < e.size(); i++)
    {
        vector<string> aux2;
        for (int j = 0; j < e[i].size(); j++)
        {
            aux2.pb(e[i][j]);
        }
        unionEntidades.pb(aux2);
    }
    for (int i = 1; i < e2.e.size(); i++)
    {
        vector<string> aux2;
        for (int j = 0; j < e2.e[i].size(); j++)
        {
            aux2.pb(e2.e[i][j]);
        }
        unionEntidades.pb(aux2);
    }

    // imprimimos la union de las entidades
    for (int i = 0; i < unionEntidades[0].size(); i++)
    {
        cout << unionEntidades[0][i];
     
    }
    cout << "\n";
    for (int i = 1; i < unionEntidades.size(); i++)
    {
        for (int j = 0; j < unionEntidades[i].size(); j++)
        {
            cout << unionEntidades[i][j];
           
        }
        cout << "\n";
    }
    }



    getchar();
    return unionEntidades;
}

vector<vector<string>> entidad::interseccionEntidades(entidad e2){
    vector<vector<string>> interseccionEntidades;
    vector<string> aux;
    if(e[0].size() != e2.e[0].size()){
        cout << "No se puede realizar la interseccion de las entidades";
        return interseccionEntidades;
    }else{

    for (int i = 0; i < e[0].size(); i++)
    {
        aux.pb(e[0][i]);
    }
   
    interseccionEntidades.pb(aux);

    for (int i = 1; i < e.size(); i++)
    {
        for (int j = 1; j < e2.e.size(); j++)
        {
            vector<string> aux2;
            vector<string> aux3;
            for (int k = 0; k < e[i].size(); k++)
            {
                aux2.pb(e[i][k]);
            }
            for (int k = 0; k < e2.e[j].size(); k++)
            {
                aux3.pb(e2.e[j][k]);    
            }
            if(aux2 == aux3){
                interseccionEntidades.pb(aux2);
            }
        }
    }

    // imprimimos la interseccion de las entidades
    for (int i = 0; i < interseccionEntidades[0].size(); i++)
    {
        cout << interseccionEntidades[0][i];
       
    }
    cout << "\n";
    for (int i = 1; i < interseccionEntidades.size(); i++)
    {
        for (int j = 0; j < interseccionEntidades[i].size(); j++)
        {
            cout << interseccionEntidades[i][j];
          
        }
        cout << "\n";
    }
    }

    return interseccionEntidades;
}

vector<vector<string>> entidad::diferenciaEntidades(entidad e2){

    vector<vector<string>> diferenciaEntidades;
    vector<string> aux;
    int cont=0;
    if(e[0].size() != e2.e[0].size()){
        cout << "No se puede realizar la diferencia de las entidades";
        return diferenciaEntidades;
    }else{

    for (int i = 0; i < e[0].size(); i++)
    {
        aux.pb(e[0][i]);
    }
    diferenciaEntidades.pb(aux);
    

    for(int i = 1; i < e.size(); i++){
            vector<string> aux2;
            for (int k = 0; k < e[i].size(); k++)
            {
                aux2.pb(e[i][k]);
            }

            for(int z = 0; z < e2.e.size(); z++){
                if(aux2 != e2.e[z]){
                    cont++;
                }
            }
            if( cont == e2.e.size())
                diferenciaEntidades.pb(aux2);
        
            cont = 0;
            aux2.clear();
    }

    // imprimimos la diferencia de las entidades
    for (int i = 0; i < diferenciaEntidades[0].size(); i++)
    {
        cout << diferenciaEntidades[0][i];
       
    }
    cout << "\n";
    for (int i = 1; i < diferenciaEntidades.size(); i++)
    {
        for (int j = 0; j < diferenciaEntidades[i].size(); j++)
        {
            cout << diferenciaEntidades[i][j];
          
        }
        cout << "\n";
    }
    }

    return diferenciaEntidades;

}
