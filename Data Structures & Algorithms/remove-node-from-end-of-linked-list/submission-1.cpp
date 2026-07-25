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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //count the size of the LL
        //do size - n traversals. 
        //remove the next node.
        if (head == NULL) return head; 
        ListNode* tail = head; 
        int size = 1; 
        while (tail -> next!=NULL){
            tail = tail -> next; 
            size++; //by the end of the loop i get the size of the LL. 
        }
        ListNode* dummy = new ListNode (0); 
        dummy = head; //this is done in order to deal with the cases wherein the head
        //node itself needs to be deleted. SO we equate dummy = head and then return dummy -> next, i.e head -> next. 
        if (size == n) return dummy -> next;
        int counter = 1; 
        ListNode* curr = head; 
        while (counter != size - n){
            curr = curr -> next; 
            counter ++; 
        }
        if (curr -> next != NULL)
            curr -> next = curr -> next -> next; 
        return head; 

    }
};
