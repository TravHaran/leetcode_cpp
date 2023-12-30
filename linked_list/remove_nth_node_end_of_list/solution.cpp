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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        int length = 1;
        while(cur->next){
            cur = cur->next;
            length++;
        }
        int target = length - n;
        cur = head;
        target--;
        while(target>0){
            cur = cur->next;
            target--;
        }
        if(cur==head && target<0) // we need to remove the head
            head = head->next;
        else { //we dont need to remove the head
            cur->next = cur->next->next;
        }
        return head; 
    }
};