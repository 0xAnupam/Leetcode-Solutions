int score(vector<int> &a,vector<int> &b){
        int res=0;
        int i=0,n=a.size();
        while(i<n){
                res+=(a[i]==b[i]);
                i++;
        }
        return res;
}
int dp[8][512];
int f(vector<vector<int>>& students, vector<vector<int>>& mentors,int idx,int cur,int n){
        if(idx==n){
                return 0;
        }
        if(dp[idx][cur]!=-1){
                return dp[idx][cur];
        }
        int res=0;
        for(int i=0;i<n;i++){
                if(((1<<i)&cur)==0){
                        res=max(res,score(students[idx],mentors[i])+f(students,mentors,idx+1,(cur+(1<<i)),n));
                }
        }
        return dp[idx][cur]=res;
}
class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n=students.size();
            memset(dp,-1,sizeof(dp));
            return f(students,mentors,0,0,n);
    }
};