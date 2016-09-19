
#ifndef TABLA_TOKEN_H
#define TABLA_TOKEN_H


#include <iostream>
#include <fstream>
#include <map>
#include <vector>

#include <string>

using namespace std;

typedef class tabla_token TABLA;


//----------------------------------------------------
//class_error
//----------------------------------------------------
class class_error{
  int _fila;
  int _columna;
  string _tipo_error;
  string _solucion_error;
public:
  class_error(int f=-1,
        int c=-1,
        string tipo_err="sin error",
        string sol_err="no hay error"){
    _fila=f;
    _columna=c;
    _tipo_error=tipo_err;
    _solucion_error=sol_err;
  }
  int obtener_fila();
  int obtener_columna();
  string obtener_tipo_error();
  string obtener_solucion_error();

};
//----------------------------------------------------
//fin class_error
//----------------------------------------------------




//----------------------------------------------------
//class_token
//----------------------------------------------------

class class_token{
  class_error _error;
  string _token_del_lexema;
public:
  class_token(const string token){
    _token_del_lexema=token;
    class_error er_temp;
    _error=er_temp;
  }
  class_token(const string token,const class_error& er){
    _token_del_lexema=token;
    _error=er;
  }
  class_error obtener_error();
  string obtener_token_del_lexema();
};
//----------------------------------------------------
//fin class_token
//----------------------------------------------------




//----------------------------------------------------
//tabla_token
//----------------------------------------------------

class tabla_token{
  typedef map<string,class_token> _map_tabla_token;
  typedef typename _map_tabla_token::iterator _it_map_tabla_token;
  typedef pair<string,class_token> _newpair;
  _map_tabla_token _tabla_token;
  _it_map_tabla_token _it_tabla_token;

  void insertar(const string lexema, const class_token& t);

public:
  tabla_token(){
    _it_tabla_token=_tabla_token.end();
  }
  void imprimir_tabla();
  void iniciar_tokens_especificos();
  void insertar_token_no_especifico(const string lexema, const string token_lexema, const class_error& er);
  void insertar_token_no_especifico(const string lexema, const string token_lexema , int f,int c, const string tipo_err,const string solucion_err);

};


//----------------------------------------------------
//fin tabla_token
//----------------------------------------------------






#endif //TABLA_TOKEN_H
