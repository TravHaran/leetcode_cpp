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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        deque<TreeNode*> q = {root, root};
        TreeNode* node1;
        TreeNode* node2;
        while(!q.empty()){
            node1 = q.front();
            q.pop_front();
            node2 = q.front();
            q.pop_front();
            if(!node1 && !node2) continue;
            if(!node1 || !node2 || node1->val!=node2->val) return false;
            q.push_back(node1->left);
            q.push_back(node2->right);
            q.push_back(node1->right);
            q.push_back(node2->left);
        }
        return true;
    }
};