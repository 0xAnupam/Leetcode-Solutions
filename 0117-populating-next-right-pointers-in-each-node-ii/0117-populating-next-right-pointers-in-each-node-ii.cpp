/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
void dfs(Node* root,int level,vector<Node*> &res){
        if(root==NULL){
                return ;
        }
        if(res.size()==level){
                root->next=NULL;
                res.push_back(root);
                
        }
        else {
                (res[level]->next)=root;
                res[level]=root;
                
        }
        dfs(root->left,level+1,res);
        dfs(root->right,level+1,res);
}
class Solution {
public:
    Node* connect(Node* root) {
         vector<Node*> t;
            dfs(root,0,t);
            return root;
    }
};