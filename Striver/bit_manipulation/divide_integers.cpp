// brute approach

// we every time remove just multiples of divisor from dividend,and when the dividend gets lesser
// than its kth multiple , we return the k.
// cnt=0;
// ans=0;
//   while(dividend>=divisor+cnt){
//       cnt+=divisor  // next multiple
//       ans+=1;       // k ko bhi increase kro..
//   }
// this will give TLE in cases like dividend =2^31 and divisor = 1;






// optimised approach:-  o(log n base2)^2 time complexity space -> o(1).

// we know any number can be represnted in the form of powers of 2.
// then , rather than increasing the k by 1, we can increasing it in the form power of 2.
// for example, 22/3 = 7, we can write 7 as (2^2+2^1+2^0) okay.
// rather than removing firstly 3, then 6,9,12,15,18,21
// we can do, 3*2^0=3<22 okay, 3*2^1=6<22 okay, 3*2^2=12<22 okay,3*2^3=24 it becomes greater than 22, we can remove it.
// 22-12=10, and ans mein add kiya 2^2  // jaise pehle hum 1 add krte thee ans mein beacuse everytime we were removing 1st ,2nd , 3rd multiple and so on,
// but now we are removing in 2^x form.


class Solution {
public:
    int divide(int dividend, int divisor) {

        if(dividend==divisor) return 1;
        if(dividend==0) return 0;

        if(dividend==INT_MIN && divisor==-1) return INT_MAX; // it will give ans as 2^31 out of bound of integers]

        bool sign=true;  //+ve
        // agr dono mein se koi ek bhi negative then , sign ko false krdiya.
        if(dividend>0 && divisor<0) sign=false;
        if(dividend<0 && divisor>0) sign=false;

        long n=abs((long)dividend);
        long d=abs((long)divisor);
        long ans=0;

        while(n>=d){   //-> basically d here can be represneted in sum of power of two, and we are running this everytime after removing some pwer of twos from divided so logn
             int cnt=0;
             while(n>=(d<<cnt+1)){  // -> to check which is the greatest power of 2 which when multiplied with divisor exceed divided, so logn
                cnt++;
             }
             ans+=(1<<cnt);
             n-=(d<<cnt);
        }

        return (sign?ans:(-1*ans));
    }
};