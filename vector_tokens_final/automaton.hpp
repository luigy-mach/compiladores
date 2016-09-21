
#ifndef ATOMATAS_H
#define ATOMATAS_H


#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define AFD class_AFD<capsula>::type
#define AUTOMATON class_AFD<capsula>::type
typedef  bool (*pfun)(char c);


//----------------------------------------------------
//capsula
//----------------------------------------------------
class capsula{
public:
  string _nombre;
  bool _error;
  capsula();
  capsula(string nombre, bool error=false);
};
//----------------------------------------------------
//fin capsula
//----------------------------------------------------



//----------------------------------------------------
//automaton
//----------------------------------------------------

template <class A>
class automaton;
template <class T>
struct class_AFD
{
  typedef automaton<T> type;
};

template<typename N>
class nodo{
private:
  int _tipo; // -1 inicial; 0 normal ; 1 terminal
  N _capsula; // datos encapsulados
public:
  nodo(){}
  nodo(const N capsula, int tipo=0);
  const N capsula() const;
  int tipo() const;
};

template<typename N>
nodo<N>::nodo(const N capsula, int tipo){
    _capsula=capsula;
    _tipo=tipo;
}
template<typename N>
const N nodo<N>::capsula() const{
    return _capsula;
}
template<typename N>
int nodo<N>::tipo() const{
    return _tipo;

}





template<typename T>
class transicion{
private:
public:
  pfun _pf;
  const nodo<T>* _sig;
  transicion(){}
  transicion(const nodo<T>* sig, pfun pf);
};

template<typename T>
transicion<T>::transicion(const nodo<T>* sig, pfun pf){
  _sig=sig;
  _pf=pf;
}




template<typename A>
class automaton{
  const nodo<A>* _root;
  public:
  typedef vector< transicion<A> > _vec_trans;
  typedef map< nodo<A>, _vec_trans > _map_estados;
  typedef pair< nodo<A>, _vec_trans > _pairnew;
  _map_estados _estados;

  automaton(){_root=NULL;}
  // automaton();
  ~automaton(){}
  int verificar_entrada(string* s, A& out_capsula);
  bool es_terminal(const nodo<A>* n);
  void insertar_estado(const A capsula,
                      int tipo=0);
  void insertar_transicion(const A capsula_actual,
                           const A capsula_sig,
                           pfun pf);
  const nodo<A> nodo_inicio()const;
  void unir_automata_con(const A capsula_inicio,
                         const automaton<A>& a_otro,
                         pfun pf);
  const nodo<A>* nodo_inicio_puntero() const;
};

  // template<typename A>
  // automaton<A>::automaton(){
  //   _root=NULL;
  // }

  template<typename A>
  int automaton<A>::verificar_entrada(string* s, A& out_capsula){
    typename _map_estados::iterator it_map;
    typename _vec_trans::iterator it_vec;
    typename string::iterator its = s->begin();
    it_map=_estados.find(*_root);
    // cout<<it_map->first.capsula()._nombre<<" <- "<<endl;
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
      // cout<<" ->"<<it_map->first.capsula()._nombre<<endl;
    }
    out_capsula=it_map->first.capsula();
    return es_terminal(&(it_map->first))?it_map->first.tipo():0;
  }

  template<typename A>
  bool automaton<A>::es_terminal(const nodo<A>* n) {
    return (n->tipo()>=1)?true:false;
  }

  template<typename A>
  void automaton<A>::insertar_estado
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
  void automaton<A>::insertar_transicion
                    (const A capsula_actual,
                     const A capsula_sig,
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
  const nodo<A> automaton<A>::nodo_inicio() const {
    return *_root;
  }

  template<typename A>
  const nodo<A>* automaton<A>::nodo_inicio_puntero() const {
    return _root;
  }

  template<typename A>
  void  automaton<A>::
                  unir_automata_con(const A capsula_inicio,
                                    const automaton<A>& automata_fin,
                                    pfun pf){
    typename _map_estados::iterator it1;
    nodo<A> xntemp(capsula_inicio);
    it1=_estados.find(xntemp);


    // const nodo<A>* xxntemp = automata_fin.nodo_inicio_puntero();
    _estados.insert(automata_fin._estados.begin(),automata_fin._estados.end());

    const nodo<A> xxntemp = automata_fin.nodo_inicio();
    typename _map_estados::iterator it2;
    it2=_estados.find(xxntemp);


    if( it1!=_estados.end() && it2!=_estados.end() ){
      transicion<A> ttemp(&(it2->first),pf);
      it1->second.push_back(ttemp);
      // std::cout << "union " << it->first.capsula()._nombre <<std::endl;

    }
    return;
  }





//----------------------------------------------------
//fin automaton
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
// funciones numeros
//----------------------------------------------------
bool es_cero(char c);
bool es_x(char c);
bool es_o(char c);
bool es_numero_sin_cero(char c);
bool es_numero_con_cero(char cautomata_string);
bool es_octal(char c);
bool es_hex(char c);
//----------------------------------------------------
//fin funciones numeros
//----------------------------------------------------



//----------------------------------------------------
// funciones string
//----------------------------------------------------
bool es_letra(char c);
bool es_guion_bajo(char c);
bool es_numero(char c);
bool es_comilla(char c);
//----------------------------------------------------
//fin funciones string
//----------------------------------------------------








#endif //AUTOMTAS_H
