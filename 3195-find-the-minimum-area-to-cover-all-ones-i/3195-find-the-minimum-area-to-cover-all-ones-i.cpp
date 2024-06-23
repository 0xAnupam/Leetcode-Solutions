class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
     int minX=1e9,minY=1e9,maxX=0,maxY=0;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    minX=min(minX,i);
                    minY=min(minY,j);
                    maxX=i;
                    maxY=max(maxY,j);
                }
            }
        }
        return (maxX-minX+1)*(maxY-minY+1);
    }
};