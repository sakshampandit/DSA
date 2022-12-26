//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
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

class Solution{
  public:
    Node* middle(Node* head)
    {
        Node *a=head;
        Node *b=head;
        while(b!=NULL && b->next!=NULL)
         {   a=a->next;
            b=b->next->next;
        }
        return a;
    }
    
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node* head)
    {
        //Your code here
        if(!head||!head->next)
        return true;
        
        Node* mid=middle(head);
        Node* prev=NULL;

        Node* curr=mid;

        Node* next;

        while(curr){

            next=curr->next;

            curr->next=prev;

            prev=curr;

            curr=next;
        }
        Node* last=prev;
        Node* temp=head;
        while(last)
        {
            if(temp->data!=last->data)
            return false;
            
            temp=temp->next;
            last=last->next;
        }
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends