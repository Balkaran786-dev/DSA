#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<pair<int,int>> find_nearer_pts_to_origin(vector<pair<int,int>> points,int k){
    priority_queue<pair<int,pair<int,int>>> pq;  //maxheap
    vector<pair<int,int>> anspts(k);// to store all the points that are nearer to origin
    for(auto &ele:points){
        int dist=ele.first+ele.second;
        pq.push(make_pair(dist,ele)); //distance,pair of coordinates.
        if(pq.size()>k){
            pq.pop();
        }
    }

    while(!pq.empty()){
        anspts[pq.size()-1]=pq.top().second;
        pq.pop();
    }

    return anspts;
}
int main(){
    int n,k;
    cout<<"The number of points are:";
    cin>>n;
    cout<<"The number of points that need to be find:";
    cin>>k;
    vector<pair<int,int>> points(n);
    for(auto &ele:points){
        cin>>ele.first>>ele.second;
    }
    vector<pair<int,int>> anspts=find_nearer_pts_to_origin(points,k);
    for(auto &ele:anspts){
        cout<<ele.first<<" "<<ele.second<<endl;
    }
    return 0;
}