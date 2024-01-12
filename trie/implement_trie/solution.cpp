#include <unordered_map>
#include <string>
using namespace std;

class TrieNode{ 
public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord;
    TrieNode(){
        children = {};
        endOfWord = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for(auto c : word){
            if(!cur->children.count(c))
                cur->children[c] = new TrieNode();
            cur = cur->children[c];
        }
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for(auto c : word){
            if(!cur->children.count(c))
                return false;
            cur = cur->children[c];
        }
        return cur->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(auto c :  prefix){
            if(!cur->children.count(c))
                return false;
            cur = cur->children[c];
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */