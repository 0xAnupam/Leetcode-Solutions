int dp[1001][1002];
int f(vector<pair<int,int>> &p,int idx,int n,int max_age){
        if(idx==n){
                return 0;
        }
        if(dp[idx][max_age]!=-1){
                return dp[idx][max_age];
        }
        if(p[idx].second==max_age){
                return dp[idx][max_age]=p[idx].first+f(p,idx+1,n,max_age);
        }
        if(p[idx].second>max_age){
                return dp[idx][max_age]=f(p,idx+1,n,max_age);
        }
        return dp[idx][max_age]=max(p[idx].first+ f(p,idx+1,n,min(p[idx].second,max_age)),f(p,idx+1,n,max_age));
}

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> p;
            memset(dp,-1,sizeof(dp));
            int n=ages.size();
            for(int i=0;i<n;i++){
                    p.push_back({scores[i],ages[i]});
            }
            sort(p.rbegin(),p.rend());
            return f(p,0,n,1e3+1);
    }
};