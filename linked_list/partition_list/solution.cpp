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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode(); // create dummy list to store nodes less than x
        ListNode* lessHead = less;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* cur = head;
        while(cur){
            if(cur->val < x){ // if node val less than x add it to the less than x list
                if(cur==head) head = head->next;
                prev->next = cur->next;
                cur->next = nullptr;
                less->next = cur;
                less = less->next;
                cur = prev;
            }
            prev = cur;
            cur = cur->next;
        }
        less->next = head;
        return lessHead->next;
    }
};