/*#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

int main()
{
//	ifstream input("read.txt");
	ifstream myfile("TSE_txt",ios::in);
	std::vector<std::string> v;
  	std::string line;
  	while(std::getline(myfile, line))
  	{
			string::iterator it=line.begin();
			while(it!=line.end())
			{
				cout<<*it;
				it++;
	
    	
  			} 
			v.push_back(line);
	}                                     
//  	for(auto& s : v){std::cout << s << std::endl;}
		
	string str="int a =;";
	string::iterator it=str.begin();
	while(it!=str.end())
	{
		cout<<*it;
		it++;
	}*/
// istream::get example
#include <iostream>     // std::cin, std::cout
#include <fstream>      // std::ifstream

int main () {
  char str[256];

  std::cout << "Enter the name of an existing text file: ";
  std::cin.get (str,256);    // get c-string

  std::ifstream is(str);     // open file

  char c;
  while (is.get(c))
{
	if(c=='\n') {std::cout<<sizeof('\n')<<"newline";}          // loop getting single characters
	if(c==' ') {std::cout<<"space";}          // loop getting single characters
   if(c=='\t') {std::cout<<"tab";}     
std::cout << c;
}
std::cout<<sizeof(c)<<std::endl;
  is.close();                // close file


	return 0;
}
