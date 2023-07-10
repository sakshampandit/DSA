/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void InorderTraversal(TreeNode* root,vector<int>& inorder)
    {
        if(!root)return;
        
        InorderTraversal(root->left,inorder);
        inorder.push_back(root->val);
        InorderTraversal(root->right,inorder);
    }
public:
    TreeNode* balance(vector<int>& inorder,int start,int end)
    {
        if(start>end)
            return NULL;
        
        int mid=(start+end)/2;
        TreeNode* root=new TreeNode(inorder[mid]);
        
        root->left=balance(inorder,start,mid-1);
        root->right=balance(inorder,mid+1,end);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
      if(root==NULL)
          return root;
        vector<int> inorder;
        
        InorderTraversal(root,inorder);
        int n=inorder.size();
        
       return balance(inorder,0,n-1);
    }
};