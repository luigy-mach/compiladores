#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;
typedef  bool (*pfun)(char c);
#define ERROR 0
#define VACIO "vacio"
#define IMCOMPLETO "incompleto"

//typedef unordered_map<int,class_AFD*> hash;
class class_AFD;

class class_nodo{
private:
	string _nombre;
	int _tipo;
	string _token;
	vector<pair<nodo*,pfun> * _vector_nodo;

public:
	class_nodo()
	{
		_nombre= VACIO;
		_tipo= ERROR;
		_token= IMCOMPLETO;

	}
	class_nodo(string nombre,int tipo, string token)
	{
		_nombre= nombre;
		_tipo= tiṕo;
		_token= token;
	}
	void add_vector_nodo(vector<pair<nodo*,pfun> * vector_nodo)
	{
		_vector_nodo=vector_nodo;
	}

};


class class_AFD_Numero{
private:
	nodo * p_current;
	nodo * p_root;
	string _cadena_almacenada;
public:
	class_AFD(){}
	void inicializar_automata()
	{
		//isertar transiciones
		//crear todos  nodo
		//usar add vectir x cada nodo

	}
	bool reconocer(char s)
	{
		//1 (el current se mueve a un nodo
		//cadadena almacenda+=s
		//return 1

	}
	pair<string,string> resetear( bool flag)
	{
		// retorna current estado-> NUMERO, CADENA ALMACENAD
		//current=root;
		//cadena almacenada limpiar
	}

};


class automaton{
private:
	punteros a clases automata
	hash enteros ascii y punteros;
	bool flag;
public:
	automaton()
	{
			puntero clase autoataa numero = new
			inicializo la clase
			flag tiene valores 0 reconocio  espacio salto de lineo o punto y completars
			1 si esta en el automata de numeri
			2 de letra
	}
	void verificar(string buffer)
	{
		while (i) {
			/* code */
			 it = hash.find(buffer[i])  retorna punt automata y el flag
			if flag =!0
			it-Z second .reconocer(buffer[i])
			vectorlexemaytoken .push:back(it->resetear()

		}
	}

}

map<int,void*> mymap;



int main(){


	class_AFD a;
	class_AFD b;
	class_AFD c;

	mymap.insert(pair<int,void*>(1,&a));
	mymap.insert(pair<int,void*>(2,&b));
	mymap.insert(pair<int,void*>(3,&c));
	mymap.insert(pair<int,void*>(4,&a));
	mymap.insert(pair<int,void*>(5,&b));
	mymap.insert(pair<int,void*>(6,&c));

	unordered_map<int,class_AFD*> aa;
	// cout<<sizeof(aa)<<endl;



	return 0;
}
