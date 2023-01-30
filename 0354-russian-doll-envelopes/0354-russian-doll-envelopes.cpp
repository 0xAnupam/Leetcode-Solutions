int lis(vector<vector<int>> & a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int l = upper_bound(d.begin(), d.end(), a[i][0]) - d.begin();
        if (d[l-1] < a[i][0] && a[i][0] < d[l])
            d[l] = a[i][0];
    }

    int ans = 0;
    for (int l = 0; l <= n; l++) {
        if (d[l] < INF)
            ans = l;
    }
    return ans;
}
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[](const vector<int>&a,const vector<int>&b){
           if(a[1]==b[1]){
                   return a[0]>b[0];
           }     
           return a[1]<b[1];     
        });
            
            return lis(envelopes);
    }
};