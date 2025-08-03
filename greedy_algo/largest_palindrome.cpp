//leetcode question....

class Solution {
public:
    string largestPalindromic(string num) {
        int n=num.size();

        vector<int> vec(10,0);   //freq of every element storing in vec
        for(int i=0;i<n;i++){
            vec[num[i]-'0']+=1;
        }

        int total_size=0;    
        bool flag=false;
        bool is_there=false;  //so that we can tackle the case when only 0's are present


        //if more than one ele has odd freq,we will take the qdd freq of only the largest number
        //and will deduct 1 from the odd freq of other elemnt. even freq element will be considered as it is.

        //we r calcuating this total size to give an size to the vector...

        for(int i=9;i>=0;i--){
            if(i!=0 && vec[i]!=0){
                is_there=true; //makes true if even a single non zero ele present
            }

            if(vec[i]%2!=0){
                if(!flag){
                    total_size+=vec[i];
                    flag=true;
                }
                else{
                    vec[i]-=1;
                    total_size+=vec[i];
                }
            }
            else{
                total_size+=vec[i];
            }
        }

        if(!is_there){  //if only zeros are present
            return "0";
        }

        vector<char> ans(total_size);  
        int first=0;    //index to place element in ans
    
        for(int i=9;i>=0;i--){
          if(vec[i]%2!=0){  //will run only for one element or zero element (in case only even freq is presnt)
             ans[total_size/2]=char(i+48);  //to convert a number to a charcter
             vec[i]--;
           }

           while(vec[i]>0){ //now,the freq must be even
            ans[first]=char(i+48);
            ans[total_size-first-1]=char(i+48);
            vec[i]-=2;
            first++;
           }
        }
        
        string res="";    //resultant string
        for(int i=0;i<ans.size();i++){
          res+=ans[i];
        }

        int i=0;   //this is done to remove the leading zeroes
        int len=0;
        while(res[i]=='0'){
             len++;
             i++;
        }

        int sz=res.size();
        res.erase(sz-len);
        res.erase(0,len);
            
        return res;
    }
};