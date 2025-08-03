//1061.

class Solution {
public:
    char find(char ele,vector<char> &par){
         return par[ele-'a']=(par[ele-'a']==ele? ele : find(par[ele-'a'],par)); 
    }
    void Union(char ch1,char ch2,vector<char> &par){
         ch1=find(ch1,par);
         ch2=find(ch2,par);
         if(ch1<ch2) par[ch2-'a']=ch1;
         else if(ch1>ch2) par[ch1-'a']=ch2; 
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.size();
        vector<char> par(26);
        for(int i=0;i<=25;i++){
            par[i]=i+'a';
        }

        for(int i=0;i<n;i++){
            Union(s1[i],s2[i],par);
        }

        int n2=baseStr.size();
        for(int i=0;i<n2;i++){
            char ch=baseStr[i];
            char ans=par[ch-'a'];
            while(par[ans-'a']!=ans){ 
                ans=par[ans-'a'];
            }
            baseStr[i]=ans;
        }
        return baseStr;
    }
};