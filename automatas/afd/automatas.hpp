
#ifndef ATOMATAS_H
#define ATOMATAS_H


#include <iostream>
#include <map>
#include <vector>

using namespace std;

//----------------------------------------------------
//automaton
//----------------------------------------------------
  // typedef  bool (*pfun)(char c);
//fin automaton
//----------------------------------------------------


//----------------------------------------------------
//automata_finito_determinista
//----------------------------------------------------
typedef  bool (*pfun)(char c);
typedef class automata_finito_determinista AFD;

class nodo{
  public:
  int _tipo; // -1 inicial; 0 normal ; 1 terminal
  string _nombre;
  nodo(string n, int tipo);
  string nombre() const;
  int tipo() const;
};

class transicion{
  public:
  const nodo* _sig;
  pfun _pf;
  transicion(const nodo* sig, pfun pf);
};

class automata_finito_determinista{
  public:
  const nodo* _root;
  typedef vector <transicion> _vec_trans;
  typedef map< nodo, _vec_trans > _map_estados;
  typedef pair< nodo, _vec_trans > _pairnew;
  _map_estados _estados;

  automata_finito_determinista();
  int verificar_entrada(string* s);
  bool es_terminal(const nodo* n);
  void insertar_estado(string nombre,
                      int tipo);
  void insertar_transicion(string nombre,
                     string nodo_sig,
                     pfun pf);
};
//----------------------------------------------------
//fin automata_finito_determinista
//----------------------------------------------------



//----------------------------------------------------
//sobrecargas
//----------------------------------------------------
bool operator==(const nodo& a, const nodo& b);
bool operator<(const nodo& a, const nodo& b);
bool operator>(const nodo& a, const nodo& b);
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
