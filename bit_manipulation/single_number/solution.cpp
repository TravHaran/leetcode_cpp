#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // If we take XOR of zero and some bit, it will return that bit
        // If we take XOR of two same bits, it will return 0
        // duplicates will cancel out so duplicates don't matter
        int val = 0;
        for (auto n : nums){
            val = val ^ n;
        }
        return val;
    }
};