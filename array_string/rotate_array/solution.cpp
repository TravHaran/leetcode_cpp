#include <vector>
using namespace std;

class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            k %= nums.size(); // doing this allows to get a k rotation value that will always be less than the array size
            int end = nums.size()-1;
            // reverse from beginning of array to end - k;
            reverse(nums, 0, end - k);
            // reverse from end - k + 1 to end
            reverse(nums, end - k + 1, end);
            // reverse entire array
            reverse(nums, 0, end);
        }
    private:
        void reverse(vector<int>& nums, int start, int end){
            int temp;
            while(start < end){
                temp = nums[start];
                nums[start] = nums[end];
                nums[end] = temp;
                start++;
                end--;
            }
        }
};