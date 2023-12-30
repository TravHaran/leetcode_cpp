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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        //get length and tail of list
        ListNode* tail = head;
        int length = 1;
        while(tail->next){
            tail = tail->next;
            length++;
        }
        k %= length; // this will make sure our k value is less than length;
        int target = length - k;
        ListNode* cur = head;
        target--;
        while(target >0){
            cur= cur->next;
            target--;
        }
        tail->next = head;
        head = cur->next;
        cur->next = nullptr;
        return head; 
    }
};