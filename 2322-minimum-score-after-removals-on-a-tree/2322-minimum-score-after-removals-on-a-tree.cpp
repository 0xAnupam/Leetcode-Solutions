class Solution {
public:
    int dfs1(int node,int par,int X,vector<int>*adj,int &res,vector<int>&nums){
            int x=0;
            for(auto &i:adj[node]){
                    if(i==par)continue;
                    int xorr=dfs1(i,node,X,adj,res,nums);
                    //del edge
                    dfs2(0,-1,X^xorr,adj,res,node,i,xorr,nums);
                    x^=xorr;
                    
            }
            x^=nums[node];
            return x;
    }   
    int dfs2(int node,int par,int X,vector<int>*adj,int &res,int A,int B,int Y,vector<int>&nums){
            int x=nums[node];
            for(auto &i:adj[node]){
                    if(i==par)continue ;
                    if(node==A && i==B)continue ;
                    int xorr=dfs2(i,node,X,adj,res,A,B,Y,nums);
                    int rest=X^xorr;
                    res=min(res,max({xorr,rest,Y})-min({xorr,rest,Y}));
                    x^=xorr;
                    
            }
            return x;
    }    
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int X=0;
        for(auto &i:nums)X^=i;
            int n=nums.size();
            vector<int> adj[n+1];
            for(auto &i:edges){
                    adj[i[0]].emplace_back(i[1]);
                    adj[i[1]].emplace_back(i[0]);
            }
            int res=INT_MAX;
            dfs1(0,-1,X,adj,res,nums);
            return res;
            
    }
};