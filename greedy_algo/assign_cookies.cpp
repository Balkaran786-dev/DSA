/*

dono ko sort krlenge in inc order.

if ek biscuit is able to satisfy the child move both the pointer ahead
and also increment contented

if ek biscuit is not able to satisfy the child move only the biscuit pointer ahead
beacuse agr yeh biscuit itne size vala satisfy nhi kr paya,toh agle bacche jo hain voh toh
aur kutte and bukkhe hain,toh unke bajaye pehle essi bacche ko shant krden thoda badda 
cookie dekar,

or you can think this as agr dono ko manlo aage bdhate,toh by chance essa biscuit ata jo 
abhi vale current ko toh satisfy nhi kr pa rha,but may be pichle kisi child ko kr pata,lekin
uss time shote biscuit ke addh mein humne usse bhi skip krdeya.

toh pehle series vise baccho ko satisfy kro,

*/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int i=0;
        int j=0;
        int G=g.size();
        int S=s.size();
        int contented=0;
        while(i<G && j<S){
            if(s[j]>=g[i]){
               contented++;
               i++;
               j++;
            }
            else{
                j++;
            }
        }
        return contented;
    }
};