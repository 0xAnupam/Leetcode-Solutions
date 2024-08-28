int dist(vector<int> *maxi , int n){
    vector<int> dis(n,n);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    dis[0]=0;
    while(pq.size()){
        auto p=pq.top();
        pq.pop();
        if(dis[p.second]<p.first)continue ;
        if(p.second==n-1)return p.first;
        for(auto &i:maxi[p.second]){
            if(dis[i]>1+p.first){
                dis[i]=1+p.first;
                pq.push({1+p.first,i});
            }
        }
    }
    return dis.back();
}
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> maxi[n];
        for(int i=0;i<n-1;i++)maxi[i].push_back(i+1);
        int q=queries.size();
        vector<int> res(q);
        for(int i=0;i<q;i++){
            maxi[queries[i][0]].push_back(queries[i][1]);
            res[i]=dist(maxi,n);
        }
        return res;
    }
};