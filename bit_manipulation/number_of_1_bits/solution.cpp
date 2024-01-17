#include <cstdint>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        //get the ith bit of n and if it's equal to 1 increment count
        int count = 0;
        for(int i = 0; i < 32; i++){
            if((n>>i) & 1) count++;
        }
        return count;
        
    }
};