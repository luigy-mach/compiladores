#include "automaton.hpp"

//----------------------------------------------------
//automaton
//----------------------------------------------------

//completarsh!

//----------------------------------------------------
//fin automaton
//----------------------------------------------------



//----------------------------------------------------
//automaton
//----------------------------------------------------
  capsula::capsula(){
    _nombre="vacio";
    _error=false;
  };
  capsula::capsula(string nombre, bool error){
    _nombre=nombre;
    _error=error;
  };





//----------------------------------------------------
//fin automaton
//----------------------------------------------------





//----------------------------------------------------
//sobrecargas
//----------------------------------------------------

//----------------------------------------------------
//fin sobrecargas
//----------------------------------------------------



//----------------------------------------------------
// funciones numeros
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
//fin funciones numeros
//----------------------------------------------------




//----------------------------------------------------
// funciones string
//----------------------------------------------------
bool es_letra(char c){
  return ((c>=65 && c<=90) || (c>=97 && c<=122))?true:false;
}

bool es_guion_bajo(char c){
  return (c==95)?true:false;
}

bool es_numero(char c){
  return (c>=48 && c<=57)?true:false;
}

bool es_comilla(char c){
  return (c==34)?true:false;
}
//----------------------------------------------------
//fin funciones string
//----------------------------------------------------