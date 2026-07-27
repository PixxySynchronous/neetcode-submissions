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

    ListNode* reverseKGroup(ListNode* head, int k) {
        //Check if k nodes are prresent. If not simply return the list.
        ListNode* temp = head; 
        for (int i = 0 ; i<k ; i++){
            if (temp == NULL)
                return head; 
            temp = temp -> next; 
        }
        ListNode* prev = NULL;
        ListNode* frwd = NULL; 
        ListNode* curr = head; 
        int counter = k; 
        while (curr != NULL && counter != 0){
            frwd = curr -> next; 
            curr -> next = prev; 
            prev = curr; 
            curr = frwd;
            counter --;
        }//prev now points to the ACTUAL head of the rev ll. In example 1, pass 1, prev points to 3. 
        //reverse k nodes. Now head would the last node, and head -> next should point to the next reversed k list. 
        if (frwd!= NULL) //hasnt reached the end. 
        head -> next = reverseKGroup (frwd , k); 
        return prev; //if frwd = NULL, we have nothing to rev so we return the actual head. 

    }
};
