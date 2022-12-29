string rev(string s){
        string r="";
        for(auto &i:s){
                r+=(i-'0'+1)%2+'0';
        }
        return r;
}
class Solution {
public:
        
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<string,int> mp;
        int m=matrix.size(),n=matrix[0].size();
            for(int i=0;i<m;i++){
                    string r="";
                    for(int j=0;j<n;j++){
                            r+=('0'+matrix[i][j]);
                    }
                    mp[r]++;
            }
            int res=0;
            for(auto &i:mp){
                    res=max(res,i.second+mp[rev(i.first)]);
            }
            return res;
            
    }
};