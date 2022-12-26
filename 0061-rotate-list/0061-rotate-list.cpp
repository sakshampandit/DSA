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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL)
            return head;
        
        ListNode* temp=head;
        int l=0;
        while(temp->next)
        {     ++l;
              temp=temp->next;
        }
        
        temp->next=head;
        k=k%(l+1);
        int i=l-k;
       ListNode* temp1=head;
        while(i--)
        {   
            temp1=temp1->next;
        }
       ListNode* head1=temp1->next;
        temp1->next=NULL;
        return head1;
    }
};