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
const long long m=1e9+7;
long long sum(TreeNode* root){
        if(root==NULL){
                return 0;
        }
        return root->val+sum(root->left)+sum(root->right);
}
 long long dfs(TreeNode* root,long long &res,long long S){
        if(root==NULL){
            return 0;
        }
        long long sum1=dfs(root->left,res,S);
        long long sum2=dfs(root->right,res,S);
        long long pro1=((S-sum1-sum2-root->val)*(sum2+root->val));
         pro1=max(pro1,((S-sum1-sum2)*(sum2)));
         long long
        pro2=((S-sum2-sum1-root->val)*(sum1+root->val));
         pro2=max(pro2,((S-sum2-sum1)*(sum1)));
         long long pro3=((sum1+sum2+root->val)*(S-sum1-sum2-root->val));
         pro3=max(pro3,((S-sum1)*sum1));
         pro3=max(pro3,((S-sum2)*sum2));
         res=max({res,pro1,pro2,pro3});
        return (sum1+root->val+sum2);
        
    }

class Solution {
public:
   
    int maxProduct(TreeNode* root) {
        long long res=1;
            long long S=sum(root);
        dfs(root,res,S);
        return res%m;
    }
};