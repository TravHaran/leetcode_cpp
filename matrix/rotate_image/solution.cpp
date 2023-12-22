#include <vector>
using namespace std; 

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // initialize top, bottom, left, right pointers
        int top  = 0;
        int bottom = n;
        int left = 0;
        int right = n;

        // initialize swap vector of size n
        vector<int> swaps;
        for(int i  = 0; i < n; i++){
            swaps.push_back(-1111); // default value of -1111 since matrix values are between -1000 and 1000
        }
        int temp;
        while(top < bottom - 1){
            // swap first row
            for(int i = left; i < right; i++){
                temp = matrix[top][i];
                matrix[top][i] = swaps[i];
                swaps[i] = temp;
            }
            //swap last column
            for(int i = top; i < bottom; i++){
                if(swaps[i]!=-1111){
                    temp = matrix[i][right-1];
                    matrix[i][right-1] = swaps[i];
                    swaps[i] = temp;
                } 
            }
            //swap bottom row
            for(int i = right-1; i >= left; i--){
                if(swaps[n-1 - i]!=-1111){
                    temp = matrix[bottom-1][i];
                    matrix[bottom-1][i] = swaps[n-1 - i];
                    swaps[n-1 - i] = temp;
                }
            }
            //swap first column
            for(int i = bottom-1; i >= top; i--){
                if(swaps[n-1 - i]!=-1111){
                    temp = matrix[i][left];
                    matrix[i][left] = swaps[n-1 - i];
                    swaps[n-1 - i] = temp;
                }
            } 
            // swap top row if entry not -1
            for(int i = left; i < right; i++){
                if(swaps[i]!=-1111){
                    temp = matrix[top][i];
                    matrix[top][i] = swaps[i];
                    swaps[i] = temp;
                } 
            }
            top++;
            bottom--;
            left++;
            right--;
            swaps.pop_back();
            swaps.pop_back();
        }   
    }
};