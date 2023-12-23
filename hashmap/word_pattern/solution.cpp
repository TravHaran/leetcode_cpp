#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> patternMap;
        unordered_set<string> mappedWords;
        vector<string> wordList;
        string word;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i]==' '){
                wordList.push_back(word);
                word = "";
            } else if(i==s.size()-1){
                word += s[i];
                wordList.push_back(word);
            }else {
                word += s[i];
            } 
        }
        if(pattern.size() != wordList.size()) return false;
        
        for(int i = 0; i < pattern.size(); i++){
            if(patternMap.count(pattern[i])){
                if(patternMap[pattern[i]] != wordList[i])
                    return false;
            } else if(mappedWords.count(wordList[i])){
                return false;
            }  
            patternMap[pattern[i]] = wordList[i];
            mappedWords.insert(wordList[i]);
        }
        return true;
    }
};