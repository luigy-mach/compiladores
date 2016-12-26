#include"tabla_slr.hpp"
#include"gramatica_expan.hpp"


#include<stack>
using namespace std;


#define ACEPTACION "aceptar"

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
    void iniciar_slr(){
      _tabla.inicializar_tabla();
      _reducciones.inicializar();
      resetear_pilas();

    }
    string verificar_entrada(vector<string>& query);

};
