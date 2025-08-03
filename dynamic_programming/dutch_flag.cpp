#include<bits/stdc++.h>
#include<vector>
using namespace std;
void sort(vector<int> &nums){
    int low=0,mid=0,high=nums.size()-1;
       while(mid<=high){
        if(nums[mid]==0 && mid==low){
            mid++;
            low++;
        }
        else if(nums[mid]==2){
            swap(nums[mid],nums[high]);
            high--;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else if(nums[mid]==0 && mid!=low){
            swap(nums[mid],nums[low]);
            low++;
        }
       }
    
}
int main(){
    vector<int> v={0,2,1,2,1,0,0,1,2};
    sort(v);
    for(int i=0;i<v.size();i++){
          cout<<v[i]<<" ";
    }
    
    cout<<"\nName: Balkaran singh\nRollNo: 23103027\n";

}