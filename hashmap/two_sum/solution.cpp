#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> complementMap;
        for(int i = 0; i < nums.size(); i++){
            if(complementMap.count(nums[i])){
                return {complementMap[nums[i]], i};
            }
            complementMap[target-nums[i]] = i;
        }
        return {-1, -1};
    }
};