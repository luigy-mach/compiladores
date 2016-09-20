#ifndef PRE_PROCESSING_H
#define PRE_PROCESSING_H


#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <string>
#include <cstring>


using namespace std;

#define pre_processing(x,y) limpiar_comentarios_de_archivo(x,y)

namespace pre_processing{
  void cargar_buffer(char* &buffer, const char* file_name);
  void borrar_segmento_cadena(string& buffer,string::iterator& it_marca,string::iterator& it1,string::iterator& it2);
  void borrar_comentarios_buffer(string& buffer);
  void imprimir_en_archivo(const string& buff, string output_file);
  void limpiar_comentarios_de_archivo(const string  input_file, string output_file);
}





#endif //PRE_PROCESSING_H
