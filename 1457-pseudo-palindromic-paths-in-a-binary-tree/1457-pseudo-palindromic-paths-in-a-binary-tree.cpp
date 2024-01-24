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
 bool pos(vector<int>&f){
        int o=0;
        for(auto &i:f){
                if(i&1){
                        o++;
                        if(o>1){return 0;}
                }
        }
        return 1;
}
int pal(TreeNode* root,vector<int> f){
        if(root==NULL){
                return 0;
        }
        f[root->val]++;
        if(root->left || root->right){
                return pal(root->left,f)+pal(root->right,f);
        }
        return pos(f)? 1:0;
}
class Solution {
public:
        
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> f(10,0);
            return pal(root,f);
            
    }
};