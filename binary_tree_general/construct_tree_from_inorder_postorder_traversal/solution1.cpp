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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty() || postorder.empty()) return nullptr;
        int end = postorder.size()-1;
        TreeNode* root = new TreeNode(postorder[end]);
        int mid;
        //find target index in inorder
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i]==postorder[end]){
                mid = i;
                break;
            }
        }
        //partition postorder into right & left
        vector<int> post_left(postorder.begin(), postorder.begin()+ mid);
        vector<int> post_right(postorder.begin()+mid, postorder.end()-1);
        //partition inorder into right & left
        vector<int> in_left(inorder.begin(), inorder.begin()+mid);
        vector<int> in_right(inorder.begin()+mid+1, inorder.end());
        
        root->left = buildTree(in_left, post_left);
        root->right = buildTree(in_right, post_right);
        return root;
    }
};