#include <vector>
#include <string>
using namespace std;

class Solution {
    /**
     * Initialize an empty string ans to store the common prefix.
     * Sort the input list v lexicographically. 
     * This step is necessary because the common prefix should be common to all the strings, 
     * so we need to find the common prefix of the first and last string in the sorted list.
     * Iterate through the characters of the first and last string in the sorted list, 
     * stopping at the length of the shorter string.
     * If the current character of the first string is not equal to the current character of the last string, 
     * return the common prefix found so far.
     * Otherwise, append the current character to the ans string.
     * Return the ans string containing the longest common prefix.
    */
public:
    string longestCommonPrefix(vector<string>& strs) {
        string  prefix = "";
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string last = strs[strs.size()-1];

        for(int i = 0; i < min(first.size(), last.size()); i++){
            if(first[i]!=last[i])
                return prefix;
            prefix += first[i];
        }
        return prefix; 
    }
};

