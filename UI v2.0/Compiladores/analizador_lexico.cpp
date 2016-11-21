#include "analizador_lexico.hpp"
#include <QDebug>
Analizador_Lexico::Analizador_Lexico()
{
}
void Analizador_Lexico::cargar_buffer(string& string_buffer, const string& archivo){

  char* buffer;
  char* file_name= new char[archivo.size()+1];
  std::memcpy(file_name,archivo.c_str(),archivo.size()+1);


  std::ifstream is (file_name, std::ifstream::binary);

  if (is) {
  // qDebug() << "Inside  is:::";
    is.seekg (0, is.end);
    int length = is.tellg();
      is.seekg (0, is.beg);

    buffer = new char [length];
    is.read(buffer,length);
    is.close();
  }

  string_buffer=buffer;

}

void Analizador_Lexico::clean_word(string& str){
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


void Analizador_Lexico::removeCharsFromString( string &str, const char* charsToRemove ) {
   for ( unsigned int i = 0; i < strlen(charsToRemove); ++i ) {
      str.erase( remove(str.begin(), str.end(), charsToRemove[i]), str.end() );
   }
}




void Analizador_Lexico::init_automata_string(AFD & automata_string){




  automata_string.insertar_estado(capsula("q100"),-101); // inicial
  automata_string.insertar_estado(capsula("q101"), 101); // terminal 101
  automata_string.insertar_estado(capsula("q102"), 102); // terminal 102
  automata_string.insertar_estado(capsula("q103"), 100); //  no terminal q103
  automata_string.insertar_estado(capsula("q104"), 104); // terminal 104
  automata_string.insertar_estado(capsula("q105"), 104); // terminal 104

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




}



void Analizador_Lexico::init_automata_numerico(AFD & automata_numerico){
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
  automata_numerico.insertar_estado(capsula("q7"), 0); // terminal 5
  automata_numerico.insertar_estado(capsula("q8"), 7); // terminal 6

  automata_numerico.insertar_transicion(capsula("q0"),capsula("q1"),*es_cero);
  automata_numerico.insertar_transicion(capsula("q0"),capsula("q2"),*es_numero_con_cero);
  automata_numerico.insertar_transicion(capsula("q0"),capsula("q8"),*es_punto);

  automata_numerico.insertar_transicion(capsula("q2"),capsula("q2"),*es_numero_con_cero);

  automata_numerico.insertar_transicion(capsula("q1"),capsula("q1"),*es_cero);
  automata_numerico.insertar_transicion(capsula("q1"),capsula("q2"),*es_numero_sin_cero);
  automata_numerico.insertar_transicion(capsula("q1"),capsula("q3"),*es_x);
  automata_numerico.insertar_transicion(capsula("q1"),capsula("q4"),*es_o);

  automata_numerico.insertar_transicion(capsula("q3"),capsula("q5"),*es_hex);
  automata_numerico.insertar_transicion(capsula("q5"),capsula("q5"),*es_hex);

  automata_numerico.insertar_transicion(capsula("q4"),capsula("q6"),*es_octal);
  automata_numerico.insertar_transicion(capsula("q6"),capsula("q6"),*es_octal);

  automata_numerico.insertar_transicion(capsula("q7"),capsula("q8"),*es_numero_con_cero);
  automata_numerico.insertar_transicion(capsula("q8"),capsula("q8"),*es_numero_con_cero);




    // -1 =  no inicial
    // 0 = error
    // 1 = solo ceros
    // 2 = numero natural incluido el cero
    // 5 = hexadecimal
    // 6 = octal
}



void Analizador_Lexico::tokenizar_archivo(const string& nombre_archivo, vector< pair<string,string> >& lexemas_tokens){

  /////////////////////////////////////////////////////
  //tabla de tokens
  /////////////////////////////////////////////////////
  TABLA mytabla;
  mytabla.iniciar_tokens_especificos();
  // mytabla.insertar_token_no_especifico("id1","ID",100,125,"error_fatal","matate");
  //mytabla.imprimir_tabla();
  /////////////////////////////////////////////////////
  //fin tabla de tokens
  /////////////////////////////////////////////////////


  /////////////////////////////////////////////////////
  //automaton++
  /////////////////////////////////////////////////////
  unordered_map <int,string> map_token_general;
  map_token_general.insert ( std::pair<int,string>(0,"CADENA INVALIDA_NUMERO") );
  map_token_general.insert ( std::pair<int,string>(1,"CERO") );
  map_token_general.insert ( std::pair<int,string>(2,"NUMERO") );
  map_token_general.insert ( std::pair<int,string>(5,"HEXADECIMAL") );
  map_token_general.insert ( std::pair<int,string>(6,"OCTAL") );
  map_token_general.insert ( std::pair<int,string>(7,"DECIMAL") );

  map_token_general.insert ( std::pair<int,string>(100,"CADENA INVALIDA_STRING") );
  map_token_general.insert ( std::pair<int,string>(101,"ID") );
  map_token_general.insert ( std::pair<int,string>(102,"ID") );
  map_token_general.insert ( std::pair<int,string>(104,"STRING") );
  map_token_general.insert ( std::pair<int,string>(-34404,"ERROR_CADENA") );

  AFD automata_string;
  init_automata_string(automata_string);


  AFD automata_numerico;
  init_automata_numerico(automata_numerico);

  /////////////////////////////////////////////////////
  //fin automaton++
  /////////////////////////////////////////////////////

//qInfo() << "C++ Style Info Message";
  string buffer;
  cargar_buffer(buffer,"normalizado.txt");
    cout<<buffer<<endl;
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
      cout<<"_____________________"<<endl;
      cout<<"\""<<lexema_string<<"\""<<endl;
      cout<<"_____________________"<<endl;

      buffer.erase(it1,it2);
      it1=it2=buffer.begin(); //qDebug()<<fileName;);
      // it2=it1;
      it2++;
      buffer.erase(it1,it2);
      it1=it2=buffer.begin();
      bool encontrado = mytabla.buscar(lexema_string,token_string);
      if(encontrado){
        lexemas_tokens.push_back(make_pair(lexema_string,token_string));

      }
      else{
        capsula temp2("prueba",true);

        cout<<"_____________________"<<endl;
        int caso1 = automata_numerico.verificar_entrada(&lexema_string,temp2);
        cout<<lexema_string<<" _caso1"<<endl;
        cout<<caso1<<" _caso1"<<endl;
        if(caso1!=-34404 && caso1!=0){
          string temp_token_str1=map_token_general[automata_numerico.verificar_entrada(&lexema_string,temp2)];
          lexemas_tokens.push_back(make_pair(lexema_string,temp_token_str1+to_string(id_count_numero)));
          id_count_numero++;
          cout<<caso1<<" _caso1 gou!"<<endl;
        }

        cout<<"_____________________"<<endl;
        int caso2 = automata_string.verificar_entrada(&lexema_string,temp2);
        cout<<lexema_string<<" _caso2"<<endl;
        cout<<caso2<<" _caso2"<<endl;
        if(caso2!=-34404 && caso2!=100){
          string temp_token_str2=map_token_general[automata_string.verificar_entrada(&lexema_string,temp2)];
         // lexemas_tokens.push_back(make_pair(lexema_string,temp_token_str2 + std::to_string(id_count_string)));
          lexemas_tokens.push_back(make_pair(lexema_string,temp_token_str2));
          id_count_string++;
          cout<<caso2<<" _caso2 gou!"<<endl;
        }

      }
    }
    it2++;
  }
  cout<<"++++++++++++++++++++++"<<endl;
}


void Analizador_Lexico::analizar()
{

    vector< pair<string,string> > lexemas_tokens;
    vector< pair<string,string> >::iterator it_lexemas_tokens;

    /////////////////////////////////////////////////////
    //fin array lexemas
    /////////////////////////////////////////////////////


    /////////////////////////////////////////////////////
    //preprocesado
    ///////////////////////////////////////////////////////
      pre_processing::pre_processing
              ("compilar.txt"
              ,"preprocesado.txt");
      normalizador::normalizador("preprocesado.txt","normalizado.txt");

    /////////////////////////////////////////////////////
    //fin preprocesado
    ///////////////////rchivos///////////////////////////////////

    /////////////////////////////////////////////////////
    //tokenizando
    /////////////////////////////////////////////////////

    tokenizar_archivo("normalizado.txt", lexemas_tokens);


    /////////////////////////////////////////////////////
    //"fin tokenizando
    /////////////////////////////////////////////////////
    cout<<"Antes de Archivo"<<endl;
    ofstream outfile("procesado.txt");

    it_lexemas_tokens=lexemas_tokens.begin();

    cout<<"size v tokens"<<lexemas_tokens.size()<<endl;

    while(it_lexemas_tokens!=lexemas_tokens.end())
    {
      cout<<it_lexemas_tokens->first<<" -> "<<it_lexemas_tokens->second<<endl;
      outfile<<it_lexemas_tokens->first<<" -> "<<it_lexemas_tokens->second<<endl;

      it_lexemas_tokens++;
    }
    cout<<"Despues de Archivo"<<endl;

    outfile.close();
}
