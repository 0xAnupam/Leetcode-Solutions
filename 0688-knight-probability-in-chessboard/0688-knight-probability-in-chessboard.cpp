
long double dp[26][26][101];
class Solution {
public: 
        vector<pair<int,int>> moves ={{-2,1},{-2,-1},{2,-1},{2,1},{1,2},{1,-2},{-1,2},{-1,-2}};
        bool valid(int n,int i,int j){
                return (i>=0 && j>=0 && i<n && j<n);
        }
        
        long double knight(int n, int k,int r, int c){
                
                if(!valid(n,r,c)){
                        return 0;
                }
                
                
                if(k==0){
                        return 1;
                }
                if(dp[r][c][k]+1>1e-2){
                        return dp[r][c][k];
                }
                long double res=0; 
                
                for(auto &xy:moves){
                      
                        res+=knight(n,k-1,r+xy.first,c+xy.second);
                }
                long double p=8;
                return dp[r][c][k]=(res/8);
        }
    double knightProbability(int n, int k, int row, int column) {
           memset(dp,-1,sizeof(dp));
            long double ways=knight(n,k,row,column),p=8;
            // for(int i=0;i<k;i++){
            //         ways/=p;
            // }
            
            return ways;
    }
};