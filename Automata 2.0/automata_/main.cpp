#include <QCoreApplication>
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

using namespace std;

class automata
{

private:
    int _filas;
    int _columnas;
    int ** tabla_transiciones;
    unordered_map<int,string> hash_estado_final;


public:
    automata()
    {
        /*for(int i=0;i<20;++i)
        {
            for(int j=0;j<255;++j)
            {
                tabla_transiciones[i][j]=-1;
            }
        }

        hash_estado_final.insert(pair<int,string>(1,"FLOAT"));
        hash_estado_final.insert(pair<int,string>(2,"STRING"));*/
    }
    void inicializar(int filas,int columnas)
    {
        // Crea la matriz dinamica y la rellena con -2
        _filas=filas;
        _columnas=columnas;
        tabla_transiciones = new int *[filas];
        for(int i = 0; i<filas;++i)
        {
            tabla_transiciones[i] = new int[columnas];
        }
        for(int i=0;i<20;++i)
            for(int j=0;j<255;++j)
                tabla_transiciones[i][j]=-2;
    }
    bool llenar_tabla_de_transiciones(string nombre_archivo)
    {
        string cadena;
        ifstream entrada(nombre_archivo);
        if(entrada.is_open())
        {
            while(entrada.getline())
        }
        else
            return false;
    }

    void insertar_transicion(int estado,int caracter,int siguiente_estado)
    {
        //Inserta la transicion de un estado y un caracter
        tabla_transiciones[estado][caracter]=siguiente_estado;
    }
    void insertar_estado_final(int estado, string nombre)
    {
        hash_estado_final.insert(pair<int,string>(estado,nombre));
    }

    void verificar(string nombre_archivo)
    {


    }

    ~automata()
    {
        // Elimino los vectores de la matriz
        for (int i = 0; i < _filas; i++)
                delete[] tabla_transiciones[i];
        // Elimino el vector de la matriz principal
        delete[] tabla_transiciones;
    }


};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);



    return a.exec();
}
