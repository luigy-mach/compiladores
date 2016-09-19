#include <iostream>
#include <map>
#include <vector>
#include "automatas.hpp"


using namespace std;


//enum token {    cvb=0, cero=1, numero=2, octal= 5, hexadecimal=6 };


int main(){

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

  automata->insertar_estado("q0",-1); // inicial
  automata->insertar_estado("q1", 1); // terminal 1
  automata->insertar_estado("q2", 2); // terminal 2
  automata->insertar_estado("q3", 0); // no terminal
  automata->insertar_estado("q4", 0); // no terminal
  automata->insertar_estado("q5", 5); // terminal 5
  automata->insertar_estado("q6", 6); // terminal 6


  automata->insertar_transicion("q0","q1",*es_cero);
  automata->insertar_transicion("q1","q1",*es_cero);
  automata->insertar_transicion("q1","q2",*es_numero_sin_cero);
  automata->insertar_transicion("q1","q3",*es_x);
  automata->insertar_transicion("q3","q5",*es_hex);
  automata->insertar_transicion("q5","q5",*es_hex);

  automata->insertar_transicion("q1","q4",*es_o);
  automata->insertar_transicion("q4","q6",*es_octal);
  automata->insertar_transicion("q6","q6",*es_octal);

  automata->insertar_transicion("q0","q2",*es_numero_sin_cero);
  automata->insertar_transicion("q2","q2",*es_numero_con_cero);


      // -1 =  no inicial
      // 0 = error
      // 1 = solo ceros
      // 2 = numero natural incluido el cero
      // 5 = hexadecimal
      // 6 = octal


  string my1="0O";
  cout<< token[automata->verificar_entrada(&my1)] <<endl;

/*  string my2="0064";
  cout<< token[automata->verificar_entrada(&my2)] <<endl;

  string my3="0o647";
  cout<< token[automata->verificar_entrada(&my3)] <<endl;

  string my4="0000";
  cout<< token[automata->verificar_entrada(&my4)] <<endl;

  string my5="0xxx";
  cout<< token[automata->verificar_entrada(&my5)] <<endl;
*/


  return 0;
}
