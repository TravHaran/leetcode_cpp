#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int num_words = words.size();
        int word_len = words[0].size();
        if(s.size() < word_len*num_words)
            return result;
        unordered_map<string, int> word_map;
        string concat;
        //create frequency map of words
        for(const string word : words){
            concat += word;
            word_map[word]++;
        }
        if(s==concat) // handle edge case in which large word list is equal to string
            return {0};
        
        int start;
        string cur_word;
        unordered_map<string, int> temp_word_map;
        unordered_set<string> prev_seen; // cache to store previously seen unique concatenations
        
        for(int l = 0; l < s.size(); l++){
            if(prev_seen.count(s.substr(l, word_len*num_words))==1){ 
                result.push_back(l);
                continue;
            }
            cur_word = s.substr(l, word_len);
            if(word_map.count(cur_word)==1){
                concat = "";
                start = l;
                temp_word_map = word_map;
                while(l <= (s.size() - word_len) && temp_word_map.count(cur_word)==1){
                    concat += cur_word;
                    temp_word_map[cur_word]--;
                    if(temp_word_map[cur_word] == 0) temp_word_map.erase(cur_word);
                    l += word_len;
                    cur_word = s.substr(l, word_len);
                }
                if(temp_word_map.empty()){
                    result.push_back(start);
                    prev_seen.insert(concat);
                } 
                l = start; // reset l to start so that we can increment to next element of string
            }
        }
        return result;
    }
};

int main(){
    Solution solution;
    string s = "wordgoodgoodgoodbestword";
    vector<string> words = {"word","good","best","word"};
    vector<int> result = solution.findSubstring(s, words);
    for(const auto el : result){
        cout<<el<<endl;
    }
}