//gfg
int minSwaps(vector<int>& arr) {
        
        vector<pair<int,int>> vec;
        for(int i=0;i<arr.size();i++){
            vec.push_back(make_pair(arr[i],i));
        }
        sort(vec.begin(),vec.end());
        int total_swaps=0;
        for(int i=0;i<vec.size();i++){
 
            int val=vec[i].first;
            int idx=vec[i].second;
            if(idx!=i){
                total_swaps++;
                swap(vec[i],vec[idx]);
                i--;
            }
        }
        return total_swaps;
    }