/* Problem-Link:- https://leetcode.com/problems/add-two-numbers/ */



/* Solution-1 => With Extra space */
/* Time comp. - O(N) */
/* Space comp. - O(N) */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0), *cur = dummy;
        for (int c = 0; l1 || l2 || c; c /= 10, cur = cur->next) {
            if (l1) c += l1->val;
            if (l2) c += l2->val;
            cur->next = new ListNode(c % 10);
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return dummy->next;
    }
};



/* Solution-2 => without extra space */
/* Time comp. - O(N) */
/* Space comp. - O(1) */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry = 0;
        ListNode * pl1, * head = l1;
        
        while(l1 && l2){
            int temp = l1 -> val + l2 -> val + carry;
            l1 -> val = temp % 10;
            carry = temp / 10;
            pl1 = l1;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        
        while(l1){
            int temp = l1 -> val + carry;
            l1 -> val = temp % 10;
            carry = temp / 10;
            pl1 = l1;
            l1 = l1->next;
        }
        if(l2){
            pl1 -> next = l2;
            l1 = pl1 -> next;
            while(l1){
                int temp = l1 -> val + carry;
                l1 -> val = temp % 10;
                carry = temp / 10;
                pl1 = l1;
                l1 = l1->next;
            }
        }
        
        if(carry)   pl1 -> next = new ListNode(carry);
        
        return head;
    }
};
