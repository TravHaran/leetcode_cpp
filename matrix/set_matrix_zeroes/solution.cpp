#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
    // O(N) time
    // O(M) space
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> z_rows;
        unordered_set<int> z_cols;
        for(int row = 0; row < matrix.size(); row++){
            for(int col = 0; col < matrix[0].size(); col++){
                if(matrix[row][col]==0){
                    z_rows.insert(row);
                    z_cols.insert(col);
                }  
            }
        }
        for(auto r : z_rows){
            for(int i = 0; i < matrix[0].size(); i++){
                matrix[r][i] = 0;
            }
        }
        for(auto c : z_cols){
            for(int i = 0; i < matrix.size(); i++){
                matrix[i][c] = 0;
            }
        }

        
    }
};

