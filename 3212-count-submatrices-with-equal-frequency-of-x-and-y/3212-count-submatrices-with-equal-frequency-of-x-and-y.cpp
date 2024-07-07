class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> x(m,vector<int>(n,0)),y=x;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='X'){
                    x[i][j]=1;
                }
                else if(grid[i][j]=='Y'){
                    y[i][j]=1;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++)x[i][j]+=x[i][j-1],y[i][j]+=y[i][j-1];
        }
        for(int j=0;j<n;j++){
            for(int i=1;i<m;i++)x[i][j]+=x[i-1][j],y[i][j]+=y[i-1][j];
        }
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(x[i][j] && x[i][j]==y[i][j])res++;
            }
        }
        return res;
    }
};