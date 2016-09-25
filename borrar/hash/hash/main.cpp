#include <QCoreApplication>
#include<unordered_map>
using namespace std;
typedef  bool (*pfun)(char c);
typedef unordered_map<int,pfun> hash_function;



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    hash_function mytabla;
    //mytabla.insert(pair<int,pfun>(0,*es_cero));
   // mytabla.insert(pair<int,pfun>(0,*es_cero));
    return a.exec();
}
