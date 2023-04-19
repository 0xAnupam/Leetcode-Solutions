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
int f(TreeNode * root,int l){
        if(root==NULL){
                return 0;
        }
        if(mp.find({root,l})!=mp.end())
        {
                return mp[{root,l}];
        }
        if(l){
                return mp[{root,l}]=1+f(root->left,0);
        }
        return mp[{root,l}]=1+f(root->right,1);
}
class Solution {
public:
    int longestZigZag(TreeNode* root) {
        mp.clear();
        queue<TreeNode* > q;
            q.push(root);
            int res=0;
            while(!q.empty()){
                    auto p=q.front();
                    q.pop();
                    if(p==NULL){
                            continue;
                    }
                    res=max({res,f(p,1),f(p,0)});
                    q.push(p->left);
                    q.push(p->right);
            }
            return res-1;
    }
};