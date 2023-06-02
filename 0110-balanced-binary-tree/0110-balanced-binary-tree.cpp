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
    int height(TreeNode* node){
        if(node==NULL)return 0;//base condition
        int lh,rh;
        lh=height(node->left);//check for left
        rh=height(node->right);//check for right
        if(lh==-1||rh==-1)//check whether subtree exist
            return -1;
        if(abs(lh-rh)>1)return -1;//check the main condition given
        return 1+max(lh,rh);//return height
    }
    bool isBalanced(TreeNode* root) {
        return height(root)!=-1;//answer
    }
};