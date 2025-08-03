#include<iostream>
using namespace std;
void towerOfHanoi(int n, char from, char to,char by){
    if(n==0){
      return;
    }
    towerOfHanoi(n - 1, from, by, to);
    cout<<n<<" disk : "<< from <<" -> "<<to<<endl;
    towerOfHanoi(n - 1, by, to, from);
}
int main(){
   int n;
   cout<<"Enter the number of disks:- "<<endl;
   cin>>n;
   towerOfHanoi(n, 'a', 'c', 'b');
    return 0;
}


// class MyCircularDeque {
// public:
//     list<int> lt;
//     int cs;
//     int total_sz;
//     MyCircularDeque(int k) {
//         this->cs=0;
//         this->total_sz=k;
//     }
    
//     bool insertFront(int value) {
//         if(cs==total_sz) return false;
//         lt.push_front(value);
//         cs++;
//         return true;
//     }
    
//     bool insertLast(int value) {
//         if(cs==total_sz) return false;
//         lt.push_back(value);
//         cs++;
//         return true;
//     }
    
//     bool deleteFront() {
//         if(cs==0)return false;
//         lt.pop_front();
//         cs--;
//         return true;
//     }
    
//     bool deleteLast() {
//         if(cs==0)return false;
//         lt.pop_back();
//         cs--;
//         return true;
//     }
    
//     int getFront() {
//         if(cs==0) return -1;
//         else return *(lt.begin());
//     }
    
//     int getRear() {
//         if(cs==0) return -1;
//         else return *(lt.rbegin());
//     }
    
//     bool isEmpty() {
//         return cs==0;
//     }
    
//     bool isFull() {
//         return cs==total_sz;
//     }
// };


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
       