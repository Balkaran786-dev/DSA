/*
Gfg se dekho 

*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        vector<int> Union;
        int i=0,j=0;
        int A=a.size();
        int B=b.size();
        while(i<A && j<B){
            if(a[i]==b[j]){
                Union.push_back(a[i]);
                while(i+1<A && a[i]==a[i+1]){
                    i++;
                }
                while(j+1<B && b[j]==b[j+1]){
                    j++;
                }
                i++;
                j++;
            }
            else if(b[j]>a[i]){
                Union.push_back(a[i]);
                while(i+1<A && a[i]==a[i+1]){
                    i++;
                }
                i++;
            }
            else{
                Union.push_back(b[j]);
                while(j+1<B && b[j]==b[j+1]){
                    j++;
                }
                j++;
            }
        }
        while(i<A){
            Union.push_back(a[i]);
            while(i+1<A && a[i]==a[i+1]){
                    i++;
            }
            i++;
        }
        while(j<B){
            Union.push_back(b[j]);
            while(j+1<B && b[j]==b[j+1]){
                    j++;
            }
            j++;
        }
        
        return Union;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends