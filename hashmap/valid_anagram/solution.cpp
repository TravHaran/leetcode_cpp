#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char, int> charMapS;
        for(const auto el : s){
            charMapS[el]++;
        }
        for(int i = 0; i < t.size(); i++){
            if(charMapS.count(t[i])){
                charMapS[t[i]]--;
                if(charMapS[t[i]]==0) charMapS.erase(t[i]);
            } else {
                return false;
            }
        }
        if(charMapS.empty()) return true;
        return false; 
    }
};