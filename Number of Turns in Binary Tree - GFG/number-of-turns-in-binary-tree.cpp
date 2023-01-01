//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
      
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
          
        // Get the current node's value from the string
        string currVal = ip[i];
          
        // If the left child is not null
        if(currVal != "N") {
            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }
          
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
          
        // If the right child is not null
        if(currVal != "N") {
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function template for C++
/*
Structure of the node of the tree is as follows 
struct Node {
    struct Node* left, *right;
    int data;
};
*/

class Solution{
 public:
   int turn(Node*root,int n,char sign)
   {
       if(root==nullptr) return INT_MAX-1;
       if(root->data==n) return 0;
       
       int h1=0,h2=0;
       if(sign=='L')
       {
         h1=turn(root->left,n,'L');
         h2=1+turn(root->right,n,'R');
       }
       else if(sign=='R') //Do same as above;
       {
           h1=1+turn(root->left,n,'L');
           h2=turn(root->right,n,'R');
       }
       return min(h1,h2);
   }
   Node* lca(Node* root ,int n1 ,int n2)
   {
      if(root==nullptr){
        return nullptr;
      }
      
      if(root->data==n1|| root->data==n2){
          return root;
      }
      
      Node* h1= lca(root->left,n1,n2);
      Node* h2= lca(root->right,n1,n2);
      
      if(h1==nullptr)
       return h2;
      if(h2==nullptr) 
        return h1;
      
      if((h1->data==n1 || h2->data==n2) || (h1->data==n2 || h2->data==n1))
        return root;
   }
   
   
   int NumberOFTurns(struct Node* root, int first, int second)
   {
     Node* lc=lca(root,first,second);
     
     int turn1=min(turn(lc,first,'L'),turn(lc,first,'R'));
     int turn2=min(turn(lc,second,'L'),turn(lc,second,'R'));
     
     if(turn1+turn2==0 && (lc->data==first || lc->data==second)) return -1;
     
      if((lc->data==first || lc->data==second)) return turn1+turn2;
      
      return turn1+turn2+1; 
   }
};

//{ Driver Code Starts.

int main()
{
    int t;
    struct Node *child;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        int turn, first, second;
        cin>>first>>second;
        Solution ob;
        if ((turn = ob.NumberOFTurns(root, first, second) ))
            cout<<turn<<endl;
        else 
            cout<<"-1\n";
        cin.ignore();
    }
    return 0;
}

// } Driver Code Ends