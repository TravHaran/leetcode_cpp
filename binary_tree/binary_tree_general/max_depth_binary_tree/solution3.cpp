#include <algorithm>
#include <vector>
using namespace std;

class Solution {
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
    // pre-order iterative dfs solution
    int maxDepth(TreeNode* root) {
        int depth = 0;
        int max_depth = 0;
        vector<pair<TreeNode*, int>> stack = {{root, 1}};
        TreeNode* node;
        while(!stack.empty()){
            node = stack.back().first;
            depth = stack.back().second;
            stack.pop_back();
            if(node){ // node is null we ignore
                max_depth = max(max_depth, depth);
                stack.push_back({node->left, depth+1});
                stack.push_back({node->right, depth+1});
            }
        }
        return max_depth;
    }
};