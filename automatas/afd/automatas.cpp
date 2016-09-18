#include "automatas.hpp"

//----------------------------------------------------
//automaton
//----------------------------------------------------

//completarsh!

//----------------------------------------------------
//fin automaton
//----------------------------------------------------



//----------------------------------------------------
//automata_finito_determinista
//----------------------------------------------------
  nodo::nodo(string n, int tipo=0){
    _nombre=n;
    _tipo=tipo;
  };
  string nodo::nombre() const{
    return _nombre;
  };
  int nodo::tipo() const{
    return _tipo;
  }

  transicion::transicion(const nodo* sig, pfun pf){
    _sig=sig;
    _pf=pf;
  };

  automata_finito_determinista::automata_finito_determinista(){
    _root=NULL;
  }

  int automata_finito_determinista::verificar_entrada(string* s){
    _map_estados::iterator it_map;
    _vec_trans::iterator it_vec;
    string::iterator its = s->begin();
    it_map=_estados.find(*_root);
    int x=0;
    while( its != s->end() ){
      it_vec=it_map->second.begin();
      while( it_vec!=it_map->second.end() && !it_vec->_pf(*its)  ){
          it_vec++;
      }

      if( it_vec==it_map->second.end() ){
        //cout<<"error: cadena no valida"<<endl;
        return 0;
      }
      it_map=_estados.find(it_vec->_sig->nombre());
      its++;
    }
    return es_terminal(&(it_map->first))?it_map->first.tipo():0;
  };


  bool automata_finito_determinista::es_terminal(const nodo* n) {
    return (n->tipo()>=1)?true:false;
  };

  void automata_finito_determinista::insertar_estado
                     (string nombre,
                      int tipo=0 ){
    _vec_trans vtemp;
    nodo ntemp(nombre,tipo);
    _estados.insert(_pairnew(ntemp,vtemp));
    _map_estados::iterator it;
    it=_estados.find(ntemp);
    if(tipo==-1){
      _root=&(it->first);
    }
  };

  void automata_finito_determinista::insertar_transicion
                    (string nombre,
                     string nodo_sig,
                     pfun pf){
    _map_estados::iterator it1;
    _map_estados::iterator it2;
    nodo xntemp(nombre);
    nodo xxntemp(nodo_sig);
    it1=_estados.find(xntemp);
    it2=_estados.find(xxntemp);

    if( it1!=_estados.end() && it2!=_estados.end() ){
      transicion ttemp(&(it2->first),pf);
      it1->second.push_back(ttemp);
    }
  };

//----------------------------------------------------
//fin automata_finito_determinista
//----------------------------------------------------





//----------------------------------------------------
//sobrecargas
//----------------------------------------------------
bool operator==(const nodo& a, const nodo& b){
  return (a.nombre()==b.nombre())?true:false;
}

bool operator<(const nodo& a, const nodo& b){
  return (a.nombre()<b.nombre())?true:false;
}

bool operator>(const nodo& a, const nodo& b){
  return (a.nombre()>b.nombre())?true:false;
}
//----------------------------------------------------
//fin sobrecargas
//----------------------------------------------------



//----------------------------------------------------
// funciones
//----------------------------------------------------
bool es_cero(char c){
  return (c==48)?true:false;
}

bool es_x(char c){
  return (c==88 || c==120)?true:false;
}
bool es_o(char c){
  return (c==79 || c==111)?true:false;
}

bool es_numero_sin_cero(char c){
  return (c>=49 && c<=57)?true:false;
}
bool es_numero_con_cero(char c){
  return (c>=48 && c<=57)?true:false;
}

bool es_octal(char c){
  return (c>=0 && c<=55)?true:false;
}

bool es_hex(char c){
  return ( es_numero_con_cero(c) || (c>=65 && c<=70) || (c>=97 && c<=102) )?true:false;
}
//----------------------------------------------------
//fin funciones
//----------------------------------------------------
