#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <vector>
#include <string>
using namespace std;

class Solution {
    // Time: O(N * M^2), Space: O(N * M^2)
    // where M is the length of each word and N is the total number of words in the input word list
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // build adjacency list
        unordered_map<string, vector<string>> adj;
        //include the first word
        string pattern;
        wordList.push_back(beginWord);
        int wordLen;
        for(auto word : wordList){
            wordLen = word.length();
            for(int i = 0; i < word.length(); i++){
                pattern = word.substr(0, i) + '*' + word.substr(i+1, wordLen);
                adj[pattern].push_back(word);
            }
        }
        unordered_set<string> visit{beginWord};
        deque<string> q{beginWord};
        int steps = 1;
        int size;
        string curWord;
        while(!q.empty()){
            size = q.size();
            for(int i = 0; i < size; i++){
                curWord = q.front();
                q.pop_front();
                if(curWord==endWord) return steps;
                wordLen = curWord.length();
                for(int j = 0; j < curWord.length(); j++){
                    pattern = curWord.substr(0, j) + '*' + curWord.substr(j+1, wordLen);
                    for(auto neighbor : adj[pattern]){
                        if(!visit.count(neighbor)){
                            q.push_back(neighbor);
                            visit.insert(neighbor);
                        }
                    }
                }
            }
            steps++;  
        }
        return 0;
    }
};