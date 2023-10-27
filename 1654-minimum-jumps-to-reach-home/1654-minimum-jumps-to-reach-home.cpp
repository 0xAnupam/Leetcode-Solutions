const int N=4e4+1;
int dis[N][2];
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        for(int i=0;i<N;i++){
                dis[i][0]=dis[i][1]=INT_MAX;
        }
            for(auto &i:forbidden){
                    dis[i][0]=dis[i][1]=-1;
            }
            priority_queue<vector<int>> pq;
            pq.push({0,0,0});
            dis[0][0]=0;
            while(pq.size()){
                    auto p=pq.top();
                    pq.pop();
                    
                    p[0]*=-1;
                    if(dis[p[1]][p[2]]<p[0]){
                            continue ;
                    }
                    //right
                    if(p[1]+a<N && dis[p[1]+a][0]>1+p[0]){
                            dis[p[1]+a][0]=1+p[0];
                            pq.push({-dis[p[1]+a][0],p[1]+a,0});
                    }
                    //left
                    if(p[2]==0 && p[1]>=b && dis[p[1]-b][1]>1+p[0]){
                            dis[p[1]-b][1]=1+p[0];
                            pq.push({-dis[p[1]-b][1],p[1]-b,1});
                    }
            }
            int res=-1;
            if(dis[x][0]!=INT_MAX){
                    res=dis[x][0];
            }
            if(dis[x][1]!=INT_MAX){
                    if(res==-1){
                            res=dis[x][1];
                    }else{
                            res=min(res,dis[x][1]);
                    }
            }
            return res;
            // return dis[x]==INT_MAX ? -1 : dis[x];
    }
};