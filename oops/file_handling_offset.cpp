 #include<fstream>
 #include<iostream>
 using namespace std;
 int main()
 {
 int pos;
 fstream outFile;     
//create Object

 outFile.open("Message.txt",ios::out);   //open file for writing

 outFile<<"WELCOME TO THE WORLD OF C++ PROGRAMMING";

 cout<<"\n The current position of Write pointer is";
 cout<<outFile.tellp();   // display current position

 cout<<"\n Enter the position to move :";
 cin>>pos;
 outFile.seekg(pos, ios::beg);  // move pointer to specified position

 cout<<"\n The position of get pointer is :";
 cout<<outFile.tellg();     

//position of get pointer
 cout<<"\n Enter the poistion to move from current position :";
 cin>>pos;

 outFile.seekg(pos, ios::cur);
 cout<<"\n The position of get pointer is :";
 cout<<outFile.tellg();     

//position of get pointer
 cout<<"\n Enter the poistion to move from end :";
 cin>>pos;
 outFile.seekg(-pos, ios::end);       
  
//relocate get pointer
 cout<<"\n The position of get pointer is :";
 cout<<outFile.tellg();     
return 0;
 }