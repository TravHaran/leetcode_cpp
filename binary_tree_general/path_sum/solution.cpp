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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        //process current node
        targetSum -= root->val;
        if(!root->left && !root->right){ // node is a leaf node check that we reached the targetSum
            if(targetSum==0) return true;
            return false;
        }
        // recursively check left and right children
        //if either one is true we return true;
        return hasPathSum(root->left, targetSum)|| hasPathSum(root->right, targetSum);
    }

};