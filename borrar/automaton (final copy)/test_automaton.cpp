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
  automata_numerico.insertar_estado(datos("q1"),-1); // inicial
  automata_numerico.insertar_estado(datos("q1"), 1); // terminal 1
  automata_numerico.insertar_estado(datos("q2"), 2); // terminal 2
  automata_numerico.insertar_estado(datos("q3"), 0); // no terminal
  automata_numerico.insertar_estado(datos("q4"), 0); // no terminal
  automata_numerico.insertar_estado(datos("q5"), 5); // terminal 5
  automata_numerico.insertar_estado(datos("q6"), 6); // terminal 6


  automata_numerico.insertar_transicion(datos("q0"),datos("q1"),*es_cero);
  automata_numerico.insertar_transicion(datos("q1"),datos("q2"),*es_numero_sin_cero);
  automata_numerico.insertar_transicion(datos("q1"),datos("q1"),*es_cero);
  automata_numerico.insertar_transicion(datos("q1"),datos("q3"),*es_x);
  automata_numerico.insertar_transicion(datos("q3"),datos("q5"),*es_hex);
  automata_numerico.insertar_transicion(datos("q5"),datos("q5"),*es_hex);

  automata_numerico.insertar_transicion(datos("q1"),datos("q4"),*es_o);
  automata_numerico.insertar_transicion(datos("q4"),datos("q6"),*es_octal);
  automata_numerico.insertar_transicion(datos("q6"),datos("q6"),*es_octal);

  automata_numerico.insertar_transicion(datos("q0"),datos("q2"),*es_numero_sin_cero);
  automata_numerico.insertar_transicion(datos("q2"),datos("q2"),*es_numero_con_cero);


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
  automaton.insertar_estado(datos("q101"),-1); // inicial
  automaton.insertar_estado(datos("q102"),100); // inicial
  automaton.insertar_transicion(datos("q101"),datos("q102"),*es_cero);
  // automaton.insertar_transicion(datos("q102"),datos("q102"),*es_cero);

  // string my1="00000000000";
  // // cout<< token[automaton.verificar_entrada(&my1)] <<endl;
  // cout<< automaton.verificar_entrada(&my1)<<endl;

  // uniendo automatas
  automaton.unir_automata_con(datos("q102"),automata_numerico,*es_cero);




  string my2="00000000000064";
  cout<<"////////////todo ok"<<endl;
  // cout<< token[automata_numerico.verificar_entrada(&my2)] <<endl;
  cout<< token[automaton.verificar_entrada(&my2)] <<endl;

  // string my3="0o647";
  // cout<< token[automaton.verificar_entrada(&my3)] <<endl;
  //
  // string my4="0000";
  // cout<< token[automaton.verificar_entrada(&my4)] <<endl;
  //
  // string my5="0xxx";
  // cout<< token[automaton.verificar_entrada(&my5)] <<endl;


cout<<"////////////todo ok"<<endl;

  return 0;
}
