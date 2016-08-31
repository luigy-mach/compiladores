#include <iostream>
#include <map>
#include <vector>


using namespace std;



typedef  bool (*pfun)(char c);


struct nodo{
  int _tipo; // -1 inicial; 0 normal ; 1 terminal
  string _nombre;

  nodo(string n, int tipo=0){
    _nombre=n;
    _tipo=tipo;
  }
  string nombre() const{
    return _nombre;
  }
  int tipo() const{
    return _tipo;
  }
};

bool operator==(const nodo& a, const nodo& b){
  return (a.nombre()==b.nombre())?true:false;
};

bool operator<(const nodo& a, const nodo& b){
  return (a.nombre()<b.nombre())?true:false;
};

bool operator>(const nodo& a, const nodo& b){
  return (a.nombre()>b.nombre())?true:false;
};


struct transicion{
  const nodo* _sig;
  pfun _pf;
  transicion(const nodo* sig, pfun pf){
    _sig=sig;
    _pf=pf;
  }
};


struct automatafd{
  const nodo* root;
  typedef vector <transicion> vec_trans;
  typedef map< nodo, vec_trans > map_estados;
  typedef pair< nodo, vec_trans > pairnew;
  map_estados estados;
  //typedef map_estados::iterator it_map;
  //typedef vec_trans::iterator it_vec;

  enum Foo { a, b, c = 10, d, e = 1, f, g = f + c };


  automatafd(){
    root=NULL;
  }

  int verificar_entrada(string* s){
    map_estados::iterator it_map;
    vec_trans::iterator it_vec;
    string::iterator its = s->begin();
    it_map=estados.find(*root);

    while( its != s->end() ){
      it_vec=(it_map->second).begin();
      while( !it_vec->_pf(*its)){
          it_vec++;
          if( it_vec==(it_map->second).end() ){
            return 0;
          }
      }
      it_map=estados.find(it_vec->_sig->nombre());
      its++;

    }
    return it_map->first._tipo;
  }

  void insertar_estado(string nombre,
                      int tipo=0 ){
    vec_trans vtemp;
    nodo ntemp(nombre,tipo);
    estados.insert(pairnew(ntemp,vtemp));
    map_estados::iterator it;
    it=estados.find(ntemp);
    if(tipo==-1){
      root=&(it->first);
    }
  }

  void insertar_transicion(string nombre,
                     string nodo_sig,
                     pfun pf){
    map_estados::iterator it1;
    map_estados::iterator it2;
    nodo xntemp(nombre);
    nodo xxntemp(nodo_sig);
    it1=estados.find(xntemp);
    it2=estados.find(xxntemp);

    if( it1!=estados.end() && it2!=estados.end() ){
      transicion ttemp(&(it2->first),pf);
      it1->second.push_back(ttemp);
    }
  }

};


// ----------------------------------
// funciones
// ---------------------------------
bool es0(char c){
  return (c==48)?true:false;
};

bool esxX(char c){
  return (c==88 || c==120)?true:false;
};
bool esoO(char c){
  return (c==79 ||c==111)?true:false;
};

bool es_numero(char c){
  return (c>=48 || c<=57)?true:false;
};

bool es_octal(char c){
  return (c>=0 || c<=55)?true:false;
};

bool es_hex(char c){
  return (c>=48 || c<=57 || c>=65 || c<=70 || c>=97 || c<=102)?true:false;
};


int main(){
  automatafd automata;
  automata.insertar_estado("q0",-1);
  automata.insertar_estado("q1", 0);
  automata.insertar_estado("q2", 1);
  automata.insertar_estado("q3", 2);
  automata.insertar_estado("q4", 3);

  automata.insertar_transicion("q0","q1",*es0);
  automata.insertar_transicion("q1","q2",*esxX);
    automata.insertar_transicion("q2","q2",*es_hex);
  automata.insertar_transicion("q1","q3",*esoO);
    automata.insertar_transicion("q3","q3",*es_octal);
  automata.insertar_transicion("q1","q4",*es_numero);
    automata.insertar_transicion("q4","q4",*es_numero);




  string my="02131";
  cout<< automata.verificar_entrada(&my) <<endl;


  return 0;
}
