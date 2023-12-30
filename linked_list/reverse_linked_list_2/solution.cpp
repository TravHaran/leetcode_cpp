class Solution {
private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    }; 
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        int count = 1;
        while(count < left){
            prev = cur;
            cur = cur->next;
            count++;
        }
        //by end of loop cur points to left, start reversing
        ListNode* start = prev; // save this node to connect to after reversing
        ListNode* reversedHead = cur; // save the head of the reversed list
        ListNode* nextNode = cur->next;
        while(count < right){
            //point cur next to node after next node
            cur->next = nextNode->next;
            nextNode->next = reversedHead;
            reversedHead = nextNode;
            nextNode = cur->next;
            count++;
        }
        //connect start to head of reversed list
        if(start){ // start is not at beginning of list
            start->next = reversedHead;
            return head;
        } 
        // we reversed from the beginning of the list since start is at beginning
        return reversedHead;    
    }
};