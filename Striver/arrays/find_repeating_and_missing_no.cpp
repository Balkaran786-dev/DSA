// o(n^2) time, o(1) space
// find for 1 in array, count its occurrence in array,if cnt==2 repeating or if it is -1, it is the missing value
// now find for 2, 3 .....n




// o(2n)->time  o(n)->space
// taking a hasharray.
// storing the frequency of values in the hasharray and then iterating over the hasharray
// to find the repeating and the missing values.



// x=repeating no.
// y=missing no.

// if you do this, you will get to know that
// x-y=(sum of given numbers)-(sum of numbers from 1 to n)=val1; 
// x^2-y^2=(sum of the square of given numbers)-(sum of the squares of numbers from 1 to n);
// x^2-y^2=(x+y)(x-y);
// x+y=(x^2-y^2)/(x-y)= val2;
// x=(val1+val2)/2;
// y=x-val1;


class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        long Sn= (long) n * (n+1) / 2;
        long S2n=(long) n * (n+1) * (2 * n+1) /6;
        long S=0;
        long S2=0;
        for(int i=0;i<n;i++){
            S+=arr[i];
            S2+=(long)arr[i] * arr[i];
        }
        long val1=S-Sn;
        long val2=(S2-S2n)/val1;
        
        int x=(int)(val1+val2)/2;
        int y=(int) x-val1;
        return {x,y};
    }
};

