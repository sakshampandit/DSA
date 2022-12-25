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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL)
            return NULL;
    ListNode*prev=NULL;
    ListNode* q;
    ListNode*curr=head;
    ListNode*fcurr=head;
    while(fcurr && fcurr->next)
    {
        fcurr=fcurr->next->next;
        prev=curr;
        curr=curr->next;
    }
    q= prev->next;    
    prev->next=q->next;
    delete(q);
    return head; 
    }
};