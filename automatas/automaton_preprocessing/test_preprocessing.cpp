#include <iostream>
#include <map>
#include <vector>
#include "automaton.hpp"


using namespace std;


//enum token {    cvb=0, cero=1, numero=2, octal= 5, hexadecimal=6 };


void init_automata_numerico(AFD & automata_numerico){
  // -1 estado inicial
  // 0 no terminal
  // >0 terminal
  automata_numerico.insertar_estado(capsula("q0"),-1); // inicial
  automata_numerico.insertar_estado(capsula("q1"), 1); // terminal 1
  automata_numerico.insertar_estado(capsula("q2"), 2); // terminal 2
  automata_numerico.insertar_estado(capsula("q3"), 0); // no terminal
  automata_numerico.insertar_estado(capsula("q4"), 0); // no terminal
  automata_numerico.insertar_estado(capsula("q5"), 5); // terminal 5
  automata_numerico.insertar_estado(capsula("q6"), 6); // terminal 6


  automata_numerico.insertar_transicion(capsula("q0"),capsula("q1"),*es_cero);
  automata_numerico.insertar_transicion(capsula("q1"),capsula("q2"),*es_numero_sin_cero);
  automata_numerico.insertar_transicion(capsula("q1"),capsula("q1"),*es_cero);
  automata_numerico.insertar_transicion(capsula("q1"),capsula("q3"),*es_x);
  automata_numerico.insertar_transicion(capsula("q3"),capsula("q5"),*es_hex);
  automata_numerico.insertar_transicion(capsula("q5"),capsula("q5"),*es_hex);

  automata_numerico.insertar_transicion(capsula("q1"),capsula("q4"),*es_o);
  automata_numerico.insertar_transicion(capsula("q4"),capsula("q6"),*es_octal);
  automata_numerico.insertar_transicion(capsula("q6"),capsula("q6"),*es_octal);

  automata_numerico.insertar_transicion(capsula("q0"),capsula("q2"),*es_numero_sin_cero);
  automata_numerico.insertar_transicion(capsula("q2"),capsula("q2"),*es_numero_con_cero);


    // -1 =  no inicial
    // 0 = error
    // 1 = solo ceros
    // 2 = numero natural incluido el cero
    // 5 = hexadecimal
    // 6 = octal
}



int main(int argc, char *argv[]){
// int main(){

  /////////////////// TABLE TOKENS /////////////////////
  map <int,string> token;
 token.insert ( std::pair<int,string>(0,"cadena invalida") );
 token.insert ( std::pair<int,string>(1,"cero") );
 token.insert ( std::pair<int,string>(2,"numero") );
 token.insert ( std::pair<int,string>(6,"octal") );
 token.insert ( std::pair<int,string>(5,"hexadecimal") );
 token.insert ( std::pair<int,string>(100,"tmr") );
 //------------------------------------------------------

 /////////////////////ESTADOS//////////////////////
 // -1 estado inicial
 // 0 no terminal
 // >0 terminal
 /////////////////////////////////////////////////

  AFD automata_numerico;
  init_automata_numerico(automata_numerico);


  AUTOMATON automaton;
  automaton.insertar_estado(capsula("q101"),-1); // inicial
  automaton.insertar_estado(capsula("q102"),100); // inicial
  automaton.insertar_transicion(capsula("q101"),capsula("q102"),*es_cero);
  //automaton.insertar_transicion(capsula("q102"),capsula("q102"),*es_cero);


  capsula temp1;
  string my1="00000";
  // cout<< token[automaton.verificar_entrada(&my1)] <<endl;
  cout<< automaton.verificar_entrada(&my1,temp1)<<endl;

  // uniendo automatas
  automaton.unir_automata_con(capsula("q102"),automata_numerico,*es_cero);


  capsula temp2("prueba",true);

  string my2="000o23";
  cout<< token[automata_numerico.verificar_entrada(&my2,temp2)] <<endl;
  cout<<"_nombre: "<< temp2._nombre <<endl; //nodo donde termino
  cout<<"_error: "<< temp2._error <<endl; //tiene error?
  cout<<"////////////todo ok"<<endl;

  // cout<< token[automaton.verificar_entrada(&my2)] <<endl;
  // cout<<"////////////todo ok"<<endl;
  //
  //
  // string my3="000x647";
  // cout<< token[automaton.verificar_entrada(&my3)] <<endl;
  // cout<<"////////////todo ok"<<endl;
  //
  //
  // string my4="0000";
  // cout<< token[automaton.verificar_entrada(&my4)] <<endl;
  // cout<<"////////////todo ok"<<endl;
  //
  // string my5="0xxx";
  // cout<< token[automaton.verificar_entrada(&my5)] <<endl;


cout<<"FIN////////////todo ok"<<endl;

  return 0;
}
