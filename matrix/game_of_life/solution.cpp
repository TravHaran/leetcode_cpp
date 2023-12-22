#include <vector>
using namespace std;

class Solution {
private: 
    int checkNeighbors(vector<vector<int>>& board, int i, int j){
        int m = board.size();
        int n = board[0].size();
        int live=0;
        //check left
        if(j-1 >=0 && (board[i][j-1]==1 || board[i][j-1]==3)) live++;
        //check right
        if(j+1 < n && (board[i][j+1]==1 || board[i][j+1]==3)) live++;;
        //check top
        if(i-1 >=0 && (board[i-1][j]==1 || board[i-1][j]==3)) live++;
        //check bottom
        if(i+1 < m && (board[i+1][j]==1 || board[i+1][j]==3)) live++;
        //check top right
        if(i-1 >=0 && j+1 < n && (board[i-1][j+1]==1 || board[i-1][j+1]==3)) live++; 
        //check top left
        if(i-1 >=0 && j-1 >=0 && (board[i-1][j-1]==1 || board[i-1][j-1]==3)) live++;
        //check bottom right
        if(i+1 < m && j+1 < n && (board[i+1][j+1]==1 || board[i+1][j+1]==3)) live++;
        //check bottom left
        if(i+1 < m && j-1 >= 0 && (board[i+1][j-1]==1 || board[i+1][j-1]==3)) live++;
        return live;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int check;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                check = checkNeighbors(board, i, j);
                if(board[i][j]==1 && (check<2 || check>3))
                    board[i][j]=3; // newly dead
                else if(board[i][j]==0 && (check==3)){
                    board[i][j]=2; // newly alive
                }
            }
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j]==2) board[i][j]=1;
                else if(board[i][j]==3) board[i][j]=0;
            }
        }
    }
};