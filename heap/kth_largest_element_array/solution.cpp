#include <vector>
using namespace std;

class Solution {
    //Time: O(n + klogn)
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end()); // Time -> O(n)   --> (Heapify)
        for(int i = 0; i < k-1; i++){
            pop_heap(nums.begin(), nums.end()); // k log n
            //pop heap does not remove the element instead the element is at the end , so to remove it
            nums.pop_back();
        }
        return nums.front();
        
    }
};