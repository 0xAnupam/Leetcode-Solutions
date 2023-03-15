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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
            int prev=0;
            bool f=0;
            q.push(root);
            while(q.size()){
                    auto p=q.front();
                    q.pop();
                    if(p==NULL){
                            f=1;
                           
                    }
                    else{ 
                           if(f){
                                   return 0;
                           } 
                           q.push(p->left);
                           q.push(p->right); 
                   
                    }
            }
            return 1;
    }
};