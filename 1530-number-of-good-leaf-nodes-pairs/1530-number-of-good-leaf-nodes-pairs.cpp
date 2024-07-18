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

TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) return root;
    TreeNode* left = LCA(root->left, p, q);
    TreeNode* right = LCA(root->right, p, q);
    if (left != nullptr && right != nullptr) return root;
    return left != nullptr ? left : right;
}

void leaf(vector<TreeNode*>& l, TreeNode* root, map<TreeNode*, int>& h, int lv) {
    if (root == nullptr) return;
    h[root] = lv;
    if (!root->left && !root->right) {
        l.push_back(root);
        return;
    }
    leaf(l, root->left, h, lv + 1);
    leaf(l, root->right, h, lv + 1);
}

class Solution {
public:
   int countPairs(TreeNode* root, int distance) {
        int count = 0;
        dfs(root, distance, count);
        return count;
    }

private:
    vector<int> dfs(TreeNode* node, int distance, int& count) {
        if (!node) return {};
        if (!node->left && !node->right) return {1};

        vector<int> leftDistances = dfs(node->left, distance, count);
        vector<int> rightDistances = dfs(node->right, distance, count);

        for (int l : leftDistances) {
            for (int r : rightDistances) {
                if (l + r <= distance) count++;
            }
        }

        vector<int> currentDistances;
        for (int l : leftDistances) {
            if (l + 1 < distance) currentDistances.push_back(l + 1);
        }
        for (int r : rightDistances) {
            if (r + 1 < distance) currentDistances.push_back(r + 1);
        }

        return currentDistances;
    }
};
