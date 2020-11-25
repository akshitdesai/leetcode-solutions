/* Problem-Link:- https://leetcode.com/problems/delete-node-in-a-linked-list/ */


/* Solution-1 */
/* Time comp. - O(N) */
/* Space comp. - O(1) */

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* next = node->next;
        *node = *next;
        delete next;
    }
};
