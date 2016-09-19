#include <iostream>
#include <map>
#include <vector>
#include "automaton.hpp"


using namespace std;


//enum token {    cvb=0, cero=1, numero=2, octal= 5, hexadecimal=6 };





int main(int argc, char *argv[]){
// int main(){

  /////////////////// TABLE TOKENS /////////////////////
  map <int,string> token;
 token.insert ( std::pair<int,string>(0,"cadena invalida") );
 token.insert ( std::pair<int,string>(1,"cero") );
 token.insert ( std::pair<int,string>(2,"numero") );
 token.insert ( std::pair<int,string>(6,"octal") );
 token.insert ( std::pair<int,string>(5,"hexadecimal") );
 //------------------------------------------------------





  AFD automata;
    // -1 estado inicial
    // 0 no terminal
    // >0 terminal



  automata.insertar_estado(datos("q1"),-1); // inicial
  automata.insertar_estado(datos("q1"), 1); // terminal 1
  automata.insertar_estado(datos("q2"), 2); // terminal 2
  automata.insertar_estado(datos("q3"), 0); // no terminal
  automata.insertar_estado(datos("q4"), 0); // no terminal
  automata.insertar_estado(datos("q5"), 5); // terminal 5
  automata.insertar_estado(datos("q6"), 6); // terminal 6


  automata.insertar_transicion(datos("q0"),datos("q1"),*es_cero);
  automata.insertar_transicion(datos("q1"),datos("q2"),*es_numero_sin_cero);
  automata.insertar_transicion(datos("q1"),datos("q1"),*es_cero);
  automata.insertar_transicion(datos("q1"),datos("q3"),*es_x);
  automata.insertar_transicion(datos("q3"),datos("q5"),*es_hex);
  automata.insertar_transicion(datos("q5"),datos("q5"),*es_hex);

  automata.insertar_transicion(datos("q1"),datos("q4"),*es_o);
  automata.insertar_transicion(datos("q4"),datos("q6"),*es_octal);
  automata.insertar_transicion(datos("q6"),datos("q6"),*es_octal);

  automata.insertar_transicion(datos("q0"),datos("q2"),*es_numero_sin_cero);
  automata.insertar_transicion(datos("q2"),datos("q2"),*es_numero_con_cero);


      // -1 =  no inicial
      // 0 = error
      // 1 = solo ceros
      // 2 = numero natural incluido el cero
      // 5 = hexadecimal
      // 6 = octal


  string my1="0O0";
  cout<< token[automata.verificar_entrada(&my1)] <<endl;

  string my2="0064";
  cout<< token[automata.verificar_entrada(&my2)] <<endl;

  string my3="0o647";
  cout<< token[automata.verificar_entrada(&my3)] <<endl;

  string my4="0000";
  cout<< token[automata.verificar_entrada(&my4)] <<endl;

  string my5="0xxx";
  cout<< token[automata.verificar_entrada(&my5)] <<endl;


cout<<"////////////todo ok"<<endl;

  return 0;
}
