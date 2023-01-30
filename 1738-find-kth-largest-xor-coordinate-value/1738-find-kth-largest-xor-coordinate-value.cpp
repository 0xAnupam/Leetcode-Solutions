class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m=matrix.size(),n=matrix[0].size();
            for(int j=0;j<n;j++){
                    for(int i=1;i<m;i++){
                            matrix[i][j]^=matrix[i-1][j];
                    }
            }
            vector<int> l;
            for(auto &i:matrix){
                   int x=0;
                    for(auto &j:i){
                            x^=j;
                            l.emplace_back(x);
                    }
            }
            sort(l.rbegin(),l.rend());
            return l[k-1];
    }
};