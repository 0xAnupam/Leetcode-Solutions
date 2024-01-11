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
        void dfs(TreeNode* root,int &res,int a,int b){
                if(root==NULL){
                        return ;
                }
               
                 res=max(res,root->val-a);
                 res=max(res,b-root->val);               
                dfs(root->left,res,min(a,root->val),max(b,root->val));
                dfs(root->right,res,min(a,root->val),max(b,root->val));
        }
    int maxAncestorDiff(TreeNode* root) {
        
        int res=0;
        dfs(root,res,root->val,root->val);
        return res;
    }
};