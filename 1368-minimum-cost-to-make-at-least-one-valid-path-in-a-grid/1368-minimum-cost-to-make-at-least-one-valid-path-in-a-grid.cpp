vector<pair<int,int>> moves ={{0,1},{0,-1},{1,0},{-1,0}};
bool valid(int i,int j,int m,int n){
        return (i>=0 && j>=0 && i<m && j<n);
}
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
            int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dis(m,vector<int>(n,1e9));
            queue<pair<pair<int,int>,int>> q;
            q.push({{0,0},0});
            dis[0][0]=0;
            int x,y;
            while(q.size()){
                    auto p=q.front();
                    q.pop();
                    x=p.first.first+moves[grid[p.first.first][p.first.second]-1].first;
                    y=p.first.second+moves[grid[p.first.first][p.first.second]-1].second;
                    if(valid(x,y,m,n) && dis[x][y]>p.second){
                            dis[x][y]=p.second;
                            q.push({{x,y},p.second});
                    }
                    for(auto &i:moves){
                             x=p.first.first+i.first;
                             y=p.first.second+i.second;
                             if(valid(x,y,m,n) && dis[x][y]>1+p.second){
                                     dis[x][y]=1+p.second;
                                     q.push({{x,y},1+p.second});
                             }
                    }
                    
            }
            return dis[m-1][n-1];
    }
};