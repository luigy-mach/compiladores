#include <iostream>
#include <map>
#include <vector>

#include "tabla_token.hpp"


using namespace std;


int main(int argc, char *argv[]){



  TABLA mytabla;
  mytabla.iniciar_tokens_especificos();

  mytabla.insertar_token_no_especifico("id1","ID",100,125,"error_fatal","matate");
  mytabla.insertar_token_no_especifico("id2","ID",11000,1125,"todo bien","vacio");

  mytabla.imprimir_tabla();

  return 0;
}
