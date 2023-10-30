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
int vis;
void dfs(TreeNode* root, int k,int &res){
        if(root==nullptr){
                return ;
        }
        dfs(root->left,k,res);
        vis++;
        if(vis==k){
                res=root->val;
                return ;
        }
        dfs(root->right,k,res);
        
}
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int res=-1;
            vis=0;
            dfs(root,k,res);
            return res;
    }
};