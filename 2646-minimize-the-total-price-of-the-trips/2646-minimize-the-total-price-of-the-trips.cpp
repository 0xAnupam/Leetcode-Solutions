int dp[51][2];
int f(vector<vector<int>> &edges,vector<int>&price,vector<int> &weight,int pos,int node ,int par){
        if(dp[node][pos]!=-1){
            return dp[node][pos];
        }
    
        int res=0;
        for(auto &i:edges[node]){
            if(i!=par){
                res+=(f(edges,price,weight,1,i,node));
            }
        }
        if(!pos){
        return dp[node][pos]=price[node]*weight[node]+res;
        }
        int r=0;
        for(auto &i:edges[node]){
            if(i!=par){
                r+=(f(edges,price,weight,0,i,node));
               
            }
        }
        return dp[node][pos]=min(res+ price[node]*weight[node],r+ (price[node]*weight[node])/2);
        
    
    
}
void dfs(int node,int par,vector<vector<int>> &adj,vector<vector<int>> &path,vector<int> &temp){
    temp.push_back(node);
    path[node]=temp;
    for(auto &i:adj[node]){
        if(i!=par){
            dfs(i,node,adj,path,temp);
        }
    }
    temp.pop_back();
}
class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> adj(n,vector<int>()),path(n);
        for(auto &i:edges){
            adj[i[0]].emplace_back(i[1]);
            adj[i[1]].emplace_back(i[0]);
        }
        vector<int> t;
        dfs(0,-1,adj,path,t);
        vector<int> weight(n,0);
        for(auto &i:trips){
            int A=0,B=0;
            int N=path[i[0]].size(),M=path[i[1]].size();
            while(A<N && B<M && path[i[0]][A]==path[i[1]][B]){
                A++;
                B++;
            }
            A--;
            while(A<N){
                weight[path[i[0]][A]]++;
                A++;
            }
            while(B<M){
                weight[path[i[1]][B]]++;
                B++;
            }
        }
        memset(dp,-1,sizeof(dp));
        return f(adj,price,weight,1,0,-1);
        
    }
};