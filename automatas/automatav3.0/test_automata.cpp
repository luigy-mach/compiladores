#include <iostream>
#include <map>
#include <vector>
#include "automata.hpp"


using namespace std;

#define STR_SIN_TOKEN "sin_token_define"




int main(int argc, char *argv[]){


  cout<<"********************************"<<endl;
  class_automata au;
  au.insertar_estado("q1",-1,STR_SIN_TOKEN);
  au.insertar_estado("q2",2,"STRING_INCOMPLETO");
  au.insertar_estado("q3",3,"STRING");
  au.insertar_estado("q4",0,STR_SIN_TOKEN);
  au.insertar_estado("q5",5,"CHAR_INCOMPLETO");
  au.insertar_estado("q6",6,"CHAR");
  au.insertar_estado("q7",0,STR_SIN_TOKEN);
  au.insertar_estado("q8",0,STR_SIN_TOKEN);
  au.insertar_estado("q9",0,STR_SIN_TOKEN);
  au.insertar_estado("q10",10,"COMENTARIO_LARGO");
  au.insertar_estado("q11",0,STR_SIN_TOKEN);
  au.insertar_estado("q12",12,"COMENTARIO_CORTO");

  au.insertar_estado("q13",13,"STRING_ID");
  au.insertar_estado("q14",14,"NUMERO_ENTERO_CERO");//solo un cero
  au.insertar_estado("q15",0,STR_SIN_TOKEN);
  au.insertar_estado("q16",16,"HEXADECIMAL");
  au.insertar_estado("q17",0,STR_SIN_TOKEN);
  au.insertar_estado("q18",18,"NUMERO_ENTERO");//acepta puro ceros
  au.insertar_estado("q19",0,STR_SIN_TOKEN);
  au.insertar_estado("q20",20,"NUMERO_DOUBLE");

  au.insertar_estado("q21",21,"SALTO_DE_LINEA");
  au.insertar_estado("q22",22,"TABULACION");
  au.insertar_estado("q23",23,"ESPACIO_EN_BLANCO");

  au.insertar_estado("q24",24,"OCTAL");


  cout<<"****"<<endl;

  
  au.insertar_transicion("q1","q2","\"");
  au.insertar_transicion("q2","q2",todo_menos('\"'));//todo menos \"
  au.insertar_transicion("q2","q3","\"");

  au.insertar_transicion("q1","q4","\'");
  au.insertar_transicion("q4","q5",todo_menos('\''));//todo menos \'
  au.insertar_transicion("q5","6","\'");

  au.insertar_transicion("q1","q7","/");

  au.insertar_transicion("q7","q8","*");
  au.insertar_transicion("q8","q8",todo_menos('*'));//todo menos *
  au.insertar_transicion("q8","q9","*");
  au.insertar_transicion("q9","q10","/");

  au.insertar_transicion("q7","q11","/");
  au.insertar_transicion("q11","q11",todo_menos('\n'));//todo menos \n
  au.insertar_transicion("q11","q12","\n");


  au.insertar_transicion("q1","q13","qwertyuiopasdfghjklzxcvbnm");
  au.insertar_transicion("q1","q13","_");

  au.insertar_transicion("q13","q13","qwertyuiopasdfghjklzxcvbnm");
  au.insertar_transicion("q13","q13","_");
  au.insertar_transicion("q13","q13","0123456789");


  au.insertar_transicion("q1","q14","0");

  au.insertar_transicion("q14","q18","0");

  au.insertar_transicion("q14","q15","x");
  au.insertar_transicion("q14","q15","X");
  au.insertar_transicion("q15","q16","0123456789ABCDEF");//hexadecimal
  au.insertar_transicion("q16","q16","0123456789ABCDEF");


  au.insertar_transicion("q14","q17","o");
  au.insertar_transicion("q14","q17","O");
  au.insertar_transicion("q17","q24","01234567");
  au.insertar_transicion("q24","q24","01234567");

  au.insertar_transicion("q1","q18","123456789");
  au.insertar_transicion("q18","q18","0123456789");

  au.insertar_transicion("q18","q19",".");

  au.insertar_transicion("q1","q19",".");
  au.insertar_transicion("q19","q20","0123456789");
  au.insertar_transicion("q20","q20","0123456789");

  au.insertar_transicion("q1","q21","\n");
  au.insertar_transicion("q1","q22","\t");
  au.insertar_transicion("q1","q23"," ");



  cout<<"********************************"<<endl;


  string test="in.t&a/=3//asdfd;\n ";
  vector< pair<string,string> > vec;
  vector< pair<string,string> >::iterator it;
  au.verificar_cadena(test,vec);


  cout<<"////////////////////////////////////////"<<endl;
  for(it=vec.begin() ; it!=vec.end() ; it++){
    cout<< it->first<<"-------"<<it->second<<endl;
  }

  cout<<"FIN//////////////////////////////////////todo ok"<<endl;

  return 0;
}
