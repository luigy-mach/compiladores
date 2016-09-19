#include "tabla_token.hpp"






//----------------------------------------------------
//class_error
//----------------------------------------------------
int class_error::obtener_fila(){
  return _fila;
}
int class_error::obtener_columna(){
  return _columna;
}
string class_error::obtener_tipo_error(){
  return _tipo_error;
}
string class_error::obtener_solucion_error(){
  return _solucion_error;
}

//----------------------------------------------------
//fin class_error
//----------------------------------------------------



//----------------------------------------------------
//class_token
//----------------------------------------------------
class_error class_token::obtener_error(){
  return _error;
}
string class_token::obtener_token_del_lexema(){
  return _token_del_lexema;
}
//----------------------------------------------------
//fin class_token
//----------------------------------------------------






//----------------------------------------------------
//tabla_token
//----------------------------------------------------
void tabla_token::imprimir_tabla(){
  _it_tabla_token = _tabla_token.begin();
  while(_it_tabla_token!=_tabla_token.end()){
    cout<<_it_tabla_token->first<<" | "
        << _it_tabla_token->second.obtener_token_del_lexema()<< " | "
        << _it_tabla_token->second.obtener_error().obtener_fila() <<" | "
        << _it_tabla_token->second.obtener_error().obtener_columna()<<" | "
        << _it_tabla_token->second.obtener_error().obtener_tipo_error() <<" | "
        << _it_tabla_token->second.obtener_error().obtener_solucion_error() <<" | "
        <<endl;
    _it_tabla_token++;
  }
  return;
}

void tabla_token::iniciar_tokens_especificos(){
  insertar("int",class_token("INT") );
  insertar("main",class_token("MAIN") );
  insertar("while",class_token("WHILE") );
  insertar(";",class_token("PUNTO_COMA") );
  insertar(" ",class_token("ESPACIO") );
}


void tabla_token::insertar(const string lexema, const class_token& tok){
  _tabla_token.insert(_newpair(lexema,tok));
}

void tabla_token::insertar_token_no_especifico(const string lexema,
                                               const string token_lexema,
                                               const class_error& er){
  _tabla_token.insert(_newpair( lexema,class_token(token_lexema,er)));
}

void tabla_token::insertar_token_no_especifico(const string lexema,
                                               const string token_lexema,
                                               int f,
                                               int c,
                                               const string tipo_err,
                                               const string solucion_err){
  _tabla_token.insert(_newpair( lexema,class_token(token_lexema,class_error(f,c,tipo_err,solucion_err))));
}

//----------------------------------------------------
//fin tabla_token
//----------------------------------------------------





//----------------------------------------------------
//sobrecargas
//----------------------------------------------------

//----------------------------------------------------
//fin sobrecargas
//----------------------------------------------------



//----------------------------------------------------
// funciones
//----------------------------------------------------

//----------------------------------------------------
//fin funciones
//----------------------------------------------------
