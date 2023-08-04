//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
  
    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }
  
    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++

/*class Node {
public:
    int data;
    Node* next;
  
    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }
  
    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};*/

// class Node
// {
//     int data;
//     Node* next;
//     Node()
//     {
//      data=0;
//      next=NULL;
//     }
//     Node(data)
//     {
//         this->data=data;
//         this->next=NULL;
//     }
// }
class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        // code here
        Node* head=NULL;
        if(arr.size()==0)
        return head;
        head=new Node(arr[0]);
        int i=1;
        Node* curr=head;
        while(i<arr.size() && curr!=NULL)
        {
            Node* temp=new Node(arr[i]);
            i++;
            curr->next=temp;
            curr=temp;
        }
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        Node* ans = obj.constructLL(arr);
        while (ans) {
            cout << ans->data << " ";
            ans = ans->next;
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends