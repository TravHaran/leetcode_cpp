#include <unordered_set>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        unordered_set<int> col;
        unordered_set<int> posDiag;
        unordered_set<int> negDiag;

        int res = 0;
        backtrack(0, res, n, col, posDiag, negDiag);
        return res;
    }

    void backtrack(int r, int& res, int& n, unordered_set<int> col, unordered_set<int> posDiag, unordered_set<int> negDiag){
        if(r==n){ // reached the last row
            res++;
            return;
        }
        // go through every possible column
        for(int c = 0; c < n; c++){
            if(col.count(c) || posDiag.count(r+c) || negDiag.count(r-c)){
                continue; // don't place a queen in any of these positions
            }
            col.insert(c);
            posDiag.insert(r+c);
            negDiag.insert(r-c);
            backtrack(r+1, res, n, col, posDiag, negDiag); // move to next row
            //clean up
            col.erase(c);
            posDiag.erase(r+c);
            negDiag.erase(r-c);
        }
    }
};