#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freqCount;
        for(auto n : arr){
            freqCount[n]++;
        }
        unordered_set<int> counts;
        for(auto [key, count] : freqCount){
            if(counts.count(count)) return false;
            counts.insert(count);
        }
        return true;
        
    }
};