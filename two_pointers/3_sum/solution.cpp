#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i = 0;
        int j = 1;
        int k = nums.size()-1;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-1; i++){
            j = i+1;
            k = nums.size()-1;
            while(j < k){
                if(nums[j]+nums[k] == -nums[i]){
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while(j < k && nums[j] == nums[j-1]) j++; // skip consecutive equal elements
                    k--;
                    while(j < k && nums[k] == nums[k+1]) k--; // skip consecutive equal elements
                } else if (nums[j]+nums[k] < -nums[i]){
                    j++;
                } else {
                    k--;
                }
            }
            while(i+1 < nums.size() && nums[i]==nums[i+1]){ // skip consecutive equal elements
                i++;
            }
        }
        return result;
    }
};