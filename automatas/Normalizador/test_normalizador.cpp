#include <iostream>
#include <map>
#include <string>
#include "normalizador.hpp"


using namespace std;
using namespace normalizador;

//enum token {    cvb=0, cero=1, numero=2, octal= 5, hexadecimal=6 };


int main(){
  const char* input="in.txt";
  const char* ouput="ou.txt";
  normalizador::normalizar_archivo(input,ouput);
  return 0;
}
