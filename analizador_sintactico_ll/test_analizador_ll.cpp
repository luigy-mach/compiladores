#include"ll.hpp"
#include<iostream>

#include <unordered_map>
#include <string>



#include <stack>

using namespace std;




void verificar(stack<string>& pila){
    cout<< pila.top()<<endl;
    



}


int main(){

    stack<string> mystack;
    
    
    
    
    // num+id*num
    mystack.push("num");
    mystack.push("*");
    mystack.push("id");
    mystack.push("+");
    mystack.push("num");

    verificar(mystack);
    class_ll myll;
    myll.inicializar_gramatica();
    myll.algoritmo_ll();

    return 0;
}