using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
    //Time: O(N), Space: O(1)
    //use three pointer approach to build linked list at each level
public:
    Node* connect(Node* root) {
        // the three pointers that we will use are: head, cur, and start
        Node* head = root;
        while(head){
            Node* start = new Node(); // a dummy node that represents the start of each level from the left
            Node* cur = start;
            while(head){
                // build linked list of subtree from head
                if(head->left){
                    cur->next = head->left;
                    cur = cur->next;
                }
                if(head->right){
                    cur->next = head->right;
                    cur = cur->next;
                }
                // move to next subtree
                head = head->next;
            }
            //move head to start of next level
            head = start->next;
        }
        return root;
    }
};