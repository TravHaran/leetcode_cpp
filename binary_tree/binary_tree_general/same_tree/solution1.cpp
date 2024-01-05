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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // iterative bfs
        deque<TreeNode*> queue1 = {p};
        deque<TreeNode*> queue2 = {q};
        int size;
        while(!queue1.empty() && !queue2.empty()){
            p = queue1.front();
            q = queue2.front();
            queue1.pop_front();
            queue2.pop_front();
            if(!p && !q) continue;
            if(!p || !q || p->val != q->val) return false;

            queue1.push_back(p->left);
            queue1.push_back(p->right);
            queue2.push_back(q->left);
            queue2.push_back(q->right);
        }
        return true;
    }
};