#ifndef TABLA_SLR
#define TABLA_SLR




#include <iostream>
#include <unordered_map>
#include<fstream>
#include<vector>
#include<queue>

#include <stack>


using namespace std;



#define MSJ_ERROR "err"

#define TABLA class_hash2::type1
#define FILA class_hash2::type0


#define STR_ESPACIO_SEPARADOR "          "
#define STR_ESPACIO_SEPARADOR_PEQUENO "        "



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

public:
    tabla_anagra(){}
    void inicializar_tabla(){
      leer_archivo(_tabla,"/home/luigy/Desktop/compiladores/compiladores/lector_tabla_anagra/new/ANAGRA_TABLE_FULL.csv");
    }
    void convertir_a_vector(string str, string delimitador,vector<string>& vec);
    void convertir_a_cola(string str,string delimitador,queue<string>& vec);
    string consultar(string fila, string columna);
    void imprimir_tabla(TABLA& t);

};


#endif //TABLA_SLR
