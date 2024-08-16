class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        map<int,int> mp;
        int n=arrays.size();
        int res=0;
        int a=arrays[0].back(),b=arrays[0][0];
        for(int i=1;i<n;i++){
            res=max(res,max(abs(a-arrays[i][0]),abs(arrays[i].back()-b)));
            a=max(a,arrays[i].back());
            b=min(b,arrays[i][0]);
        }
        return res;
    }
};