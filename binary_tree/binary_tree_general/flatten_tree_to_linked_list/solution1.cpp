 
class Solution {
    // Time: O(N), Space: O(N)
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
        dfsFlatten(root);
    }
    TreeNode* dfsFlatten(TreeNode* root){
        if(!root) return nullptr;
        TreeNode* leftTail = dfsFlatten(root->left);
        TreeNode* rightTail = dfsFlatten(root->right);
        if(leftTail){
            leftTail->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        if(rightTail) return rightTail;
        if(leftTail) return leftTail;
        return root;
    }
};