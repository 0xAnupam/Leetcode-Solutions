class Solution {
public:
    int dp[101][101];
    int sum(vector<int>& piles,int ind,int m,int s){
            int n=piles.size();
            if(ind>=n){
                    return s;
            }
            if(dp[ind][m]!=-1){
                    return dp[ind][m];
            }
            int res=0,f=0;
            for(int i=ind;i<min(ind+2*m,n);i++){
                    f+=piles[i];
                    res=max(res,s-sum(piles,i+1,max(m,i-ind+1),s-f));
            }
            return dp[ind][m]=res;
            
    }    
    int stoneGameII(vector<int>& piles) {
        int s=0;
            memset(dp,-1,sizeof(dp));
        for(int &i:piles){s+=i;}
            return sum(piles,0,1,s);
    }
};