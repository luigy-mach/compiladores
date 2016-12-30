

#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <string>
#include "defines_includes.hpp"


#include "analizador_lexico.hpp"



using namespace std;


int main(int argc, char *argv[]){
  class_analizador_lexico analizador;


  vector< pair<string,string> > vec;

  analizador.inicializar_analizardor_lexico("jhony4.ino");
  analizador.obtener_vector_tokens(vec);




  cout<<"//////////aaa//////////////////////////////"<<endl;
  cout<<"FIN//////////////////////////////////////todo ok"<<endl;

  return 0;
}
