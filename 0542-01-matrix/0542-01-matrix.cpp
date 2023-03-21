vector<pair<int,int>> moves={{0,1},{1,0},{0,-1},{-1,0}};
bool val(int i,int j,int n,int m){
    return (i>=0 && j>=0 && i<n && j<m);
}
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
            queue<pair<int,int>> q;
            int m=mat.size(),n=mat[0].size();
            vector<vector<int>> dis(m,vector<int>(n,1e9));
            for(int i=0;i<m;i++){
                    for(int j=0;j<n;j++){
                            if(mat[i][j]==0){
                                    dis[i][j]=0;
                                    q.push({i,j});
                            }
                    }
            }
            while(q.size()){
                    auto p=q.front();
                    q.pop();
                    for(auto &i:moves){
                           int x=i.first+p.first;
                           int y=i.second+p.second;
                           if(val(x,y,m,n) && dis[x][y]>dis[p.first][p.second]+1){
                                    q.push({x,y});
                                    dis[x][y]=dis[p.first][p.second]+1;
                           }
                    }
                    
            }
            return dis;
    }
};