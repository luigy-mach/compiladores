#ifndef TABLA_SLR
#define TABLA_SLR


#include <iostream>
#include <unordered_map>
#include<fstream>
#include<vector>
#include<queue>

#include <stack>


using namespace std;

#include "defines_includes.hpp"


#define TABLA class_hash2::type1
#define FILA class_hash2::type0


struct class_hash2{
  typedef std::unordered_map< string,string > type0;
  typedef std::unordered_map< string,type0 > type1;
};

class tabla_anagra{
  TABLA _tabla;
  stack<char> entrada;
  stack<char> salida;
  void leer_archivo(TABLA& t,string archivo);
  void insertar(TABLA& t,queue<string> cabecera, queue<string>& fila);
  void convertir_a_vector(string str, string delimitador,vector<string>& vec);
  void convertir_a_cola(string str,string delimitador,queue<string>& vec);

public:
    tabla_anagra(){}
<<<<<<< HEAD
    void inicializar_tabla();
=======
    void inicializar_tabla(){
      leer_archivo(_tabla,"new/ANAGRA_TABLE_FULL.csv");
    }
    void convertir_a_vector(string str, string delimitador,vector<string>& vec);
    void convertir_a_cola(string str,string delimitador,queue<string>& vec);
>>>>>>> 01bf27a079175456578839226d36ee6740b9d06e
    string consultar(string fila, string columna);
    void imprimir_tabla(TABLA& t);

};


#endif //TABLA_SLR
