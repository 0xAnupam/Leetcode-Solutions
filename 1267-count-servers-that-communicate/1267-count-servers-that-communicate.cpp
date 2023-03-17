class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int res=0;
            int m=grid.size(),n=grid[0].size();
            vector<int> vis(m,0);
            for(int i=0;i<m;i++){
                    int cnt=0;
                    for(auto &j:grid[i]){
                            cnt+=j;
                    }
                    if(cnt>1){
                            res+=cnt;
                            vis[i]=1;
                    }
            }
            for(int j=0;j<n;j++){
                    int cnt=0,a=0;
                    for(int i=0;i<m;i++){
                        if(grid[i][j]){
                                cnt++;
                                a+=vis[i];
                        }       
                    }
                    if(cnt>1){
                            res+=(cnt-a);
                    }
            }
            return res;
    }
};