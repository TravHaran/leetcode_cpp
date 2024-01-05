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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        deque<int> levelVals;
        vector<int> level;
        deque<TreeNode*> q{root};
        int size;
        TreeNode* node;
        bool zig = false; // we will flip polarity after each level order traversal
        while(!q.empty()){
            size = q.size();
            levelVals = {};
            zig = !zig; // flip polarity
            for(int i = 0; i < size; i++){
                node = q.front();
                q.pop_front();
                if(node){
                    // depending on the polarity we change the order of how we insert into the queue
                    if(!zig) levelVals.push_front(node->val);
                    else levelVals.push_back(node->val);

                    if(node->left) q.push_back(node->left);
                    if(node->right) q.push_back(node->right);
                }
            }
            // insert level as vector
            level = vector<int>(levelVals.begin(), levelVals.end());
            result.push_back(level);
        }
        return result;  
    }
};