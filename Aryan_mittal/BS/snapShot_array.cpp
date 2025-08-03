// giving MLE 
// beacuse im making as many vectors in instances as snap is called..so it goes to max 10^8 times

class SnapshotArray {
    public:
        vector<int> Array;
        vector<vector<int>> instances;
        int snapShot;
        SnapshotArray(int length) {
            Array.resize(length,0);
            snapShot=0;
        }
        
        void set(int index, int val) {
            Array[index]=val;
        }
        
        int snap() {
            instances.push_back({snapShot});   // Push {1} first
            instances.back().insert(instances.back().end(), Array.begin(), Array.end());  
            snapShot++;
            return snapShot-1;
        }
        
        int get(int index, int snap_id) {
            int lo=0;
            int hi=instances.size()-1;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                if(instances[mid][0]==snap_id){
                    return instances[mid][index+1];
                }
                else if(instances[mid][0]>snap_id){
                    hi=mid-1;
                }
                else{
                    lo=mid+1;
                }
            }
            return -1;
        }
    };
    



    //optimised.
// i really want to know that particular ele at that snapshot..
// i don't need to store the entire array at every snapshot.
// instead, when im updating some ele, i can store at which snapshot period im doing it and what value im giving to it. i can store that at that index
// for this , i can maintain vector of vector of pair  , first part stores the snapshot and second part stores the ele  at that index
// while searching for that snapID, may be that won't be present because we are only storing snapshot when we are updating or calling set function
// so, for every snapid , i need to find (the equal to or just smaller snapid) in the vector of vector...
// mATLAB ,mene spanid 2 pe change kiya, than i just took snaps 3 times that made my spanid to 5,
// so when i check at snapid=5, it will give me same ele as what we had at snapid=2;;;


class SnapshotArray {
    public:
        vector<vector<pair<int, int>>> vec;
        int currSnap;
    
        SnapshotArray(int length) {
            vec.resize(length);
            currSnap = 0;
        }
    
        void set(int index, int val) {
            if (vec[index].empty() || vec[index].back().first != currSnap) {
                vec[index].push_back({currSnap, val});
            }
    
            else {
                vec[index].back().second = val;
            }
            return;
        }
    
        int snap() {
            currSnap++;
            return currSnap - 1;
        }
        
        int get(int index, int snap_id) {
            int lo = 0, hi = vec[index].size() - 1;
            int result = 0; // Default value if nothing is found
    
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (vec[index][mid].first == snap_id) {
                    return vec[index][mid].second; // Found exact match
                } else if (vec[index][mid].first < snap_id) {
                    result =
                        vec[index][mid].second; // Store the closest lower value
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
    
            return result; // Return the closest previous snapshot value
        }
    };
    
   