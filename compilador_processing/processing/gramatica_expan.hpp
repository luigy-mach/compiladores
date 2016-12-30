#ifndef GRAMATICA_EXPAN
#define GRAMATICA_EXPAN


#include <iostream>
#include <unordered_map>
#include<fstream>
#include<vector>
#include<queue>
#include <stack>


#include "defines_includes.hpp"


using namespace std;



#define TABLA1 class_hash1::type1
#define FILA1 class_hash1::type0


struct class_hash1{
  typedef std::unordered_map< string,string > type0;
  typedef std::unordered_map< string,type0 > type1;
};


class gramatica_expan{
  TABLA1 _tabla;
  void leer_archivo(TABLA1& t,string archivo);
  void insertar(TABLA1& t, queue<string>& fila);

public:
    gramatica_expan(){}
    void inicializar();
    void convertir_a_vector(string str, string delimitador,vector<string>& vec);
    void convertir_a_cola(string str,string delimitador,queue<string>& vec);
    string obtener_estado(string num_reducir);
    int obtener_estado_num(string num_reducir);
    void imprimir_tabla(TABLA1& t);

};

#endif //GRAMATICA_EXPAN
