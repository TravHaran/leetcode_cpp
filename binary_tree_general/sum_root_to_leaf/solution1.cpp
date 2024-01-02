class Solution {
    // Time: O(N), Space: O(H) where H is the height of the tree
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
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        return check(root, 0);
    }
    int check(TreeNode* node, int sum){
        if(!node) return 0;
        sum = sum*10 + node->val; //digit based addition
        if(!node->left && !node->right){
            return sum;
        }
        return check(node->left, sum) + check(node->right, sum);
    }
};