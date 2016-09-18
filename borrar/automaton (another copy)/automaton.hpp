
#ifndef ATOMATAS_H
#define ATOMATAS_H


#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define AFD class_AFD<datos>::type
#define AUTOMATON class_AFD<datos>::type
typedef  bool (*pfun)(char c);


//----------------------------------------------------
//automaton
//----------------------------------------------------

  // falta automaton

//----------------------------------------------------
//fin automaton
//----------------------------------------------------



//----------------------------------------------------
//capsula
//----------------------------------------------------

class datos{
public:
  string _nombre;
  bool _error;
  datos();
  datos(string nombre, bool error=false);
};
//----------------------------------------------------
//fin capsula
//----------------------------------------------------




//----------------------------------------------------
//automata_finito_determinista
//----------------------------------------------------

template <class A>
class automata_finito_determinista;
template <class T>
struct class_AFD
{
  typedef automata_finito_determinista<T> type;
};

template<typename N>
class nodo{
private:
  int _tipo; // -1 inicial; 0 normal ; 1 terminal
  N _capsula; // datos encapsulados
public:
  nodo(){}
  nodo(const N capsula, int tipo=0);
  N capsula() const;
  int tipo() const;
};

template<typename T>
class transicion{
private:
public:
  pfun _pf;
  const nodo<T>* _sig;
  transicion(){}
  transicion(const nodo<T>* sig, pfun pf);
};

template<typename A>
class automata_finito_determinista{
  public:
  const nodo<A>* _root;
  typedef vector< transicion<A> > _vec_trans;
  typedef map< nodo<A>, _vec_trans > _map_estados;
  typedef pair< nodo<A>, _vec_trans > _pairnew;
  _map_estados _estados;

  automata_finito_determinista(){_root=NULL;}
  // automata_finito_determinista();
  ~automata_finito_determinista(){}
  int verificar_entrada(string* s);
  bool es_terminal(const nodo<A>* n);
  void insertar_estado(const A capsula,
                      int tipo=0);
  void insertar_transicion(A capsula_actual,
                     A capsula_sig,
                     pfun pf);
  const nodo<A> nodo_inicio();
  void unir_automata_con(A capsula_inicio,
                         const automata_finito_determinista<A> a_otro,
                         pfun pf);
};

  template<typename N>
  nodo<N>::nodo(const N capsula, int tipo){
      _capsula=capsula;
      _tipo=tipo;
  }
  template<typename N>
  N nodo<N>::capsula() const{
      return _capsula;
  }
  template<typename N>
  int nodo<N>::tipo() const{
      return _tipo;

  }


  template<typename T>
  transicion<T>::transicion(const nodo<T>* sig, pfun pf){
    _sig=sig;
    _pf=pf;
  }

  //
  // template<typename A>
  // automata_finito_determinista<A>::automata_finito_determinista(){
  //   _root=NULL;
  // }

  template<typename A>
  int automata_finito_determinista<A>::verificar_entrada(string* s){
    typename _map_estados::iterator it_map;
    typename _vec_trans::iterator it_vec;
    typename string::iterator its = s->begin();
    it_map=_estados.find(*_root);
    while( its != s->end() ){
      it_vec=it_map->second.begin();
      while( it_vec!=it_map->second.end() && !it_vec->_pf(*its)  ){
          it_vec++;
      }

      if( it_vec==it_map->second.end() ){
        return 0;
      }

      it_map=_estados.find(it_vec->_sig->capsula());
      its++;
    }
    return es_terminal(&(it_map->first))?it_map->first.tipo():0;
  }

  template<typename A>
  bool automata_finito_determinista<A>::es_terminal(const nodo<A>* n) {
    return (n->tipo()>=1)?true:false;
  }

  template<typename A>
  void automata_finito_determinista<A>::insertar_estado
                     (const A capsula,
                      int tipo ){
    _vec_trans vtemp;
    nodo<A> ntemp(capsula,tipo);
    _estados.insert(_pairnew(ntemp,vtemp));
    typename _map_estados::iterator it;
    it=_estados.find(ntemp);
    if(tipo==-1){
      _root=&(it->first);
    }
  }

  template<typename A>
  void automata_finito_determinista<A>::insertar_transicion
                    (A capsula_actual,
                     A capsula_sig,
                     pfun pf){

    typename _map_estados::iterator it1;
    typename _map_estados::iterator it2;
    nodo<A> xntemp(capsula_actual);
    nodo<A> xxntemp(capsula_sig);
    it1=_estados.find(xntemp);
    it2=_estados.find(xxntemp);

    if( it1!=_estados.end() && it2!=_estados.end() ){
      transicion<A> ttemp(&(it2->first),pf);
      it1->second.push_back(ttemp);
    }
  }


  template<typename A>
  const nodo<A> automata_finito_determinista<A>::nodo_inicio(){
    return _root;
  }
  template<typename A>
  void  automata_finito_determinista<A>::
                  unir_automata_con(A capsula_inicio,
                                    const automata_finito_determinista<A> automata_fin,
                                    pfun pf){
    insertar_transicion(capsula_inicio,automata_fin.nodo_inicio().capsula(),pf);
  }





//----------------------------------------------------
//fin automata_finito_determinista
//----------------------------------------------------



//----------------------------------------------------
//sobrecargas
//----------------------------------------------------
// template<typename K>
// bool operator==(const nodo<K>& a, const nodo<K>& b);
// template<typename K>
// bool operator<(const nodo<K>& a, const nodo<K>& b);
// template<typename K>
// bool operator>(const nodo<K>& a, const nodo<K>& b);


template<typename K>
bool operator==(const nodo<K>& a, const nodo<K>& b){
  // return (a.nombre()==b.nombre())?true:false;
  return (a.capsula()._nombre==b.capsula()._nombre)?true:false;
}

template<typename K>
bool operator<(const nodo<K>& a, const nodo<K>& b){
  return (a.capsula()._nombre<b.capsula()._nombre)?true:false;
}

template<typename K>
bool operator>(const nodo<K>& a, const nodo<K>& b){
  return (a.capsula()._nombre>b.capsula()._nombre)?true:false;
}

//----------------------------------------------------
//fin sobrecargas
//----------------------------------------------------




//----------------------------------------------------
// funciones
//----------------------------------------------------
bool es_cero(char c);
bool es_x(char c);
bool es_o(char c);
bool es_numero_sin_cero(char c);
bool es_numero_con_cero(char c);
bool es_octal(char c);
bool es_hex(char c);
//----------------------------------------------------
//fin funciones
//----------------------------------------------------


#endif //AUTOMTAS_H
