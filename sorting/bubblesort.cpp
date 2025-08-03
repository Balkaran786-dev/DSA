#include<iostream>
#include<vector>
using namespace std;
void bubblesort(vector<int> &v){
    int n=v.size();
    for(int i=0;i<n-1;i++){  //n-1 times hi loop run hoga.akhri element n-1 iteration ke baad apne aap right place pe aa jayega.
        bool flag=false;  // agar pehle hi 1 aur 2 passes mein sorted ban gyi, so no need to go ahead..hence taken this flag
        for(int j=0;j<n-1-i;j++){ // -i esliye kyunki har ek pass ke sath ek last element apni correct position pe ajeyega so no need to check it
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
                flag=true;
            }
        }
        if(!flag){  // only if the swaping doesn't occur even one time,then !flag is true
            break;
        }
    }
}
int main(){
    vector<int> vec={2,100,7,8,1};
    bubblesort(vec);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
}