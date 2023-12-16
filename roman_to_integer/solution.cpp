#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> numerals = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int result = numerals[s[0]];
        for(int i = 1; i < s.size(); i++){
            if(
                ((s[i]=='V' || s[i]=='X') && s[i-1]=='I') ||
                ((s[i]=='L' || s[i]=='C') && s[i-1]=='X') ||
                ((s[i]=='D' || s[i]=='M') && s[i-1]=='C')
                ){
                result += (numerals[s[i]] - numerals[s[i-1]] - numerals[s[i-1]]);
            } else {
                result += numerals[s[i]];
            }
        }
        return result;   
    }
};