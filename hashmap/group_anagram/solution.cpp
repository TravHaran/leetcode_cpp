#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        string unsorted_word;
        vector<vector<string>> result;
        for(auto word : strs){
            unsorted_word = word;
            sort(word.begin(), word.end());
            // for(auto el : word){
            //     word_int += int(el);
            // }
            if(groups.count(word)){
                groups[word].push_back(unsorted_word);
            } else {
                groups[word] = {unsorted_word};
            }
        }
        for(auto [key, val] : groups){
            result.push_back(val);
        }
        return result; 
    }
};