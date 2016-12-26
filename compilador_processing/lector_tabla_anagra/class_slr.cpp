
#include "class_slr.hpp"

void slr::resetear_pilas(){
  while(!pila_salida.empty())
    pila_salida.pop();
  while(!pila_entrada.empty())
      pila_entrada.pop();
  pila_salida.push("0");
  pila_entrada.push("$");
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
  string cabeza_salida="___";
  string cabeza_entrada="__*__";
  cabeza_entrada=pila_entrada.top();
  cabeza_salida=pila_salida.top();
  while(!gramatica_aceptada(cabeza_salida,cabeza_entrada) && pila_entrada.size()>2 ){
    cabeza_entrada=pila_entrada.top();
    cabeza_salida=pila_salida.top();
    cout<<"@@@@@@@@@@@@@@@@@1"<<endl;
    cout<<cabeza_salida<<"<-->"<<cabeza_entrada<<endl;
    cout<<pila_salida.size()<<"<-->"<<pila_entrada.size()<<endl;

    string memoria=_tabla.consultar(cabeza_salida,cabeza_entrada);
    cout<<cabeza_salida<<"+"<<cabeza_entrada<<">>"<<"_____________"<<endl;
    cout<<"memoria: "<<memoria<<endl;
    if(memoria==ACEPTACION){
      cout<<"TODO OK!"<<endl;
      return "gramatica_aceptada gol!!!";
    }
    string x=memoria.substr(0,1);
    string y=memoria.substr(1);
    if(x=="d"){
      cout<<"desplazamiento:"<<x<<y<<endl;
      pila_salida.push(cabeza_entrada);
      pila_salida.push(y);
      pila_entrada.pop();

    }else if(x=="r"){
      cout<<"reduccion:"<<x<<y<<endl;
      string estado_reduccion=_reducciones.obtener_estado(y);
      int num_pop=stoi(_reducciones.obtener_estado_num(y));
      cout<<estado_reduccion<<num_pop<<endl;
      for(int i=0;i<num_pop*2;i++){
        cout<<"pop :"<<pila_salida.top()<<endl;
        pila_salida.pop();
      }
      cout<<">>> :"<<pila_salida.top()<<endl;
      string temporal=_tabla.consultar(pila_salida.top(),estado_reduccion);
      cout<<temporal<<"!!!!"<<endl;
      pila_salida.push(estado_reduccion);
      pila_salida.push(temporal);
    }
    else{
      cout<<"algo muy malo paso"<<endl;
      return "gramtica no reconocida";
    }
    cout<<"@@@@@@@@@@@@@@@@@2"<<endl;
  }
  cout<<"TODO OK!"<<endl;
  cout<< "gramatica_aceptada gol222!!!"<<endl;
  cout<<"@@@@@@@@@@@@@@@@@FIN"<<endl;

}



bool slr::gramatica_aceptada(string fil, string col){
  string temp=_tabla.consultar(fil,col);
  return temp==ACEPTACION?true:false;
}
