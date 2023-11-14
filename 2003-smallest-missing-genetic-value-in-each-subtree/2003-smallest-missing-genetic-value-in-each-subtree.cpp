const int N=1e5+2;
struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};
int dfs(int node,vector<int>* adj,vector<int>& nums,vector<int>& mini){
        int res=nums[node];
        for(auto &i:adj[node]){
                res=min(res,dfs(i,adj,nums,mini));
        }
        return mini[node]=res;
}
void F(int node,vector<int>* adj,vector<int>& nums,vector<int>&mex,vector<int>& mini,FenwickTree &A){
       int l=1,h=nums.size(),m;
        while(l<=h){
                m=(l+h)/2;
                if(A.sum(0,m)==m){
                        l=m+1;
                }
                else{
                        h=m-1;
                }
        }

        mex[node]=l;
        A.add(nums[node],-1);
        for(auto &i:adj[node]){
                A.add(mini[i],-1);
        }
        for(auto &i:adj[node]){
                A.add(mini[i],1);
                F(i,adj,nums,mex,mini,A);
                A.add(mini[i],-1);
        }        
}
class Solution {
public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
       int n=nums.size();
            vector<int> adj[n];
            for(int i=1;i<n;i++){
                    adj[parents[i]].push_back(i);
            }
            FenwickTree A(N);
            vector<int> mini(n,0),mex=mini;
            dfs(0,adj,nums,mini);
            for(auto &i:nums){
                    A.add(i,1);
            }
            F(0,adj,nums,mex,mini,A);
            return mex;

    }
};