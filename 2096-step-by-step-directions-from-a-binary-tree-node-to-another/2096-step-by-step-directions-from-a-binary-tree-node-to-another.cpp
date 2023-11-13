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
TreeNode* lca(TreeNode* root, int startValue, int destValue){
        if(root==nullptr || root->val==startValue || root->val==destValue){
                return root;
        }
        TreeNode* left=lca(root->left,startValue,destValue);
        TreeNode* right=lca(root->right,startValue,destValue);
        if(left==nullptr){
                return right;
        }
        else if(right==nullptr){
                return left;
        }
        return root;
}
int level(TreeNode* root,int height,int target){
        if(root==nullptr){
                return 0;
        }
        if(root->val==target){
                return height;
        }
        return level(root->left,height+1,target)+level(root->right,height+1,target);
}
pair<bool,string> path(TreeNode* root,int target)
{
        if(root==nullptr ){
                return {0,""};
        }
        if(root->val==target){
                return {1,""};
        }
        auto l=path(root->left,target);
        if(l.first==1){
                l.second+='L';
                return l;
        }
        auto r=path(root->right,target);
        r.second+='R';
        return r;
}
class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* common=lca(root,startValue,destValue);
            string res="",tmp=path(common,destValue).second;
            int H=level(common,0,startValue);
            while(H>0){
                    res+='U';
                    H--;
            }
            reverse(tmp.begin(),tmp.end());
            res+=tmp;
            return res;
    }
};