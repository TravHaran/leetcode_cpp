class Solution {
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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return symmetric(root, root);
    }
    bool symmetric(TreeNode* node1, TreeNode* node2){
        if(!node1 && !node2) return true;
        if(!node1 || !node2 || node1->val!=node2->val) return false;
        return symmetric(node1->left, node2->right) && symmetric(node1->right, node2->left);
    }
};