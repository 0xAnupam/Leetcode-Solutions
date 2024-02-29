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
    bool isEvenOddTree(TreeNode* root) {
        int level=1;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                    queue<TreeNode*> p;
                    int prev;
                    if(level&1){
                            prev=0;
                            while(!q.empty()){
                                    if((q.front()->val&1)==0 || prev>=(q.front()->val)){
                                            return 0;
                                    }
                                    prev=q.front()->val;
                                    if(q.front()->left)p.push(q.front()->left);
                                    if(q.front()->right)p.push(q.front()->right);
                                    q.pop();
                            }
                    }
                    else{
                            prev=INT_MAX;
                            while(!q.empty()){
                                    if((q.front()->val&1)|| prev<=(q.front()->val)){
                                            return 0;
                                    }
                                    prev=q.front()->val;
                                    if(q.front()->left)p.push(q.front()->left);
                                    if(q.front()->right)p.push(q.front()->right);
                                    q.pop();
                            }
                    }
                    level++;
                    swap(p,q);
            }
            return 1;
    }
};