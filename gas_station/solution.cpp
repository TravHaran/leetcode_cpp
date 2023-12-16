#include <vector>
using namespace std;

class Solution {
    /**
     * if we run out of fuel say at some ith gas station then all the gas stations 
     * between ith and starting point are bad starting point as well.
     * So, this means we can start trying at next gas station on the i + 1 station. 
    */
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_diff = 0; // keep track of total gas - cost difference
        int start = 0;
        int tank = 0;
        for(int i = 0; i < gas.size(); i++){
            total_diff += gas[i] - cost[i];
            tank += gas[i] - cost[i];
            if(tank < 0){ // gas tank goes -ve
                tank = 0; // reset tank
                start = i+1; // update to new starting point
            }
        }
        return (total_diff >=0) ? start : -1;   
    }
};