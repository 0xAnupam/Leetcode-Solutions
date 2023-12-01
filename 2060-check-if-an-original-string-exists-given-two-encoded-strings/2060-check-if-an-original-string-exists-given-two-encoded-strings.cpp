const int N=1e3+1;
int dp[2*N+1][41][41];
int f(string &a,string &b,int i,int j,int m,int n,int k){
        if(i==m && j==n && k==0)return 1;
        if(dp[N+k][i][j]!=-1){
                return dp[N+k][i][j];
        }
        if(k==0){
                if(i==m || j==n)return 0;
                if(a[i]>='a' && a[i]<='z'){
                        if(b[j]>='a' && b[j]<='z'){
                                return dp[N+k][i][j]=a[i]==b[j] ? f(a,b,i+1,j+1,m,n,k) : 0;
                        }
                        //b digit
                        int idx=j;
                        while(idx<n && b[idx]>='0' && b[idx]<='9')idx++;
                        bool flag=0;
                        int cur=0;
                        for(int l=j;l<idx;l++){
                                cur*=10;
                                cur+=(b[l]-'0');
                                flag|=f(a,b,i,l+1,m,n,k+cur);
                        }
                        return dp[N+k][i][j]=flag;
                }
                else if(b[j]>='a' && b[j]<='z'){
                       //a digit
                        int idx=i;
                        while(idx<m && a[idx]>='0' && a[idx]<='9')idx++;
                        bool flag=0;
                        int cur=0;
                        for(int l=i;l<idx;l++){
                                cur*=10;
                                cur+=(a[l]-'0');
                                flag|=f(a,b,l+1,j,m,n,k-cur);
                        }
                        return dp[N+k][i][j]=flag;
                }
                // else b digit
                int idx=j;
                while(idx<n && b[idx]>='0' && b[idx]<='9')idx++;
                bool flag=0;
                int cur=0;
                for(int l=j;l<idx;l++){
                        cur*=10;
                        cur+=(b[l]-'0');
                        flag|=f(a,b,i,l+1,m,n,k+cur);
                }
                return dp[N+k][i][j]=flag;     
        }
        if(k>0){//deal a
                if(i==m)return 0;
                if(a[i]>='a' && a[i]<='z'){
                        return dp[N+k][i][j]=f(a,b,i+1,j,m,n,k-1);
                }
                // a digit
                int idx=i;
                while(idx<m && a[idx]>='0' && a[idx]<='9')idx++;
                bool flag=0;
                int cur=0;
                for(int l=i;l<idx;l++){
                        cur*=10;
                        cur+=(a[l]-'0');
                        flag|=f(a,b,l+1,j,m,n,k-cur);
                }
                return dp[N+k][i][j]=flag;
        }
        // deal b
        if(j==n)return 0;
        if(b[j]>='a' && b[j]<='z'){
                   return dp[N+k][i][j]= f(a,b,i,j+1,m,n,k+1);     
        }
        // b digit
        int idx=j;
        while(idx<n && b[idx]>='0' && b[idx]<='9')idx++;
        bool flag=0;
        int cur=0;
        for(int l=j;l<idx;l++){
                cur*=10;
                cur+=(b[l]-'0');
                flag|=f(a,b,i,l+1,m,n,k+cur);
        }
        return dp[N+k][i][j]=flag;
}
class Solution {
public:
    bool possiblyEquals(string s1, string s2) {
        int m=s1.size(),n=s2.size();
            memset(dp,-1,sizeof(dp));
            return f(s1,s2,0,0,m,n,0);
    }
};