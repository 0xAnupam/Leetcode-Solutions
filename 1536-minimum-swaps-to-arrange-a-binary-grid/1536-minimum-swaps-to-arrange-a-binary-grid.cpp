bool omk(vector<int>&grid,int idx,int n){
        for(int i=idx;i<n;i++){
                if(grid[i])return 0;
        }
        return 1;
}
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size(),res=0;
            for(int i=0;i<n-1;i++){
                    int j=i;
                    while(j<n && !omk(grid[j],i+1,n)){
                            j++;
                    }
                    if(j==n)return -1;
                    res+=(j-i);
                    for(int k=j;k>i;k--){
                            swap(grid[k-1],grid[k]);
                    }
                    
            }
            return res;
    }
};