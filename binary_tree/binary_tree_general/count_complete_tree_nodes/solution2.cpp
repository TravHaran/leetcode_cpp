#include <math.h>
using namespace std;

class Solution {
    // Time: O(logN * logN), Space: O(N) 
private:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
public:
    int countNodes(TreeNode* root) {
        int lH = leftHeight(root); // get height count by traversing left most branch
        int rH = rightHeight(root); // get height count by traversing right most branch
        if(lH==rH) // full tree
            return pow(2, rH) -1; //full binary tree has 2^h - 1 nodes
        // if not full tree, add 1 to account for the current node and recursively check left and right 
        return countNodes(root->left) + countNodes(root->right) + 1;
    }

    int leftHeight(TreeNode* node){
        if(!node) return 0;
        int count = 0;
        while(node){
            count++;
            node = node->left;
        }
        return count;
    }

    int rightHeight(TreeNode* node){
        if(!node) return 0;
        int count = 0;
        while(node){
            count++;
            node = node->right;
        }
        return count;
    }
};