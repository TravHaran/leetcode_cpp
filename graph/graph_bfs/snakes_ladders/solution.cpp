#include <vector>
#include <deque>
#include <unordered_set>
using namespace std;

class Solution {
    // Time: O(n^2), Space: O(n^2)
private: 
    pair<int, int> inToPos(int square){
        int r = (square - 1) / length; // compute row
        int c = (square - 1) % length; // compute column
        if(r % 2) // check if row is even
            c = length - 1 - c; //if so we need to get the reverse order
        return {r, c};
    }
public:
    int length;
    int snakesAndLadders(vector<vector<int>>& board) {
        length = board.size();
        // reverse the board so that the first position is at index 0
        reverse(board.begin(), board.end()); // makes calculations simpler
        deque<pair<int, int>> q{{1, 0}}; // square, moves
        unordered_set<int> visit;
        int square;
        int nextSquare;
        int moves;
        int r;
        int c;
        pair<int, int> pos;
        while(!q.empty()){
            square = q.front().first;
            moves = q.front().second;
            q.pop_front();
            for(int i = 1; i < 7; i++){ // check all 6 possible moves
                nextSquare = square + i;
                pos = inToPos(nextSquare);
                r = pos.first;
                c = pos.second;
                if(board[r][c] != -1) // we've encountered snake/ladder
                    nextSquare = board[r][c];
                if(nextSquare==length*length) // we've reached end of board
                    return moves+1;
                if(!visit.count(nextSquare)){ // visit neighbors
                    visit.insert(nextSquare); 
                    q.push_back({nextSquare, moves+1});
                } 
            }  
        }
        return -1;
    }
};