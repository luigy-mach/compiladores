

#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <string>


#include "analizador_lexico.hpp"
#include "class_slr.hpp"

using namespace std;


int main(){

  vector< pair<string,string> > vec;
  class_analizador_lexico analizador;
  analizador.inicializar_analizardor_lexico("jhony4.ino");
  analizador.obtener_vector_tokens(vec);

  slr mysrl;
  mysrl.iniciar_slr();
  string resultado = mysrl.verificar_entrada_2(vec);
  cout<<resultado<<endl;

  return 0;
}
