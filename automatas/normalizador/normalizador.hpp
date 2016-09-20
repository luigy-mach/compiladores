#ifndef NORMALIZADOR_H
#define NORMALIZADOR_H

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cstring>


using namespace std;

#define normalizador(x,y) normalizar_archivo(x,y)

namespace normalizador{

  void cargar_map(char* &pointer,map<char,char> & mymap);
  void normalizar_cadena(string & mystr,char* &pointer,map<char,char> & mymap);
  void normalizar_archivo(const char* & input,const char* & ouput);
  void normalizar_archivo(const string& in,const string& out);
}
#endif //NORMALIZADOR_H
