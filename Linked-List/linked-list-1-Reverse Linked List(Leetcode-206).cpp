/* Problem-Link:- https://leetcode.com/problems/reverse-linked-list */


/* Solution-1 => Iterative */
/* Time comp. - O(N) */
/* Space comp. - O(1) */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *current = head, *previous = NULL, *nxt;
        while(current!=NULL){
            nxt = current->next;
            current -> next = previous;
            previous = current;
            current = nxt;
        }
        return previous;
    }
};


/* Solution-2 => Recursive */
/* Time comp. - O(N) */
/* Space comp. - O(N) */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode* rest = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
 
        return rest;
    }
};
