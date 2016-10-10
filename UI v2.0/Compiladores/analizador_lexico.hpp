#ifndef ANALIZADOR_LEXICO_H
#define ANALIZADOR_LEXICO_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility> //pair
#include <algorithm> //remove
#include <unordered_map>

#include "tabla_token.hpp"
#include "normalizador.hpp"
#include "pre_processing.hpp"
#include "automaton.hpp"

using namespace normalizador;
using namespace pre_processing;


using namespace std;


class Analizador_Lexico
{
private:
    vector< pair<string,string> > lexemas_tokens;
    vector< pair<string,string> >::iterator it_lexemas_tokens;
public:
    Analizador_Lexico();
    void cargar_buffer(string& string_buffer, const string& archivo);
    void clean_word(string& str);
    void removeCharsFromString( string &str, const char* charsToRemove );
    void init_automata_string(AFD & automata_string);
    void init_automata_numerico(AFD & automata_numerico);
    void tokenizar_archivo(const string& nombre_archivo, vector< pair<string,string> >& lexemas_tokens);
    void analizar();
    void reset();

};

#endif // ANALIZADOR_LEXICO_H
