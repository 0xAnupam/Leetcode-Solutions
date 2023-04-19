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
void dfs(TreeNode* root,vector<int> &a){
        if(root==NULL){
                return ;
        }
        dfs(root->left,a);
        a.push_back(root->val);
        dfs(root->right,a);
}
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a,b,c;
            dfs(root1,a);
            dfs(root2,b);
            int i=0,j=0,n=a.size(),m=b.size();
            while(i<n && j<m){
                    if(a[i]<b[j]){
                            c.push_back(a[i++]);
                    }
                    else{
                            c.push_back(b[j++]);
                    }
            }
            while(i<n){
                    c.push_back(a[i++]);
            }
            while(j<m){
                    c.push_back(b[j++]);
            }
            return c;
    }
};