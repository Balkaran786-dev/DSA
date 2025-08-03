// we basicaaly need to add
// extra student to that class that will make the larger increment the avg pass ration
// who will make that? jiska khudka pass ratio jada hoga,
// abb, kiska pass ratio jada increse hoga ek extra student add krne ke baad, ussi ke basis
// per hume sort krna hai, jiska yeh extra student add krne par change jada bada hua, we will prefer to add in it.

// so, we Keep a max heap of the current class 
//sizes and order them by the change in pass ratio.

class Solution {
    public:
        double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
            auto gain = [](double pass, double total) {
                return (pass + 1) / (total + 1) - pass / total;
            };
    
            priority_queue<pair<double, pair<int, int>>> maxHeap;
    
            double sum = 0.0;
    
            for (const auto& cls : classes) {
                int pass = cls[0], total = cls[1];
                sum += (double)pass / total;  
                maxHeap.push({gain(pass, total), {pass, total}});
            }
    
            for (int i = 0; i < extraStudents; ++i) {
                auto [currentGain, data] = maxHeap.top(); maxHeap.pop();
                int pass = data.first, total = data.second;
    
                sum -= (double)pass / total;
                pass += 1;
                total += 1;
                sum += (double)pass / total;
    
                maxHeap.push({gain(pass, total), {pass, total}});
            }
    
            return sum / classes.size();
        }
    };