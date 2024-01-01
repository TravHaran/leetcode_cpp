#include <vector>
using namespace std;

class Solution {
    //Time: O(N^2), Space: O(N)
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        int mid;
        // find the target_idx in inorder list
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i]==preorder[0]){
                mid = i;
                break;
            }
        }
        // partition preorder into left and right
        vector<int> left_pre(preorder.begin()+1, preorder.begin()+mid+1);
        vector<int> right_pre(preorder.begin()+mid+1, preorder.end());
        // partition inorder into left and right
        vector<int> left_in(inorder.begin(), inorder.begin() + mid);
        vector<int> right_in(inorder.begin()+mid+1, inorder.end());

        root->left = buildTree(left_pre, left_in);
        root->right = buildTree(right_pre, right_in);
        return root;
    }
};