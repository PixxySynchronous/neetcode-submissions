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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
     ListNode* p1 = list1; 
     ListNode* p2 = list2; 
     ListNode* Sorted = new ListNode (-1); //Dummy Node. Avoids edge cases
     ListNode* SortedTail = Sorted; 
     if (p1 == NULL) return p2; 
     if (p2 == NULL) return p1;
     while (p1 != NULL && p2!= NULL){
        if (p1->val <= p2->val){
            SortedTail->next = p1;
            SortedTail = SortedTail -> next;
            p1 = p1->next;
        }
        else{
            SortedTail->next = p2;
            SortedTail = SortedTail -> next;
            p2 = p2->next;  
        }
     }
     if (p1 == NULL)
        SortedTail ->next = p2;     //since remaining p2 is already sorted,
        //we just connect it to sorted tail. Same reasoning for the below statement
    
    else 
        SortedTail -> next = p1; 
    return Sorted->next; 
    }
};
