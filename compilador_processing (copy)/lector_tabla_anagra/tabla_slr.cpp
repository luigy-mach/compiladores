#include"tabla_slr.hpp"


string tabla_anagra::consultar(string fila, string columna){
  if( _tabla.find(fila) == _tabla.end() ){
    cout<< "xxxxxx cout : error interno: errorXX_fila--->"<<fila<<endl;
    return "xxxxxx: errorXX_fila: no encontrada";
  }
  if( _tabla.find(fila)->second.find(columna)==_tabla.find(fila)->second.end() ) {
    cout<< "xxxxxx cout : error interno: errorYY_columna--->"<<columna<<endl;
    return "xxxxxx: errorYY_columna: no encontrada :";
  }
  string temp = _tabla.find(fila)->second.find(columna)->second;

  return temp;
}

void tabla_anagra::leer_archivo(TABLA& t,string archivo){
  queue<string> cola_cabecera;
  queue<string> cola_buff;
  ifstream in(archivo);
  string buffer = STR_EMPTY;
  string cabecera = STR_EMPTY;
  getline(in,cabecera);
  convertir_a_cola(cabecera,STR_SIMBOLO_SEPARACION,cola_cabecera);
    cola_cabecera.pop();
  while(getline(in,buffer)){
    convertir_a_cola(buffer,STR_SIMBOLO_SEPARACION,cola_buff);
    insertar(t,cola_cabecera,cola_buff);
  }
  //imprimir_tabla(_tabla);
}


void tabla_anagra::convertir_a_cola(string str,string delimitador,queue<string>& vec){
  size_t pos=0;
  string buff;
  while((pos=str.find(delimitador))!=string::npos){
      buff=str.substr(0,pos);
      string error=MSJ_ERROR;
      pos==0?vec.push(error):vec.push(buff);
      str.erase(0,pos+delimitador.length());
  }
  buff=str.substr(0,pos);
  string error=MSJ_ERROR;
  pos==0?vec.push(error):vec.push(buff);
  str.erase(0,pos+delimitador.length());

}


void tabla_anagra::insertar(TABLA& t,queue<string> cabecera, queue<string>& fila){
  string num_fila=fila.front();
  fila.pop();
  FILA temp;
  while (!cabecera.empty()) {
    string str_fila=cabecera.front();
    string str_columna=fila.front();
    if(str_columna==MSJ_ERROR){
          str_columna= str_columna +">"+ num_fila +">"+str_fila;
    }
    temp.insert({str_fila,str_columna});
    cabecera.pop();
    fila.pop();
  }
  t.insert({num_fila,temp});

}


void tabla_anagra::imprimir_tabla(TABLA& t){

    cout<<"------------------------------------------------------------------"<<endl;

    for(TABLA::iterator i=t.begin();i!=t.end();i++){

        cout<< STR_ESPACIO_SEPARADOR;
        for(FILA::iterator j=i->second.begin();j!=i->second.end();j++){
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

    for(TABLA::iterator i=t.begin();i!=t.end();i++){
        string tmp=STR_ESPACIO_SEPARADOR;
        string tmp2=i->first +"  -> ";
        tmp.replace(tmp.begin(),tmp.begin()+tmp2.size(),tmp2);
        cout<< tmp;

        for(FILA::iterator j=i->second.begin();j!=i->second.end();j++){

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
