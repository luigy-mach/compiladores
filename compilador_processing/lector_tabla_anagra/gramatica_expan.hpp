#ifndef GRAMATICA_EXPAN
#define GRAMATICA_EXPAN


#include <iostream>
#include <unordered_map>
#include<fstream>
#include<vector>
#include<queue>
#include <stack>


using namespace std;

#define MSJ_ERROR "err"

#define TABLA1 class_hash1::type1
#define FILA1 class_hash1::type0

#define STR_ESPACIO_SEPARADOR "          "
#define STR_ESPACIO_SEPARADOR_PEQUENO "        "


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
    void inicializar(){
      leer_archivo(_tabla,"/new/gramatica_ampliada.csv");
    }
    void convertir_a_vector(string str, string delimitador,vector<string>& vec);
    void convertir_a_cola(string str,string delimitador,queue<string>& vec);
    string obtener_estado(string num_reducir);
    int obtener_estado_num(string num_reducir);
    void imprimir_tabla(TABLA1& t);

};

#endif //GRAMATICA_EXPAN
