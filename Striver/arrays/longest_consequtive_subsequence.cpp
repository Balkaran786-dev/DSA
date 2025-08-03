//Brute force:-
//o(n^2) time
//for every ele, we start loop form i=0 to i=n, if we get the next ele , we inc the cnt and find for the next to nxt ele
//basically you got the idea.







//Better solution:-
//if we sort the numbers,the consequtive numbers will come nearer to each other, why said nearer only not together
// beacuse there can be multiple ele with same val,
// initially ,we know, at min,out len will be 1, cnt=0;
// we will keep track of lastSmaller ele,


// if while traversing, last Smaller ele is equal to arr[i]-1, that means we can have it in the consequtive subsequence,
// hence, increment cnt, and change he last smallerele to arr[i], because ahead we need to find the next ele to arr[i],,
// if last Smaller ele is equal to arr[i], don't do anything, we won't add it in it in the consequtive subsequence,
// if last Smaller ele is not equal to arr[i], means current ele is 100 as last Smaller ele is 4, than in that case start
// cnt from 1(we will start forming a new subsequence) and  change he last smallerele to arr[i]


//o(nlogn + n) time


class Solution {
  public:
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int cnt=0;
        int lastSmaller=INT_MIN;
        int longest_len=1;
        for(int i=0;i<n;i++){
            if(arr[i]-1==lastSmaller){
                cnt++;
                lastSmaller=arr[i];
            }
            else if(arr[i]!=lastSmaller){
                cnt=1;
                lastSmaller=arr[i];
            }
            longest_len=max(longest_len,cnt);
        }
        return longest_len;
    }
};


//Optimal
//put everything in an unordered set,
//while traversing in the set,
//if for current ele,you are able to find the ele-1 in the set, don;t start forming sequence,
// bacuse as you know the sequence may start from one less number to it, why to start forming from it as it anyway not
// going to give the longest sequence, 
// if you r nt aable to find ele-1, then start forming subsequnec from it, take cnt=1, find if ele+1 is presnt if yes cnt++, and find for next


class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(arr[i]);
        }
        int longest_len=1;
        for(auto ele:st){
            if(st.find(ele-1)==st.end()){
                int cnt=1;
                int x=ele;
                while(st.find(x+1)!=st.end()){
                    cnt+=1;
                    x+=1;
                }
                longest_len=max(longest_len,cnt);
            }
        }
        return longest_len;
    }
};
