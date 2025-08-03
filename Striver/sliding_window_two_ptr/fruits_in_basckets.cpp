//first solu  o(n^2) time o(1) space
//generating all substring
// when forming substring , will include only 2 type of ele if third ele comes, ill break out of inner loop,means ill stop my subtring 





class Solution {
  public:
    int totalFruits(vector<int> &arr) { // o(n) time o(1) space
        // code here
        int n=arr.size();
        int f_fruit=arr[0];
        int s_fruit=-1;
        int length=1;//obviously first ele ko toh lunga hi na
        int f_idx=0; // last index of first fruit
        int s_idx=-1; //last index of secind fruit which is not yet discovered
        
        
        int lo=0,hi=1;  
        while(hi<n && arr[hi]==arr[lo]){
            hi++;
            length+=1; 
            f_idx++;  //updating last index of first ruit
        }
        
        if(hi<n){   //means we have found the second ele..
            length+=1;
            s_fruit=arr[hi];  //updating the second fruit
            s_idx=hi;    //updating last index of second fruit
        }
        
        hi+=1;

        while(hi<n){ 

            int ele=arr[hi];
            if(ele==f_fruit){ //if ele is equal to first fruit
                length=max(length,hi-lo+1);
                f_idx=hi;   //updating last index of first ruit
            }
            else if(ele==s_fruit){  //if ele is equal to second fruit
                length=max(length,hi-lo+1);
                s_idx=hi;  //updating last index of second fruit
            }
            else{
                if(f_idx<s_idx){   // agr mera first fruit ka last index is kamm than the last index of second fruit, it will be better for me to upadte my first fruit.
                    lo=f_idx+1;
                    f_fruit=ele;
                    f_idx=hi;
                }

                else{ // agr mera second fruit ka last index is kamm than the last index of first fruit, it will be better for me to update my second fruit.
                    lo=s_idx+1;
                    s_fruit=ele;
                    s_idx=hi;
                }
            }
            hi+=1;
        }

        return length;
    }
};

