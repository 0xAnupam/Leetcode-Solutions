const int N=101;
int dp[N][N];
int f(vector<vector<int>>& clips,int idx,int a,int &time,int &n){
        if(a>=time){
                return 0;
        }
        if(idx==n){
                return 1<<7;
        }
        if(dp[idx][a]!=-1){
                return dp[idx][a];
        }
        int res=f(clips,idx+1,a,time,n);
        if(clips[idx][0]<=a){
                return dp[idx][a]=min(res,1+f(clips,idx+1,max(a,clips[idx][1]),time,n));
        }
        return dp[idx][a]=res;
        
        
}
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int n=clips.size();
            sort(clips.begin(),clips.end());
            memset(dp,-1,sizeof(dp));
        int res=f(clips,0,0,time,n);
            return res>n ? -1:res;
    }
};