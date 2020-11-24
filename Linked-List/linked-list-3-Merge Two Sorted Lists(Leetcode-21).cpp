/* Problem-Link:- https://leetcode.com/problems/merge-two-sorted-lists/ */


/* Solution-1 => Iterative */
/* Time comp. - O(N+M) */
/* Space comp. - O(1) */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    
        ListNode *head = new ListNode(-1), *temp;
        temp = head;
        
        while(l1 && l2){
            if(l1->val <= l2->val){
                head -> next = l1;
                head = head -> next;
                l1 = l1 -> next;
            } else if (l1->val > l2->val){
                head -> next = l2;
                head = head -> next;
                l2 = l2 -> next;
            }
        }
        
        while(l1){
            head -> next = l1;
            head = head -> next;
            l1 = l1 -> next; 
        }
        
        while(l2){
            head -> next = l2;
            head = head -> next;
            l2 = l2 -> next; 
        }
        
        return temp->next;
    }
};
