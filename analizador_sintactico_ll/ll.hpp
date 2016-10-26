
#ifndef ALGORITMO_LL_H
#define ALGORITMO_LL_H

#include <iostream>
#include <vector>

#include<unordered_map>
#include<string>

using namespace std;



#define FILA class_hash::type1
#define IT_FILA class_hash::it_type1
 
#define CONJUNTO class_hash::type2
#define IT_CONJUNTO class_hash::it_type2

#define TABLA class_hash::type3
#define IT_TABLA class_hash::it_type3

#define FILA_TABLA class_hash::type0
#define IT_FILA_TABLA class_hash::it_type0


#define GRAMATICA class_multi_hash::multi_hash
#define IT_GRAMATICA class_multi_hash::it_multi_hash


#define STR_SIMBOLO_LAMBDA "lambda"
#define STR_ERROR_TABLA "error_g_t"
#define STR_DOLAR "$" 

#define STR_ERROR_CODIGO "matateXD! has hecho algo mal..."




struct class_hash{
    typedef std::unordered_map< string,vector<string> > type0;
    typedef std::unordered_map< string,string > type1;
    typedef std::unordered_map< string,type1 > type2;
    typedef std::unordered_map< string,type0 > type3;

    typedef std::unordered_map< string,vector<string> >::iterator it_type0;
    typedef std::unordered_map< string,string >::iterator it_type1;
    typedef std::unordered_map< string,type1 >::iterator it_type2;
    typedef std::unordered_map< string,type0 >::iterator it_type3;
};


struct class_multi_hash{
    typedef std::unordered_multimap< string, std::vector<string> > multi_hash;
    typedef std::unordered_multimap< string, std::vector<string> >::iterator it_multi_hash;
};




//----------------------------------------------------
//ANALIZADOR_SINTACTICO_LL
//----------------------------------------------------
class class_ll{

public:
    CONJUNTO _primeros;
    CONJUNTO _segundos;
    TABLA _tabla;
    FILA _estados_no_terminales;
    FILA _estados_terminales;
    FILA _simbolos;
    GRAMATICA _gramatica;

    string _str_inicial;
    vector<string> _vec_nt;
    
    void cargar_gramatica(){

        _str_inicial="E";
        _estados_terminales.insert({{"id","id"},
                                    {"num","num"},
                                    {"(","("},
                                    {")",")"},
                                    {"+","+"},
                                    {"*","*"},
                                    {"-","-"},
                                    {"/","/"},
                                    {STR_SIMBOLO_LAMBDA,STR_SIMBOLO_LAMBDA}
                                    });
        _vec_nt={{"E"},{"E1"},{"T"},{"T1"},{"F"}};

        vector<string> temp1;
            temp1.push_back("T");
            temp1.push_back("E1");
        _gramatica.insert({{"E",temp1}});

        vector<string> temp2;
            temp2.push_back("+");
            temp2.push_back("T");
            temp2.push_back("E1");
        vector<string> temp3;
            temp3.push_back("-");
            temp3.push_back("T");
            temp3.push_back("E1");
        vector<string> temp4;
            temp4.push_back(STR_SIMBOLO_LAMBDA);
        _gramatica.insert({{"E1",temp2}});
        _gramatica.insert({{"E1",temp3}});
        _gramatica.insert({{"E1",temp4}});


        vector<string> temp5;
            temp5.push_back("F");
            temp5.push_back("T1");
        _gramatica.insert({{"T",temp5}});


        vector<string> temp6;
            temp6.push_back("*");
            temp6.push_back("F");
            temp6.push_back("T1");
        vector<string> temp7;
            temp7.push_back("/");
            temp7.push_back("F");
            temp7.push_back("T1");
        vector<string> temp8;
            temp8.push_back(STR_SIMBOLO_LAMBDA);
        _gramatica.insert({{"T1",temp6}});
        _gramatica.insert({{"T1",temp7}});
        _gramatica.insert({{"T1",temp8}});
        

        vector<string> temp9;
            temp9.push_back("(");
            temp9.push_back("E");
            temp9.push_back(")");
        vector<string> temp10;
            temp10.push_back("num");
        vector<string> temp11;
            temp11.push_back("id");
        _gramatica.insert({{"F",temp9}});
        _gramatica.insert({{"F",temp10}});
        _gramatica.insert({{"F",temp11}});

        /*-IMPORTANTE-*/
        extraer_simbolos();
    }
      

    void generar_tabla_vacia(){
        FILA_TABLA temp_fila;
        for(IT_FILA i=_estados_terminales.begin();i!=_estados_terminales.end();i++){
            vector<string> vec;
            vec.push_back(STR_ERROR_TABLA);
            temp_fila.insert({{i->first},{vec}});
        }

        for(IT_FILA i=_simbolos.begin();i!=_simbolos.end();i++){
            vector<string> vec;
            vec.push_back(STR_ERROR_TABLA);
            temp_fila.insert({{i->first},{vec}});
        }
        
        for(IT_FILA i=_estados_no_terminales.begin();i!=_estados_no_terminales.end();i++){
            _tabla.insert({{i->first},{temp_fila}});
        }
    }

    bool validar_estado_recursivo(string e,string simbolo){
        auto it = _gramatica.equal_range(e);
        for(auto m=it.first;m!=it.second;m++){

        }
    }

    void generar_tabla(){
        generar_tabla_vacia();
 
        for(auto it1=_primeros.begin();it1!=_primeros.end();it1++){
            for(auto it2=it1->second.begin();it2!=it1->second.end();it2++){
                if(it2->second==STR_SIMBOLO_LAMBDA){
                    cout<<"lambda encontrad"<<endl;
                    auto e_seg=_segundos.find(it1->first);
                    if(e_seg!=_segundos.end()){
                        for(auto i=e_seg->second.begin();i!=e_seg->second.end();i++){
                            vector<string> t;
                            t.push_back(STR_SIMBOLO_LAMBDA);
                            insertar_en_tabla(it1->first,i->second,t);
                        }    
                    }
                    else
                    {
                        cout<<"algo malo paso encontrado lambda"<<endl;
                    }

                }
                else
                {
                    auto  
                    // auto it=find(vec.begin(),vec.end(),"a");
                    if(it1->first){
                       cout<<"camino corto"<<endl; 
                    }
                    else
                    {
                        cout<<"camino largo"<<endl;
                    }
                }
            }
        }

    }


    void extraer_simbolos(){
        //BORRAR//////////////////////
            //emulando simbolos
            _estados_no_terminales.insert({{"E","E"},{"T","T"},{"T1","T1"},{"E1","E1"},{"F","F"}});
            _simbolos.insert({{"(","("},
                              {")",")"},
                              {"+","+"},
                              {"-","-"},
                              {"/","/"},
                              {"*","*"},
                              {STR_DOLAR,STR_DOLAR}
                              });
        //FIN-BORRAR//////////////////
    }

    void crear_primeros(){
        for(IT_FILA i=_estados_no_terminales.begin();i!=_estados_no_terminales.end();i++){
            _primeros.insert({{i->first},{}});
        }
    }
    void insertar_en_primeros(string str1, string str2){
        IT_CONJUNTO tt = _primeros.find(str1);
        if(tt!=_primeros.end()){
            tt->second.insert({{str2},{str2}});
        }
        else{
            _primeros.insert({{str1},{}});
            insertar_en_primeros(str1,str2);
        }
    }
    void insertar_en_segundos(string str1, string str2){
        IT_CONJUNTO tt = _segundos.find(str1);
        if(tt!=_segundos.end()){
            tt->second.insert({{str2},{str2}});
        }
        else{
            _segundos.insert({{str1},{}});
            insertar_en_segundos(str1,str2);
        }
    }

    bool insertar_en_tabla(string str1,string str2 ,vector<string> vec){
        auto cc = _tabla.find(str1);
        if(cc!=_tabla.end()){
            auto ff=cc->second.find(str2);
            if(ff!=cc->second.end()){
                ff->second=vec;
            }else{
                return false;    
            }
            
        }
        else{
            return false;
        }
    }
    
    void crear_segundos(){
        for(IT_FILA i=_estados_no_terminales.begin();i!=_estados_no_terminales.end();i++){
            _segundos.insert({{i->first},{}});
        }
    }

    bool es_terminal(string str){
         IT_FILA it=_estados_terminales.find(str);
         return it!=_estados_terminales.end();
    }
    
    bool buscar_recursiva_primeros(string nt,string temp){
        auto itt = _gramatica.equal_range(temp);
        for(auto it=itt.first;it!=itt.second;it++){
            //  cout<<it->first<<endl;
            auto ii=it->second.begin();
            if(ii!=it->second.end()){
                //  cout<<"........"<<*ii<<endl;
                if(es_terminal(*ii)){
                    insertar_en_primeros(nt,*ii);
                }else{
                    buscar_recursiva_primeros(nt,*ii);
                }
            }else{
                //no deberia pasar
                cout<<"esto no deberia pasar:"<<STR_ERROR_CODIGO<<endl;
            }
            // cout<<"*********"<<endl;
        }
    }

    bool busqueda_iterativa_segundos(string nt_b){
        for(auto a_it=_gramatica.begin();a_it!=_gramatica.end();a_it++){
            auto a = a_it->second;
            
            for(auto i_b=a.begin()+1;i_b!=a.end();i_b++){
                if(*i_b==nt_b){
                    cout<<a_it->first<<"->"<<*i_b<<endl;
                    //regla_2
                    if(i_b+1==a.end()){    
                        cout<<"regla_2"<<endl;
                        auto t=_segundos.find(a_it->first)->second;   
                        for(auto k=t.begin();k!=t.end();k++){
                              insertar_en_segundos(nt_b,k->second);
                        }
                    }
                    //regla_3 
                    else if(!es_terminal(*(i_b+1))){
                        cout<<"regla_3"<<endl;
                        auto nt_beta=i_b+1;
                        if(!primeros_contiene_lambda(*nt_beta)){
                            cout<<"__caso 3 a"<<endl;
                            auto m=_primeros.find(*nt_beta);
                            if(m!=_primeros.end())  {
                                auto p1=_primeros.find(*nt_beta)->second;
                                for(auto h=p1.begin();h!=p1.end();h++){
                                    insertar_en_segundos(nt_b,h->second);
                                }        
                            }else{
                                cout<<"error_caso 3 a"<<endl;            
                            }

                        }else{
                            cout<<"__caso 3 b"<<endl;
                            auto p1=_primeros.find(*nt_beta)->second;
                            for(auto z=p1.begin();z!=p1.end();z++){
                                if(z->second!=STR_SIMBOLO_LAMBDA){
                                    insertar_en_segundos(nt_b,z->second);                               
                                }
     
                            }
                            auto s1=_segundos.find(a_it->first)->second;
                            for(auto n=s1.begin();n!=s1.end();n++){
                                insertar_en_segundos(nt_b,n->second);
                            }
                        }

                    }
                    //caso no terminal a la derecha
                    else{
                        insertar_en_segundos(nt_b,*(i_b+1));
                        cout<<"caso no terminal a la derecha"<<endl;
                    }
                }
                else{
                    // cout<<"no hubo coincidencias"<<endl;
                }
            }
        }
    }

    bool primeros_contiene_lambda(string nt){
        auto it=_primeros.find(nt);
        if(it!=_primeros.end()){
            auto i = it->second.find(STR_SIMBOLO_LAMBDA);
            if(i!=it->second.end()){
                return true;
            }else{
                return false;
            }
        }
        else{
            return false;
        }
    }

   

public:
    class_ll(){}
    void imprimir_tabla();
    void imprimir_primeros();
    void imprimir_segundos();
    
    void inicializar_gramatica(){
        cargar_gramatica();
        crear_primeros();
        crear_segundos();  
    }

    void algoritmo_ll(){
        //una vez inicializada_gramatica

        //aplicando algoritmo
        for(auto it=_vec_nt.begin();it!=_vec_nt.end();it++){
            buscar_recursiva_primeros(*it,*it);
        }
        imprimir_primeros();
        //regla_1
        insertar_en_segundos(_str_inicial,STR_DOLAR);
        for(auto it1=_vec_nt.begin();it1!=_vec_nt.end();it1++){
            //regla_2
            //regla_3
            busqueda_iterativa_segundos(*it1);
        }
        imprimir_segundos();
        

        //parte final
        generar_tabla();
        imprimir_tabla();

    }




    void insertar(string str1,string str2){
    }
     
    void verificar(string str){
    }

    
    
};
//----------------------------------------------------
//fin ANALIZADOR_SINTACTICO_LL
//----------------------------------------------------









#endif //ALGORITMO_LL_H
