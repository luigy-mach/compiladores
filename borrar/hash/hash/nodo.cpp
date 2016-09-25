#include "nodo.hpp"

nodo::nodo()
{
    nombre=VACIO;
    tipo= ERROR;
    token= IMCOMPLETO;

}
nodo::nodo(string n_nombre, int n_tipo, string n_token)
{
    nombre=n_nombre;
    tipo=n_tipo;
    token=n_token;
}
void nodo::set_next_nodo(v_nodos n_vector_nodo)
{
    vector_nodo=n_vector_nodo;
}
void nodo::set_nombre(string n_nombre)
{
    nombre=n_nombre;
}

void nodo::set_tipo(int n_tipo)
{
    tipo=n_tipo;
}

void nodo::set_token(string n_token)
{
    token=n_token;
}

string nodo::get_nombre()
{
    return this->nombre;
}

string nodo::get_token()
{
    return this->token;
}

int nodo::get_tipo()
{
    return this->tipo;
}

v_nodos::iterator nodo::get_next_nodo()
{
    return vector_nodo.begin();
}
