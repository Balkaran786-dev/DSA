
//o(n^2) time    o(n)+o(n) space
class Solution{
public:
    void insert_at_bottom(stack<int> &input,int x){ 
     stack<int> temp;
     while(input.empty()!=true){ //till the time input stack doesn't get empty,keep doing this process
        int curr=input.top();
        input.pop();
        temp.push(curr);
     }
     input.push(x);
     while(temp.empty()!=true){
        int curr=temp.top();
        temp.pop();
        input.push(curr);
     }
    }
    void reverse_helper(stack<int> &input){  //timecomplexity-o(n**2)  spacecomplexity-o(n);
     if(input.empty()){
        return;
     }
     int curr=input.top();
     input.pop();
     reverse_helper(input);
     insert_at_bottom(input,curr);
    }
    void Reverse(stack<int> &St){
        reverse_helper(St);
    }
};

