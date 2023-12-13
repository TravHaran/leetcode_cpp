#include <vector>
#include <assert.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2)
            return nums.size();
        int i = 1;
        int dup_count=0;
        while(i < nums.size()){
            if(nums[i]==nums[i-1]){
                dup_count++;
                if(dup_count>1){
                    nums.erase(nums.begin()+i);
                    dup_count--;
                } else {
                    i++;
                } 
            } else {
                dup_count=0;
                i++;
            }
        }
        return nums.size(); 
    }
};

int main(){
    Solution solution;
    vector<int> nums = {1,1,1,2,2,3};
    vector<int> expected = {1,1,2,2,3};
    solution.removeDuplicates(nums);
    assert(expected==nums);
}