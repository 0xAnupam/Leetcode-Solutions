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
        void dfs(TreeNode* root,vector<vector<int>> &edge){
                if(root==NULL){
                        return ;
                }
                if(root->left){
                        edge[root->val].push_back(root->left->val);
                        edge[root->left->val].push_back(root->val);
                }
                if(root->right){
                        edge[root->val].push_back(root->right->val);
                        edge[root->right->val].push_back(root->val);
                }
                dfs(root->left,edge);
                dfs(root->right,edge);
        }
        
    int amountOfTime(TreeNode* root, int start) {
        vector<vector<int>> edge(100001);
            vector<bool> visit(100001);
            dfs(root,edge);
            int res=0;
            queue<pair<int,int>> q;
            q.push({start,0});
            while(q.size()){
                    auto p=q.front();
                    q.pop();
                    visit[p.first]=true;
                    res=max(res,p.second);
                    for(auto &i:edge[p.first]){
                            if(visit[i]==false){
                                    q.push({i,p.second+1});
                            }
                    }
            }
            return res;
    }
};