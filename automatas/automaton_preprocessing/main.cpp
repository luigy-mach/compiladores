// read a file into memory
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream


#include<string>

using namespace std;



void cargar_buffer(char* &buffer){

  std::ifstream is ("test.txt", std::ifstream::binary);
  if (is) {
    is.seekg (0, is.end);
    int length = is.tellg();
	  is.seekg (0, is.beg);

    buffer = new char [length];
    is.read(buffer,length);
    is.close();
    //cout<<buffer<<endl;
  }
}

void borrar_segmento_cadena(string& buffer,string::iterator& it_marca,string::iterator& it1,string::iterator& it2){
  it_marca=it1;
  buffer.erase(it1,it2);
  buffer.insert(it_marca,'\n');
  it1=it_marca;
  it2=it_marca;
}


void borrar_comentarios_buffer(string& buffer, string& resultado){
  string::iterator it_marca;
  string::iterator it1;
  string::iterator it2;
  it_marca=it1=it2=buffer.begin();
  while(it2!=buffer.end()){
    if(*it2=='/'){
        it1==it2;
        it2++;
        if(*it2=='/'){
          while(*it2!='\n'){
            it2++;
          }
          borrar_segmento_cadena(buffer,it_marca,it1,it2);
        }
        else if(*it2=='*'){

        }
    }
    it2++;
  }


}





int main () {

  char* buff;
  cargar_buffer(buff);
  string buffer=buff;
  delete[] buff;
  string resultado="resultado_vacio";
  borrar_comentarios_buffer(buffer,resultado);

  //cout<<resultado<<endl;



  // string prueba="hola \nesto \nes \nuna prueba";
  // string prueba="hola \nesto es una prueba";
  string prueba="012\n345\n6789";
  string::iterator it_marca=prueba.begin();
  string::iterator it1=prueba.begin();
  string::iterator it2=prueba.begin();
  //borrar_segmento_cadena(prueba,it_marca,it1,it2);
  cout<<prueba<<endl;
  cout<<"////////////////////////"<<endl;
  while(it2 != prueba.end()){
    if(*it2=='\n'){
      it1=it2;
      it2++;
      borrar_segmento_cadena(prueba,it_marca,it1,it2);
      // cout<<"it1:\""<<*it1<<"\""<<endl;
      // cout<<"it2:\""<<*it2<<"\""<<endl;
    }

    it2++;
  }
  cout<<"\""<<prueba<<"\""<<endl;



  // cout<<*it_marca<<endl;
  // if(it1!=prueba.end())
  // cout<<"it1:\""<<*it1<<"\""<<endl;
  // if(it2!=prueba.end())
  // cout<<"it2:\""<<*it2<<"\""<<endl;


  return 0;
}
