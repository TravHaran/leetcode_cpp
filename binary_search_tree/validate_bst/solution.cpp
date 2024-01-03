#include <vector>
using namespace std;

class Solution {
    // iterative dfs inorder traversal
    // a binary search tree has the property that the sequence obtained through inorder traversal is a sorted array
    // simply check that the previous element of the traversal is less than the current element
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
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        vector<TreeNode*> stack{root};
        TreeNode* node = root->left;
        while(node){
            stack.push_back(node);
            node = node->left;
        }
        while(!stack.empty()){
            node = stack.back();
            if(prev && prev->val >= node->val) return false;
            prev= node;
            stack.pop_back();
            node = node->right;
            while(node){
                stack.push_back(node);
                node = node->left;
            }
        }
        return true; 
    }
};