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
    ListNode* revLL (ListNode* mid){
        ListNode* curr = mid;
        ListNode* prev = NULL;
        ListNode* frwd = NULL;
        while (curr!= NULL){
            frwd = curr -> next; 
            curr -> next = prev;
            prev = curr; 
            curr = frwd; 
        }
        return prev; 
    }
    void reorderList(ListNode* head) {
        //Need to reach the middle of the list, then reverse the second half. 
        ListNode* slow = head; 
        ListNode* fast = head; 
        while (fast -> next!= NULL && fast->next -> next !=NULL){ //we want the lower value of mid for even length strings. 
            slow = slow->next; 
            fast = fast -> next -> next; 
        }
        ListNode* p2 = revLL(slow->next); 
        slow -> next = NULL; //we need to split the list down the middle
        ListNode* p1 = head; 
        ListNode* p2next = NULL;
        ListNode* p1next = NULL;
        while (p2 != NULL){
            p2next = p2 -> next; 
            p1next = p1 -> next;
            p1  -> next = p2; 
            p2 -> next = p1next; 
            p1 = p1next;
            p2 = p2next; 
        }

    }
};
