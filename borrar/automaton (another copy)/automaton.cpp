#include "automaton.hpp"

//----------------------------------------------------
//automaton
//----------------------------------------------------

//completarsh!

//----------------------------------------------------
//fin automaton
//----------------------------------------------------



//----------------------------------------------------
//automata_finito_determinista
//----------------------------------------------------
  datos::datos(){
    _nombre="vacio";
    _error=false;
  };
  datos::datos(string nombre, bool error){
    _nombre=nombre;
    _error=error;
  };





//----------------------------------------------------
//fin automata_finito_determinista
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
bool es_cero(char c){
  return (c==48)?true:false;
}

bool es_x(char c){
  return (c==88 || c==120)?true:false;
}
bool es_o(char c){
  return (c==79 || c==111)?true:false;
}

bool es_numero_sin_cero(char c){
  return (c>=49 && c<=57)?true:false;
}
bool es_numero_con_cero(char c){
  return (c>=48 && c<=57)?true:false;
}

bool es_octal(char c){
  return (c>=0 && c<=55)?true:false;
}

bool es_hex(char c){
  return ( es_numero_con_cero(c) || (c>=65 && c<=70) || (c>=97 && c<=102) )?true:false;
}
//----------------------------------------------------
//fin funciones
//----------------------------------------------------
