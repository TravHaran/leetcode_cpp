#include <unordered_set>
#include <vector>
#include <deque>
#include <string>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // convert worldList to set
        unordered_set<string> word_set(wordList.begin(), wordList.end());
        deque<string> q{beginWord};
        unordered_set<string> visited{beginWord};
        string curWord;
        string newWord;
        int wordLength;
        int level = 1;
        int size;
        while(!q.empty()){
            size = q.size();
            for(int i = 0; i < size; i++){
                curWord = q.front();
                q.pop_front();
                if(curWord==endWord) return level;
                for(int i = 0; i < curWord.length(); i++){
                    wordLength = curWord.length();
                    for(int c = 97; c < 123; c++){
                        newWord = curWord.substr(0, i) + (char)c + curWord.substr(i+1, wordLength);
                        if(!visited.count(newWord) && word_set.count(newWord)){
                            q.push_back(newWord);
                            visited.insert(newWord);
                        }
                    }
                }
            }
            level++;
        }
        return 0;
    }
};