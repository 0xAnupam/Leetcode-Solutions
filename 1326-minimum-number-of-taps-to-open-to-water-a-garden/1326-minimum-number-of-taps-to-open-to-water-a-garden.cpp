int* dp;
class Solution {
public:
    int minTaps(int n, vector<int>& ranges)
    {
        dp=new int[n+2];
        for(int i=0 ; i<=n+1 ; i++)
        {
            
            
            dp[i]=1e8;
        }
        dp[0]=0;
        int new_dp[n+2];
        for(int i=1 ; i<=n+1 ; i++)
        {
              
            new_dp[0]=0;  
            for(int j=max(0,i-1-ranges[i-1] ); j<=n ; j++)
            {   
                int off=dp[j];
                int on=1e8;
                if(i-1-ranges[i-1]<j && i-1+ranges[i-1]>=j)
                on=1+dp[max(i-1-ranges[i-1] , 0)];
                new_dp[j]=min(on , off);
                dp[j]=new_dp[j];
                if(i-1+ranges[i-1]<j){
                        break;
                }
            }
            
            
        }
        int val=dp[n];
        if(val>=1e8)
        val=-1;
        return val;
    }
};