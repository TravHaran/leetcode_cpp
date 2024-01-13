#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
using namespace std;

class TrieNode {
    // Time: O(M(4* 3^(L-1))), where M is the number of cells in the board and L is the max length of words
    // Space: O(N), where N is the total number of letters in the trie
public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord;
    TrieNode() {
        children = {};
        endOfWord = false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }

    void insert(string word){
        TrieNode* cur = root;
        for(auto c : word){
            if(!cur->children.count(c)) cur->children[c] = new TrieNode();
            cur = cur->children[c];
        }
        cur->endOfWord = true;
    }

    void pruneWord(string word){
        TrieNode* node = root;
        for(auto c : word){
            if(node->children[c]->children.empty()){
                node->children.erase(c);
                return;
            }
            node = node->children[c]; 
        }
    }

};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<string> result;
        // build trie out of list of words
        Trie wordTrie = Trie();
        for(auto word : words){
            wordTrie.insert(word);
        }
        // for every element in the board run dfs
        int ROWS = board.size();
        int COLS = board[0].size();
        set<pair<int, int>> visit;
        string word;
        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                dfs(board, r, c, "", visit, result, wordTrie.root, wordTrie);
                //treat every position as the start of a new word
                //and run dfs function in which we recursively build a word as we traverse
                //and at each step we check the Trie to see if the word we've build so far exists
                // if it exists we add it to the result

            }
        }
        vector<string> found_words(result.begin(), result.end());
        return found_words;
    }

    void dfs(vector<vector<char>>& board, int r, int c, string word, set<pair<int,int>>& visit, unordered_set<string>& result, TrieNode* node, Trie& trie){
        int ROWS = board.size();
        int COLS = board[0].size();
        if(min(r, c) < 0 || r >= ROWS || c >= COLS || visit.count({r, c})|| !node->children.count(board[r][c])) return;
        visit.insert({r, c});
        node = node->children[board[r][c]];
        word += board[r][c];
        if(node->endOfWord){
            result.insert(word);
            // this is optimization, remove the word after it has been found
            node->endOfWord = false;
            trie.pruneWord(word);
        }
        dfs(board, r+1, c, word, visit, result, node, trie);
        dfs(board, r-1, c, word, visit, result, node, trie);
        dfs(board, r, c+1, word, visit, result, node, trie);
        dfs(board, r, c-1, word, visit, result, node, trie);
        visit.erase({r, c}); // backtrack
    }
};