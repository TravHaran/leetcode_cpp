#include <cstdint>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i = 0; i < 32; i++){
            // get the ith bit of n
            uint32_t bit = (n >> i) & 1;
            //update result
            res = res | (bit << (31 - i));
        }
        return res;
    }
};