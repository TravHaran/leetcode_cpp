#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // it is given that all integers appear thrice except one. 
        // So, if we add all integers modulo 3, then the integer which appears once will be left out.
        int val = 0;
        // iterate over all bits
        for(int i = 0; i < 32 ; i++){
            int bitSum = 0;
            // for this bit, iterate over all integers
            for(auto n : nums){
                //compute the bit of num and update bitsum
                bitSum += (n >> i) & 1;
            }
            // compute the bit of the loner and update our result at the ith bit
            int lonerBit = bitSum % 3;
            val = val | (lonerBit << i);
        }
        return val;
    }
};