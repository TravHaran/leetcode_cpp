#include <vector>
#include <deque>
using namespace std;

class Solution {
    // Time: O(N), Space: O(D) where D is the diameter of the tree
    //Iterative BFS approach
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
    vector<int> rightSideView(TreeNode* root) {
        deque<TreeNode*> q{root};
        vector<int> result;
        int size;
        TreeNode* node;
        while(!q.empty()){
            size = q.size();
            for(int i = 0; i < size; i++){
                node = q.front();
                q.pop_front();
                if(node){
                    if(i==size-1)
                        result.push_back(node->val);
                    if(node->left) q.push_back(node->left);
                    if(node->right) q.push_back(node->right);
                } 
            }
        }
        return result;
    }
};