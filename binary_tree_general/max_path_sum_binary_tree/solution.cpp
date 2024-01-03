#include <algorithm>
using namespace std;

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
    int maxPathSum(TreeNode* root){
        int maxSum = INT32_MIN;
        // call helper function that will recursively traverse the tree and update maxSum
        computeMaxSum(root, maxSum);
        return maxSum;
    }
    int computeMaxSum(TreeNode* node, int& maxSum){
        // compute the max contribution that either left or right can add to the current maxSum
        if(!node) return 0;
        // recursively call left and right
        int leftSum = max(0, computeMaxSum(node->left, maxSum));
        int rightSum = max(0, computeMaxSum(node->right, maxSum));
        // the above calls will take us to the leaf nodes at which point we compute the maxSum and work back upwards
        maxSum = max(maxSum, leftSum + rightSum + node->val);
        return max(leftSum, rightSum) + node->val; // return the max contribution of either left or right subtree to current node value
    }

};