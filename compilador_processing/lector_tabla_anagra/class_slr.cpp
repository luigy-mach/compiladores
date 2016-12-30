
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

  cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@1"<<endl;
  while( !gramatica_aceptada(cabeza_salida, cabeza_entrada) && pila_entrada.size()>2 ){
    cabeza_entrada=pila_entrada.top();
    cabeza_salida=pila_salida.top();

    cout<<"mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm1"<<endl;
    cout<<cabeza_salida<<"<-->"<<cabeza_entrada<<endl;
    cout<<"        tamaños de colas: "<<pila_salida.size()<<" - "<<pila_entrada.size()<<endl;

    string memoria = _tabla.consultar(cabeza_salida,cabeza_entrada);
    //cout<<cabeza_salida<<"<-->"<<cabeza_entrada<<">>"<<endl;
    // cout<<"memoria: "<<memoria<<endl;
    if( memoria == STR_ACEPTACION ){
      cout<<"TODO Okkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk!"<<endl;
      return "gramatica_aceptadaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    }


    string x=memoria.substr(0,1);
    string y=memoria.substr(1);
    cout<<"memoria  : "<<x<<" <-> "<<y<<endl;
    if(x=="d"){
    // if(x==STR_DESPLAZAMIENTO){
      cout<<"     desplazamiento:"<<x<<y<<endl;
      pila_salida.push(cabeza_entrada);
      pila_salida.push(y);
      pila_entrada.pop();

    // }else if(x==STR_REDUCCION){
    }
    else if(x=="r"){
        cout<<"     reduccion: "<< x <<" - "<< y <<endl;
        string estado_reduccion = _reducciones.obtener_estado(y);
        cout<<"         estado_reduccion: "<< estado_reduccion << endl;
        int num_pop = _reducciones.obtener_estado_num(y);
        cout<<"         num_pop: " << num_pop <<endl;
        for(int i=0;i<num_pop*2;i++){
          cout<<"------inicio"<<endl;
          cout<<"       pop :"<<pila_salida.top()<<endl;
          pila_salida.pop();
          cout<<"------fin"<<endl;
        }
      cout<<">>> :"<<pila_salida.top()<<endl;
      string temporal = _tabla.consultar(pila_salida.top(),estado_reduccion);
      cout<<"> : "<< temporal <<"!!!!"<<endl;
      pila_salida.push(estado_reduccion);
      pila_salida.push(temporal);
    }
    else{
      cout<<"algo muy malo paso >> no es ni D ni R"<<endl;
      return "gramatica no reconocida >> error_en_tabla R_D";
    }
    cout<<"mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm2"<<endl;
  }

  cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@2"<<endl;

  cout<<"TODO OK!"<<endl;
  return "gramatica reconocida";
}


bool slr::gramatica_aceptada(string fil, string col){
  string temp=_tabla.consultar(fil,col);
  return temp==STR_ACEPTACION?true:false;
}
