/*


1.Vertical cuts increases vertical blocks and horizontal cuts increases horizontal blocks.
2.if we applying a vertical cut over n horizontal blocks,then total cost+=cost of single vertical cut*n;


To reduce the total cost,we need to do expensive cuts on as many less blocks as possible.
agar hum expensive cuts pehle krnege,toh voh kam blocks pe hoga,kyunki initially ek purre block
ko toh ham ek block hi mannege.


dono costs vali vector ko sort krenge in the decreasing order.
dono ke first element pe ek ek variable point karvadenge.
merge sort vala funda yahan lgadenge i.e jo dono mein se bada hoga voh cut pehle krenge
and variable ko aage bdhayenge.fir compare krenge and so on.


*/


#include<iostream>  //T.C-o(nlogn+mlogm)   S.C-o(sort ka space-> logn)

#include<vector>

#include<algorithm>

using namespace std;
int min_cutting_cost(vector<int> &v,vector<int> &h){
    sort(v.begin(),v.end(),greater<int>());
    sort(h.begin(),h.end(),greater<int>());
    int vert_blocks=1,hori_blocks=1;   //total vertical and horizontal blocks
    int total_cost=0;
    int vert=0,hort=0;                 //to traverse the sorted arrays,we are using two pointers; 
    while(vert<v.size() && hort<h.size()){
        if(v[vert]>=h[hort]){
             total_cost+=v[vert]*hori_blocks;
             vert_blocks++;
             vert++;
        }
        else if(v[vert]<h[hort]){
            total_cost+=h[hort]*vert_blocks;
            hori_blocks++;
            hort++;
        }
    }
    
    while(vert<v.size()){
        total_cost+=v[vert]*hori_blocks;
        vert_blocks++;
        vert++;
    }
    while(hort<h.size()){
        total_cost+=h[hort]*vert_blocks;
        hori_blocks++;
        hort++;
    }

    return total_cost;
}

int main(){
    int M=6,N=4;
    vector<int> x(M-1);  //for storing the cost of vertical cuts
    vector<int> y(N-1);  //for storing the cost of horizontal cuts
    for(int i=0;i<x.size();i++){
        cin>>x[i];
    }
    for(int i=0;i<y.size();i++){
        cin>>y[i];
    }
    cout<<min_cutting_cost(x,y);
    return 0;
}