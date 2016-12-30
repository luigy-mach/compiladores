#include"tabla_slr.hpp"
#include"gramatica_expan.hpp"

#include<stack>
#include <utility>
#include <vector>


#include "defines_includes.hpp"

using namespace std;

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
    void iniciar_slr();
    string verificar_entrada(vector<string>& query);
    string verificar_entrada_2(vector< pair<string,string> >& query1);

};
