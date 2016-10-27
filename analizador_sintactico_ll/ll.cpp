#include "ll.hpp"


#define STR_ESPACIO_SEPARADOR "            "
#define STR_ESPACIO_SEPARADOR_PEQUENO "     "

void class_ll::imprimir_tabla(){



    cout<<"------------------------------------------------------------------"<<endl;
    for(IT_TABLA i=_tabla.begin();i!=_tabla.end();i++){
      
        cout<< STR_ESPACIO_SEPARADOR;
        for(IT_FILA_TABLA j=i->second.begin();j!=i->second.end();j++){
            string cuadrito=STR_ESPACIO_SEPARADOR;
            string::iterator it=cuadrito.begin();
            string temp;
            temp = j->first;
            cuadrito.replace(it,it+temp.size(),temp);
            cout<< cuadrito ;
        } 
        cout<<endl ;
        break;
    }

    for(IT_TABLA i=_tabla.begin();i!=_tabla.end();i++){
        string tmp=STR_ESPACIO_SEPARADOR;
        string tmp2=i->first +"  -> ";
        tmp.replace(tmp.begin(),tmp.begin()+tmp2.size(),tmp2);
        cout<< tmp;
        
        for(IT_FILA_TABLA j=i->second.begin();j!=i->second.end();j++){

            string cuadrito=STR_ESPACIO_SEPARADOR;
            string::iterator it=cuadrito.begin();
            string temp;
            for(auto z=j->second.begin();z!=j->second.end();z++){
                    temp+=*z; 
            } 
            cuadrito.replace(it,it+temp.size(),temp);
            cout<< cuadrito ;        
        }
        cout<<endl;
    }
    cout<<"------------------------------------------------------------------"<<endl;

}    






void class_ll::imprimir_primeros(){
    cout<<"------------------------------------------------------------------"<<endl;
    for(IT_CONJUNTO i=_primeros.begin();i!=_primeros.end();i++){
        string cuadrito=STR_ESPACIO_SEPARADOR_PEQUENO;
        string::iterator it=cuadrito.begin();
        string temp= i->first + "->"; 
        cuadrito.replace(it,it+temp.size(),temp);
        cout<< cuadrito ;
        for(IT_FILA j=i->second.begin();j!=i->second.end();j++){
            string cuadrito2=STR_ESPACIO_SEPARADOR_PEQUENO;
            string::iterator it2=cuadrito2.begin();
            string temp2= j->second;
            cuadrito2.replace(it2,it2+temp2.size(),temp2);
            cout<< cuadrito2 ;        
        }
        cout<<endl;
    }
    cout<<"------------------------------------------------------------------"<<endl;

}    



void class_ll::imprimir_segundos(){
    cout<<"------------------------------------------------------------------"<<endl;
    for(IT_CONJUNTO i=_segundos.begin();i!=_primeros.end();i++){
         string cuadrito=STR_ESPACIO_SEPARADOR_PEQUENO;
        string::iterator it=cuadrito.begin();
        string temp= i->first + "->"; 
        cuadrito.replace(it,it+temp.size(),temp);
        cout<< cuadrito ;
        
        for(IT_FILA j=i->second.begin();j!=i->second.end();j++){   
           string cuadrito2=STR_ESPACIO_SEPARADOR_PEQUENO;
            string::iterator it2=cuadrito2.begin();
            string temp2= j->second;
            cuadrito2.replace(it2,it2+temp2.size(),temp2);
            cout<< cuadrito2 ;            
        }
        cout<<endl;
    }
    cout<<"------------------------------------------------------------------"<<endl;

}    


