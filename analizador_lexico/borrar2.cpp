#include<iostream>
#include <unordered_map>
using namespace std;



int main(){

    unordered_map<string, int> hash;

    hash.insert({"will",1});
    hash.insert({"who",2});
    hash.insert({"how",3});
    hash.insert({"be",4});



    cout<<"resultado; "<<hash["beAaaa"]<<"<--"<<endl;

    char c='ñ';
    // cout << int(c);


    return 0;
}