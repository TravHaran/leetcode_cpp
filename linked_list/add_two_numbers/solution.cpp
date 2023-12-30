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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* result = dummy;

        int sum;
        int carry;
        int l1_val;
        int l2_val;

        while(l1 && l2){
            sum  = l1->val + l2->val ;
            dummy->next = new ListNode( sum % 10);
            carry = sum/10;
            l1 = l1->next;
            l2 = l2->next;
            if(l1){
                l1->val += carry;
                carry = 0;
            } else if(l2){
                l2->val += carry;
                carry = 0;
            }
            dummy = dummy->next;   
        }
        while(l1){
            sum = l1->val;
            dummy->next = new ListNode( sum % 10);
            carry = sum/10;
            l1 = l1->next;
            if(l1){
                l1->val += carry;
                carry = 0;
            }
            dummy = dummy->next;  
        }
        while(l2){
            sum = l2->val;
            dummy->next = new ListNode( sum % 10);
            carry = sum/10;
            l2 = l2->next;
            if(l2){
                l2->val += carry;
                carry = 0;
            }
            dummy = dummy->next;  
        }
        if(carry!=0)
            dummy->next = new ListNode(carry);
        return result->next;
    }
};