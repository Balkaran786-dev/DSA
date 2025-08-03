//1st approach  //o(N!+N*N!); time   
// 1st string ke sabhi permuatation ko ek vector of string mein store krvalo
// then turn by turn, sabhi ko string 2 mein through find function labh lo. at any step,
// you r able to find any permutation in string 2 return true;





//sliding window approach and 2 pointer approach, here once your size of window gets eual to length f string s1,
// aap constant hi rkhoge , means l++ kiya matlab ek unit decrease hua, then r++ kiya matlab 1 unit increase kiya.
// o(n) time , o(n) space
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int sz=s1.length();
        int n=s2.length();
        
        if(sz>n) return false;
        vector<int> freq(26,0);
        for(int i=0;i<sz;i++){
            freq[s1[i]-'a']++;
        }

        int l=0,r=0;
        vector<int> temp(26,0);
        while(r<n){
            temp[s2[r]-'a']++;

            if(r-l+1==sz){
                if(temp==freq) return true;

                temp[s2[l]-'a']--;
                l++;
            }

            r++;  // in every case whether the size is equal or less than
        }

        return false;
    }
};


