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
    TreeNode* bstFromPreorder(vector<int>& p) {
        int i=0;
        return build(p,i,INT_MAX);
    }
public:
    TreeNode* build(vector<int>&p, int& i,int bound)
    {
        if(i==p.size()||p[i]>bound)return NULL;
        TreeNode* root=new TreeNode(p[i++]);
        root->left=build(p,i,root->val);
        root->right=build(p,i,bound);
        return root;
    }
};