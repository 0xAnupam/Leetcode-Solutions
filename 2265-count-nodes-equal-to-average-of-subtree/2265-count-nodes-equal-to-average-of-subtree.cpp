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
int res=0;
pair<int,int> dfs(TreeNode* root){
        if(root==NULL){
                return {0,0};
        }
        int a=root->val,b=1;
        auto l=dfs(root->left),h=dfs(root->right);
        a+=(l.first+h.first);
        b+=(l.second+h.second);
        int p=(a/b);
        if(root->val==p){
                res++;
        }
        return{a,b};
}
class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        res=0;
        dfs(root);
            return res;
    }
};