//simple brute force...
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
       
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(boxes[j]=='1'){
                    ans[i]+=abs(i-j);
                }
            }

            for(int k=i+1;k<n;k++){
                if(boxes[k]=='1'){
                    ans[i]+=abs(i-k);
                }
            }
        }

        return ans;
    }
};


//prefix sum...

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
       
    
        vector<int> ans(n,0);
        int ones=0;
        int dist=0;
        for(int i=0;i<n;i++){
            ans[i]+=dist;
            if(boxes[i]=='1'){
                ones++;
            }
            dist=dist+ones;
        }
        
        ones=0;
        dist=0;
        for(int i=n-1;i>=0;i--){
            ans[i]+=dist;
            if(boxes[i]=='1'){
                ones++;
            }
            dist=dist+ones;
        }

        return ans;
    }
};