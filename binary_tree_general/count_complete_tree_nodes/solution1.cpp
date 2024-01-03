
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
    int sum = 0;
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        sum++;
        countNodes(root->left);
        countNodes(root->right);
        return sum;
    }
};