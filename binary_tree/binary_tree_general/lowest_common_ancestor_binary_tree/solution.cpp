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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return check(root, p, q);

    }

    TreeNode* check(TreeNode* node, TreeNode* p, TreeNode* q){
        if(!node || node==p || node==q) return node;
        TreeNode* l = check(node->left, p, q);
        TreeNode* r = check(node->right, p, q);
        if(l && r){ // if both l and r is not null, then p and q exist on different subtrees
            // in this case the LCA is the parent which we return as the current node
            return  node;
        } else if(l){ // if only l is not null, then both p and q exist in the left subtree 
            // in this case we return the node that was set for l
            return l;
        } else { // if only r is not null, then both p and q exist in the right subtree
            // in this case we return the node that was set for r
            return r;
        }
    }
};