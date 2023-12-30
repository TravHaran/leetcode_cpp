using namespace std;

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = new ListNode();
        prev->next = head;
        ListNode* start = prev; // dummy node to preserve head of list
        while(cur){
            if(cur->next && cur->val == cur->next->val){
                while(cur->next && cur->val == cur->next->val){ // increment until no more duplicates values
                    cur = cur->next;
                }
                prev->next = cur->next; // remove duplicates
                cur = prev->next; 
            }     
            else {
                prev = cur;
                cur = cur->next;
            }
        }
        return start->next; 
    }
};