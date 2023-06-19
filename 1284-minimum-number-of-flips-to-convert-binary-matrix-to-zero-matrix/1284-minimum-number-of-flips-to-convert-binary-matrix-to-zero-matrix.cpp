int score(vector<vector<int>>& mat,int m,int n){
        int r=0;
        for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                        if(mat[i][j]){
                                r|=(1<<(i*m+j));
                        }
                }
        }
        return r;
}
int dp[1<<10];
vector<pair<int,int>> moves={{0,0},{-1,0},{1,0},{0,1},{0,-1}};
bool val(int i,int j,int m,int n){
        return (i>=0 && j>=0 && i<m && j<n);
}
void flipper(vector<vector<int>>& mat,int m,int n,int i,int j){
        for(auto &xy:moves)
        {
                int x=i+xy.first,y=j+xy.second;
                if(val(x,y,m,n)){
                        mat[x][y]=(mat[x][y]+1)&1;
                }
        }
        
}
int f(vector<vector<int>>& mat,int m,int n){
        priority_queue<pair<pair<int,int>,vector<vector<int>>>> pq;
        pq.push({{0,score(mat,m,n)},mat});
        dp[score(mat,m,n)]=0;
        while(pq.size()){
                
                auto p=pq.top();
                pq.pop();
                if(-p.first.first>dp[p.first.second]){
                        continue ;
                }
               
                for(int i=0;i<m;i++){
                        for(int j=0;j<n;j++){
                                flipper(p.second,m,n,i,j);
                                int scr=score(p.second,m,n);
                                if(dp[scr]>1-p.first.first){
                                        dp[scr]=1-p.first.first;
                                        pq.push({{-dp[scr],scr},p.second});
                                }
                                flipper(p.second,m,n,i,j);
                                
                        }
                }
                
        }
        return dp[0];
}
class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        for(int i=0;i<1024;i++){
                dp[i]=1e9;
        }
        int r= f(mat,mat.size(),mat[0].size());  
        return r>=1e9 ? -1:r;
    }
};