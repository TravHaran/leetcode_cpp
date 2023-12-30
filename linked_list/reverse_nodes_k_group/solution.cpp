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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        //get length of list
        int length = 1;
        while(cur->next){
            cur = cur->next;
            length++;
        }
        int reversals = length/k; // the amount of times we need to reverse k groups
        // to reverse linked list you need 3 pointers: cur, next, & revHead.
        cur = head;
        ListNode* revHead = nullptr;
        ListNode* nextNode;
        ListNode* start = nullptr; // we will use this to make conncections after each reversal
        int count;
        while(reversals > 0){
            count = 0;
            revHead = cur;
            nextNode = cur->next;
            while(nextNode && count < k-1){ // reverse until count reaches k
                cur->next = nextNode->next;
                nextNode->next = revHead;    
                revHead = nextNode;
                nextNode = cur->next;
                count++;
            }
            if(reversals==length/k){ //reset new head pointer after first reversal
                head = revHead;
            }
            if(start!=nullptr){ // connect nodes after each reversal
                start->next = revHead;
            }
            start = cur; 
            cur = cur->next;
            reversals--;
        }
        return head;  
    }
};