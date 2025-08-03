// brute force
class Solution {
    public:
        string removeOccurrences(string s, string part) {
            int sz=part.size();
            if(s.length()<sz) return s;
    
            while(s.length()>0){
                int idx=s.find(part);
                if(idx>=s.length()){
                    break;
                }
    
                s.erase(idx,sz);
            }
    
            return s;
        }
    };

// a lill better
// stack based.
