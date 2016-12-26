#include "automata.hpp"

//----------------------------------------------------
//nodo
//----------------------------------------------------

class_nodo::class_nodo(string qn,int tipo_bandera, string token){
    _qn=qn;
    _tipo_bandera=tipo_bandera;
    _token=token;
}

void class_nodo::insertar_en_hash(class_nodo* pnodo, string str){
  string::iterator it1;
  it1=str.begin();
  while(it1!=str.end()){
    _myhash.insert({*it1,pnodo});
    it1++;
  }
}

void class_nodo::insertar_en_hash(class_nodo* pnodo, char str){

  _myhash.insert({str,pnodo});

}

bool class_nodo::verificar_char(char c,class_nodo*& pnodo){
  if(_myhash.find(c)!=_myhash.end()){
    pnodo=_myhash[c];
    return true;
  }
  pnodo=NULL;
  return false;
}

bool class_nodo::posee_token(){
  return _tipo_bandera>0?true:false;
}

string class_nodo::obtener_token(){
  if(this->posee_token()){
    return _token;
  }
  else
  {
    return STR_SIN_TOKEN;
  }
}

string class_nodo::obtener_qn(){
  return _qn;
}

int class_nodo::obtener_tipo_bandera(){
  return _tipo_bandera;
}

//----------------------------------------------------
//fin nodo
//----------------------------------------------------



//----------------------------------------------------
//automata
//----------------------------------------------------

class_automata::class_automata(){
  _pComienzo=NULL;
  _pActual=NULL;
   _acumulador="";
}

void class_automata::insertar_estado(string qn1, int tipo_bandera , string token){
  if(!_pComienzo){
    _pComienzo=new class_nodo(qn1,tipo_bandera,token);
    _pActual=_pComienzo;
    _estados.insert({qn1,_pComienzo});
  }
  class_nodo* pnodotemp;
  pnodotemp=new class_nodo(qn1,tipo_bandera,token);
  _estados.insert({qn1,pnodotemp});
}

void class_automata::insertar_transicion(string qn1, string qn2, string str){
  class_nodo* pnodo1=NULL;
  class_nodo* pnodo2=NULL;
  pnodo1=_estados[qn1];
  pnodo2=_estados[qn2];
  if(pnodo1 && pnodo2){
    pnodo1->insertar_en_hash(pnodo2,str);
  }
}

void class_automata::insertar_transicion(string qn1, string qn2, char str){
  class_nodo* pnodo1=NULL;
  class_nodo* pnodo2=NULL;
  pnodo1=_estados[qn1];
  pnodo2=_estados[qn2];
  if(pnodo1 && pnodo2){
    pnodo1->insertar_en_hash(pnodo2,str);
  }
}




void class_automata::reiniciar_posicion(){
  _pActual=_pComienzo;
  _acumulador="";
}

string class_automata::obtener_acumulador(){
  return _acumulador;
}

int class_automata::verificar_caracter_a_caracter(char c, string& token, string& acumulador){
  class_nodo* pnodotemp=NULL;
  es_ascci(c);

  if(_pActual->verificar_char(c,pnodotemp)){
    _pActual=pnodotemp;
    _acumulador=_acumulador+c;
    return 0;//continuar recibiendo
  }
  if(_pActual==_pComienzo){
    _acumulador=_acumulador+c;
  }
  token =_pActual->obtener_token();
  acumulador=this->obtener_acumulador();
  this->reiniciar_posicion();

  if(token==STR_SIN_TOKEN){
    return -1;// error automata
  }
  return 1; // cadena aceptada en automata
}

void class_automata::verificar_cadena(string& cadena,vector<pair<string,string>>& resultado){
  string::iterator it1=cadena.begin();
  string temp1="vacio_token";
  string temp2="vacio_acumulador";
  int x=0;
  while(it1!=cadena.end()){
        int option = this->verificar_caracter_a_caracter(*it1,temp1,temp2);
        int i=-3;

        switch (option)
        {
          case 1:   resultado.push_back(pair<string,string>(temp2,temp1));
                    // cout<<"if 1 guardar: "<<*it1<<endl;
                    x++;
                    break;

          case 0:   //cout<<"if 2 continuar extrayendo: "<<*it1<<endl;
                    x++;
                    it1++;
                    break;

          case -1:  temp1=STR_SIMBOLO_DESCONOCIDO;
                    resultado.push_back(pair<string,string>(temp2,temp1));
                    // cout<<"else 2 error_cadena: "<<*it1<<endl;
                    x++;
                    it1++;
                    break;
          default: cout<<"algo malo paso aqui!"<<endl;
        }
  }
}

//----------------------------------------------------
//fin automata
//----------------------------------------------------




//----------------------------------------------------
//funciones
//----------------------------------------------------

bool es_ascci(char c){
  if(c>=0 && c<=254){
      return true;
  }
  // throw -1;
  return false;
}
string todo_menos(char c){
  string temp="";
  cout<<">>>>>>>>>>>>>>>>>>>>>:> "<<c<<" < "<<endl;
  for(int i=0;i<256;i++){
    if(i!=c){
      char tchar=i;
      temp=temp+tchar;
    }
  }
  return temp;
}
//----------------------------------------------------
//fin funciones
//----------------------------------------------------
