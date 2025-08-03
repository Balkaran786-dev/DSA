/*
since for every ele,we have choices,we can increase or decrease or keep it same, in such case greedily soch skte hain

to make max distinct ele,
hum sabse pehle element ko as left as possible bnaeyenge,mtlab uska lowerbound.if we do it,we will have higher liberty and space for next elemnts to transform it.for ex e have 1,2,2,3  k=2;
for 1, range={-1,3} if we make it 2, then for 2nd elemnt that is 2,range{0,4} the liberty to change and form a distinct ele is reduced ,but if we make 1  as -1 ,the liberty of 2nd ele to make a distinct ele increases.

So,for every ele,we will make it as left as possible in its range,keeping in mind that it needs to make distinct ele,'
for that,we need to sort ele in inc order,
then the lower bound of every ele will be in non decresing order,

we r not actually going to change the ele,but we maintain a prevMax
to make max distinct ele,hume try krna hai,ele ko as left as possible bhi rkhe but prevMax se badda,

if prevMax<lowerBound then ele ko lowerBound bna denge(Actual mein nhi),and
prevMax lowerbound bna diya kyunki abh next ele usse badda hone chahiye.

if lowerbound<prevMax<upperbound,then uss ele ko prevMax+1(this will be in range) bna denge  (why only +1? because hume as left as possible rkhna hai esiliye :)  )  

if prevMax>=upperBound then we should not change it as it won't make a distinct ele.

*/


class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int distinctCount=0;
        int prevMax=INT_MIN;

        for(int ele:nums){
            int lowerBound=ele-k;
            int upperBound=ele+k;

            if(prevMax<lowerBound){
                prevMax=lowerBound;
                distinctCount++;
            }
            else if(prevMax<upperBound){
                distinctCount++;
                prevMax++;
            }
        }
        return distinctCount;
    }
};