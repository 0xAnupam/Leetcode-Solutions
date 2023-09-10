class Solution {
public:
bool f(unordered_map<long long,int>& umap, vector<vector<int>>& dp, vector<int>& stones, int i, int prev, int n)
{
    if(i==n-1)return true;
    if(dp[i][prev]!=-1)return dp[i][prev];
    bool ans = false;
    bool found1 = false, found2 = false, found3 = false;
        
    int k = max((stones[i]-stones[prev]),1);
    cout<<i<<endl;
    if(umap.find(k+stones[i])!=umap.end())found1= true;
    if(umap.find(k-1+stones[i])!=umap.end())found2= true;
    if(umap.find(k+1+stones[i])!=umap.end())found3= true;
    if(found1 && umap[k+stones[i]]>i && f(umap,dp,stones,umap[k+stones[i]],i,n))
    {
        return dp[i][prev]=true;
    }
    if(found2 && umap[k-1+stones[i]]>i && f(umap,dp,stones,umap[k-1+stones[i]],i,n))
    {
        return dp[i][prev]=true;
    }
    if(found3 && umap[k+1+stones[i]]>i && f(umap,dp,stones,umap[k+1+stones[i]],i,n))
    {
        return dp[i][prev]=true;
    }
    return dp[i][prev] = ans;
}
    bool canCross(vector<int>& stones) {
       unordered_map<long long,int> umap;
       for(int i=0;i<stones.size();i++)umap[stones[i]]=i;
       int n = stones.size();
       vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
       bool ans=0;
       if(stones[1]==1){
               ans=f(umap,dp,stones,1,0,n);
       } 
            return ans;
    }
};