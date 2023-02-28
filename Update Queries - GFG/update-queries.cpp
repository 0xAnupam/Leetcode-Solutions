//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> updateQuery(int N,int Q,vector<vector<int>> &U)
        {  
           vector<int> res(N),f(18,0);
           vector<vector<int>> arr(N+1,vector<int> (18,0));
           for(int i=0;i<Q;i++){
              
               for(int j=0;j<18;j++){
                   if((1<<j)&(U[i][2])){
                         arr[U[i][0]-1][j]++;
                         arr[U[i][1]][j]--;    
                   }
               }
           }
           for(int i=0;i<N;i++){
               int r=0;
              for(int j=0;j<18;j++){
                  f[j]+=arr[i][j];
                  if(f[j]){
                      r|=(1<<j);
                  }
              }
               res[i]=r;
           }
           return res;
            
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector <vector <int>> u(q,vector <int>(3));
        for(int i=0;i<q;i++)
            cin>>u[i][0]>>u[i][1]>>u[i][2];
        Solution a;
        vector <int> ans=a.updateQuery(n,q,u);//<<endl;
        for(auto j:ans)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends