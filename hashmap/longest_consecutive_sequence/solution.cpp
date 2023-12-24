#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max_len = INT32_MIN;
        unordered_set<int> nums_set;
        nums_set.insert(nums.begin(), nums.end());
        int n;
        int count;
        for(auto val : nums_set){
            if(!nums_set.count(val-1)){
                n = val;
                count = 1;
                while(nums_set.count(n+1)){
                    count++;
                    n++;
                }
                max_len = max(max_len, count);
            }   
        }
        return max_len==INT32_MIN ? 0 : max_len; 
    }
};