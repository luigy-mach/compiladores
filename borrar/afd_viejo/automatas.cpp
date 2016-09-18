#include "automatas.hpp"

#include <iostream>
#include <map>
#include <vector>

using namespace std;


//----------------------------------------------------
//automaton
//----------------------------------------------------
//----------------------------------------------------
//fin automaton
//----------------------------------------------------

//cout<<"hola"<<endl;

//----------------------------------------------------
//_automata_finito_determinista
//----------------------------------------------------
// typedef  bool (*pfun)(char c);
// typedef struct _nodo _nodo;
// typedef struct _transicion _transicion;
// typedef struct _automata_finito_determinista AFD;
//


typedef  bool (*pfun)(char c);

struct _nodo;
typedef struct _nodo{
  int _tipo; // -1 inicial; 0 normal ; 1 terminal
  string _nombre;

  _nodo(string n, int tipo=0){
    _nombre=n;
    _tipo=tipo;
  }
  string nombre() const{
    return _nombre;
  }
  int tipo() const{
    return _tipo;
  }
} _nodo;

struct _transicion;
typedef struct _transicion{
  const _nodo* _sig;
  pfun _pf;
  _transicion(const _nodo* sig, pfun pf){
    _sig=sig;
    _pf=pf;
  }
}_transicion;

struct _automata_finito_determinista;
typedef struct _automata_finito_determinista{
  const _nodo* root;
  typedef vector <_transicion> vec_trans;
  typedef map< _nodo, vec_trans > map_estados;
  typedef pair< _nodo, vec_trans > pairnew;
  map_estados estados;

  _automata_finito_determinista(){
    root=NULL;
  }

  int verificar_entrada(string* s){
    map_estados::iterator it_map;
    vec_trans::iterator it_vec;
    string::iterator its = s->begin();
    it_map=estados.find(*root);
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
      it_map=estados.find(it_vec->_sig->nombre());
      its++;
    }
    return es_terminal(&(it_map->first))?it_map->first.tipo():0;
  }


  bool es_terminal(const _nodo* n) {
    return (n->tipo()>=1)?true:false;
  }

  void insertar_estado(string nombre,
                      int tipo=0 ){
    vec_trans vtemp;
    _nodo ntemp(nombre,tipo);
    estados.insert(pairnew(ntemp,vtemp));
    map_estados::iterator it;
    it=estados.find(ntemp);
    if(tipo==-1){
      root=&(it->first);
    }
  }

  void insertar_transicion(string nombre,
                     string _nodo_sig,
                     pfun pf){
    map_estados::iterator it1;
    map_estados::iterator it2;
    _nodo xntemp(nombre);
    _nodo xxntemp(_nodo_sig);
    it1=estados.find(xntemp);
    it2=estados.find(xxntemp);

    if( it1!=estados.end() && it2!=estados.end() ){
      _transicion ttemp(&(it2->first),pf);
      it1->second.push_back(ttemp);
    }
  };

}_automata_finito_determinista;



//----------------------------------------------------
//fin _automata_finito_determinista
//----------------------------------------------------





//----------------------------------------------------
//sobrecargas
//----------------------------------------------------
bool operator==(const _nodo& a, const _nodo& b){
  return (a.nombre()==b.nombre())?true:false;
}

bool operator<(const _nodo& a, const _nodo& b){
  return (a.nombre()<b.nombre())?true:false;
}

bool operator>(const _nodo& a, const _nodo& b){
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
