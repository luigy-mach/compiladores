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




void init_automata_string(AFD & automata_string){

  // -1 estado inicial
  // 0 no terminal
  // >0 terminal

  automata_string.insertar_estado(capsula("q100"),-100); // inicial
  automata_string.insertar_estado(capsula("q101"), 100); // terminal 101
  automata_string.insertar_estado(capsula("q102"), 102); // terminal 102
  automata_string.insertar_estado(capsula("q103"), 100); //  no terminal q103
  automata_string.insertar_estado(capsula("q104"), 104); // terminal 102

  // automata_string.insertar_transicion(capsula(""),capsula(""),*pf);
  automata_string.insertar_transicion(capsula("q100"),capsula("q101"),*es_letra);
  automata_string.insertar_transicion(capsula("q100"),capsula("q101"),*es_guion_bajo);

  automata_string.insertar_transicion(capsula("q101"),capsula("q102"),*es_numero);
  automata_string.insertar_transicion(capsula("q101"),capsula("q102"),*es_letra);

  automata_string.insertar_transicion(capsula("q102"),capsula("q102"),*es_numero);
  automata_string.insertar_transicion(capsula("q102"),capsula("q102"),*es_letra);

  automata_string.insertar_transicion(capsula("q100"),capsula("q103"),*es_comilla);
  automata_string.insertar_transicion(capsula("q103"),capsula("q103"),*es_letra);
  automata_string.insertar_transicion(capsula("q103"),capsula("q103"),*es_numero);
  automata_string.insertar_transicion(capsula("q103"),capsula("q103"),*es_guion_bajo);

  automata_string.insertar_transicion(capsula("q103"),capsula("q104"),*es_comilla);




  // -1 =  no inicial
  // 0 = error
  // 1 = STRING
  // 2 = QUE_SERA_?



}

int main(int argc, char *argv[]){
// int main(){

 //  /////////////////// TABLE TOKENS /////////////////////
 //  map <int,string> token;
 // token.insert ( std::pair<int,string>(0,"cadena invalida") );
 // token.insert ( std::pair<int,string>(1,"cero") );
 // token.insert ( std::pair<int,string>(2,"numero") );
 // token.insert ( std::pair<int,string>(6,"octal") );
 // token.insert ( std::pair<int,string>(5,"hexadecimal") );
 // token.insert ( std::pair<int,string>(100,"tmr") );
 // //------------------------------------------------------
 //
 // /////////////////////ESTADOS//////////////////////
 // // -1 estado inicial
 // // 0 no terminal
 // // >0 terminal
 // /////////////////////////////////////////////////
 //
 //  AFD automata_numerico;
 //  init_automata_numerico(automata_numerico);


 map <int,string> map_token_general;
 map_token_general.insert ( std::pair<int,string>(0,"CADENA INVALIDA_NUMERO") );
 map_token_general.insert ( std::pair<int,string>(1,"CERO") );
 map_token_general.insert ( std::pair<int,string>(2,"NUMERO") );
 map_token_general.insert ( std::pair<int,string>(6,"OCTAL") );
 map_token_general.insert ( std::pair<int,string>(5,"HEXADECIMAL") );

 map_token_general.insert ( std::pair<int,string>(100,"CADENA INVALIDA_STRING") );
 map_token_general.insert ( std::pair<int,string>(101,"ID") );
 map_token_general.insert ( std::pair<int,string>(102,"ID") );
 map_token_general.insert ( std::pair<int,string>(104,"STRING") );
 map_token_general.insert ( std::pair<int,string>(34404,"error") );


 AFD automata_string;
 init_automata_string(automata_string);


 AFD automata_numerico;
 init_automata_numerico(automata_numerico);




  //
  //
  // AUTOMATON automaton;
  // automaton.insertar_estado(capsula("q101"),-1); // inicial
  // automaton.insertar_estado(capsula("q102"),100); // inicial
  // automaton.insertar_transicion(capsula("q101"),capsula("q102"),*es_cero);
  // //automaton.insertar_transicion(capsula("q102"),capsula("q102"),*es_cero);


  capsula temp1;
  string my1="00000";
  // cout<< token[automaton.verificar_entrada(&my1)] <<endl;

  //cout<< automaton.verificar_entrada(&my1,temp1)<<endl;


  // uniendo automatas
  //automaton.unir_automata_con(capsula("q102"),automata_numerico,*es_cero);


  capsula temp2("prueba",true);
  
  string my2="aaaa";
  cout<< map_token_general[automata_string.verificar_entrada(&my2,temp2)] <<endl;
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
