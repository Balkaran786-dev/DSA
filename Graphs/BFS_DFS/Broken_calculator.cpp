//simple BFS
//ek toh app pehle hi check krlo, if target<startValue return startValue-target;
//otherwise start bfs from startVakue,
//if that number is equal to target, return the number of steps,
//two options if number is lesser than 
//target, then both options if formed number is less than 0, dont push it in queue
//how you can reduce the edges., we can also take visited array, to mark what vakues you have already visited.


//Greedy approach
//backward solution,
//* -> /   - -> +
//divide by 2 when it is even
//add 1 when it is odd

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans=0;
        while(target>startValue){
            ans++;
            if(target%2==1) target++;
            else target/=2;
        }
        return ans+startValue-target;
    }
};