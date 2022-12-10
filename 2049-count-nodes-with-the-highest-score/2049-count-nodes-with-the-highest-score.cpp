long long dfs(long long node,vector<vector<int>> &edges,long long n,map<long long,long long> &mp){
        long long l=1;
        long long N=n-1;
        long long p=1;
        for(auto &i:edges[node]){
                long long h=dfs(i,edges,n,mp);
                p*=h;
                N-=h;
                l+=h;
                
        }
       
        if(N==0){
                N++;
        }
        mp[p*N]++;
        return l;
}
class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
            int n=parents.size();
        vector<vector<int>> edges(n+2,vector<int>());
            for(int i=1;i<n;i++){
                    edges[parents[i]].push_back(i);
            }
           
            map<long long,long long> mp;
            dfs(0,edges,n,mp);
            
          auto p=*mp.rbegin();
            
         return p.second;
    }
};