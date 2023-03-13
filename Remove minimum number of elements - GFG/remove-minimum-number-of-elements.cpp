//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int minRemove(int a[], int b[], int n, int m) {
        const int N=1e5+1;
        int fa[N],fb[N];
        memset(fa,0,sizeof(fa));
        memset(fb,0,sizeof(fb));
        for(int i=0;i<n;i++){
            fa[a[i]]++;
        }
        for(int i=0;i<m;i++){
            fb[b[i]]++;
        }
        int res=0;
        for(int i=0;i<N;i++){
            res+=min(fa[i],fb[i]);
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int a[n], b[m];
        for (i = 0; i < n; i++) cin >> a[i];
        for (i = 0; i < m; i++) cin >> b[i];
        Solution obj;
        cout << obj.minRemove(a, b, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends