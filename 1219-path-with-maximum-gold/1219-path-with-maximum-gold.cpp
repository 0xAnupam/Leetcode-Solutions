vector<pair<int,int>> moves={{-1,0},{1,0},{0,-1},{0,1}};
bool val(int i,int j,int n,int m){
    return (i>=0 && j>= 0 && i<n && j<m);
}
int dfs(int i,int j,int n,int m,vector<vector<int>>& grid){
        if(!val(i,j,n,m)){
                return 0;
        }
        if(grid[i][j]==0){
                return 0;
        }
        int res=grid[i][j];
        grid[i][j]=0;
        int k=0;
        for(auto &xy:moves){
                k=max(k,dfs(i+xy.first,j+xy.second,n,m,grid));
        }
        grid[i][j]=res;
        return res+k;
}
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
            int res=0;
            for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                            if(grid[i][j]){
                                    res=max(res,dfs(i,j,n,m,grid));
                            }
                    }
            }
            return res;
    }
};