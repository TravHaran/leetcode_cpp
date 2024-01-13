#include <string>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord;
    TrieNode(){
        children = {};
        endOfWord = false;
    }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(auto c : word){
            if(!cur->children.count(c))
                cur->children[c] = new TrieNode();
            cur = cur->children[c];
        }
        cur->endOfWord = true;  
    }
    
    bool search(string word) {
        return dfs(0, root, word);
    }

    bool dfs(int j, TrieNode* root, string& word){
        TrieNode* cur = root;
        for(int i = j; i < word.length(); i++){
            char c = word[i];
            if(c=='.'){
                for(auto [key, val] : cur->children){
                    if(dfs(i+1, val, word)) return true;
                }
                return false;
            } else {
                if(!cur->children.count(c))
                    return false;
                cur = cur->children[c];
            }
        }
        return cur->endOfWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */