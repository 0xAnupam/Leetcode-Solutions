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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
           vector<vector<int>> res;
            if(root==NULL){
                    return res;
            }
            q.push({root,0});
            while(q.size()){
                    auto p=q.front();
                    q.pop();
                    if(res.size()==p.second){
                            res.push_back({});
                            
                    }
                    res[p.second].push_back(p.first->val);
                    
                            if(p.first->left){
                                    q.push({p.first->left,p.second+1});
                            }
                            if(p.first->right){
                                    q.push({p.first->right,p.second+1});
                            }
                    
                    
            }
            int n=res.size();
            for(int i=1;i<n;i+=2){
                    reverse(res[i].begin(),res[i].end());
            }
            return res;
    }
};