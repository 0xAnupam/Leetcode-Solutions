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
string f(vector<TreeNode*> &res,TreeNode* root,map<string,int> &mp){
        if(root==NULL){
                return "-";
        }
        string p="<"+f(res,root->left,mp)+','+to_string(root->val)+'.'+f(res,root->right,mp)+">";
        mp[p]++;
        if(mp[p]==2){
                res.push_back(root);
        }
       // cout<<p<<'\n';
        return p;
}
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
            map<string,int> mp;
            f(res,root,mp);
            return res;
    }
};