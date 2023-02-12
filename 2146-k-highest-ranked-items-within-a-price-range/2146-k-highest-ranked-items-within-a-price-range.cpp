vector<pair<int,int>> moves={{-1,0},{1,0},{0,1},{0,-1}};
bool valid(int i,int j,int &m,int &n){
        return (i>=0 && j>=0 && i<m && j<n);
}
struct Node{
        int a,b,d;
        Node(int a,int b,int d){
                this->a=a;
                this->b=b;
                this->d=d;
        }
};
class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int m=grid.size(),n=grid[0].size();
            vector<vector<int>> dis(m,vector<int>(n,1e9));
            queue<Node*> q; 
            q.push(new Node(start[0],start[1],0));
            dis[start[0]][start[1]]=0;
            int x,y;
            while(q.size()){
                    auto p=q.front();
                    q.pop();
                    for(auto &i:moves){
                            x=p->a+i.first;
                            y=p->b+i.second;
                            if(valid(x,y,m,n) && grid[x][y] && dis[x][y]>1+p->d){
                                    dis[x][y]=1+p->d;
                                    q.push(new Node(x,y,dis[x][y]));
                            }
                    }
            }
            vector<vector<int>> v;
            for(int i=0;i<m;i++){
                    for(int j=0;j<n;j++){
                            if(grid[i][j]>=pricing[0] && grid[i][j]<=pricing[1] && dis[i][j]<1e9){
                                    v.push_back({{dis[i][j]},grid[i][j],i,j});
                            }
                    }
                    
            }
            sort(v.begin(),v.end());
            k=min(k,(int)v.size());
            vector<vector<int>> res;
            for(int i=0;i<k;i++){
                    res.push_back({{v[i][2]},{v[i][3]}});
            }
            return res;
    }
       
};