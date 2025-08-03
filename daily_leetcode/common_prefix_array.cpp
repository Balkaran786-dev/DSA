class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> mp1;  //ele, freq
        unordered_map<int,int> mp2;
        int ans=0;
        int n=A.size();
        vector<int> C(n);
        for(int i=0;i<n;i++){
            mp1[A[i]]++;
            mp2[B[i]]++;
            if(mp2.find(A[i])!=mp2.end()){
                ans+=1;
                mp1[A[i]]--;
                mp2[A[i]]--;
            }
            if(mp2[B[i]]!=0 && mp1.find(B[i])!=mp1.end()){
                ans+=1;
                mp1[B[i]]--;
                mp2[B[i]]--;
            }
            C[i]=ans;
        }
        return C;
    }
};