class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),res=0;
            vector<int> l(m),r(n);
            int k=0;
            for(auto &i:grid){
                    int maxi=0;
                    for(auto &j:i){
                            maxi=max(j,maxi);
                    }
                    l[k++]=maxi;
            }
            for(int j=0;j<n;j++){
                    int maxi=0;
                    for(int i=0;i<m;i++){
                            maxi=max(maxi,grid[i][j]);
                    }
                    r[j]=maxi;
            }
            for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                            res+=(min(r[j],l[i])-grid[i][j]);
                           
                    }
                   
            }
            return res;
    }
};