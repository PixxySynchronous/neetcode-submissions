/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode (-1); 
        ListNode* tail = dummy; //we will traverse through tail. return dummy -> next
        int carry = 0; 
        int sum = 0; 
        while (l1 != NULL && l2 != NULL){
            sum = (l1->val + l2->val + carry); 
            carry = sum/10;
            tail -> next = new ListNode (sum%10); //make the new node before pointing to it. 
            tail = tail -> next; 
            l1 = l1 -> next; 
            l2 = l2 -> next; 
        }
        while (l1){
            sum = l1->val + carry;
            carry = sum/10; 
            tail -> next = new ListNode (sum%10);
            tail = tail -> next; 
            l1 = l1 -> next; 
        }
        while (l2){
            sum = l2->val + carry;
            carry = sum/10; 
            tail -> next = new ListNode (sum%10);
            tail = tail -> next; 
            l2 = l2 -> next; 
        }

        if (carry != 0){ //carry may still be left. 
            tail -> next = new ListNode (carry);
            tail = tail -> next; 
        }
        return dummy -> next; 
        

    }
};
