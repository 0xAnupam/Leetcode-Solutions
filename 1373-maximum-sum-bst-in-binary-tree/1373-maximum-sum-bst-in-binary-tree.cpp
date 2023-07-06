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
struct node{
        int val;
        int l;
        int r;
        bool f;
        node(int val,int l,int r,bool f){
                this->val=val;
                this->l=l;
                this->r=r;
                this->f=f;
        }
        
};
node id(0,0,0,0);
int res=0;
node f(TreeNode* root)
{
        if(root==NULL){
                return id;
        }
        node cur(root->val,root->val,root->val,1);
        if(root->left){
                auto L=f(root->left);

                
                if(L.f && L.r<root->val){
                        cur.val+=L.val;
                        cur.l=L.l;

                }
                else{
                        cur=id;
                }
        }
        if(root->right){
                auto R=f(root->right);
                if(R.f && root->val<R.l ){
                        cur.val+=R.val;
                        cur.r=R.r;
                }
                else{
                        cur=id;
                }
        }
        res=max(res,cur.val);
    //    cout<<root->val<<'\t'<<cur.val<<'\t'<<cur.l<<'\t'<<cur.r<<'\t'<<cur.f<<'\n';
        return cur;
        
}
class Solution {
public:
    int maxSumBST(TreeNode* root) {
            res=-1e9;
        f(root).val;
            return res;
    }
};