
#ifndef ATOMATAS_H
#define ATOMATAS_H


#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define AFD class_AFD<capsula>::type
#define AUTOMATON class_AFD<capsula>::type
typedef  bool (*pfun)(char c);


#define ERROR 0
#define SIN_NOMBRE "sin nombre"
#define IMCOMPLETO "incompleto"
#define SIN_TOKEN "sin token"

//----------------------------------------------------
//nodo
//----------------------------------------------------
class class_nodo{
  string _nombre;
  int _tipo;
  string _token;
public:
  class_nodo(){
    _nombre = SIN_NOMBRE;
    _tipo = ERROR;
    _token = SIN_TOKEN;
  }
  class_nodo(string nombre, int tipo, string token){
    _nombre = nombre;
    _tipo = tipo;
    _token = token;
  }
  
};
//----------------------------------------------------
//fin nodo
//----------------------------------------------------



//----------------------------------------------------
//automaton
//----------------------------------------------------



//----------------------------------------------------
//fin automaton
//----------------------------------------------------



//----------------------------------------------------
//sobrecargas
//----------------------------------------------------
// template<typename K>
// bool operator==(const nodo<K>& a, const nodo<K>& b);
// template<typename K>
// bool operator<(const nodo<K>& a, const nodo<K>& b);
// template<typename K>
// bool operator>(const nodo<K>& a, const nodo<K>& b);

//
// template<typename K>
// bool operator==(const nodo<K>& a, const nodo<K>& b){
//   // return (a.nombre()==b.nombre())?true:false;
//   return (a.capsula()._nombre==b.capsula()._nombre)?true:false;
// }
//
// template<typename K>
// bool operator<(const nodo<K>& a, const nodo<K>& b){
//   return (a.capsula()._nombre<b.capsula()._nombre)?true:false;
// }
//
// template<typename K>
// bool operator>(const nodo<K>& a, const nodo<K>& b){
//   return (a.capsula()._nombre>b.capsula()._nombre)?true:false;
// }

//----------------------------------------------------
//fin sobrecargas
//----------------------------------------------------




//----------------------------------------------------
// funciones numeros
//----------------------------------------------------
bool es_cero(char c);
bool es_x(char c);
bool es_o(char c);
bool es_numero_sin_cero(char c);
bool es_numero_con_cero(char c);
bool es_octal(char c);
bool es_hex(char c);
//----------------------------------------------------
//fin funciones numeros
//----------------------------------------------------



//----------------------------------------------------
// funciones string
//----------------------------------------------------
bool es_letra(char c);
bool es_guion_bajo(char c);
bool es_numero(char c);
bool es_comilla(char c);
//----------------------------------------------------
//fin funciones string
//----------------------------------------------------








#endif //AUTOMTAS_H
