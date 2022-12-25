//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node* head)
    {
        Node* prev=NULL;
        Node* curr=head;
        Node* nextr;
        while(curr!=NULL)
        {
            nextr=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextr;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        
        head=reverse(head);
        Node *temp=head;
        Node* prev=head;
        int sum=temp->data+1;
        temp->data=sum%10;
        int carry=sum/10;
        temp=temp->next;
        while(temp!=NULL)
        {  
            sum=temp->data+carry;
            temp->data=sum%10;
            carry=sum/10;
            prev=temp;
            temp=temp->next;
        }
        if(carry!=0)
        prev->next=new Node(carry);
        
        head=reverse(head);
        return head;
        
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends