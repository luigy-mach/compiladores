

#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <string>
#include "defines_includes.hpp"


#include "analizador_lexico.hpp"



using namespace std;


int main(int argc, char *argv[]){
  class_analizador_lexico analizador;


  vector< pair<string,string> > vec;
  analizador.inicializar_analizardor_lexico("jhony4.ino");
  analizador.obtener_vector_tokens(vec);

  cout<<"//////////aaa//////////////////////////////"<<endl;

  std::vector<int> v={1,2,3,4,5,6,7,8,9};
  std::vector<int>::iterator it;
  //it=v.begin()+2;
  //v.erase(it);
  for(it=v.begin();it!=v.end();it++){
    if(*it==5){
      it=v.erase(it);
      
    }
    cout<<*it<<endl;

  }



  cout<<"FIN//////////////////////////////////////todo ok"<<endl;

  return 0;
}
