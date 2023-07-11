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
void Inorder(TreeNode* root,vector<int>& inorder)
  {
      if(!root)return;
      
      Inorder(root->left,inorder);
      inorder.push_back(root->val);
      Inorder(root->right,inorder);
  }    
public:
    bool findTarget(TreeNode* root, int target) {
    vector<int>inorder;
    Inorder(root,inorder);
    int left=0,right=inorder.size()-1;
    while(left<right){
    if(inorder[left]+inorder[right]==target)return 1;
    else if(inorder[left]+inorder[right]<target)left++;
    else
    right--;
    }
    return 0;
    }
};