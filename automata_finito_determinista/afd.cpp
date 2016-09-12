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

  automatafd(){
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


  bool es_terminal(const nodo* n) {
    return (n->tipo()>=1)?true:false;
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
  };

};


// ----------------------------------
// funciones
// ---------------------------------
bool es_cero(char c){
  return (c==48)?true:false;
};

bool es_x(char c){
  return (c==88 || c==120)?true:false;
};
bool es_o(char c){
  return (c==79 || c==111)?true:false;
};

bool es_numero_sin_cero(char c){
  return (c>=49 && c<=57)?true:false;
};
bool es_numero_con_cero(char c){
  return (c>=48 && c<=57)?true:false;
};

bool es_octal(char c){
  return (c>=0 && c<=55)?true:false;
};

bool es_hex(char c){
  return ( es_numero_con_cero(c) || (c>=65 && c<=70) || (c>=97 && c<=102) )?true:false;
};

//----------------------------------------------------
//fin funciones
//----------------------------------------------------



//enum token {    cvb=0, cero=1, numero=2, octal= 5, hexadecimal=6 };


////////////////////////////////////////////////////////////////////////////
//////////////////MAIN
////////////////////////////////////////////////////////////////////////////
int main(){

  /////////////////// TABLE TOKENS /////////////////////
  map <int,string> token;
 token.insert ( std::pair<int,string>(0,"cadena invalida") );
 token.insert ( std::pair<int,string>(1,"cero") );
 token.insert ( std::pair<int,string>(2,"numero") );
 token.insert ( std::pair<int,string>(6,"octal") );
 token.insert ( std::pair<int,string>(5,"hexadecimal") );
 //------------------------------------------------------


  automatafd automata;
  // -1 estado inicial
  // 0 no terminal
  // >0 terminal

  automata.insertar_estado("q0",-1); // inicial
  automata.insertar_estado("q1", 1); // terminal 1
  automata.insertar_estado("q2", 2); // terminal 2
  automata.insertar_estado("q3", 0); // no terminal
  automata.insertar_estado("q4", 0); // no terminal
  automata.insertar_estado("q5", 5); // terminal 5
  automata.insertar_estado("q6", 6); // terminal 6


  automata.insertar_transicion("q0","q1",*es_cero);
  automata.insertar_transicion("q1","q1",*es_cero);
  automata.insertar_transicion("q1","q2",*es_numero_sin_cero);
  automata.insertar_transicion("q1","q3",*es_x);
  automata.insertar_transicion("q3","q5",*es_hex);
  automata.insertar_transicion("q5","q5",*es_hex);

  automata.insertar_transicion("q1","q4",*es_o);
  automata.insertar_transicion("q4","q6",*es_octal);
  automata.insertar_transicion("q6","q6",*es_octal);

  automata.insertar_transicion("q0","q2",*es_numero_sin_cero);
  automata.insertar_transicion("q2","q2",*es_numero_con_cero);


      // -1 =  no inicial
      // 0 = error
      // 1 = solo ceros
      // 2 = numero natural incluido el cero
      // 5 = hexadecimal
      // 6 = octal


  string my1="0O";
  cout<< token[automata.verificar_entrada(&my1)] <<endl;

/*  string my2="0064";
  cout<< token[automata.verificar_entrada(&my2)] <<endl;

  string my3="0o647";
  cout<< token[automata.verificar_entrada(&my3)] <<endl;

  string my4="0000";
  cout<< token[automata.verificar_entrada(&my4)] <<endl;

  string my5="0xxx";
  cout<< token[automata.verificar_entrada(&my5)] <<endl;
*/




  return 0;
}
