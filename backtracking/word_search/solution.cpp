#include <vector>
#include <string>
using namespace std;

class Solution {
    //Time: O(N⋅3^L), where N is the number of cells in the board, and L is the length of the word to be matched.
    //Space: O(L), where L is the length of the word to be matched.
public:
    bool exist(vector<vector<char>>& board, string word) {
        int ROWS = board.size();
        int COLS = board[0].size();
        string curWord;
        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(dfs(r, c, 0, word, board)) return true;
            }
        }
        return false;
    }

    bool dfs(int r, int c, int i, string& word, vector<vector<char>>& board){
        if(i==word.size()) return true;
        int ROWS = board.size();
        int COLS = board[0].size(); 
        if(min(r, c) < 0 || r >= ROWS || c >= COLS || word[i]!=board[r][c]) return false;
        char visitedChar = board[r][c];
        board[r][c] = '#';
        bool res = (
            dfs(r+1, c, i+1, word, board) || 
            dfs(r-1, c, i+1, word, board) || 
            dfs(r, c+1, i+1, word, board) || 
            dfs(r, c-1, i+1, word, board));
        board[r][c] = visitedChar;
        return res;
    }
};