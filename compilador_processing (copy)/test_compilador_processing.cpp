

#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <string>
#include "analizador_lexico/defines_includes.hpp"
#include "lector_tabla_anagra/defines_includes.hpp"

#include "analizador_lexico/analizador_lexico.hpp"
#include"lector_tabla_anagra/class_slr.hpp"




using namespace std;


int main(){

vector< pair<string,string> > vec;

  class_analizador_lexico analizador;
  analizador.inicializar_analizardor_lexico("jhony4.ino");
  analizador.obtener_vector_tokens(vec);


  slr mysrl;
  mysrl.iniciar_slr();
  cout<<"!!!!!!!!!!!!!!!!!!!!!"<<endl;
  //string resultado = mysrl.verificar_entrada(vec);
  //cout<<resultado<<endl;
  cout<<"!!!!!!!!!!!!!!!!!!!!!"<<endl;




  cout<<"//////////aaa//////////////////////////////"<<endl;
  cout<<"FIN//////////////////////////////////////todo ok"<<endl;

  return 0;
}
