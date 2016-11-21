
#ifndef ANALIZADOR_LEXICO_H
#define ANALIZADOR_LEXICO_H

#include "defines_includes.hpp"

#include <iostream>
#include <vector>
#include <unordered_map>

#include "automata.hpp"
#include "tabla_token.hpp"
using namespace std;



//----------------------------------------------------
//ANALIZADOR_LEXICO
//----------------------------------------------------
class class_analizador_lexico{
public:
    class_automata* _myautomata;
    class_tabla_token* _mytabla;
    void cargar_automata();
    void cargar_tabla_token_especificos();

public:
    class_analizador_lexico();
    void inicializar_analizardor_lexico();
    void cargar_archivo(string& archivo);

};

//----------------------------------------------------
//fin ANALIZADOR_LEXICO
//----------------------------------------------------




//----------------------------------------------------
//funciones 
//----------------------------------------------------

//----------------------------------------------------
//fin funciones
//----------------------------------------------------




#endif //ANALIZADOR_LEXICO_H
