#ifndef NORMALIZADOR_H
#define NORMALIZADOR_H

#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

#define normalizador(x,y) normalizar(x,y)
namespace normalizador{

  void cargar_map(char* &pointer,map<char,char> & mymap);
  void normalizar_cadena(string & mystr,char* &pointer,map<char,char> & mymap);
  void normalizar_archivo(const char* & input,const char* & ouput);
}
#endif //NORMALIZADOR_H