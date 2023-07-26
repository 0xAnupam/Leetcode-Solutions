class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
            int dis[n];
            priority_queue<pair<int,int>> pq;
            for(int i=0;i<n;i++){
                    dis[i]=1;
                    pq.push({-ratings[i],i});
            }
            while(pq.size()){
                    auto p=pq.top();
                    pq.pop();
                    p.first*=-1;
                    
                    if(p.second && ratings[p.second-1]>ratings[p.second] && dis[p.second-1]<=dis[p.second]){
                            dis[p.second-1]=1+dis[p.second];
                            pq.push({-dis[p.second-1],p.second-1});
                    }
                    if(p.second<n-1 && ratings[p.second+1]>ratings[p.second] && dis[p.second+1]<=dis[p.second]){
                            dis[p.second+1]=1+dis[p.second];
                            pq.push({-dis[p.second+1],p.second+1});
                    }
                    
            }
            int res=0;
            for(int i=0;i<n;i++){
                    res+=dis[i];
            }
            return res;
    }
};