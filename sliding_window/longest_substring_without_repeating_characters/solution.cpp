#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> seen = {};
        int l = 0;
        int maxLen = 0;
        for(int r = 0; r < s.size(); r++){
            while(seen.count(s[r])==1){ // remove duplicates
                seen.erase(s[l]);
                l++;
            }
            // now theres no more duplicates so insert and calculate max size
            seen.insert(s[r]);
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;  
    }
};