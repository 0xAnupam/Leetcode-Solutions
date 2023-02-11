bool valid(int i,int j,int &m,int &n){
        return (i>=0 && j>=0 && i<m && j<n);
}
vector<pair<int,int>> moves ={{-1,0},{1,0},{0,1},{0,-1}};
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
            vector<vector<int>> dis(m,vector<int>(n,1e9));
            queue<pair<int,int>> q;
            for(int i=0;i<m;i++){
                    for(int j=0;j<n;j++){
                            if(grid[i][j]){
                                    q.push({i,j});
                                    dis[i][j]=0;
                            }
                    }
            }int x,y,res=0;
            while(q.size()){
                    auto p=q.front();
                    q.pop();
                    for(auto &i:moves){
                           x=i.first+p.first;
                           y=i.second+p.second;
                            if(valid(x,y,m,n) && dis[x][y]>dis[p.first][p.second]+1){
                                    q.push({x,y});
                                    dis[x][y]=dis[p.first][p.second]+1;
                            }
                            
                    }
            }
            for(auto &i:dis){
                    for(auto &j:i){
                            res=max(res,j);
                    }
            }
            return (res==0 || res==1e9) ? -1:res;
    }
};