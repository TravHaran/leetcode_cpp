#include <vector>
using namespace std;

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        // create output array
        vector<int> output;
        vector<int> nums;
        for(int i = 0; i < n; i++){
            nums.push_back(0);
        }
        int count=0;
        // for each query update output
        for(auto& query : queries){
            int idx = query[0];
            int color = query[1];
            // check if there are adjacent colors before color change and update count
            if(nums[idx]!=0){ // we ignore zero elements
                // check if left was the same
                if(idx-1 >=0 && nums[idx-1]==nums[idx]) count--;
                // check if right was the same
                if(idx+1 < nums.size() && nums[idx+1]==nums[idx]) count--;
            }
            //update nums
            nums[idx] = color;
            // after updating nums we need to update count by checking left and right
            if(idx-1 >=0 && nums[idx-1]==nums[idx]) count++;
            if(idx+1 < nums.size() && nums[idx+1]==nums[idx]) count++;
            output.push_back(count);
        }
        return output;
    }
};