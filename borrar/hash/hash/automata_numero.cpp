#include "automata_numero.hpp"

Automata_Numero* Automata_Numero::instance()
{
    if (!s_instance)
        s_instance = new Automata_Numero;
    return s_instance;
}
bool es_cero(char c){return (c==48)?true:false;}
bool es_x(char c){return (c==88 || c==120)?true:false;}
bool es_o(char c){return (c==79 || c==111)?true:false;}
bool es_numero_sin_cero(char c){return (c>=49 && c<=57)?true:false;}
bool es_numero_con_cero(char c){return (c>=48 && c<=57)?true:false;}
bool es_octal(char c){return (c>=0 && c<=55)?true:false;}
bool es_hex(char c){return ( es_numero_con_cero(c) || (c>=65 && c<=70) || (c>=97 && c<=102) )?true:false;}
bool es_punto(char c){return (c==46)?true:false;}

void Automata_Numero::inicializar()
{
    nodo q1("q1",1,"CERO");
    nodo q2("q2",2,"NUMERO");
    nodo q3("q3",0,"INCORRECTO");
    nodo q4("q4",0,"INCORRECTO");
    nodo q5("q5",5,"HEXADECIMAL");
    nodo q6("q6",6,"OCTAL");
    nodo q7("q7",0,"INCORRECTO");
    nodo q8("q8",7,"DECIMAL");

    v_nodos tmp;
    tmp.push_back(pair<nodo*,pfun>(&q1,es_cero));
    tmp.push_back(pair<nodo*,pfun>(&q2,es_numero_con_cero);
    tmp.push_back(pair<nodo*,pfun>(&q8,es_punto));
    p_root->set_next_nodo(tmp);
    tmp.clear();

    tmp.push_back(pair<nodo*,pfun>(&q1,es_cero));
    tmp.push_back(pair<nodo*,pfun>(&q3,es_x));
    tmp.push_back(pair<nodo*,pfun>(&q4,es_o));
    tmp.push_back(pair<nodo*,pfun>(&q7,es_numero_con_cero));
    q1.set_next_nodo(tmp);
    tmp.clear();

    tmp.push_back(pair<nodo*,pfun>(&q2,es_numero_con_cero));
    tmp.push_back(pair<nodo*,pfun>(&q7,es_punto));
    tmp.push_back(pair<nodo*,pfun>(&q1,es_cero));
    tmp.push_back(pair<nodo*,pfun>(&q1,es_cero));
    tmp.push_back(pair<nodo*,pfun>(&q1,es_cero));
    tmp.push_back(pair<nodo*,pfun>(&q1,es_cero));
    tmp.push_back(pair<nodo*,pfun>(&q1,es_cero));
    tmp.push_back(pair<nodo*,pfun>(&q1,es_cero));
}

bool Automata_Numero::reconocer(char s)
{

}

lexema_token Automata_Numero::get_cadena_reonocida()
{

}
