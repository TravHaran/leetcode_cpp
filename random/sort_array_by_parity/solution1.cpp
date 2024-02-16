#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> odd;
        vector<int> even;
        for(auto& n : nums){
            if(n%2 == 0) even.push_back(n);
            else odd.push_back(n);
        }
        even.insert(even.end(), odd.begin(), odd.end());
        return even;
    }
};