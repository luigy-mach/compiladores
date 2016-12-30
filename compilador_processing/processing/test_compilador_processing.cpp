

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

  vector<string> test4;
    test4.push_back("void");
    test4.push_back("id");
    test4.push_back("signoparentesisabierto");
    test4.push_back("signoparentesiscerrado");
    test4.push_back("signollavesabierta");
    test4.push_back("signollavescerrada");



  // vector<string> test3;
  //   test3.push_back("int");
  //   test3.push_back("id");
  //   test3.push_back("signopuntoycoma");


  // string resultado = mysrl.verificar_entrada(test4);
  string resultado = mysrl.verificar_entrada_2(vec);
  cout<<resultado<<endl;


  // vector<string> test;
  //   test.push_back("int");
  //   test.push_back("id");
  //   test.push_back("signoigual");
  //   test.push_back("numero");
  //   test.push_back("signopuntoycoma");
  //

  cout<<"!!!!!!!!!!!!!!!!!!!!!"<<endl;


  return 0;
}
