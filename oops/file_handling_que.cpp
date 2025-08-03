#include<iostream>
#include<fstream>
using namespace std;
int main(){
    string file_name;
    cin>>file_name;

    ofstream outfile;
    outfile.open(file_name);

    if(!outfile){
        cout<<"File cannot be opened\n";
        exit(1);
    }

    string employee_detail;
    cin.ignore();
    for(int i=0;i<4;i++){  //we wanna insert the details of 4 employee
           
          getline(cin,employee_detail);
          outfile<<employee_detail;
    }

    outfile.close();

    ifstream infile(file_name);
    if(!infile){
        cout<<"File cannot be opened\n";
        exit(1);
    }

    while(infile.eof()==0){
        getline(infile,employee_detail);
        cout<<employee_detail<<endl;
    }

    infile.close();
}