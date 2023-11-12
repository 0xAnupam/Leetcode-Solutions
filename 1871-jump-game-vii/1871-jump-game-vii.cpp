class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
            vector<int> dp(2*n+1,0);
            dp[0]=1;
            dp[1]=-1;
            int sum=0;
            int i=0;
            while(i<n){
                sum+=dp[i];
                    if(s[i]=='0' && sum>0){
                            dp[i+minJump]++;
                            dp[i+maxJump+1]--;
                            if(i==n-1){
                                    return 1;
                            }
                    }
                    
                    i++;
            }
            return 0;
    }
};