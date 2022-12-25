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
    int length(ListNode* head)
    {
        int l=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            l++;
            temp=temp->next;
        }
        return l;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=length(headA);
        int l2=length(headB);
        ListNode* ptr1=NULL;
        ListNode* ptr2=NULL;
        int d=0;
        if(l1>=l2)
        {
            d=l1-l2;
            ptr1=headA;
            ptr2=headB;
        }
        else{
            d=l2-l1;
            ptr1=headB;
            ptr2=headA;
        }
        while(d--)
        {
            ptr1=ptr1->next;
            if(ptr1==NULL)
                return NULL;
        }
        while(ptr1!=ptr2)
        {
            
            ptr1=ptr1->next;
            ptr2=ptr2->next;
            if(ptr1==NULL||ptr2==NULL)
                return NULL;
        }
        return ptr1;
    }
};