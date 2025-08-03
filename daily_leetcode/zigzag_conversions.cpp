// simply observation based..
class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        vector<string> vec(numRows,"");
        int i=0; //to iterate over the given string
        while(i<n){
            
            for(int a=0; a<=numRows-1 && i<n ; a++){
                vec[a].push_back(s[i]);
                i++;
            }
            for(int a=numRows-2; a>=1 && i<n ; a--){
                vec[a].push_back(s[i]);
                i++;
            }
        }

        string str="";
        for(string ele:vec){
            str+=ele;
        }
        return str;
    }
};






//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    int floorSqrt(int n) {
        // Your code goes here
        int lo=1; //starting of the array
        int hi=n/2; //ending of the array  //sqaure root of n will always lie between 1 to n/2..
        int ans;
        while(lo<=hi){
           int mid=(lo+hi)/2;  //modified form to tackle overflow mid=lo+(hi-lo)/2
           if(mid*mid<=n){
            ans=mid;
            lo=mid+1;
           }
           else{
            hi=mid-1;
           }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends