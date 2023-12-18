vector<pair<int,int>> moves={{0,1},{1,0},{0,-1},{-1,0}};
bool valid(int i,int j,int m,int n){
        return (i>=0 && j>=0 && i<m && j<n);
}
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int k=0;
        int st_x,st_y,m=grid.size(),n=grid[0].size();
            for(int i=0;i<m;i++){
                    for(int j=0;j<n;j++){
                            if(grid[i][j]>='a' && grid[i][j]<='z'){
                                    k++;
                            }
                            else if(grid[i][j]=='@'){
                                    st_x=i,st_y=j;
                            }
                    }
            }
            int mask=(1<<k),res=INT_MAX;
            int dis[m][n][mask];
            for(auto &i:dis){
                    for(auto &j:i){
                            for(auto &x:j)x=INT_MAX;
                    }
            }
            queue<vector<int>> q;
            dis[st_x][st_y][0]=0;
            q.push({0,st_x,st_y,0});
            while(!q.empty()){
                    auto p=q.front();
                    q.pop();
                    int D=p[0],x=p[1],y=p[2],bitmask=p[3];
                    if(dis[x][y][bitmask]<D)continue ;
                    
                    for(auto &xy:moves){
                            int newx=x+xy.first;
                            int newy=y+xy.second;
                            if(valid(newx,newy,m,n) && grid[newx][newy]!='#'){
                                    //lock
                                    if(grid[newx][newy]>='A' && grid[newx][newy]<='Z'){
                                          
                                            if((1<<(grid[newx][newy]-'A')&bitmask) && dis[newx][newy][bitmask]>1+D){
                                                    dis[newx][newy][bitmask]=1+D;
                                                    q.push({1+D,newx,newy,bitmask});
                                            }
                                    }
                                    
                                    else{
                                            int newbitmask=bitmask;
                                            //key
                                            if(grid[newx][newy]>='a' && grid[newx][newy]<='z'){
                                                    newbitmask|=(1<<(grid[newx][newy]-'a'));
                                            }
                                            // rest cells
                                            if(dis[newx][newy][newbitmask]>1+D){
                                                    dis[newx][newy][newbitmask]=1+D;
                                                    q.push({1+D,newx,newy,newbitmask});
                                             }
                                    }
                               }
                            }
                    }
            for(int i=0;i<m;i++){
                    for(int j=0;j<n;j++)res=min(res,dis[i][j][mask-1]);
            }
            return res==INT_MAX ? -1 : res;
    }
};