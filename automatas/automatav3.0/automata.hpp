
#ifndef ATOMATA_H
#define ATOMATA_H

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


#define STR_SIN_TOKEN "sin_token_define"
// #define NULL 0

class class_nodo;
struct class_hash{
    typedef std::unordered_map< string ,class_nodo* > type_string_hash;
    typedef std::unordered_map< char,class_nodo* > type_char_hash;
};

#define HASH_NODO class_hash::type_char_hash
#define HASH_ESTADOS class_hash::type_string_hash

//----------------------------------------------------
//nodo
//----------------------------------------------------
class class_nodo{
    HASH_NODO _myhash;
    int _tipo_bandera;
    string _token;
    string _qn;
public:
    class_nodo(string qn,int tipo_bandera, string token);
    void insertar_en_hash(class_nodo* pnodo, string str);
    bool verificar_char(char c,class_nodo*& pnodo);
    bool posee_token();
    string obtener_token();
    string obtener_qn();
    int obtener_tipo_bandera();

};
//----------------------------------------------------
//fin nodo
//----------------------------------------------------



//----------------------------------------------------
//automata
//----------------------------------------------------

class class_automata{
    class_nodo* _pComienzo;
    class_nodo* _pActual;
    HASH_ESTADOS _estados;
    string _acumulador;
    void reiniciar_posicion();
public:
    class_automata();
    void insertar_estado(string qn1, int tipo_bandera , string token);
    void insertar_transicion(string qn1, string qn2, string srt);
    string obtener_acumulador();
    int verificar_caracter_a_caracter(char c, string& token, string& acumulador);
    void verificar_cadena(string& cadena,vector< pair<string,string> >& resultado);  

};


//----------------------------------------------------
//fin automata
//----------------------------------------------------



//----------------------------------------------------
//funciones 
//----------------------------------------------------

bool es_ascci(char c);
string todo_menos(char c);

//----------------------------------------------------
//fin funciones
//----------------------------------------------------




#endif //AUTOMTA_H
