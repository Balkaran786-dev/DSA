//when only one type of bracket,for instance parenthesis are there in the input.

//have a variable counter initialised with zero.
//if a opening bracket comes,increase it by one.
//if a closing bracket comes,first check that counter>0 and then decrease it by 1.
//at last if our counter is 0 that means every opening bracket gets its counter part hence return true,otherwise false

#include<iostream>
using namespace std;
bool is_balanced(string str){
    int counter=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='('){
            counter++;
        }
        else{
            if(counter>0){
                counter--;
            }
            else{
                return false;
            }
        }
    }
    return counter==0;
}
int main(){
    string str;
    cin>>str;

    cout<<is_balanced(str);
    return 0;
}