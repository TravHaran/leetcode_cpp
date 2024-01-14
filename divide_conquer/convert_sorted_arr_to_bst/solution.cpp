#include <vector>
using namespace std;

class Solution {
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
public:
    // divide and conquer approach
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(0, nums.size()-1, nums);
    }

    TreeNode* helper(int l, int r, vector<int>& nums){
        if(l > r) return nullptr;
        int m = (l + r)/2;
        TreeNode* root = new TreeNode(nums[m]);
        //compute left subtree
        root->left = helper(l, m-1, nums);
        //compute right subtree
        root->right = helper(m+1, r, nums);
        return root;
    }
};