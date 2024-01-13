#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>result;
        // handle base case: if num contains 1 element there is only one permutation
        if(nums.size()==1) return {{nums.begin(), nums.end()}};
        
        for(int i = 0; i < nums.size(); i++){
            //remove beginning element of nums and save it
            int n = nums[0];
            nums = {nums.begin()+1, nums.end()};
            vector<vector<int>> perms = permute(nums);
            // now we have a vector for each permutation
            for(auto perm : perms){ // update permutations
                perm.push_back(n);
                result.push_back(perm);
            }
            nums.push_back(n); //backtrack
        }
        return result;
    }
};