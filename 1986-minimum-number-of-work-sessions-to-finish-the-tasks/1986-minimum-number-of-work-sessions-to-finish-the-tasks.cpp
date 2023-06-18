int dp[16][1<<14];
int Time;
int f(vector<int> &task,int not_taken,int n,int t){
        if(not_taken==0){
                return 0;
        }
        if(dp[t][not_taken]!=-1){
                return dp[t][not_taken];
        }
        
        int res=n;
        for(int i=0;i<n;i++){
                if((1<<i)&not_taken ){
                        if(t+task[i]<=Time){
                                res=min(res,(t==0)+f(task,(not_taken)^(1<<i),n,t+task[i]));
                        }
                        res=min(res,1+f(task,(not_taken)^(1<<i),n,task[i]));
                }
        }
        return dp[t][not_taken]=res;
}
class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        Time=sessionTime;
        int n=tasks.size();
            memset(dp,-1,sizeof(dp));
            int not_taken=(1<<n)-1;
            return f(tasks,not_taken,n,0);
            
    }
};