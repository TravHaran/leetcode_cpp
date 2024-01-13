#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    //Time: O(N*4^N)
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits=="") return result;
        unordered_map<char, string> digitMap = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "qprs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        backtrack(digits, 0, "", result, digitMap);
        return result;
    }
    
    void backtrack(string& digits, int i, string curStr, vector<string>& result, unordered_map<char, string>& map){
        if(curStr.length()==digits.length()){
            result.push_back(curStr);
            return;
        }
        for(auto c : map[digits[i]]){
            backtrack(digits, i+1, curStr+c, result, map);
        }
    }
};