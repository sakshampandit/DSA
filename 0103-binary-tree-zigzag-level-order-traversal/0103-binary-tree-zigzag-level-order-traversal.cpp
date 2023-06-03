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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //answer vector
        vector<vector<int>>result;
        //base condition
        if(root==NULL)return result;
        queue<TreeNode*>q;
        q.push(root);
         // flag value to switch l to r and r to l      
        bool flag=true;
        while(!q.empty())
        {
            int size=q.size();
            //inserting the node in a single row
            vector<int>row(size);
            
            for(int i=0;i<size;i++)
            {   TreeNode* node=q.front();
                q.pop();
                int index=(flag==true)?i:size-1-i;
                row[index]=node->val;
             // if there exist a left child push it 
             if(node->left)
                 q.push(node->left);
             //if there exist a right child push it
             if(node->right)
                 q.push(node->right);
            }
            //switch the flag after one full iteration
            flag=!flag;
            //pushing the result in the row
            result.push_back(row);
        }
        //returning the result
        return result;
    }
};