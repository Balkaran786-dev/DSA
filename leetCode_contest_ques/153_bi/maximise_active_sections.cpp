// groups find krte jayo and jisme sabse jada zeroes honge, usko store krlo,
// uska start and end indices,  kyunki voh sara group toh 1 ban jayega. fer uske elava 
// jo 1 bach gaye unko count  bhi toh krna hai,

// group is subsequent 0s then subsequent 1s then subsequent 0s,
// agr ek bhi esa group nhi mila, toh just count the ones,
// beacuse hum sirf ek baar hi operation kr skte hain, isiliye,
// sabse jada zeroes vala group find kro...


class Solution {
    public:
        int maxActiveSectionsAfterTrade(string s) {
            int n=s.size();
            int max_left=-1,max_right=-1;
            int left=-1,mid=-1,right_e=-1;
            int cnt_0=0;
            int max_cnt_0=0;
            int max_len=-1;
            for(int i=0;i<n;i++){
                if(s[i]=='0' && mid==-1 && left==-1){ //left portion
                    left=i;
                    cnt_0++;
                }
                else if(s[i]=='0' && mid==-1 && left!=-1){ //for subsequent zeroes in left portion
                     cnt_0++;
                }
                else if(s[i]=='0' && mid!=-1 && i==n-1){  // for last ele if it is zero
                    right_e=i;
                    cnt_0++;
                    if(cnt_0>max_cnt_0){
                        max_left=left;
                        max_right=right_e;
                        max_len=right_e-left+1;
                    }
                }
                else if(s[i]=='0' && mid!=-1){  //right portion
                    right_e=i;
                    cnt_0++;
                }
                else if(s[i]=='1' && left!=-1 && right_e==-1){ // middle 1's portion
                    mid=i;
                }
                else if(s[i]=='1' && right_e!=-1){  //another group , so jump to it by updation the max_len if needed
                    if(cnt_0>max_cnt_0){
                        max_left=left;
                        max_right=right_e;
                        max_cnt_0=cnt_0;
                        max_len=right_e-left+1;
                    }
                    left=mid+1;
                    mid=i;
                    right_e=-1;
                    cnt_0=mid-left;
                }
                continue;
            }
            int cnt=0;
            if(max_len!=-1){
                cnt+=(max_len);
            }
            for(int i=0;i<=max_left;i++){
                if(s[i]=='1') cnt++;
            }
            for(int i=max_right+1;i<n;i++){
                if(s[i]=='1') cnt++;
            }
            return cnt;
        }
    };