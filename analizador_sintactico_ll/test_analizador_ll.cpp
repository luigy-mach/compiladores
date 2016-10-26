#include"ll.hpp"
#include<iostream>

#include <unordered_map>

using namespace std;





int main(){

    // CONJUNTO _primeros;    
    class_ll myll;
    myll.inicializar_gramatica();
    myll.algoritmo_ll();


    // auto itt = myll._gramatica.equal_range("F");

    // for(auto it=itt.first;it!=itt.second;it++){
    //     cout<<"---"<<endl;
    //     cout<<it->first<<endl;
    //     for(auto ii=it->second.begin();ii!=it->second.end();ii++){
    //          cout<<"........"<<*ii<<endl;
    //     }
        

    // }
    
    
    
    myll._primeros.insert({{"E"},{}});
    myll._primeros.insert({{"E1"},{}});
    myll._primeros.insert({{"T"},{}});
    myll._primeros.insert({{"T1"},{}});
    myll._primeros.insert({{"A"},{}});
    myll._primeros.insert({{"1"},{}});
    myll._primeros.insert({{"Z"},{}});

    IT_CONJUNTO tt = myll._primeros.find("T");
    tt->second.insert({{"+"},{"+"}});
    tt->second.insert({{"/"},{"/"}});
    tt->second.insert({{"-"},{"-"}});

    // for(auto i=myll._primeros.begin();i!=myll._primeros.end();i++){
    //     cout<<">>>"<<i->first<<endl;
    // }
    // for(auto i=myll._gramatica.begin();i!=myll._gramatica.end();i++){
    //     cout<<i->first<<endl;
    // }
    
    
    // IT_CONJUNTO it=myll._primeros.find("T");
    // if( it!=myll._primeros.end()  ){
    //     cout<<"si esta "<<endl;
    //     IT_FILA itf=it->second.find("/");
    //     if(itf != it->second.end()){
    //         cout<<"si esta 2"<<endl;
    //     }
    //     else
    //     {
    //     cout<<"no esta 2"<<endl;    
    //     }
        
    // }
    // else{
    //     cout<<"no esta "<<endl;
    // }


    return 0;
}