#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(nums.size()==1)
            return {to_string(nums[0])};
        string range;
        int range_start;
        int count=0;
        for(int i = 0; i < nums.size(); i++){
            if(i==0){
                range_start = nums[i];
                count++;
            } else {
                if(nums[i]!= nums[i-1]+1){
                    // append the range to result
                    if(count==1) { //range contains single item
                        range = to_string(range_start);
                    } else {
                        range = to_string(range_start) + "->" + to_string(nums[i-1]);
                    }
                    result.push_back(range);
                    count = 1;
                    range_start = nums[i]; // set new start of range
                    if(i==nums.size()-1)
                        result.push_back(to_string(range_start));
                } else if(i==nums.size()-1){
                    range = to_string(range_start) + "->" + to_string(nums[i]);
                    result.push_back(range);
                }else {
                    count++;
                }

            }
        }     
        return result;
    }
};