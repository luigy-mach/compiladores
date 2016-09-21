#include <iostream>
#include<string>
#include <map>
#include <vector>
#include <utility> //pair
#include<algorithm> //remove



#include "tabla_token.hpp"
#include "normalizador.hpp"
#include "pre_processing.hpp"
#include "automaton.hpp"
using namespace normalizador;
using namespace pre_processing;


using namespace std;

void cargar_buffer(string& string_buffer, const string& archivo){

  char* buffer;
  char* file_name= new char[archivo.size()+1];
  std::memcpy(file_name,archivo.c_str(),archivo.size()+1);


  std::ifstream is (file_name, std::ifstream::binary);
  if (is) {
    is.seekg (0, is.end);
    int length = is.tellg();
	  is.seekg (0, is.beg);

    buffer = new char [length];
    is.read(buffer,length);
    is.close();
  }

  string_buffer=buffer;

}

void clean_word(string& str){
  std::size_t found = str.find_first_of(" ");
  while (found!=std::string::npos)
  {
    str.erase(str[found],str[found+1]);
    found=str.find_first_of(" ",found+1);
  }
}


template<typename T, typename P>
T remove_if(T beg, T end, P pred)
{
    T dest = beg;
    for (T itr = beg;itr != end; ++itr)
        if (!pred(*itr))
            *(dest++) = *itr;
    return dest;
}


void removeCharsFromString( string &str, const char* charsToRemove ) {
   for ( unsigned int i = 0; i < strlen(charsToRemove); ++i ) {
      str.erase( remove(str.begin(), str.end(), charsToRemove[i]), str.end() );
   }
}




void init_automata_string(AFD & automata_string){

  // -1 estado inicial
  // 0 no terminal
  // >0 terminal
  // automata_string.insertar_estado(capsula("q100"),-100); // inicial
  // automata_string.insertar_estado(capsula("q101"), 101); // terminal 101
  // automata_string.insertar_estado(capsula("q102"), 102); // terminal 102
  // automata_string.insertar_estado(capsula("q103"), 100); //  no terminal q103
  // automata_string.insertar_estado(capsula("q104"), 104); // terminal 102
  //
  // // automata_string.insertar_transicion(capsula(""),capsula(""),*pf);
  // automata_string.insertar_transicion(capsula("100"),capsula("101"),*es_letra);
  // automata_string.insertar_transicion(capsula("100"),capsula("101"),*es_guion_bajo);
  //
  // automata_string.insertar_transicion(capsula("101"),capsula("102"),*es_numero);
  // automata_string.insertar_transicion(capsula("101"),capsula("102"),*es_letra);
  //
  // automata_string.insertar_transicion(capsula("102"),capsula("102"),*es_numero);
  // automata_string.insertar_transicion(capsula("102"),capsula("102"),*es_letra);
  //
  // automata_string.insertar_transicion(capsula("100"),capsula("103"),*es_comilla);
  // automata_string.insertar_transicion(capsula("103"),capsula("103"),*es_letra);
  // automata_string.insertar_transicion(capsula("103"),capsula("103"),*es_numero);
  // automata_string.insertar_transicion(capsula("103"),capsula("103"),*es_guion_bajo);
  //
  // automata_string.insertar_transicion(capsula("103"),capsula("104"),*es_comilla);



  automata_string.insertar_estado(capsula("q100"),-1); // inicial
  automata_string.insertar_estado(capsula("q101"), 1); // terminal 101
  automata_string.insertar_estado(capsula("q102"), 2); // terminal 102
  automata_string.insertar_estado(capsula("q103"), 0); //  no terminal q103
  automata_string.insertar_estado(capsula("q104"), 4); // terminal 102

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







int main(){


/////////////////////////////////////////////////////
//array lexemas
/////////////////////////////////////////////////////
// vector<string,string> lexemas_tokens;
// vector<string,string>::iterator it_lexemas_tokens;
vector< pair<string,string> > lexemas_tokens;
vector< pair<string,string> >::iterator it_lexemas_tokens;

/////////////////////////////////////////////////////
//fin array lexemas
/////////////////////////////////////////////////////




/////////////////////////////////////////////////////
//preprocesado
///////////////////////////////////////////////////////
// map <int,string> map_token_numerico;
// map_token_numerico.insert ( std::pair<int,string>(0,"CADENA INVALIDA") );
// map_token_numerico.insert ( std::pair<int,string>(1,"CERO") );
// map_token_numerico.insert ( std::pair<int,string>(2,"NUMERO") );
// map_token_numerico.insert ( std::pair<int,string>(6,"OCTAL") );
// map_token_numerico.insert ( std::pair<int,string>(5,"HEXADECIMAL") );
  pre_processing::pre_processing
          ("archivos/compilar.txt"
          ,"archivos/preprocesado.txt");// OJO falla con comentarios-> /*largos*/
  normalizador::normalizador("archivos/preprocesado.txt","archivos/normalizado.txt");
/////////////////////////////////////////////////////
//fin preprocesado
/////////////////////////////////////////////////////



/////////////////////////////////////////////////////
//tabla de tokens
/////////////////////////////////////////////////////

TABLA mytabla;
mytabla.iniciar_tokens_especificos();
// cout<<"........................................................"<<endl;
// //mytabla.imprimir_tabla();
// cout<<"........................................................"<<endl;
// mytabla.insertar_token_no_especifico("id2","ID",11000,1125,"todo bien","vacio");
// mytabla.insertar_token_no_especifico("id1","ID",100,125,"error_fatal","matate");
//mytabla.imprimir_tabla();

/////////////////////////////////////////////////////
//fin tabla de tokens
/////////////////////////////////////////////////////




/////////////////////////////////////////////////////
//automaton++
/////////////////////////////////////////////////////
// map <int,string> map_token_general;
// map_token_general.insert ( std::pair<int,string>(0,"CADENA INVALIDA_NUMERO") );
// map_token_general.insert ( std::pair<int,string>(1,"CERO") );
// map_token_general.insert ( std::pair<int,string>(2,"NUMERO") );
// map_token_general.insert ( std::pair<int,string>(6,"OCTAL") );
// map_token_general.insert ( std::pair<int,string>(5,"HEXADECIMAL") );

//
// map_token_general.insert ( std::pair<int,string>(100,"CADENA INVALIDA_STRING") );
// map_token_general.insert ( std::pair<int,string>(0,"CADENA INVALIDA_STRING") );
// map_token_general.insert ( std::pair<int,string>(101,"ID") );
// map_token_general.insert ( std::pair<int,string>(102,"ID") );
// map_token_general.insert ( std::pair<int,string>(104,"STRING") );
//
//



//
map <int,string> map_token_numerico;
map_token_numerico.insert ( std::pair<int,string>(0,"CADENA_INVALIDA_NUMERO") );
map_token_numerico.insert ( std::pair<int,string>(1,"CERO") );
map_token_numerico.insert ( std::pair<int,string>(2,"NUMERO") );
map_token_numerico.insert ( std::pair<int,string>(6,"OCTAL") );
map_token_numerico.insert ( std::pair<int,string>(5,"HEXADECIMAL") );

map <int,string> map_token_string;
map_token_string.insert ( std::pair<int,string>(0,"CADENA_INVALIDA_STRING") );
map_token_string.insert ( std::pair<int,string>(1,"ID") );
map_token_string.insert ( std::pair<int,string>(2,"ID") );
map_token_string.insert ( std::pair<int,string>(4,"STRING_AUTOMATA") );

AFD automata_numerico;
init_automata_numerico(automata_numerico);

AFD automata_string;
init_automata_string(automata_string);





/////////////////////////////////////////////////////
//automaton++
/////////////////////////////////////////////////////







/////////////////////////////////////////////////////
//tokenizando
/////////////////////////////////////////////////////

  string buffer;
  cargar_buffer(buffer,"archivos/normalizado.txt");
  // cout<<buffer<<endl;
  string::iterator it1;
  string::iterator it2;
  it1=it2=buffer.begin();

  string token_string;

  cout<<"++++++++++++++++++++++"<<endl;
  int id_count_numero=0;
  int id_count_string=0;
  while(it2!=buffer.end()){
    if(*it2==' ' || *it2=='\n'){
      string lexema_string(it1,it2);
      removeCharsFromString( lexema_string, "        \n" );
      cout<<"\""<<lexema_string<<"\""<<endl;
      buffer.erase(it1,it2);
      it1=it2=buffer.begin();
      // it2=it1;
      it2++;
      buffer.erase(it1,it2);
      it1=it2=buffer.begin();
      bool encontrado = mytabla.buscar(lexema_string,token_string);
      if(encontrado){
        lexemas_tokens.push_back(make_pair(lexema_string,token_string));
      }
      else{
        // lexemas_tokens.push_back(make_pair(lexema_string,"falta automata"));
        capsula temp2("prueba",true);

        string temp_token_str;
        int caso1 = automata_numerico.verificar_entrada(&lexema_string,temp2);
        cout<<lexema_string<<"_caso1"<<endl;
        cout<<caso1<<"_caso1"<<endl;
        if(caso1!=0){
          cout<<caso1<<"_caso1 gou!"<<endl;
          //string temp_token_str = map_token_numerico[automata_numerico.verificar_entrada(&lexema_string,temp2)];
          // cout<<map_token_numerico[automata_numerico.verificar_entrada(&lexema_string,temp2)]<<endl;
            string temp_token_str1=map_token_numerico[automata_numerico.verificar_entrada(&lexema_string,temp2)];
          lexemas_tokens.push_back(make_pair(lexema_string,temp_token_str1+to_string(id_count_numero)));
          id_count_numero++;
          //continue;
        }

        int caso2 = automata_string.verificar_entrada(&lexema_string,temp2);
        cout<<lexema_string<<"_caso2"<<endl;
        cout<<caso2<<"_caso2"<<endl;
        if(caso2!=0){
          cout<<caso2<<"_caso2 gou!"<<endl;
          //string temp_token_str = map_token_string[automata_numerico.verificar_entrada(&lexema_string,temp2)];
          string temp_token_str2=map_token_string[automata_string.verificar_entrada(&lexema_string,temp2)];
          lexemas_tokens.push_back(make_pair(lexema_string,temp_token_str2 + std::to_string(id_count_string)));
          id_count_string++;
          //continue;
        }



      }
    }
    it2++;
  }
  cout<<"++++++++++++++++++++++"<<endl;

  cout<<"*********************"<<endl;
  it_lexemas_tokens=lexemas_tokens.begin();
  while(it_lexemas_tokens!=lexemas_tokens.end()){
    cout<<it_lexemas_tokens->first<<" -> "<<it_lexemas_tokens->second<<endl;

    it_lexemas_tokens++;
  }
  cout<<"*********************"<<endl;

  /////////////////////////////////////////////////////
  //fin tokenizando
  /////////////////////////////////////////////////////




  return 0;









}
