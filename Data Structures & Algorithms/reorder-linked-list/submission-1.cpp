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
    ListNode* revLL ( ListNode* head){
        if ( head == NULL )
            return NULL; 
        if ( head -> next == NULL)
            return head; 
        ListNode* curr = head; 
        ListNode* frwd = head; 
        ListNode* prev = NULL; 
        while ( curr != NULL){
            frwd = curr -> next; 
            curr -> next = prev; 
            prev = curr; 
            curr = frwd; 
        }
        return prev; 
        
    }
    void reorderList(ListNode* head) {
     
        ListNode* fast = head; 
        ListNode* slow = head; 
        while ( fast -> next != NULL && fast -> next -> next != NULL ){
            fast = fast -> next -> next ;
            slow = slow -> next ; 
        }
        slow -> next = revLL (slow -> next); 
        ListNode* head2 = slow -> next; 
        slow -> next = NULL; 
        ListNode* curr = head; 
        while (head2 != NULL){
            ListNode* temp = curr ->next;
            ListNode* slowNext = head2  -> next;  
            curr -> next = head2 ;
            head2 -> next = temp; 
            curr = temp; 
            head2 = slowNext; 
        }
    }
};
