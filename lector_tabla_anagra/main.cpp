#include"tabla_slr.hpp"
#include"gramatica_expan.hpp"


#include<stack>
using namespace std;


#define ACEPTACION "aceptar"

class slr{
  tabla_anagra    _tabla;
  gramatica_expan _reducciones;
  stack<string> pila_entrada;
  stack<string> pila_salida;
  void insertar_consulta(vector<string>& vec);
  void resetear_pilas();
  bool gramatica_aceptada(string fil, string col);
public:
    slr(){ }
    void iniciar_slr(){
      _tabla.inicializar_tabla();
      _reducciones.inicializar();
      resetear_pilas();

    }
    string verificar_entrada(vector<string>& query);

};

void slr::resetear_pilas(){
  while(!pila_salida.empty())
    pila_salida.pop();
  while(!pila_entrada.empty())
      pila_entrada.pop();
  pila_salida.push("0");
  pila_entrada.push("$");
}

void slr::insertar_consulta(vector<string>& vec){
  resetear_pilas();
  vector<string>::reverse_iterator rit;
  for(rit=vec.rbegin() ; rit!=vec.rend() ; rit++){
    pila_entrada.push(*rit);
  }
}

string slr::verificar_entrada(vector<string>& query){
  insertar_consulta(query);
  string cabeza_salida="___";
  string cabeza_entrada="__*__";
  cabeza_entrada=pila_entrada.top();
  cabeza_salida=pila_salida.top();
  while(!gramatica_aceptada(cabeza_salida,cabeza_entrada) && pila_entrada.size()>2 ){
    cabeza_entrada=pila_entrada.top();
    cabeza_salida=pila_salida.top();
    cout<<"@@@@@@@@@@@@@@@@@1"<<endl;
    cout<<cabeza_salida<<"<-->"<<cabeza_entrada<<endl;
    cout<<pila_salida.size()<<"<-->"<<pila_entrada.size()<<endl;

    string memoria=_tabla.consultar(cabeza_salida,cabeza_entrada);
    cout<<cabeza_salida<<"+"<<cabeza_entrada<<">>"<<"_____________"<<endl;
    cout<<"memoria: "<<memoria<<endl;
    if(memoria==ACEPTACION){
      cout<<"TODO OK!"<<endl;
      return "gramatica_aceptada gol!!!";
    }
    string x=memoria.substr(0,1);
    string y=memoria.substr(1);
    if(x=="d"){
      cout<<"desplazamiento:"<<x<<y<<endl;
      pila_salida.push(cabeza_entrada);
      pila_salida.push(y);
      pila_entrada.pop();

    }else if(x=="r"){
      cout<<"reduccion:"<<x<<y<<endl;
      string estado_reduccion=_reducciones.obtener_estado(y);
      int num_pop=stoi(_reducciones.obtener_estado_num(y));
      cout<<estado_reduccion<<num_pop<<endl;
      for(int i=0;i<num_pop*2;i++){
        cout<<"pop :"<<pila_salida.top()<<endl;
        pila_salida.pop();
      }
      cout<<">>> :"<<pila_salida.top()<<endl;
      string temporal=_tabla.consultar(pila_salida.top(),estado_reduccion);
      cout<<temporal<<"!!!!"<<endl;
      pila_salida.push(estado_reduccion);
      pila_salida.push(temporal);
    }
    else{
      cout<<"algo muy malo paso"<<endl;
      return "gramtica no reconocida";
    }
    cout<<"@@@@@@@@@@@@@@@@@2"<<endl;
  }
  cout<<"TODO OK!"<<endl;
  cout<< "gramatica_aceptada gol222!!!"<<endl;
  cout<<"@@@@@@@@@@@@@@@@@FIN"<<endl;

}



bool slr::gramatica_aceptada(string fil, string col){
  string temp=_tabla.consultar(fil,col);
  return temp==ACEPTACION?true:false;
}

int main(){

  vector<string> test;
  test.push_back("int");
  test.push_back("id");
  test.push_back("signoigual");
  test.push_back("numero");
  test.push_back("signopuntoycoma");




  vector<string> test2;
  test2.push_back("void");
  test2.push_back("id");
  test2.push_back("signoparentesisabierto");
  test2.push_back("int");
  test2.push_back("id");
  test2.push_back("signoparentesiscerrado");
  test2.push_back("signollavesabierta");
    // test2.push_back("id");
    // test2.push_back("signoparentesisabierto");
    // test2.push_back("id");
    // test2.push_back("signocoma");
    // test2.push_back("id");
    // test2.push_back("signoparentesiscerrado");
    // test2.push_back("signopuntoycoma");
  test2.push_back("signollavescerrada");

  // void id signoparentesisabierto int id signoparentesiscerrado signollavesabierta
  //     id signoparentesisabierto id signocoma id signoparentesiscerrado signopuntoycoma
  //     id signoparentesisabierto id signocoma id signoparentesiscerrado signopuntoycoma
  //     id signoparentesisabierto id signocoma id signoparentesiscerrado signopuntoycoma
  //     id signoparentesisabierto id signocoma id signoparentesiscerrado signopuntoycoma
  // signollavescerrada


  vector<string> test3;
  test3.push_back("int");
  test3.push_back("id");
  test3.push_back("signopuntoycoma");

  vector<string> test4;
  test4.push_back("int");
  test4.push_back("id");
  test4.push_back("signopuntoycoma");
  test4.push_back("int");
  test4.push_back("id");
  test4.push_back("signoigual");
  test4.push_back("numero");
  test4.push_back("signopuntoycoma");
  // int id signoigual numero signopuntoycoma


  slr mysrl;
  mysrl.iniciar_slr();
  cout<<"!!!!!!!!!!!!!!!!!!!!!"<<endl;
  string resultado = mysrl.verificar_entrada(test2);
  cout<<resultado<<endl;
  cout<<"!!!!!!!!!!!!!!!!!!!!!"<<endl;

  return 0;
}
