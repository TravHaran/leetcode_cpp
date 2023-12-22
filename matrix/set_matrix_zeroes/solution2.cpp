#include <vector>
using namespace std;

class Solution {
    // O(N) time
    // O(1) space
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool fr = false;
        bool fc = false;
        // we use the initial row and column values of the matrix as indicators to zero out an entry
        for(int row = 0; row < matrix.size(); row++){
            for(int col = 0; col < matrix[0].size(); col++){
                if(matrix[row][col]==0){
                    if(row==0) fr=true;
                    if(col==0) fc=true;
                    matrix[0][col] = 0;
                    matrix[row][0] = 0;
                }
            }
        }
        // we don't modify the first row or column because modifying that affects the way we update the rest of the matrix
        for(int row = 1; row < matrix.size(); row++){
            for(int col = 1; col < matrix[0].size(); col++){
                if(matrix[0][col]==0 || matrix[row][0]==0){
                    matrix[row][col] = 0;
                }
            }
        }
        // now we check if the first row or column needs to be zeroed out
        if(fr){
            for(int col = 0; col < matrix[0].size(); col++){
                matrix[0][col] = 0;
            }
        }
        if(fc){
            for(int row = 0; row < matrix.size(); row++){
                matrix[row][0] = 0;
            }
        }
        
    }
};