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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //initialize dummy node
        ListNode* dummy = new ListNode();
        //save head for result output
        ListNode* result = dummy;
        
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;

        while(cur1 && cur2){
            if(cur2->val >= cur1->val){
                dummy->next = cur1;
                cur1 = cur1->next;
            } else {
                dummy->next = cur2;
                cur2 = cur2->next;
            }
            dummy = dummy->next;
        }
        if(!cur1){
            dummy->next = cur2;
        }
        if(!cur2){
            dummy->next = cur1;
        }
        return result->next;   
    }
};