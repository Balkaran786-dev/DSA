// num2 ka sirf hume set bits chahiye, for that we use __builtin_popcount();
// To minimise the result, we must know that we need to make the left bits as zero as possible.
// for this, during Xor, 0 only occurs either both the bits are 0 or 1.
// In x, we traverse from left and if any bit in the num1 is set, we will make
// that corresponding bit in x as set , by doing result|=(1<<i);
// also we decrease our target_set_bits count by 1.
// in this way we do this.
// after this trversal till the 0th bit , if our target_bits are still remaining,
// we traverse in this x from right, and make the unset bit in the x as set. so that 
// humari set bits vali condition fulfil ho hi ,sath ke sath overall value of the resultant remain minimum.


class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int target_bits=__builtin_popcount(num2);

        int result=0;
        for(int i=31;i>=0 && target_bits>0;i--){ //left to right, whrever we see any set bit in num1,put the corresponding bit in x as set, so that the resultant bit will be 0 .
            if(num1 & (1<<i)){
                result|=(1<<i);
                target_bits--;
            }
        }

        for(int i=0;i<32 && target_bits>0;i++){  //if target bits are still left already,then from right to left, we start make the remainig unset to set bits
                  if((result & (1<<i))==0){
                      result|=(1<<i);
                      target_bits--;
                  }
        }

        return result;
    }
};