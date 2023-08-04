
int f(int &res,string &s,int node,char p,vector<vector<int>> &adj){
        if(s[node]==p){
                f(res,s,node,'.',adj);
                return 0;
        }
        int maxi=0,s_maxi=0;
        for(auto &i:adj[node]){
                int r=f(res,s,i,s[node],adj);
                if(r>maxi){
                        s_maxi=maxi;
                        maxi=r;
                }
                else if(r>s_maxi){
                        s_maxi=r;
                }
        }
        res=max(res,maxi+s_maxi+1);
        return 1+maxi;
}
class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n=s.size();
            vector<vector<int>> adj(n);
            for(int i=1;i<n;i++){
                    adj[parent[i]].emplace_back(i);
            }
            int res=0;
            f(res,s,0,'.',adj);
            return res;
    }
};