// //1st part
// #include<bits/stdc++.h>
// using namespace std;
// class String{
//    string str;
//  public:
//     String(){
//         str="";
//     }

//     String(char* p){
//         for(int i=0;i<strlen(p);i++){
//             str.push_back(p[i]);
//         }
//     }

//     void get_value(){
//         cout<<"The value of string is:- "<<str<<endl;
//     }
// };

// int main(){
//     int n;
//     cout<<"size of string is:- ";
//     cin>>n;

//     char* p=new char[n]{};
//     for(int i=0;i<n;i++){
//         char ch;
//         cin>>ch;
//         p[i]=ch;
//     }
//     String obj;
//     obj=p;   //basic dataype to derived datatype
//     obj.get_value();

//     return 0;
// }

// //2nd part
#include<bits/stdc++.h>
using namespace std;
class String{
   string str;
 public:
    String(string s){
        str=s;
    }

    void get_value(){
        cout<<"The value of string is:- "<<str<<endl;
    }

    operator char*();
};
String::operator char *(){
    char* p=new char[str.size()+1]{};
    for(int i=0;i<str.size();i++){
        p[i]=str[i];
    }
    return p;
}

int main(){
    string s;
    cout<<"Enter your string:- ";
    cin>>s;

    String obj(s);
    obj.get_value();
    
    char* p;
    p=obj;  //derived datatype to basic datatype
    

    for(int i=0;i<strlen(p);i++){
        cout<<p[i];
    }

    return 0;
}


