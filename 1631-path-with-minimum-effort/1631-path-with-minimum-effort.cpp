vector<pair<int,int>> moves={{-1,0},{1,0},{0,-1},{0,1}};
bool val(int i,int j,int n,int m){
    return (i>=0 && j>= 0 && i<n && j<m);
}
bool f(vector<vector<int>>&grid,int n,int mid){
    int x,y,m=grid[0].size();
    vector<vector<bool>> vis (n, vector<bool>(m,0));
    queue<pair<int,int>> q;
    vis[0][0]=1;
    q.push({0,0});
    while(q.size()){
        auto p=q.front();
        q.pop();
        for(auto &i: moves){
            x=p.first+i.first;
            y=p.second+i.second;
            if(val(x,y,n,m) && vis[x][y]==0 && abs(grid[x][y]-grid[p.first][p.second])<=mid){
                vis[x][y]=1;
                q.push({x,y});
            }
        }
    }
    return vis[n-1][m-1];
}
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
      int n=grid.size();
        int l=0,h=1e6,m;
        while(l<=h){
            m=(l+h)/2;
            if(f(grid,n,m)){
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return l;   
    }
};