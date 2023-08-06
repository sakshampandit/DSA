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
    Node* reverse(Node *head)
    {
        if(head==NULL ||head->next==NULL)
        return head;
        Node* newhead=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return newhead;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        Node* f=reverse(first);
        Node* s=reverse(second);
        int sum=0,c=0;
        Node* res=NULL;
        Node* curr=NULL;
        while(f!=NULL || s!=NULL)
        {
            int sum=c+(f?f->data:0)+(s?s->data:0);
            c=(sum>=10)?1:0;
            sum=sum%10;
            Node* temp=new Node(sum);
            if(res==NULL)
            {
                res=temp;
                curr=temp;
            }
            else
            {
                curr->next=temp;
                curr=temp;
            }
            if(f)f=f->next;
            if(s)s=s->next;
        }
        if(c>0)
        {
            Node* temp=new Node(c);
            curr->next=temp;
            curr=temp;
        }
        res=reverse(res);
        return res;
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