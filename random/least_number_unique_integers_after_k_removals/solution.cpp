#include <vector>
#include <unordered_map>
using namespace std;

/**
Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.
Example 2:
Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.

Test Case 1: [5, 5, 4], k = 1
let's suppose from the array we have a frequency count of each element
{ 
    5 : 2,
    4 : 1  
}
let's say this is sorted in terms of frequency
{ 
    4 : 1,
    5 : 2
}

the unique_count is simply the size of the freq_map
So unique_count = 2;
so for each term if we subtract the count from k, and if k >=0 we decrement unique_count
for 4; k - 1 = 1 - 1 = 0, so now k = 0, unique_count--: 1
so in this case we stop and return unique_count : 1

Test Case 2: [4, 3, 1, 1, 3, 3, 2], k = 3
let's suppose from the array we have a frequency count of each element
{ 
    4 : 1,
    3 : 3,
    1 : 2,
    2 : 1
}
let's say this is sorted in terms of frequency
{
    4 : 1,
    2 : 1,
    1 : 2,
    3 : 3
}
the unique_count is simply the size of the freq_map
So unique_count = 4;
so for each term if we subtract the count from k, and if k >=0 we decrement unique_count
for 4; k - 1 = 3 - 1 = 2, so now k = 2, unique_count--: 3
for 2; k - 1 = 2 - 1 = 1, so now k = 1, unique_count--: 2
for 1; k - 2 = 1 - 2, k  = -1, k < 0, this means that there's still remainders for this term
so in this case we stop and return unique_count : 2
*/
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // create a freq_count of arr
        unordered_map<int, int> freq_count;
        for(auto& n : arr){
            freq_count[n]++;
        }
        vector<int> frequencies;
        int unique_count = freq_count.size();
        for(auto& [key, val] : freq_count){
            frequencies.push_back(val);
        }
        sort(frequencies.begin(), frequencies.end());
        for(auto& f : frequencies){
            k -= f;
            if(k >= 0) unique_count--;
            else return unique_count;
        }
        return unique_count;  
    }
};