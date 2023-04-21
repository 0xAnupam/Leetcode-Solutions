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
map<pair<TreeNode*,int>,int> mp;
int f(TreeNode* root,int have){
        if(root==NULL){
                return 0;
        }
        pair<TreeNode*,int> t={root,have};
        if(mp.find(t)!=mp.end()){
                return mp[t];
        }
        int a=0,b=0;
        if(have){
                int res=1;
                if(root->left){
                        a+=(f(root->left->left,0)+f(root->left->right,0));
                }
                if(root->right){
                        b+=(f(root->right->left,0)+f(root->right->right,0));
                }
        
               int  p=1+min({f(root->left,1)+f(root->right,0),f(root->left,0)+f(root->right,1),f(root->left,1)+f(root->right,1)});
                p=min({p,1+f(root->right,1)+a,1+f(root->left,1)+b});
                res+=(a+b);
                return mp[t]=min(res,p);
        }
        int op=0,op1=1;
        if(root->left==NULL && root->right==NULL){
                op=1;
        }
        else{
                if(root->left==NULL && root->right){
                        op=f(root->right,1);
                }
                else if(root->right==NULL && root->left){
                        op=f(root->left,1);
                }
                else{
                        op=min(f(root->left,1)+f(root->right,0),f(root->left,0)+f(root->right,1));
                }
                
        }
        if(root->left){
                op1+=(f(root->left->left,0)+f(root->left->right,0));
        }
        if(root->right){
                        op1+=(f(root->right->left,0)+f(root->right->right,0));
        }
        return mp[t]=min(op,op1);
}
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        mp.clear();    
        return f(root,0);
    }
};