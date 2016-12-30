
#include "class_slr.hpp"


void slr::iniciar_slr(){
  _tabla.inicializar_tabla();
  _reducciones.inicializar();
  resetear_pilas();
}


void slr::resetear_pilas(){
  while(!pila_salida.empty())
    pila_salida.pop();
  while(!pila_entrada.empty())
      pila_entrada.pop();
  pila_salida.push(SIMBOLO_INICIO);
  pila_entrada.push(SIMBOLO_PARADA);
}

void slr::insertar_consulta(vector<string>& vec){
  resetear_pilas();
  vector<string>::reverse_iterator rit;
  for(rit=vec.rbegin() ; rit!=vec.rend() ; rit++){
    pila_entrada.push(*rit);
  }
}


string slr::verificar_entrada(vector<string>& query){
  insertar_consulta(query);
  string cabeza_salida  = STR_EMPTY;
  string cabeza_entrada = STR_EMPTY;
  cabeza_entrada = pila_entrada.top();
  cabeza_salida  = pila_salida.top();

  while( !gramatica_aceptada(cabeza_salida, cabeza_entrada) && pila_entrada.size()>2 ){
    cabeza_entrada=pila_entrada.top();
    cabeza_salida=pila_salida.top();

    string memoria = _tabla.consultar(cabeza_salida,cabeza_entrada);
    if( memoria == STR_ACEPTACION ){
      cout<<"todo ok!"<<endl;
      return "gramatica_aceptada";
    }
    string x=memoria.substr(0,1);
    string y=memoria.substr(1);
    if(x=="d"){
      pila_salida.push(cabeza_entrada);
      pila_salida.push(y);
      pila_entrada.pop();
    }
    else if(x=="r"){
        string estado_reduccion = _reducciones.obtener_estado(y);
        int num_pop = _reducciones.obtener_estado_num(y);
        for(int i=0;i<num_pop*2;i++){
          pila_salida.pop();
        }
      string temporal = _tabla.consultar(pila_salida.top(),estado_reduccion);
      pila_salida.push(estado_reduccion);
      pila_salida.push(temporal);
    }
    else{
      return "gramatica no reconocida ";
    }
  }
  return "gramatica reconocida";
}




string slr::verificar_entrada_2(vector< pair<string,string> >& query1){
  vector< pair<string,string> >::iterator it;
  vector<string> query;
  for(it=query1.begin();it!=query1.end();it++){
    query.push_back(it->second);
  }
  // for(vector<string>::iterator ii=query.begin();ii!=query.end();ii++){
  //   cout<<*ii<<endl;
  // }
  insertar_consulta(query);
  string cabeza_salida  = STR_EMPTY;
  string cabeza_entrada = STR_EMPTY;
  cabeza_entrada = pila_entrada.top();
  cabeza_salida  = pila_salida.top();

  while( !gramatica_aceptada(cabeza_salida, cabeza_entrada) && pila_entrada.size()>2 ){
    cabeza_entrada=pila_entrada.top();
    cabeza_salida=pila_salida.top();

    string memoria = _tabla.consultar(cabeza_salida,cabeza_entrada);
    if( memoria == STR_ACEPTACION ){
      return "gramatica_aceptada";
    }


    string x=memoria.substr(0,1);
    string y=memoria.substr(1);
    if(x=="d"){
      pila_salida.push(cabeza_entrada);
      pila_salida.push(y);
      pila_entrada.pop();
    }
    else if(x=="r"){
        string estado_reduccion = _reducciones.obtener_estado(y);
        int num_pop = _reducciones.obtener_estado_num(y);
        for(int i=0;i<num_pop*2;i++){
          pila_salida.pop();
        }
      string temporal = _tabla.consultar(pila_salida.top(),estado_reduccion);
      pila_salida.push(estado_reduccion);
      pila_salida.push(temporal);
    }
    else{
      return "gramatica no reconocida";
    }
  }
  return "gramatica reconocida";
}


bool slr::gramatica_aceptada(string fil, string col){
  string temp=_tabla.consultar(fil,col);
  return temp==STR_ACEPTACION?true:false;
}
