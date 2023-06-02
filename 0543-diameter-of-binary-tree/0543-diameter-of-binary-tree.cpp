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
    int diameterOfBinaryTree(TreeNode* root) {
       // Your code here
        int maxi=0;
        Diameter(root,maxi);
        return maxi;
    }
private:
    // Function to return the diameter of a Binary Tree.
    int Diameter(TreeNode* node,int& maxi){
        if(node==NULL)return 0;
        int lh,rh;
        lh=Diameter(node->left,maxi);
        rh=Diameter(node->right,maxi);
        
        maxi=max(maxi,lh+rh);
        return 1+max(lh,rh);
    }
};