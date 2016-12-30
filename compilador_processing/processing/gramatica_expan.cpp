#include"gramatica_expan.hpp"


void gramatica_expan::inicializar(){
  leer_archivo(_tabla,ARCHIVO_GRAMATICA);
}

string gramatica_expan::obtener_estado(string num_reducir){
  if(_tabla.find(num_reducir)!=_tabla.end())
    return _tabla.find(num_reducir)->second.begin()->first;
  return STR_ERROR_OBTENER_GRAMATICA;
}

int gramatica_expan::obtener_estado_num(string num_reducir){
  if(_tabla.find(num_reducir)!=_tabla.end())
    return stoi(_tabla.find(num_reducir)->second.begin()->second);
  return -123456;
}

void gramatica_expan::leer_archivo(TABLA1& t,string archivo){
  queue<string> cola_buff;
  ifstream in(archivo);
  string buffer = STR_EMPTY;
  while(getline(in,buffer)){
    convertir_a_cola(buffer,STR_SIMBOLO_SEPARACION,cola_buff);
    //cout<<"........ .."<<buffer<<endl;
    insertar(t,cola_buff);
  }
  //imprimir_tabla(_tabla);
}


void gramatica_expan::convertir_a_cola(string str,string delimitador,queue<string>& vec){
  size_t pos=0;
  string buff = STR_EMPTY;

  while((pos=str.find(delimitador))!=string::npos){
      buff=str.substr(0,pos);
      if(pos>0){
        //cout<<"..........."<<buff<<endl;
        vec.push(buff);
      }
        str.erase(0,pos+delimitador.length());
    }
}


void gramatica_expan::insertar(TABLA1& t, queue<string>& fila){
  string num_fila = fila.front();
  fila.pop();
  string estado = fila.front();
  fila.pop();

  FILA1 temp;
    string num_estados = to_string(fila.size());
    temp.insert({estado,num_estados});

  //cout<<"###"<<num_fila<<"_"<<estado<<"_"<<num_estados<<endl;
  t.insert({num_fila,temp});
  while(!fila.empty()){
    fila.pop();
  }
}


void gramatica_expan::imprimir_tabla(TABLA1& t){

    cout<<"------------------------------------------------------------------"<<endl;

    for(TABLA1::iterator i=t.begin();i!=t.end();i++){

        cout<< STR_ESPACIO_SEPARADOR;
        for(FILA1::iterator j=i->second.begin();j!=i->second.end();j++){
            string cuadrito=STR_ESPACIO_SEPARADOR;
            string::iterator it=cuadrito.begin();
            string temp;
            temp = j->first;
            cuadrito.replace(it,it+temp.size(),temp);
            cout<< cuadrito ;
        }
        cout<<endl ;
        break;
    }

    for(TABLA1::iterator i=t.begin();i!=t.end();i++){
        string tmp=STR_ESPACIO_SEPARADOR;
        string tmp2=i->first +"  -> ";
        tmp.replace(tmp.begin(),tmp.begin()+tmp2.size(),tmp2);
        cout<< tmp;

        for(FILA1::iterator j=i->second.begin();j!=i->second.end();j++){

            string cuadrito=STR_ESPACIO_SEPARADOR;
            string::iterator it=cuadrito.begin();
            string temp;
            for(auto z=j->second.begin();z!=j->second.end();z++){
                    temp+=*z;
            }
            cuadrito.replace(it,it+temp.size(),temp);
            cout<< cuadrito ;
        }
        cout<<endl;
    }
    cout<<"------------------------------------------------------------------"<<endl;

}
