#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size()-1;
        int sum;
        while(l < r){
            sum = numbers[l] + numbers[r];
            if(sum > target){
                r--;
                while(r < l && numbers[r]==numbers[r-1]) // skip over consecutive equal elements
                    r--;
            } else if(sum < target){
                l++;
                while(r < l && numbers[l]==numbers[l+1]) // skip over consecutive equal elements
                    l++;
            } else {
                return {l+1, r+1};
            }
        }
        return {-1, -1};
    }
};