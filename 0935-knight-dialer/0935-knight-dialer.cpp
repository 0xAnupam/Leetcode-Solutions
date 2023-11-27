long long dp[5001][4][3];
class Solution {
public:
vector<pair<int,int>> moves={{-2,1},{-2,-1},{2,-1},{2,1},{1,2},{1,-2},{-1,2},{-1,-2}};     const int mod=1e9+7;
        bool valid(int i,int j,int m,int n){
                return (i>=0 && j>=0 && i<m && j<n);
        }
        long long ways(int i,int j,int m,int n,vector<vector<int>> &board,int k){
                
                if(!valid(i,j,m,n) || board[i][j]==-1){
                        return 0;
                }
                if(k==0){
                        return 1;
                }
                if(dp[k][i][j]!=-1){
                        return dp[k][i][j]%mod;
                }
                long long res=0;
                for(auto &xy:moves){
                        res+=ways(i+xy.first,j+xy.second,m,n,board,k-1)%mod;
                        res%=mod;
                }
                return dp[k][i][j]=res;
                
        }
    int knightDialer(int n) {
            memset(dp,-1,sizeof(dp));
        vector<vector<int>> board(4,vector<int>(3));
        int k=1;
        for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                        board[i][j]=k++;
                }
        }
         board[3][0]=board[3][2]=-1;
         board[3][1]=0;
            long long res=0;
            for(int i=0;i<4;i++){
                    for(int j=0;j<3;j++){
                            if(board[i][j]!=-1){
                                    res+=ways(i,j,4,3,board,n-1)%mod;
                                    res%=mod;
                            }
                    }
            }
                return res;
    }
};