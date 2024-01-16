#include <vector>
using namespace std;

class Solution {
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //handle base case
        if(lists.empty()) return nullptr;
        ListNode* l1;
        ListNode* l2;
        vector<ListNode*> mergedLists;
        while(lists.size() > 1){
            mergedLists = {};
            // iterate through list and merge adjacent lists
            for(int i = 0; i < lists.size(); i += 2){
                l1 = lists[i];
                (i+1 < lists.size()) ? l2 = lists[i+1] : l2 = nullptr;
                mergedLists.push_back(mergeLists(l1, l2));
            }
            // update the original list and repeat procesess until lists contains 1 element
            lists = mergedLists; 
        }
        return lists[0];
    }

    ListNode* mergeLists(ListNode* left, ListNode* right){
        ListNode* dummy = new ListNode(); 
        ListNode* tail = dummy;
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
        if(left) tail->next = left;
        if(right) tail->next = right;
        return dummy->next;
    }
};