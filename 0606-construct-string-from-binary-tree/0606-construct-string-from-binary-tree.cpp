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
        void helper(TreeNode* root,string &res){
                if(root==NULL){
                        return ;
                }
                res+=to_string(root->val);
                if(root->left==NULL && root->right==NULL){
                        return ;
                }
                if( root->right){
                        res+='(';
                        helper(root->left,res);
                        res+=')';
                        res+='(';
                        helper(root->right,res);
                        res+=')';
                }else if(root->left){
                        res+='(';
                        helper(root->left,res);
                        res+=')';
                }
                
        }
    string tree2str(TreeNode* root) {
        string res="";
            helper(root,res);
            return res;
    }
};