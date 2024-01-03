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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        deque<TreeNode*> q{root};
        int size;
        TreeNode* node;
        double levelVal;
        while(!q.empty()){
            size = q.size();
            levelVal = 0;
            for(int i = 0; i < size; i++){
                node = q.front();
                q.pop_front();
                if(node){
                    levelVal += node->val;
                    if(i==size-1){
                        result.push_back(levelVal/size);
                    }
                    if(node->left) q.push_back(node->left);
                    if(node->right) q.push_back(node->right);
                }
            }
        }
        return result;
    }
};