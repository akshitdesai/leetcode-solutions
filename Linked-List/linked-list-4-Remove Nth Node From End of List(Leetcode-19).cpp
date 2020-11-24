/* Problem-Link:- https://leetcode.com/problems/remove-nth-node-from-end-of-list/ */


/* Solution-1 => Two Pass */
/* Time comp. - O(N) */
/* Space comp. - O(1) */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* temp = head;
        int total = 0;

        while(temp){
            temp = temp -> next;
            total++;
        }
        
        total -= (n+1);
        temp = head;
        
        if(total<0){
            head = head->next;
            return head;
        }
            
        while(total--)
            temp = temp -> next;
        temp->next = temp -> next -> next;
        
        return head;
    }
};
