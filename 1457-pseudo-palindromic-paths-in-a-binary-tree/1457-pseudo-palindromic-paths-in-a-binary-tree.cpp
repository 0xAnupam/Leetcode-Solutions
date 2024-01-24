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
int pal(TreeNode* root,int f){
        if(root==NULL){
                return 0;
        }
        f^=(1<<(root->val));
        if(root->left || root->right){
                return pal(root->left,f)+pal(root->right,f);
        }
        return (f&(f-1)) ==0 ;
}
class Solution {
public:
        
    int pseudoPalindromicPaths (TreeNode* root) {
            return pal(root,0);
    }
};