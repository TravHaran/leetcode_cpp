class Solution {
    // Time: O(N), Space: O(1)
    // Morris Preorder Traversal Approach
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
        int sum = 0;
        int curNum = 0;
        int steps;
        TreeNode* predecessor;
        while(root){
            // if there is a left child, compute predecessor
            // if there is no link predecessor->right = root, then set it
            // if there is a link then break it
            if(root->left){
                //predecessor node is one step left and then continue right till you reach a leaf node
                predecessor = root->left;
                steps = 1;
                while(predecessor->right && predecessor->right != root){
                    predecessor = predecessor->right;
                    steps++;
                }

                //set link if it doesnt exist
                if(!predecessor->right){
                    // since this is a leaf compute curNum at the root
                    curNum = curNum * 10 + root->val;
                    predecessor->right = root;
                    // go left
                    root = root->left;
                } else {
                    //if on leaf, update sum
                    if(!predecessor->left)
                        sum += curNum;
                    // backtrack curNum to root
                    for(int i = 0; i < steps; i++){
                        curNum /= 10;
                    }
                    //break link
                    predecessor->right = nullptr;
                    // go right
                    root = root->right;
                }
            } else {
                // if there is no left child we just go right
                curNum = curNum *10 + root->val;
                //if on leaf update sum
                if(!root->right)
                    sum += curNum;
                root = root->right;
            }
        }
        return sum;
    }
};