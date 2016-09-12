#include <QCoreApplication>
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

typedef  bool (*p_fun)(char c);

class nodo_estado
{
private:
    int estado;
    string nombre;
public:
    nodo_estado(string n_nombre, int n_estado=0)
    {
        estado=n_estado;
        nombre=n_nombre;
    }

    int return_estado ()const{return estado;}
    string return_nombre()const{return nombre;}

};

bool operator==(const nodo_estado& x, const nodo_estado& y)
{
  return (x.return_nombre()==y.return_nombre())?true:false;
}

bool operator<(const nodo_estado& x, const nodo_estado& y)
{
  return (x.return_nombre()<y.return_nombre())?true:false;
}

bool operator>(const nodo_estado& x, const nodo_estado& y)
{
  return (x.return_nombre()>y.return_nombre())?true:false;
}

class transicion
{
private:
     const nodo_estado * nodo_sig;
     p_fun punt_fun;
public:
      transicion(const nodo_estado* sig, p_fun pf)
      {
        nodo_sig=sig;
        punt_fun=pf;
      }
      bool verificacion(p_fun funcion,char s_eval)
      {
          return funcion(s_eval);
      }
      p_fun get_pfun()
      {
          return punt_fun;
      }
      const nodo_estado * get_siguiente()
      {
          return nodo_sig;
      }
};

bool es_0(char c){return (c==48)?true:false;}
bool es_x(char c){return (c==88 || c==120)?true:false;}
bool es_o(char c){return (c==79 || c==111)?true:false;}
bool es_numero_0_a_9(char c){return (c>=49 && c<=57)?true:false;}
bool es_numero_con_cero(char c){return (c>=48 && c<=57)?true:false;}
bool es_octal(char c){return (c>=0 && c<=55)?true:false;}
bool es_hex(char c){return ( es_numero_con_cero(c) || (c>=65 && c<=70) || (c>=97 && c<=102) )?true:false;}

bool es_coma(char c){return (c==44)?true:false;}


class afd_numero
{

    typedef vector <transicion> vector_transi;
    typedef map< nodo_estado, vector_transi > map_estados;
    typedef pair< nodo_estado, vector_transi > nuevo_pair;

    typedef string lexeme;
    typedef string token;
    typedef map< token , lexeme > map_token;
    typedef map< int , token > tipo_token;

private:
    map_estados estados;
    tipo_token lista_token;
    map_token all_token;
    const nodo_estado * root;

public:
    afd_numero()
    {
        root=NULL;
    }
    token get_token(int t)
    {
        return lista_token[t];
    }
    //void add_
    void inicializar()
    {
        // Inicializador de Estado

        insert_estado("q0",-1);
        insert_estado("q1", 1);
        insert_estado("q2", 2);
        insert_estado("q3", 0);
        insert_estado("q4", 0);
        insert_estado("q5", 5);
        insert_estado("q6", 6);
        insert_estado("q7", 0);
        insert_estado("q8", 7);
        //Insercion de Transiciones primera vez

        insert_transicion("q0","q1",*es_0);
        insert_transicion("q1","q1",*es_0);
        insert_transicion("q1","q2",*es_numero_0_a_9);
        insert_transicion("q1","q3",*es_x);
        insert_transicion("q3","q5",*es_hex);
        insert_transicion("q5","q5",*es_hex);

        //Insercion de Transiciones segunda vez

        insert_transicion("q1","q4",*es_o);
        insert_transicion("q4","q6",*es_octal);
        insert_transicion("q6","q6",*es_octal);

        //Insercion de Transiciones tercera vez

        insert_transicion("q0","q2",*es_numero_0_a_9);
        insert_transicion("q2","q2",*es_numero_con_cero);

        insert_transicion("q2","q7",*es_coma);
        insert_transicion("q7","q8",*es_numero_0_a_9);
        insert_transicion("q8","q8",*es_numero_0_a_9);

        //Llenado de tipos
        lista_token.insert(std::pair<int,string>(0,"Cadena Incompleta"));
        lista_token.insert(std::pair<int,string>(1,"cero"));
        lista_token.insert(std::pair<int,string>(2,"numero"));
        //tipo_token.insert(1,"cero");
        lista_token.insert(std::pair<int,string>(5,"hexadecimal"));
        lista_token.insert(std::pair<int,string>(6,"octal"));

        lista_token.insert(std::pair<int,string>(7,"decimal"));
    }

    bool es_terminal(const nodo_estado* nodo)
    {
      return (nodo->return_estado()>=1)?true:false;
    }
    int reconocer(string * cadena)
    {
        map_estados::iterator it_map_est;
        vector_transi::iterator it_vec_tran;
        string::iterator it_str = cadena->begin();
        it_map_est=estados.find(*root);
        while(it_str!=cadena->end())
        {
            it_vec_tran=it_map_est->second.begin();
            while(it_vec_tran!=it_map_est->second.end() && !it_vec_tran->verificacion(it_vec_tran->get_pfun(),*it_str))
            {
                    //cout<<"it vec tran  "<< *it_str<<endl;
                    it_vec_tran++;
            }
            if( it_vec_tran==it_map_est->second.end()  ){
              cout<<" Cadena Invalida"<<endl;
              return 0;
            }
            //it_map_est++;
            it_map_est=estados.find(it_vec_tran->get_siguiente()->return_nombre());
            it_str++;


        }
        //cout<<"dddddd"<<cadena<<endl;
        return es_terminal(&(it_map_est->first))?it_map_est->first.return_estado():0;
         //return es_terminal(&(it_map_est->first));
    }

    void insert_estado(string nombre, int tipo=0 )
    {

        vector_transi v_temp;
        nodo_estado n_temp(nombre,tipo);
        estados.insert(nuevo_pair(n_temp,v_temp));
        if(tipo==-1)
        {
            cout<<"root isertado"<<endl;
          map_estados::iterator it;
          it=estados.find(n_temp);
          root=&(it->first);
        }

       cout<<"nodo "<<nombre<<"  isertado"<<endl;

    }

    void insert_transicion(string nodo_actual, string nodo_sig, p_fun pf)
    {
      map_estados::iterator it1, it2;
      nodo_estado a_n_temp(nodo_actual), s_n_temp(nodo_sig);
      it1=estados.find(a_n_temp);
      it2=estados.find(s_n_temp);

      if( it1!=estados.end() && it2!=estados.end() )
      {
        transicion t_temp(&(it2->first),pf);
        it1->second.push_back(t_temp);
        cout<<"transicion entre  "<<nodo_actual<<"  y   "<<nodo_sig<<" creada"<<endl;
      }
    }
    void print_lista_estados()
    {
        map_estados::iterator it_map_est;
        vector_transi::iterator it_vec_tran;
        //string::iterator it_str = cadena->begin();
        it_map_est=estados.find(*root);
        while(it_map_est!=estados.end())
        {
            //cout<<"Estado: "<<it_map_est->first.return_nombre()<<endl;
            it_vec_tran=it_map_est->second.begin();
            while(it_vec_tran!=it_map_est->second.end())
            {
              //cout<<"Next Estado:  "<<it_vec_tran->get_siguiente()->return_nombre()<<endl;
                it_vec_tran++;
            }
            it_map_est++;
        }
    }

};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    afd_numero automata;
    automata.inicializar();

    //automata.print_lista_estados();

    string num1;
    while(1)
    {
        cin>>num1;
        cout<< automata.get_token(automata.reconocer(&num1)) <<endl;
    }

    /*
    string num2="0064";
    cout<< automata.reconocer(&num2) <<endl;

    string num3="0o647";
    cout<< automata.reconocer(&num3) <<endl;

    string num4="0000";
    cout<< automata.reconocer(&num4) <<endl;*/
    return a.exec();
}
