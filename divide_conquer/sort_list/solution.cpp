
class Solution {
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

public:
    // MergeSort: Time: O(NlogN), Space: O(N)
    ListNode* sortList(ListNode* head) {
        // handle base case
        if(!head || !head->next) return head;

        // split the list into two halfs
        ListNode* left = head;
        ListNode* right = getMid(head);
        // we actually want right.next to be the start of the right list
        ListNode* temp = right->next;
        right->next = nullptr;
        right = temp;

        // recursively continue splitting
        left = sortList(left);
        right = sortList(right);

        // now we can merge the lists
        return merge(left, right);
    }

    ListNode* getMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* dummy = new ListNode(); // helps to handle edge case
        ListNode* tail = dummy; // this will be the position at which we insert at
        // insert the smaller node between left and right in the merged list
        while(left && right){
            if(left->val < right->val){
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }
        // append remainders to merged list
        if(left) tail->next = left;
        if(right) tail->next = right;
        return dummy->next;
    }
};