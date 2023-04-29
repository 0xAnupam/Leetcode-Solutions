bool valid(int i,int j,int m,int n){
        return (i>=0 && j>=0 && i<m && j<n);
}
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
            if(grid[0][0]){
                    return -1;
            }
        int m=grid.size(),n=grid[0].size();
            vector<vector<int>> dis(m,vector<int>(n,(int)1e9));
            priority_queue<pair<int,pair<int,int>>> pq;
            dis[0][0]=1;
            pq.push({-1,{0,0}});
            int x,y,d;
            while(pq.size()){
                    auto p=pq.top();
                    pq.pop();
                    x=p.second.first;
                    y=p.second.second;
                    d=-p.first;
                    if(dis[x][y]<d){
                            continue ;
                    }
                    for(int i=-1;i<=1;i++){
                            for(int j=-1;j<=1;j++){
                                    if(valid(x+i,y+j,m,n) && grid[x+i][y+j]==0 && dis[x+i][y+j]>1+d){
                                            dis[x+i][y+j]=d+1;
                                            pq.push({-dis[x+i][y+j],{x+i,y+j}});
                                    }
                            }
                    }
                    
            }
            return dis[m-1][n-1]==(int)1e9 ? -1:dis[m-1][n-1];
            
    }
};