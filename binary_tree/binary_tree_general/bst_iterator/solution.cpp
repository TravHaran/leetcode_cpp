#include <vector>
using namespace std;

class BSTIterator {
    // Iterative inorder dfs approach
    // Time: O(1) amortized, Space: O(N)
private:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
    vector<TreeNode*> stack = {};
public:
    BSTIterator(TreeNode* root) {
        stack.push_back(root);
        // from the root, continue left till we reach a leaf node, appending each node onto the stack
        TreeNode* cur = root->left;
        while(cur){
            stack.push_back(cur);
            cur = cur->left;
        } 
    }
    
    int next() {
        TreeNode* result = stack.back(); // next value is at the top of the stack
        stack.pop_back();
        // after this we step right and continue left till we reach a leaf node, appending each node onto the stack
        TreeNode* cur = result->right;
        while(cur){
            stack.push_back(cur);
            cur = cur->left;
        }
        return result->val;    
    }
    
    bool hasNext() { // if stack is empty we dont have a next value, else we do have a next
        return !stack.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */