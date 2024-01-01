#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    //Time: O(N), Space: O(N)
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
        unordered_map<int, int> inorder_map; // map values to index
        for(int i = 0; i <inorder.size(); i++){
            inorder_map[inorder[i]] = i;
        }
        TreeNode* root = build(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1, inorder_map);
        return root;
    }
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd, unordered_map<int, int>& map){
        if(inStart > inEnd || postStart > postEnd) return nullptr;
        TreeNode* node = new TreeNode(postorder[postEnd]);
        int mid = map[postorder[postEnd]];
        int numsLeft = mid - inStart;
        // use pointers to partition preorder and inorder into left and right
        node->left = build(inorder, postorder, inStart, mid-1, postStart, postStart+numsLeft-1, map);
        node->right = build(inorder, postorder, mid+1, inEnd, postStart+numsLeft, postEnd-1, map);
        return node;
    }
};