
#include "pre_processing.hpp"     // std::cout


// using namespace pre_processing;

void pre_processing::cargar_buffer(char* &buffer,const char* file_name){

  std::ifstream is (file_name, std::ifstream::binary);
  if (is) {
    is.seekg (0, is.end);
    int length = is.tellg();
	  is.seekg (0, is.beg);

    buffer = new char [length];
    is.read(buffer,length);
    is.close();
  }
}

void pre_processing::borrar_segmento_cadena(string& buffer,string::iterator& it_marca,string::iterator& it1,string::iterator& it2){
  // it_marca=it1;
  // string::iterator itt1=it1;
  // string::iterator itt2=it2;
  // string temp="";
  // while(itt1!=itt2){
  //   temp+=*itt1;
  //   itt1++;
  // }
  // cout<<"***"<<temp<<endl;
  buffer.erase(it1,it2);
  buffer.insert(it1,'\n');
  // it1=it_marca;
  // it2=it_marca;
}
//
// void pre_processing::borrar_segmento_cadena(string& buffer,string::iterator& it_marca,string::iterator& it1,string::iterator& it2){
//   it_marca=it1;
//   string::iterator itt1=it1;
//   string::iterator itt2=it2;
//   string temp="";
//   while(itt1!=itt2){
//     temp+=*itt1;
//     itt1++;
//   }
//
//   buffer.erase(it1,it2);
//   buffer.insert(it_marca,'\n');
//   it1=it_marca;
//   it2=it_marca;
// }


void pre_processing::borrar_comentarios_buffer(string& buffer){
  string::iterator it_marca;
  string::iterator it_temp;
  string::iterator it1;
  string::iterator it2;
  it_marca=it1=it2=buffer.begin();
  bool comentario_abierto=false;
  while(it2!=buffer.end()){
    if(*it2=='/'){
          it1=it2;
          it2++;
          if(*it2=='/'){
            while(*it2!='\n'){
              it2++;
            }
            it2++;
            borrar_segmento_cadena(buffer,it_marca,it1,it2);
          }
          else if(*it2=='*'){
              comentario_abierto=true;
              it2++;
              while(comentario_abierto){
                if(*it2=='*'){
                  it2++;
                  it_temp=it2;
                  if(*it_temp=='/'){
                    it_temp++;
                    borrar_segmento_cadena(buffer,it_marca,it1,it_temp);
                    comentario_abierto=false;
                  }
                }
                it2++;
              }
              if(it2==buffer.end()){
                borrar_segmento_cadena(buffer,it_marca,it1,it2);
              }
          }
      it2=it1;
    }
    it2++;
  }//fin while


}



//
//
// void pre_processing::borrar_comentarios_buffer(string& buffer){
//   string::iterator it_marca;
//   string::iterator it_temp;
//   string::iterator it1;
//   string::iterator it2;
//   it_marca=it1=it2=buffer.begin();
//   bool comentario_abierto=false;
//   while(it2!=buffer.end()){
//
//     if(!comentario_abierto && *it2=='/'){
//           it1=it2;
//           it2++;
//           if(*it2=='/'){
//             while(*it2!='\n'){
//               it2++;
//             }
//             it2++;
//             borrar_segmento_cadena(buffer,it_marca,it1,it2);
//           }
//           else if(*it2=='*'){
//               comentario_abierto=true;
//               it2++;
//           }
//     }
//     if(comentario_abierto){
//       if(*it2=='*'){
//         it_temp=it2;
//         it_temp++;
//         if(*it_temp=='/' || it_temp==buffer.end()){
//           it_temp++;
//           if(it_temp!=buffer.end()){
//             borrar_segmento_cadena(buffer,it_marca,it1,it_temp);
//           }
//           else{
//             it_temp--;
//             borrar_segmento_cadena(buffer,it_marca,it1,it_temp);
//           }
//           comentario_abierto=false;
//         }
//       }
//     }
//     it2++;
//   }//fin while
//
//
// }

void pre_processing::imprimir_en_archivo(const string& buff, string output_file){
  std::ofstream outfile (output_file.c_str(),std::ofstream::binary);
  char * buff_temp= new char[buff.size()+1];
  std::memcpy(buff_temp,buff.c_str(),buff.size()+1);
  outfile.write (buff_temp,buff.size()+1);
  // delete[] buff_temp;

}


void pre_processing::limpiar_comentarios_de_archivo(const string  input_file, string output_file){
  char* ifile=new char[input_file.size()+1];
  std::memcpy(ifile,input_file.c_str(),input_file.size()+1);
  char* ofile=new char[output_file.size()+1];
  std::memcpy(ofile,output_file.c_str(),output_file.size()+1);


  char* buff;

  cargar_buffer(buff,ifile);
  string buffer=buff;
  // delete[] buff;
  borrar_comentarios_buffer(buffer);
  imprimir_en_archivo(buffer,output_file);
}
