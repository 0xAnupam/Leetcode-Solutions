class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
            vector<int> x,y;
            for(int i=0;i<m;i++){
                    int a=0;
                    for(auto &j:grid[i]){
                            if(j){a++;}
                            else{a--;}
                    }
                    x.emplace_back(a);
            }
            for(int i=0;i<n;i++){
                    int a=0;
                    for(int j=0;j<m;j++){
                            if(grid[j][i]){a++;}
                            else{a--;}
                    }
                    y.emplace_back(a);
            }
            for(int i=0;i<m;i++){
                    for(int j=0;j<n;j++){
                            grid[i][j]=x[i]+y[j];
                    }
            }
            return grid;
    }
};