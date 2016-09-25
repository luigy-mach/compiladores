#ifndef NODO_HPP
#define NODO_HPP
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define ERROR 0
#define VACIO "vacio"
#define IMCOMPLETO "incompleto"

typedef  bool (*pfun)(char c);
class nodo;
typedef vector<pair<nodo*,pfun>> v_nodos;

class nodo{
private:
    string nombre;
    int tipo;
    string token;
    v_nodos vector_nodo;

public:
    nodo();
    nodo(string n_nombre,int n_tipo, string n_token);
    void set_nombre(string n_nombre);
    void set_tipo(int n_tipo);
    void set_token(string n_token);
    void set_next_nodo(v_nodos n_vector_nodo);
    string get_nombre();
    string get_token();
    int get_tipo();
    v_nodos::iterator get_next_nodo();


};


#endif // NODO_HPP
