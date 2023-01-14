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
int ans=-1e4;
map<TreeNode*,bool>mp;
int f(TreeNode* root){
        if(root==NULL ){
                return 0;
        }
       // mp[root]=1;
        int res=root->val,a=-1e3,b=a;
        
                a=f(root->left);
        
       
                b=f(root->right);
        
        ans=max({ans,0,res+a+b,a,b,res+a,res,res+b});
        
        return res+max({0,a,b});
        
}
int k=-1e4;
void dfs(TreeNode* root){
        if(root==NULL){
                return ;
        }
        k=max(k,root->val);
        f(root);
        dfs(root->left);
        dfs(root->right);
}
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        ans=0;k=-1e4;
            mp.clear();dfs(root);
            return k<0? k:ans;
    }
};