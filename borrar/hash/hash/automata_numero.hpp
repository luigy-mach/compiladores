#ifndef AUTOMATA_NUMERO_HPP
#define AUTOMATA_NUMERO_HPP

#include"nodo.hpp"

typedef pair<string,string> lexema_token;


class Automata_Numero
{
private:
nodo * p_root;
nodo * p_current;
Automata_Numero()
{
    p_root=new nodo("q0",-1,"ROOT");
    cout<<"inicializo"<<endl;
}

Automata_Numero* s_instance;
string cadena_almacenada;

public:
Automata_Numero* instance();
void inicializar();
bool reconocer(char s);
lexema_token get_cadena_reonocida();
};

#endif // AUTOMATA_NUMERO_HPP
