#include<fstream>
#include<iostream>
using namespace std;

int main()
{
   char data[100] = {0};
   char buffer[100] = {100};
   ofstream outfile;
   outfile.open("my_file");
   cout << "Writing To the File" << endl;
   cin.getline(data,100);
   outfile << data << endl;
   outfile.close();
   ifstream infile;
   infile.open("my_file");
   infile >> data;
   cout << data <<endl;
   infile.close();
   return 0;
}
