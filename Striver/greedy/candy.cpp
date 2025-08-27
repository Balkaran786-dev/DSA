// I can also think of a recursion/ backtracking solution
//but its complexity can be higher


//1st solution
// pehle left neighbours ko dekhkar  candies do
// then right neighbours ko dekhar ,
// akhri mein jo har index mein dono mein se bada hoga usko sum mein add krlo
// class Solution {  //o(n+n)-time  o(n)-space
// public:
//     int candy(vector<int>& ratings) {
//         int n=ratings.size();
//         vector<int> left(n);
        
//         left[0]=1;
//         int cnt=1;
//         for(int i=1;i<n;i++){
//              if(ratings[i]>ratings[i-1]){
//                 cnt++;
//              }
//              else{
//                 cnt=1;
//              }
//              left[i]=cnt;
//         }

//         int sum=0;
//         cnt=1;
//         for(int i=n-2;i>=0;i--){
//              if(ratings[i]>ratings[i+1]){
//                 cnt++;
//              }
//              else{
//                 cnt=1;
//              }
//              sum+=max(left[i],cnt);
//         }
//         sum+=left[n-1];  //we don't need to compare kyunki, right mein hamesha it would be 1,so jo left array mein hoga vahi ayega.....
//         return sum;
//     }
// };



// another approach.....
// great approach................
// Traverse the children from left to right. Any child that has a higher rating than their LH neighbour gets 1 more candy than their LH neighbour. Otherwise they get 1 candy.
// Next, traverse the children from right to left. Any child that has a higher rating than their RH neighbour gets 1 more candy than their RH neighbour - unless they already have more candies than their RH neighbour in which case the number of candies is unchanged.
// Finally, add up all the candies and return the total to the caller



//slope based approach
// start with 1.
// if we are on a flat surface, make cnt=1 amd add to sum,
// increasing slope pe toh koi panga nhi padna . basically,we will increment the counter and add it to sum
// panga padega, if we r on decreasing slope,
// Inside the while,we write a loop jo ke 1 se start hoga and increment hoga and sum mein add hoga jab tak there will be decreasing slope,
// as we either move to the flat or increasing slope, we move out of the loop, we will add the temp in sum
// and decrease the min of the peak and temp from it.
// matlab jo temp ki value hogi ya toh vo ayegi ya toh jo peak pehle tha voh ayega, jo bhi dono mein se maximum hoga


class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int sum=1;
        if(n==1) return sum;
        int i=1;
        int cnt=1;
        while(i<n){
            if(ratings[i]>ratings[i-1]){
                  cnt++;
                  sum+=cnt;
                  i++ ;
            } 
            else if(ratings[i]==ratings[i-1]){
                  cnt=1;
                  sum+=cnt;
                  i++;
            }
            else{
                int peak=cnt;
                int temp=1;
                while(i<n && ratings[i]<ratings[i-1]){
                    sum+=temp;
                    temp++;
                    i++;
                }
                sum+=temp;
                sum-=min(peak,temp);
                cnt=1;
            }
        }
        return sum;
    }
};