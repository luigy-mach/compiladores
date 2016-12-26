


#include <iostream>
#include<stack>
using namespace std;


#include"class_slr.hpp"


int main(){

  vector<string> test;
  test.push_back("int");
  test.push_back("id");
  test.push_back("signoigual");
  test.push_back("numero");
  test.push_back("signopuntoycoma");



  vector<string> test2;
  test2.push_back("void");
  test2.push_back("id");
  test2.push_back("signoparentesisabierto");
  test2.push_back("int");
  test2.push_back("id");
  test2.push_back("signoparentesiscerrado");
  test2.push_back("signollavesabierta");
    // test2.push_back("id");
    // test2.push_back("signoparentesisabierto");
    // test2.push_back("id");
    // test2.push_back("signocoma");
    // test2.push_back("id");
    // test2.push_back("signoparentesiscerrado");
    // test2.push_back("signopuntoycoma");
  test2.push_back("signollavescerrada");

  // void id signoparentesisabierto int id signoparentesiscerrado signollavesabierta
  //     id signoparentesisabierto id signocoma id signoparentesiscerrado signopuntoycoma
  //     id signoparentesisabierto id signocoma id signoparentesiscerrado signopuntoycoma
  //     id signoparentesisabierto id signocoma id signoparentesiscerrado signopuntoycoma
  //     id signoparentesisabierto id signocoma id signoparentesiscerrado signopuntoycoma
  // signollavescerrada


  vector<string> test3;
  test3.push_back("int");
  test3.push_back("id");
  test3.push_back("signopuntoycoma");

  vector<string> test4;
  test4.push_back("int");
  test4.push_back("id");
  test4.push_back("signopuntoycoma");
  test4.push_back("int");
  test4.push_back("id");
  test4.push_back("signoigual");
  test4.push_back("numero");
  test4.push_back("signopuntoycoma");
  // int id signoigual numero signopuntoycoma


  slr mysrl;
  mysrl.iniciar_slr();
  cout<<"!!!!!!!!!!!!!!!!!!!!!"<<endl;
  string resultado = mysrl.verificar_entrada(test);
  cout<<resultado<<endl;
  cout<<"!!!!!!!!!!!!!c!!!!!!!!"<<endl;

  return 0;
}
