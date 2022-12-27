/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //ADD A DUPLICATE LINKLIST BY POINTERS
        if(head==NULL)return head;
            
        Node* a=head;
        while(a)
        {
            Node *temp=a->next;
            a->next=new Node(a->val);
            a->next->next=temp;
            a=temp;
        }
        a=head;
        //ADD RANDOM POINTERS
        while(a)
        {  if(a->next!=NULL)
            a->next->random=(a->random!=NULL)?a->random->next:NULL;
            a=a->next->next;
        }
        //REMOVE THE DUPLICATE POINTERS
        a=head;
        Node* b=head->next;
        Node* newhead=b;
        while(a)
        {
            a->next=a->next->next;
            if(a->next==NULL)
            break;
            b->next=b->next->next;
            a=a->next;
            b=b->next;
        }
        b->next=NULL;
        return newhead;
        }
        
    
};