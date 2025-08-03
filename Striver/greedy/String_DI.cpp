class Solution {
    public:
        vector<int> diStringMatch(string s) {
            int n=s.size();
            vector<int> vec(n+1);
            int i=0;
            int p=0,q=n;
            for(auto ele:s){
                 if(ele=='I'){
                    vec[i++]=p;
                    p++;
                 }
                 else{
                    vec[i++]=q;
                    q--;
                 }
            }
            vec[i]=q;
            return vec;
        }
};

