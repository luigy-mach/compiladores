#include <iostream>
#include <map>
#include <string>
#include "normalizador.hpp"


using namespace std;
using namespace normalizador;

//enum token {    cvb=0, cero=1, numero=2, octal= 5, hexadecimal=6 };


int main(){

  normalizador::normalizador("in.txt","ou.txt");

  return 0;
}
