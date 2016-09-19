#ifdef ATOMATAS_HPP
#define ATOMATAS_HPP


//----------------------------------------------------
//automaton
//----------------------------------------------------
// typedef  bool (*pfun)(char c);
// typedef struct nodo NODO;
// typedef struct transicion TRANSICION;
// typedef struct automata_finito_determinista AFD;
//----------------------------------------------------
//fin automaton
//----------------------------------------------------


//----------------------------------------------------
//automata_finito_determinista
//----------------------------------------------------

// typedef struct nodo N;
// typedef struct transicion T;
// typedef struct automata_finito_determinista AFD;

typedef struct _nodo N;
typedef struct _transicion T;
typedef struct _automata_finito_determinista AFD;




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


#endif //AUTOMTAS_HPP
