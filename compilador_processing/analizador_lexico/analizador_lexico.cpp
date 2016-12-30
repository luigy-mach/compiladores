#include "analizador_lexico.hpp"

//----------------------------------------------------
//ANALIZADOR_LEXICO
//----------------------------------------------------

class_analizador_lexico::class_analizador_lexico(){
    _myautomata=new class_automata();
    _mytabla=new class_tabla_token();
}

void class_analizador_lexico::cargar_archivo(string archivo, string& buff ){
    ifstream in(archivo);
    string temp="";
    while(getline(in,temp)){
      buff+=temp+"\n";
      //cout<<temp<<endl;
    }
}

void class_analizador_lexico::inicializar_analizardor_lexico(string archivo){
    this->cargar_automata();
    this->cargar_tabla_token_especificos();

    this->cargar_archivo(archivo,_buffer);
    // _mytabla->imprimir_tabla();

}

void class_analizador_lexico::obtener_vector_tokens(vector< pair<string,string> >& vec){

  vector< pair<string,string> >::iterator it,it_temp;

  _myautomata->verificar_cadena(_buffer,vec);

  for(it=vec.begin(); it!=vec.end();){
    if(it->second==STR_ESPACIO_EN_BLANCO ||
       it->second==STR_SALTO_DE_LINEA ||
       it->second==STR_TABULACION ||
       it->second==STR_COMENTARIO_CORTO ||
       it->second==STR_COMENTARIO_LARGO  ){
      //  cout<<"borrando: "<<it->second<<" ----- ";
       it=vec.erase(it);
      // cout<<"despues : "<<it->second<<endl;

           //continue;
    }



    else if(it->second==STR_STRING_SIN_DEPURAR ||
       it->second==STR_SIMBOLO_DESCONOCIDO ){
        string out="ERROR_EN_TABLA";
        if(_mytabla->buscar(it->first,out)){
            // cout<<"TOKEN: "<<it->second<<endl;
            it->second=out;
        }
        it++;
    }
    else{

      string out="ERROR_EN_TABLA_GRAVE";
      if(_mytabla->buscar(it->first,out)){
          // cout<<"TOKEN: "<<it->second<<endl;
          it->second=out;
      }
      it++;
    }
  }

  int linea=1;
  for(it=vec.begin() ; it!=vec.end() ; it++){
      cout<< it->first<<"-------"<<it->second<<endl; //" ///// linea: " << linea <<endl;
      linea++;
  }


}



void class_analizador_lexico::cargar_automata(){

  cout<<"********************************"<<endl;

  _myautomata->insertar_estado("q1",-1,STR_SIN_TOKEN);
  _myautomata->insertar_estado("q2",2,"STRING_INCOMPLETO");
  _myautomata->insertar_estado("q3",3,"STRING");
  _myautomata->insertar_estado("q4",0,STR_SIN_TOKEN);
  _myautomata->insertar_estado("q5",5,"CHAR_INCOMPLETO");
  _myautomata->insertar_estado("q6",6,"CHAR");
  _myautomata->insertar_estado("q7",0,STR_SIN_TOKEN);
  _myautomata->insertar_estado("q8",0,STR_SIN_TOKEN);
  _myautomata->insertar_estado("q9",0,STR_SIN_TOKEN);
  _myautomata->insertar_estado("q10",10,STR_COMENTARIO_LARGO);//"COMENTARIO_LARGO"
  _myautomata->insertar_estado("q11",0,STR_SIN_TOKEN);
  _myautomata->insertar_estado("q12",12,STR_COMENTARIO_CORTO);//"COMENTARIO_CORTO"

  _myautomata->insertar_estado("q13",13,STR_STRING_SIN_DEPURAR);
  _myautomata->insertar_estado("q14",14,"NUMERO_ENTERO_CERO");//solo un cero
  _myautomata->insertar_estado("q15",0,STR_SIN_TOKEN);
  _myautomata->insertar_estado("q16",16,"HEXADECIMAL");
  _myautomata->insertar_estado("q17",0,STR_SIN_TOKEN);
  _myautomata->insertar_estado("q18",18,"NUMERO_ENTERO");//acepta puro ceros
  _myautomata->insertar_estado("q19",0,STR_SIN_TOKEN);
  _myautomata->insertar_estado("q20",20,"NUMERO_DOUBLE");


  _myautomata->insertar_estado("q21",21,STR_SALTO_DE_LINEA);
  _myautomata->insertar_estado("q22",22,STR_TABULACION);
  _myautomata->insertar_estado("q23",23,STR_ESPACIO_EN_BLANCO);

  _myautomata->insertar_estado("q24",24,"OCTAL");


  cout<<"****"<<endl;


  _myautomata->insertar_transicion("q1","q2","\"");
  _myautomata->insertar_transicion("q2","q2",todo_menos('\"'));//todo menos \"
  _myautomata->insertar_transicion("q2","q3","\"");

  _myautomata->insertar_transicion("q1","q4","\'");
  _myautomata->insertar_transicion("q4","q5",todo_menos('\''));//todo menos \'
  _myautomata->insertar_transicion("q5","q6","\'");

  _myautomata->insertar_transicion("q1","q7","/");

  _myautomata->insertar_transicion("q7","q8","*");
  _myautomata->insertar_transicion("q8","q8",todo_menos('*'));//todo menos *
  _myautomata->insertar_transicion("q8","q9","*");
  _myautomata->insertar_transicion("q9","q10","/");

  _myautomata->insertar_transicion("q7","q11","/");
  _myautomata->insertar_transicion("q11","q11",todo_menos('\n'));//todo menos \n
  _myautomata->insertar_transicion("q11","q12",'\n');


  _myautomata->insertar_transicion("q1","q13","qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM");
  _myautomata->insertar_transicion("q1","q13","_");

  _myautomata->insertar_transicion("q13","q13","qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM");
  _myautomata->insertar_transicion("q13","q13","_");
  _myautomata->insertar_transicion("q13","q13","0123456789");


  _myautomata->insertar_transicion("q1","q14","0");

  _myautomata->insertar_transicion("q14","q18","0");

  _myautomata->insertar_transicion("q14","q15","x");
  _myautomata->insertar_transicion("q14","q15","X");
  _myautomata->insertar_transicion("q15","q16","0123456789ABCDEF");//hexadecimal
  _myautomata->insertar_transicion("q16","q16","0123456789ABCDEF");


  _myautomata->insertar_transicion("q14","q17","o");
  _myautomata->insertar_transicion("q14","q17","O");
  _myautomata->insertar_transicion("q17","q24","01234567");
  _myautomata->insertar_transicion("q24","q24","01234567");

  _myautomata->insertar_transicion("q1","q18","123456789");
  _myautomata->insertar_transicion("q18","q18","0123456789");

  _myautomata->insertar_transicion("q18","q19",".");

  _myautomata->insertar_transicion("q1","q19",".");
  _myautomata->insertar_transicion("q19","q20","0123456789");
  _myautomata->insertar_transicion("q20","q20","0123456789");

  _myautomata->insertar_transicion("q1","q21","\n");
  _myautomata->insertar_transicion("q1","q22","\t");
  _myautomata->insertar_transicion("q1","q23"," ");



  cout<<"********************************"<<endl;

}

void class_analizador_lexico::cargar_tabla_token_especificos(){
    _mytabla->iniciar_tabla();
    // cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    // cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    // _mytabla->imprimir_tabla();
    // cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    // cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
}
//----------------------------------------------------
//fin ANALIZADOR_LEXICO
//----------------------------------------------------
