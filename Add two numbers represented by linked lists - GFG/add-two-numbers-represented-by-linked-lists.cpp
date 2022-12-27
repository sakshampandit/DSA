//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* reverseList(struct Node *head)
    {
      struct Node* prev=NULL;
       struct Node* current=head;
        struct Node* Next;
        while(current!=NULL)
        {
             Next=current->next;
            current->next=prev;
            prev=current;
            current=Next;
            // Next=current->next;
            
        }
       head=prev;
        
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first= reverseList(first);
        second= reverseList(second);
        Node*f=first;
        Node*s=second;
        int carry=0,sum=0;
        Node*ans=new Node(0);
        Node* temp=ans;
        while(f!=NULL && s!=NULL)
        {
            // if(f==NULL)
            // f->data=0;
            // if(s==NULL)
            //  s->data=0;
            sum= f->data + s->data+ carry;
            temp->next=new Node(sum%10);
            carry=sum/10;
            f=f->next;
            s=s->next;
            temp=temp->next;
        }
        while (f)
        {
            
            sum= f->data+ carry;
            temp->next=new Node(sum%10);
            carry=sum/10;
            f=f->next;
            temp=temp->next;
        }
         while (s)
        {
           
            sum=  s->data+ carry;
            temp->next=new Node(sum%10);
            carry=sum/10;
            s=s->next;
            temp=temp->next;
        }
        if(carry>0)
        {
            Node*t=new Node(carry);
            temp->next=t;
        }
        
        return reverseList(ans->next);
    }
    
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends