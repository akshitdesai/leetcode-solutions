/* Problem-Link:- https://leetcode.com/problems/reverse-linked-list */

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
