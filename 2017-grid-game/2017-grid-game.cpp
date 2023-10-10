class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long res=LLONG_MAX,a=0,b=0;
            for(auto &i:grid[0]){
                    b+=i;
            }
            int n=grid[0].size();
            for(int i=0;i<n;i++){
                    b-=grid[0][i];
                    res=min(res,max(a,b));
                    a+=grid[1][i];
            }
            return res;
    }
};