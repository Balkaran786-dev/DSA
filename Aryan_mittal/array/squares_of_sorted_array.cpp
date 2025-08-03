class Solution {
public:
    vector<int> sortedSquares(vector<int>& v) {
        int n=v.size();
    vector<int> ans(n);
    int left_ptr=0;
    int right_ptr=n-1;
    int i=n-1;
    while(left_ptr<=right_ptr){

        if(right_ptr==left_ptr){
            ans[i]=(v[left_ptr]*v[left_ptr]);
            left_ptr++;
            right_ptr--;
        }
        else if(abs(v[left_ptr])<abs(v[right_ptr])){     // abs is used too find absolute value
            ans[i]=(v[right_ptr]*v[right_ptr]);
            right_ptr--;
        }
        else if(abs(v[left_ptr])>abs(v[right_ptr])){
            ans[i]=(v[left_ptr]*v[left_ptr]);
            left_ptr++;
        }
        else if(abs(v[left_ptr])==abs(v[right_ptr])){
            ans[i]=(v[left_ptr]*v[left_ptr]);
            i--;
            ans[i]=(v[left_ptr]*v[left_ptr]);
            left_ptr++;
            right_ptr--;
        }
        i--;
    }
    
    return ans;
    }
};