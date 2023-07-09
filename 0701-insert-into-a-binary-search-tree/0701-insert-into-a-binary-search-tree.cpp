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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
       TreeNode* temp=new TreeNode(val);
        TreeNode* curr=root;
        if(root==NULL)
        {    root=temp;
             return root;
        }
        while(true)
        {
            if(root->val<val)
            {
                if(root->right!=NULL)
                {
                    root=root->right;
                }
                else
                {
                    root->right=temp;
                    break;
                }
            }
            else if(root->val>val)
            {
                if(root->left!=NULL)
                {
                    root=root->left;
                }
                else
                {
                    root->left=temp;
                    break;
                }
            }
            else
                break;
        }
        return curr;
           
    }
};