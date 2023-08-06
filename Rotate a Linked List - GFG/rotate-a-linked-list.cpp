//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    int length(Node * head)
    {
        Node *p=head;
        int l=0;
        while(p)
        {
            ++l;
            p=p->next;
        }
        return l;
    }
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {  if(head==NULL ||head->next==NULL)return head;
        Node* temp=head;
        Node* prev=NULL;
        int len=length(head);
        if(k==0 || k==len)
        return head;
     // temp=26 prev=12 c=1 len=2 k=
     int c=0;
        while(c<k)
        {   prev=temp;
            ++c;
            temp=temp->next;
        }
        prev->next=NULL;
        Node* heada=temp;
        Node* a=heada;
        while(a->next)
        {
            a=a->next;
        }
        a->next=head;
        return heada;
    }
};
    



//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends