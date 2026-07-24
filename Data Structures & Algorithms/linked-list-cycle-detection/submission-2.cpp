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
    bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head; 
        if (head == NULL || head ->next == NULL) return false;
        while (fast -> next -> next != NULL){
            fast = fast->next->next; 
            slow = slow ->next ;
            if (fast==slow)
                return true; 
            if(fast->next == NULL) return false; 

        }
        return false; 
    }
};
