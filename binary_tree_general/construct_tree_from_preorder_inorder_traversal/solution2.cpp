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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorder_map; // map the values to their index
        for(int i = 0; i < inorder.size(); i++){
            inorder_map[inorder[i]] = i;
        }
        TreeNode* root = build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1, inorder_map);
        return root;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<int, int>& map){
        if(preStart > preEnd || inStart > inEnd) return nullptr;
        TreeNode* node = new TreeNode(preorder[preStart]);
        int mid = map[preorder[preStart]];
        int numsLeft = mid - inStart;
        // use pointers to partition preorder and inorder into left and right
        node->left = build(preorder, inorder, preStart+1, preStart+numsLeft, inStart, mid-1, map);
        node->right = build(preorder, inorder, preStart+numsLeft+1, preEnd, mid+1, inEnd, map);
        return node;
    }
};