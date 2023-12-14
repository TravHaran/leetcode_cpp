#include <vector>
#include <assert.h>
using namespace std;

class Solution {
    /**
     * iterate through each index and keep track of max reachable target
     * at any point the current index is greater than the maximum reachable, 
     * then we return false
    */
    public:
        bool canJump(vector<int>& nums) {
            int reachable = 0;
            for(int i = 0; i < nums.size(); i++){
                if(i > reachable)
                    return false;
                reachable = max(reachable, i + nums[i]);
            }
            return true;
        }
};

int main(){
    Solution solution;
    vector<int> nums = {2, 5, 0, 0};
    assert(solution.canJump(nums)==true);
}