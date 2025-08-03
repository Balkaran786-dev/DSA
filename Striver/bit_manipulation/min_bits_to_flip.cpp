//1st approach 
//convert both numbers to binary and then do count++ if their bits are diff
class Solution {
public:
    int hammingDistance(int x, int y) {
        int count=0;
        int parity1,parity2;
        while(x>0 && y>0){
           parity1=x%2;
           parity2=y%2;
           if(parity1!=parity2)count++;
           x/=2;
           y/=2;
        }

        while(x>0){
           parity1=x%2;
           if(parity1==1)count++;
           x/=2;
        }
        while(y>0){
           parity2=y%2;
           if(parity2==1)count++;
           y/=2;
        }

        return count;
    }
    int minBitFlips(int start, int goal) {
        return  hammingDistance(start,goal);
    }
};




//2 approach by using inbuilt function
class Solution {
public:
    int minBitFlips(int start, int goal) {
        return __builtin_popcount(start^goal);
    }
};



//3rd approach by manually finding the set bits
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int num=start^goal;
        int cnt=0;
        while(num>1){
            cnt+=num&1;
            num=num/2;
        }
        if(num==1)cnt++;
        return cnt;
    }
};