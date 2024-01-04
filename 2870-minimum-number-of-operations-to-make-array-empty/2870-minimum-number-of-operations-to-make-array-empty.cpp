const int N=1e5+1;
int dp[N];
int f(int n){
        if(n==0){
                return 0;
        }
        if(n==1){
                return 1e6;
        }
        if(n<4){
                return 1;
        }
        if(dp[n]!=-1){
                return dp[n];
        }
        return dp[n]=1+min(f(n-2),f(n-3));
}

class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> mp;
            int res=0;
            for(auto &i:nums){
                    mp[i]++;
            }
            memset(dp,-1,sizeof(dp));
            for(auto &i:mp){
                    if(i.second==1){
                            return -1;
                    }
                    res+=f(i.second);
            }
            return res;
    }
};