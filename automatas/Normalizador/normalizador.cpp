#include "normalizador.hpp"

void normalizador::cargar_map(char* &pointer,map<char,char> & mymap)
{
  pointer=0;
  mymap['=']=' ';
  mymap[',']=' ';
  mymap['(']=' ';
  mymap[')']=' ';
  mymap[';']=' ';
  mymap['*']=' ';
  mymap['+']=' ';
  mymap['-']=' ';
  mymap['/']=' ';

};
void normalizador::normalizar_cadena(std::string & mystr,char * & pointer,map<char,char> & mymap)
{
  string::iterator np_bus= mystr.begin(),np_ant;
  std::map<char,char>::iterator p_map;
  pointer=&(*np_bus);
  p_map=mymap.find(*pointer);
  while(np_bus!=mystr.end())
  {
    np_ant=np_bus;
    pointer=&(*np_bus);
    p_map=mymap.find(*pointer);
    if(p_map->first==*pointer)
    {
        np_ant=mystr.insert(np_bus,' ');
        np_bus=mystr.insert(np_ant+=2,' ');
        np_bus++;
    }
    if(np_bus==mystr.end())
      break;
    np_bus++;
  }
  string::iterator p_bus= mystr.begin(),p_ant;
  while(p_bus!=mystr.end())
  {
    p_ant=p_bus;
    if (*p_bus==' '||*p_bus=='\t')
    {
      while(*p_bus==' '||*p_bus=='\t')
      {
        p_bus++;
      }
      mystr.erase(p_ant,p_bus);
      p_bus=mystr.insert(p_ant,' ');
      p_bus++;
    }
    else
    p_bus++;
  }
};

void normalizador::normalizar_archivo(const char* & input,const  char* & ouput)
{
  std:map<char,char> mymap;
  char * pointer;
  cargar_map(pointer,mymap);

  ifstream inf(input);
  ofstream ouf(ouput);
  string buffer;
  if (inf.is_open())
  {
    while ( getline (inf,buffer) )
    {
      normalizar_cadena(buffer,pointer,mymap);
      ouf << buffer << '\n';
    }
    inf.close();
    ouf.close();
  }
}