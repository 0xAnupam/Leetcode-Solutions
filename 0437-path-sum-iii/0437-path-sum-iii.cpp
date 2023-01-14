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
int f(TreeNode* root,int tar,long long sum,map<long long,int> &mp){
        if(root==NULL){
                return 0;
        }
        
        sum+=root->val;
        
        int res=mp[sum-tar];
        mp[sum]++;
        res+=f(root->left,tar,sum,mp);
        res+=f(root->right,tar,sum,mp);
        mp[sum]--;
        return res;
}
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        map<long long,int > mp;
            mp[0]++;
            return f(root,targetSum,0LL,mp);
    }
};