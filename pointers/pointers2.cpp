#include<iostream>
using namespace std;
void swap(int *a,int *b){
    int temp;  // jinme adress pass kiya unn pointer variable ki values pe operation kiye
    temp=*b;
    *b=*a;  // baad me dereference operator se values pass kardi
    *a=temp;
}
int main(){
    int x=50;
    int y=60;
    int *p=&x;  // jo variables hai unka address store kardiya..
    int *q=&y;  
    swap(p,q);  // jo address hai vahi pass kardiya...   fer uper padho
    cout<<x<<" "<<y;
    return 0;
}

#include<iostream>
using namespace std;
void firstAndLastIndex(string s,char ch,int *first,int *last){
       for(int i=0;i<s.size();i++){
         if(ch==s[i]){
            *first=i;
            break;
         }
       }
       for(int i=s.size()-1;i>=0;i--){
        if(ch==s[i]){
            *last=i;
            break;
        }
       }
}                           //think deeply and conceptually you will definitely understand
int main(){
    string s="aaabac";
    char ch='a';
    int first=-1;
    int last=-1;
    int *pf=&first;
    int *pl=&last;
    firstAndLastIndex(s,ch,pf,pl);
    cout<<first<<" "<<last<<endl;
    cout<<*pf<<" "<<*pl;
    return 0;
}