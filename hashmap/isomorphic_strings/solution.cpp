#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> charMapS;
        unordered_map<char, char> charMapT;
        if(s.size() == t.size()){
            for(int i = 0; i < s.size(); i++){
                if(charMapS.count(t[i])){ // check if a character in t maps to the same character in s
                    if(charMapS[t[i]]!= s[i])
                        return false;
                } else if (charMapT.count(s[i])){ // check if a character in s maps to the same character in t
                    if(charMapT[s[i]]!=t[i])
                        return false;
                }
                charMapS[t[i]] = s[i];
                charMapT[s[i]] = t[i];
            }
            return true;
        } 
        return false;  
    }
};