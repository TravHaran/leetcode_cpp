#include <deque>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
    //Time: O(N), Space: O(N)
public:
    Node* connect(Node* root) {
        if(!root) return root;
        // iterative bfs
        deque<Node*> q{root};
        int size;
        Node* node;
        while(!q.empty()){
            size = q.size();
            for(int i = 0; i < size; i++){
                node = q.front();
                q.pop_front();
                if(i==size-1) // we reached the end of the level at which there is no next
                    node->next = nullptr;
                else // we point to the next item in the queue
                    node->next = q.front();
                if(node->left) q.push_back(node->left);
                if(node->right) q.push_back(node->right);
            }
        }
        return root;
    }
};

