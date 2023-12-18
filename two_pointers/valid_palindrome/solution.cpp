#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int first = 0;
        int last = s.size()-1;
        while(first < last){
            s[first] = tolower(s[first]);
            s[last] = tolower(s[last]);
            if(!isalnum(s[first])){
                first++;
                continue;
            }
            if(!isalnum(s[last])){
                last--;
                continue;
            }
            if(s[first]!=s[last])
                return false;
            first++;
            last--;
        }
        return true;
    }
};