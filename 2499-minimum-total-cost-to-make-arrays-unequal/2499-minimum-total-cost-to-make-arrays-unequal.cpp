class Solution {
public:
    long long minimumTotalCost(vector<int>& n1, vector<int>& n2) {
    long long res = 0, cnt = 0, sz = n1.size();
    unordered_map<int, int> m{{0,0}}; // sentinel
    for (int i = 0; i < sz; ++i)
        if (n1[i] == n2[i]) {
            res += i;
            ++m[n1[i]];
            ++cnt;
        }
        
    int n_cnt=0,n=0;
    for(auto &i:m){
        if(i.second>n_cnt){
            n_cnt=i.second;
            n=i.first;
        }
    }
    long long swaps = 2 * n_cnt - cnt;
    for (int i = 0; swaps > 0 && i < sz; ++i)
        if (n1[i] != n2[i] && n1[i] != n && n2[i] != n) {
            res += i;
            --swaps;
        }
    return swaps > 0 ? -1 : res;
}
};