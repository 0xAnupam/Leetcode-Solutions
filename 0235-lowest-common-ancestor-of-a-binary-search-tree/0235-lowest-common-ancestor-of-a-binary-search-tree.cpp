/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void store(vector<TreeNode*>&a,TreeNode* root,TreeNode* tar){
        if(root==NULL){
                return ;
        }
        a.push_back(root);
        if(root==tar){
                return ;
        }
        if(root->val>tar->val){
                store(a,root->left,tar);
        }
        else{
                store(a,root->right,tar);
        }
        
}
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> a,b;
            store(a,root,p);
            store(b,root,q);
            TreeNode* res=NULL;
            int n=a.size(),m=b.size();
            int i=0,U=min(n,m);
            while(i<U && a[i]==b[i]){
                    res=a[i++];
                    
            }
            return res;
    }
};