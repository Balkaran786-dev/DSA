#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<int,string> roll_no;
    roll_no[2345]="Balkaran";
    roll_no.insert(make_pair(3465,"Ashmir"));
    roll_no[2445]="yuiu";
    roll_no[2145]="Balren";

    for(auto ele:roll_no){
        cout<<ele.first<<"-"<<ele.second<<endl;
    }
    return 0;
}