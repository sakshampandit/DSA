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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)return head;
        ListNode* p=new ListNode(0);
        p->next=head;
        ListNode* curr=p;
        while(curr->next && curr->next->next)
        {
            if(curr->next->val == curr->next->next->val)
            {
                int variable=curr->next->val;
                while( curr->next!=NULL && curr->next->val==variable)
                {
                    curr->next=curr->next->next;
                }
            }
            else
                curr=curr->next;
        }
        return p->next;
    }
};