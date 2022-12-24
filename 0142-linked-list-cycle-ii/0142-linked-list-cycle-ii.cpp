/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* a=head;
        ListNode* b=head;
        int pos=-1,i=1;
        while(b!=NULL && b->next!=NULL)
        {
            b=b->next->next;
            a=a->next;
            if(a==b)
            { 
                 a=head;
            while(a!=b)
            {
                a=a->next;
                b=b->next;
            
            }
            return a;
            }
         }
        
           return NULL;
          
    }
};