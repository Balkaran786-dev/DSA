// #include<iostream>   //o(n)  both time and space complexity
// #include<stack>
// #include<vector>
// #include<algorithm>
// using namespace std;
// vector<int> next_smaller_ele_index(vector<int> input){
//      vector<int> ans(input.size());
//      stack<int> st;
//      st.push(0);
//      for(int i=1;i<input.size();i++){
//         if(input[i]<input[i-1]){  //decreasing slope
//             while(!st.empty()){
//                 if(input[st.top()]>input[i]){
//                     ans[st.top()]=i;
//                     st.pop();
//                 }
//                 else{
//                     break;
//                 }
//             }
//             st.push(i);
//         }
//         else{           //increasing slope
//             st.push(i);
//         }
//      }
//      while(!st.empty()){
//         ans[st.top()]=input.size();
//         st.pop();
//      }
//      return ans;
// }
// vector<int> prev_smaller_ele_index(vector<int> input){
//      reverse(input.begin(),input.end());
//      vector<int> ans(input.size());
//      stack<int> st;
//      st.push(0);
//      for(int i=1;i<input.size();i++){
//         if(input[i]<input[i-1]){  //decreasing slope
//             while(!st.empty()){
//                 if(input[st.top()]>input[i]){
//                     ans[st.top()]=input.size()-i-1;
//                     st.pop();
//                 }
//                 else{
//                     break;
//                 }
//             }
//             st.push(i);
//         }
//         else{           //increasing slope
//             st.push(i);
//         }
//      }
//      while(!st.empty()){
//         ans[st.top()]=-1;
//         st.pop();
//      }
//      reverse(ans.begin(),ans.end());
//      return ans;
// }
// vector<int> Find_area(vector<int> graph){
//     vector<int> nse_idx=next_smaller_ele_index(graph);
//     vector<int> pse_idx=prev_smaller_ele_index(graph);
//     vector<int> area(graph.size());
//     for(int i=0;i<graph.size();i++){
//         area[i]=(nse_idx[i]-pse_idx[i]-1)*graph[i];
//     }
//     return area;
// }
// int main(){
//     vector<int> histogram={2,1,6,7,8,3};
//     vector<int> area=Find_area(histogram);
//     int Max_area=INT16_MIN;
//     for(int i=0;i<area.size();i++){
//         Max_area=max(Max_area,area[i]);
//     }
//     cout<<"The max area:"<<Max_area;
// }










//leetcode solution that i wrote myself
//ek example lo and phir index ki value ko set krna mein next greater ele idx find krte time curr element ko include kiya hai 
    stack<int> st;
    vector<int> next_smaller_ele_idx(vector<int> &heights){
        int n=heights.size();
        vector<int> ans(heights.size(),n);
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
                ans[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> prev_smaller_ele_idx(vector<int> &heights){
        st=stack<int>();
        int n=heights.size();
        vector<int> ans(heights.size(),-1);
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && heights[i]<heights[st.top()]){
                ans[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }  //ek example lekar phir saari index ke value aisi kyu rkhi hai samj ayegi tumko.
    int largestRectangleArea(vector<int>& heights) {
        vector<int> next_smaller=next_smaller_ele_idx(heights);
        vector<int> prev_smaller=prev_smaller_ele_idx(heights);
        int area=INT_MIN;
        for(int i=0;i<heights.size();i++){  //har ek baar ke liye uske (index-prev_smaller_ele_idx-1)+(index-next_greater)
            area=max(area,heights[i]*(abs(i-next_smaller[i])+abs(i-prev_smaller[i]-1)));
        }
        return area;
    }