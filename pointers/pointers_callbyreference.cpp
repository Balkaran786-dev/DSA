#include<iostream>  
using namespace std;  //done call by reference using ampersand operator.
void firstandlastindex(char string[],char ch,int n,int &first,int &last){
    for(int i=0;i<n;i++){
        if(string[i]==ch){
            first=i;
            break;       
        }
    }
    for(int i=n-1;i>=0;i--){
        if(string[i]==ch){
            last=i;
            break;
        }
    }
}
int main(){
    int first=-1,last=-1;
    char s[]="aabcaacd";
    char ch='c';
    firstandlastindex(s,ch,8,first,last);
    cout<<first<<endl<<last;
    return 0;
}

#include<iostream>
#include<string>  //done call by reference using pointers.
using namespace std;
void firstandlastindex(char string[],char ch,int n,int *first,int *last){
    for(int i=0;i<n;i++){
        if(string[i]==ch){
            *first=i;
            break;       
        }
    }
    for(int i=n-1;i>=0;i--){
        if(string[i]==ch){
            *last=i;
            break;
        }
    }
}
int main(){
    int first=-1,last=-1;
    char s[]="aabcaacd";
    char ch='c';
    firstandlastindex(s,ch,8,&first,&last);
    cout<<first<<endl<<last;
    return 0;
}