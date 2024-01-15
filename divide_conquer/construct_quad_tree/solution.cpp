#include <vector>
using namespace std;

class Solution {
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
public:
    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid.size(), 0, 0, grid); 
    }
    Node* dfs(int n, int r, int c, vector<vector<int>>& grid){
        bool allSame = true;
        for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[r][c]!=grid[r+i][c+j]){
                allSame = false;
                break;
            }
        }
        }
        if(allSame) return new Node(grid[r][c], true); 

        // split and recursively run dfs
        n /= 2;
        Node* topLeft = dfs(n, r, c, grid);
        Node* topRight = dfs(n, r, c+n, grid);
        Node* bottomLeft = dfs(n, r+n, c, grid);
        Node* bottomRight = dfs(n, r+n, c+n, grid);
        return new Node(0, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};