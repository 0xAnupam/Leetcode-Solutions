// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

struct node{
                int x;
                int y;
                int d;
                int k;
                node(int m,int n,int o){
                        x=m;
                        y=n;
                        d=o;
                    
                }
        };
        vector<pair<int,int>> moves {{0,-1},{0,1},{-1,0},{1,0}};
    bool valid(int i,int j,int m,int n){ 
        return (i>=0 && j>=0 && i<m && j<n);
    }
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{ int m=grid.size(),n=grid[0].size();
     // swap(n,m);
            vector<vector<int>> dis(m,vector<int>(n,1e9));
           // vector<vector<int>> KK(m,vector<int>(n,-1));
          queue<node*> q;
            // q.push(new node(0,0,0));
            // dis[0][0]=0;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]){
                        q.push(new node(i,j,0));
                        dis[i][j]=0;
                    }
                }
            }
            while(q.size()){
                    auto p=q.front();
                    q.pop();
                    for(auto &i:moves){
                            int newx=i.first+p->x,
                            newy=i.second+p->y;
                          if(valid(newx,newy,m,n) && (dis[newx][newy]>p->d+1) ){
                                 
                                  dis[newx][newy]=p->d+1;
                                  q.push(new node(newx,newy,p->d+1));
                          }  
                    }
                    
            }
	return dis;
 	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends