#include <vector>
#include <deque>
using namespace std;

class Solution {
    // Time: O(N), Space: O(D) where D is the diameter of the tree
    // Iterative BFS approach
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        vector<int> levelVals;
        deque<TreeNode*> q{root};
        int size;
        TreeNode* node;
        while(!q.empty()){
            size = q.size();
            levelVals = {};
            for(int i = 0; i < size; i++){
                node = q.front();
                q.pop_front();
                if(node){
                    levelVals.push_back(node->val);
                    if(node->left) q.push_back(node->left);
                    if(node->right) q.push_back(node->right);
                }
            }
            result.push_back(levelVals);
        }
        return result;
    }
};