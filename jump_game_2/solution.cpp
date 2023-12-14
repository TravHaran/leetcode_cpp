#include <vector>
#include <assert.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
       int min_jumps = 0;
       //define a jump window using two pointers
       int l = 0; 
       int r = 0; 
       int farthest_idx;
       while(r < nums.size() -1){
            //determine the farthest location you can reach
            farthest_idx = 0;
            for(int i = l; i < r + 1; i++){
                farthest_idx = max(farthest_idx, i+nums[i]);
            }
            // update jump window
            l = r+1;
            r = farthest_idx;
            // increment jump count
            min_jumps++;
       }
       return min_jumps;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {2, 3, 1, 1, 4};
    assert(solution.jump(nums)==2);
}