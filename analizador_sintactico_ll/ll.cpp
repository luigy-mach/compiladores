#include "ll.hpp"




void class_ll::imprimir_tabla(){
    cout<<"------------------------------------------------------------------"<<endl;
    for(IT_TABLA i=_tabla.begin();i!=_tabla.end();i++){
        cout<< "    " ;
        for(IT_FILA_TABLA j=i->second.begin();j!=i->second.end();j++){
            cout<<"    "<< j->first <<"   ";
        }
        cout<<endl ;
        break;
    }

    for(IT_TABLA i=_tabla.begin();i!=_tabla.end();i++){
        cout<< i->first << "->" ;
        for(IT_FILA_TABLA j=i->second.begin();j!=i->second.end();j++){   
            cout<<" "<< *j->second.begin() <<" ";        
        }
        cout<<endl;
    }
    cout<<"------------------------------------------------------------------"<<endl;

}    






void class_ll::imprimir_primeros(){
    cout<<"------------------------------------------------------------------"<<endl;
    for(IT_CONJUNTO i=_primeros.begin();i!=_primeros.end();i++){
        cout<< i->first << "->" ;
        for(IT_FILA j=i->second.begin();j!=i->second.end();j++){   
            cout<<" "<< j->second <<" ";        
        }
        cout<<endl;
    }
    cout<<"------------------------------------------------------------------"<<endl;

}    



void class_ll::imprimir_segundos(){
    cout<<"------------------------------------------------------------------"<<endl;
    for(IT_CONJUNTO i=_segundos.begin();i!=_primeros.end();i++){
        cout<< i->first << "->" ;
        for(IT_FILA j=i->second.begin();j!=i->second.end();j++){   
            cout<<" "<< j->second <<" ";        
        }
        cout<<endl;
    }
    cout<<"------------------------------------------------------------------"<<endl;

}    


