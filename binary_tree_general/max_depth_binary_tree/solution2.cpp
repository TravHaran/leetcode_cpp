#include <algorithm>
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
    // bfs solution
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int level  = 0;
        int size;
        deque<TreeNode*> q = {root};
        TreeNode* node;
        while(!q.empty()){
            size  = q.size();
            for(int i = 0; i < size; i++){
                node = q.front();
                q.pop_front();
                if(node->left)
                    q.push_back(node->left);
                if(node->right)
                    q.push_back(node->right);
            }
            level++;
        }
        return level;
    }
};