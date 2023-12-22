#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> charMap;
        for(const auto el : ransomNote){
            charMap[el]++;
        }
        for(const auto el : magazine){
            if(charMap.count(el)){
                charMap[el]--;
                if(charMap[el]==0) charMap.erase(el);
            }
            if(charMap.empty()) return true;
        }
        return false; 
    }
};