#include"tabla_slr.hpp"
#include"gramatica_expan.hpp"


#include<stack>
using namespace std;

<<<<<<< HEAD
#include "defines_includes.hpp"
=======

#define STR_ACEPTACION "aceptar"
#define SIMBOLO_INICIO "0"
#define SIMBOLO_PARADA "$"
#define STR_DESPLAZAMIENTO "d"
#define STR_REDUCCION "r"
>>>>>>> 01bf27a079175456578839226d36ee6740b9d06e

class slr{
  tabla_anagra    _tabla;
  gramatica_expan _reducciones;
  stack<string> pila_entrada;
  stack<string> pila_salida;
  void insertar_consulta(vector<string>& vec);
  void resetear_pilas();
  bool gramatica_aceptada(string fil, string col);
public:
    slr(){ }
<<<<<<< HEAD
    void iniciar_slr();
=======
    void iniciar_slr(){
      _tabla.inicializar_tabla();
      _reducciones.inicializar();
      resetear_pilas();
    }
>>>>>>> 01bf27a079175456578839226d36ee6740b9d06e
    string verificar_entrada(vector<string>& query);

};
