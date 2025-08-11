//the concept is equal to leaders in the array vala question

class Solution {
public:
    int maximumSwap(int num) {
        string str=to_string(num);
        int n=str.size();
        vector<int> greater(n,n-1);
        int larg=n-1;
        for(int i=n-2;i>=0;i--){
            if(str[i]>str[larg]){
                larg=i;
            }
            greater[i]=larg;
        }

        for(int i=0;i<n;i++){
            if(greater[i]!=i && str[greater[i]]!=str[i]){
                int larger=greater[i];
                swap(str[larger],str[i]);
                return stoi(str);
            }
        }
        return stoi(str);
    }
};