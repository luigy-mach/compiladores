#include <iostream>
#include <map>
#include <vector>
#include <utility> //pair
#include<algorithm> //remove



#include "tabla_token.hpp"
#include "normalizador.hpp"
#include "pre_processing.hpp"
// using namespace normalizador;
// using namespace pre_processing;


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
/////////////////////////////////////////////////////
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
mytabla.insertar_token_no_especifico("id2","ID",11000,1125,"todo bien","vacio");
mytabla.insertar_token_no_especifico("id1","ID",100,125,"error_fatal","matate");
//mytabla.imprimir_tabla();

/////////////////////////////////////////////////////
//fin tabla de tokens
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
  while(it2!=buffer.end()){
    if(*it2==' ' || *it2=='\n'){
      string lexema_string(it1,it2);
      removeCharsFromString( lexema_string, " \n" );
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
        //conectar con automaton!!!! AQUI!!!!
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
