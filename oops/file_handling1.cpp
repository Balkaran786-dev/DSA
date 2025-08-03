#include<iostream>
#include<fstream>

/*
These are some useful classes for working with files in C++

fstreambase
ifstream --> derived from fstreambase
ofstream --> derived from fstreambase*/
using namespace std;
// int main(){
//     /*In order to work with files in C++, you will have to open it. Primarily, there are 2 ways to open a file:

//     Using the constructor
//     Using the member function open() of the class*/

//     //using constructor:-
//     string s1="Harry bhai";
//     ofstream out("sample.txt");
//     out<<s1;
//     out.close();
    

//     string s2;
//     ifstream in("sample2.txt"); 
//    // in>>s2;  //it only takes input till a tabspace or a new line character
//     getline(in,s2); //it takes only one line at a time
//     getline(in,s2);
//     cout<<s2;
    


//     return 0;
// }

int main(){
   //using member function open()
   string str="Hello im balkaran singh\n im generous \n thats why nobody hates me";
   ofstream out;
   out.open("sample.txt");
   
   out<<str;

   out.close();

   ifstream in;
   in.open("sample.txt");
   while(in.eof()==0){  //eof() returns 1 if the pointer reaches the end of the file.
     getline(in,str);
     cout<<str<<endl;
   }
   
   in.close();
    return 0;
}