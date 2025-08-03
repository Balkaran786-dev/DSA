// class Solution {
// public:
//     int trap(vector<int>& height) {
//         vector<int>left;
//         vector<int>right;
//         int n=height.size();
//         right.push_back(height[n-1]);
//         left.push_back(height[0]);
//          int i=1;
//         int e=n-2;
//         int maxi1=height[0];
//         while(i<n){
//             maxi1=max(height[i], maxi1);
           
//             left.push_back(maxi1);
//             i++;
            
//         }
//         int maxi=height[n-1];
//         while(e>=0){
//              maxi=max(maxi, height[e]);
//              right.push_back(maxi);
//              e--;
//         }
//         int s=0;
//         int j=right.size()-1;
//         int ans=0;
//         while(s<left.size()&&j>=0){
//             ans+=min(left[s], right[j])-height[s];
//             s++;
//             j--;
//         }
//         return ans;
        
//     }
// }; 
       
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    vector<int> max_left_ele(vector<int> &height,int n){
        vector<int> preffix_max(n);
        preffix_max[0]=height[0];
        for(int i=1;i<n;i++){
            preffix_max[i]=max(preffix_max[i-1],height[i]);
        }
        return preffix_max;
    }

    vector<int> max_right_ele(vector<int> &height,int n){
        vector<int> suffix_max(n);
        suffix_max[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            suffix_max[i]=max(suffix_max[i+1],height[i]);
        }

        return suffix_max;
    }
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> right_max=max_right_ele(height,n);
        vector<int> left_max=max_left_ele(height,n);

        int area=0;
        for(int i=0;i<n;i++){
            int h=min(left_max[i],right_max[i]);
            area+=(h-height[i]);
        }
        return area;
    }
};
int main(){
    Solution s;
    vector<int> height={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<s.trap(height);
    return 0;
}