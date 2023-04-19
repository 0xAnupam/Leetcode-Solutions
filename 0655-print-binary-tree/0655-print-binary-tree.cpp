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
int h(TreeNode* root){
        if(root==NULL){
                return 0;
        }
        return 1+max(h(root->left),h(root->right));
}
void dfs(TreeNode* root,int r,int c,vector<vector<string>> &res,int height){
        if(root==NULL){
                return ;
        }
        int p=pow(2,height-r-2);
        res[r][c]=to_string(root->val);
        dfs(root->left,r+1,c-p,res,height);
        dfs(root->right,r+1,c+p,res,height);
}
class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int height=h(root);
        int col=pow(2,height)-1;
        vector<vector<string>> res(height,vector<string> (col));
        dfs(root,0,col/2,res,height);
        return res;
    }
};