#include <vector>
using namespace std;

class Solution{
public:
    int majorityElement(vector<int> &nums){
        int res = nums[0];
        int count = 0;
        for (int i = 0; i < nums.size(); i++){
            if (res == nums[i]){
                count++;
            } else{
                count--;
            }
            if (count < 0){
                res = nums[i];
                count++;
            }
        }
        return res;
    }
};

/**
 * Boyer-Moore Majority Vote Algorithm:
 * The Boyer-Moore Majority Vote Algorithm is an efficient algorithm for finding the majority element 
 * in a sequence (an element that appears more than n/2 times, where n is the length of the sequence).
 * Here's a simplified explanation of the algorithm:
 * 
 * Initialization:
 * Initialize two variables, candidate and count. Set count to 0.
 * 
 * Voting:
 * Iterate through the sequence.
 * For each element, check if count is 0.
 * If count is 0, set the current element as the candidate.
 * If the current element is equal to the candidate, increment count.
 * If the current element is different from the candidate, decrement count.
 * 
 * The key idea behind the algorithm is that if there is a majority element in the sequence, 
 * it will survive the vote due to its frequency being greater than n/2.
*/