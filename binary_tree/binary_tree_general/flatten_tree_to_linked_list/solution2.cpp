/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    // Time: O(N), Space: O(1)
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
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* node = root;
        while(node){
            //if node has left child
            if(node->left){
                //find the right most node
                TreeNode* rightmost = node->left;
                while(rightmost->right){
                    rightmost = rightmost->right;
                }
                //rewire connections
                rightmost->right = node->right;
                node->right = node->left;
                node->left = nullptr;
            }
            // move to the right side of the tree;
            node = node->right;
        }
    }
};