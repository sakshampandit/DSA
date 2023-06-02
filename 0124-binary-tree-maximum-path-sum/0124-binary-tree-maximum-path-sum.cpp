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
    int sum(TreeNode* node,int& s)
    {
        if(node==NULL)return 0;
        int l,r;
        l=sum(node->left,s);
        if(l<0)l=0;
        r=sum(node->right,s);
        if(r<0)r=0;
        s=max(s,node->val+l+r);
        return (node->val)+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        int s=INT_MIN;
        sum(root,s);
        return s;
    }
};