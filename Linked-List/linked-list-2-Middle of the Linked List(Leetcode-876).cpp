/* Problem-Link:- https://leetcode.com/problems/middle-of-the-linked-list/ */


/* Solution-1 => Iterative */
/* Time comp. - O(N) */
/* Space comp. - O(1) */

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        return slow;
    }
};
