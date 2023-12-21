#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <tuple>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // define row set hashmap
        unordered_map<int, unordered_set<int>> row_set;
        // define column set hashmap
        unordered_map<int, unordered_set<int>> col_set;
        // define 3x3 subbox set hashmap
        map<pair<int, int>, unordered_set<int>> box_set;
        int val;
        pair<int, int> box_pos;
        for(int row = 0; row < 9; row++){
            for(int col = 0; col < 9; col++){
                val = board[col][row];
                if(val !='.'){
                    box_pos = {row / 3, col / 3};
                    if(row_set[row].count(val) || col_set[col].count(val) || box_set[box_pos].count(val))
                        return false;
                    else {
                        row_set[row].insert(val);
                        col_set[col].insert(val);
                        box_set[box_pos].insert(val);
                    }
                }
            }
        }
        return true;  
    }
};
