#include <vector>
using namespace std;

class Solution {
/**
* Notice that if a cell has 'X' on all sides then it can not be reached by a series of 0's that start at the border. 
* Use this observation to do dfs from all 0's at the border and mark them with 'I' so as to mark invalid. 
* After this mark all 0's with X and all the 'I's back to 0.
* The time complexity is O(nn) and space is O(nn) for dfs.
*/
public:
    void solve(vector<vector<char>>& board) {
        // search for 'O' on the border
        int ROWS = board.size();
        int COLS = board[0].size();
        // top row
        for(int c = 0; c < COLS; c++){
            if(board[0][c]=='O') dfs(board, 0, c);
        }
        // bottom row
        for(int c = 0; c < COLS; c++){
            if(board[ROWS-1][c]=='O') dfs(board, ROWS-1, c);
        }
        // first column
        for(int r = 0; r < ROWS; r++){
            if(board[r][0]=='O') dfs(board, r, 0);
        }
        // last column
        for(int r = 0; r < ROWS; r++){
            if(board[r][COLS-1]=='O') dfs(board, r, COLS-1);
        }
        // linear search through matrix and flip 'I' back to 'O', and 'O' to 'X'
        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(board[r][c]=='I') board[r][c] = 'O';
                else if(board[r][c]=='O') board[r][c] = 'X';
            }
        }
        
    }
    void dfs(vector<vector<char>>& board, int r, int c){ //change all visited characters to 'I'
        if(min(r, c) < 0 || r >= board.size() || c >= board[0].size() || board[r][c]=='X' || board[r][c]=='I') return;
        board[r][c] = 'I';
        dfs(board, r+1, c);
        dfs(board, r-1, c);
        dfs(board, r, c+1);
        dfs(board, r, c-1);
    }
};