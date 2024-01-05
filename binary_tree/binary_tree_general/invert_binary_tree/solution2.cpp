#include <deque>
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
    // iterative bfs  
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        deque<TreeNode*> q = {root};
        int size;
        TreeNode* node;
        TreeNode* temp;
        while(!q.empty()){
            size = q.size();
            for(int i = 0; i < size; i++){
                node = q.front();
                q.pop_front();
                // swap left & right
                temp = node->left;
                node->left = node->right;
                node->right = temp;

                if(node->left) q.push_back(node->left);
                if(node->right) q.push_back(node->right);
            }
        }
        return root;
    }
};