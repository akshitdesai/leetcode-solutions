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

/* Solution-1 => One Pass */
/* Time comp. - O(N) */
/* Space comp. - O(1) */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* temp1 = head, *temp2 = head;
        
        for(int i = 0; i < n; i++)
            temp1 = temp1 -> next;
        
        if(temp1==NULL){
            head = head -> next;
            return head;
        }
        
        while(temp1->next!=NULL){
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        
        temp2 -> next = temp2 -> next -> next;
        
        return head;
    }
};
