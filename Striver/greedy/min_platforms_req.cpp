
// optimal solution o(2nlogn+2n)time  , o(1) space
// dekho yahan mujhe konsi bus ka konsa arrival and departure time hai , isse matlab nhi hai i don't wanna know konsi buses max platfrom cover kr rhi hai,
// i just wanna know ek time pe platform pe maximum kitni buses rhi..
// that we can know , if we are standing at the platform and looking the buses , means as the time goes by,which is definitely gonna go in a sorted manner.
// so if we sort the arr and dept time in one array and also, har ek element ka pta lge if it is arr or dept time of any bus like 8,A or 8,D

// then iterate over it, maintaining a count, which is increased when a arr time comes, beacuse that indicate ek bus ayi(we don't wanna know konsi),and decrement if bus gyi(that shows ki bus gyi)
// Jo count ki max value rhi hogi ,that are the min platforms we req.



// rather forming a separate sorted array, we can simply sort the arr and dept array separately
// take two pointers on the start of both array.
// then compare krte jate jayo, obviusly pehle arr array vala iterator hi bhar niklega.
class Solution {
  public:
   
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        int n=arr.size();
        if(n==1) return 1;
        
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        
        int platform_cnt=0;
        int max_count=0;
        int i=0,j=0;
        while(i<n){
            if(arr[i]<=dep[j]){
                platform_cnt++;
                i++;
            }
            else{
                platform_cnt--;
                j++;
            }
            max_count=max(max_count,platform_cnt);
        }
        return max_count;
        
    }
};

