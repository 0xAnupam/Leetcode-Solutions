//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
       vector<int> cost(n+1,1e9);
       vector<vector<pair<int,int>>> adj(n+1,vector<pair<int,int>>());
       for(auto &i:flights){
           adj[i[0]].push_back({i[1],i[2]});
       }
       queue<pair<int,int>> q;
       cost[k]=0;
       q.push({k,0});
       while(q.size()){
           auto p=q.front();
           q.pop();
           for(auto &i:adj[p.first]){
               if(cost[i.first]>i.second+p.second){
                   cost[i.first]=i.second+p.second;
                   q.push({i.first,cost[i.first]});
               }
           }
       }
       int res=0;
       for(int i=1;i<=n;i++){
          
           res=max(res,cost[i]);
       }
       return res==1e9 ? -1:res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends