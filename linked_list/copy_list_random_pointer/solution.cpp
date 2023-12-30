class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;
        Node* cur = head;
        Node* copy;
        Node* temp;
        Node* result;
        // create a duplicate beside each node of the original node
        while(cur){
            copy = new Node(cur->val);
            copy->next = cur->next;
            copy->random = nullptr;
            cur->next = copy;
            cur = cur->next->next;

        }
        // point each duplicate node random pointer to it's corresponding location
        cur = head;
        while(cur){
            // find the random pointer of the original and get the duplicate beside it
            cur->random != nullptr ? temp = cur->random->next : temp = nullptr;
            // move to the duplicate
            cur = cur->next;
            // point the duplicate's random pointer to the right position
            cur->random = temp;
            //move to the next original node
            cur = cur->next;
        }
        //unweave the list to separate orignal nodes from the the duplicate nodes
        cur = head;
        result = head->next;
        while(cur){
            copy = cur->next; // set duplicate node
            cur->next = copy->next; // connect original nodes
            cur = cur->next; //move to next original node
            cur != nullptr ? copy->next = cur->next : copy->next = nullptr; // connect duplicate nodes 
        }
        return result;
    }
};