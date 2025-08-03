#include<bits/stdc++.h>
using namespace std;
class binary{
   string s;
   void chk_bin();
   public:
   void setter();
   void ones_compliment();
   void display();
};
void binary::chk_bin(){
    for(int i=0;i<s.length();i++){
        if(s[i]!='0' && s[i]!='1'){
            cout<<"Incorrect binary number";
            exit(0);
        }
    }
}
void binary:: setter(){
    cout<<"Enter the binary number: ";
    cin>>s;
}
void binary::ones_compliment(){
    chk_bin();       //nesting of member function
    for(int i=0;i<s.length();i++){
        if(s[i]=='0'){
            s[i]='1';
        }
        else{
            s[i]='0';
        }
    }
}
void binary:: display(){
    cout<<"displaying string:- "<<endl;
    for(int i=0;i<s.length();i++){
        cout<<s[i];
    }cout<<endl;
}
int main(){  //but we can't call the member function chk_bin() here.
    binary b;  
    b.setter();
    b.display();
    b.ones_compliment();
    b.display();
    return 0;
}

