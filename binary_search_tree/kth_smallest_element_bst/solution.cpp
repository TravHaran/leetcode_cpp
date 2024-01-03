#include <vector>
using namespace std;

class Solution {
    // iterative dfs inorder traversal
    // a binary search tree has the property that the sequence obtained through inorder traversal is a sorted array
    // so the kth smallest element is the kth element in the traversal's output
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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0; // to keep track of the steps taken in traversal
        vector<TreeNode*> stack{root};
        //traverse leftmost branch
        TreeNode* node = root->left;
        while(node){
            stack.push_back(node);
            node = node->left;
        }
        while(!stack.empty()){
            node = stack.back();
            count++;
            if(count==k)
                return node->val;
            stack.pop_back();
            //step right
            node = node->right;
            //continue left
            while(node){
                stack.push_back(node);
                node = node->left;
            }
        }
        return -1;
    }
};