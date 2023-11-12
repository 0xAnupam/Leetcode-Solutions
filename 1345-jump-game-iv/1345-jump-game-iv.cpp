class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>> idx;
            unordered_set<int> s;
            int n=arr.size();
            for(int i=0;i<n;i++){
                    idx[arr[i]].push_back(i);
            }
            vector<int> dis(n,INT_MAX);
            dis[0]=0;
            priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
            pq.push({0,0});
            while(pq.size()){
                    auto p=pq.top();
                    pq.pop();
                    if(s.find(arr[p.second])==s.end()){
                            for(auto &i:idx[arr[p.second]]){
                                    if(dis[i]>1+p.first){
                                            dis[i]=1+p.first;
                                            pq.push({dis[i],i});
                                    }
                            }
                            s.insert(arr[p.second]);
                    }
                    if(p.second && dis[p.second-1]>1+p.first){
                            dis[p.second-1]=1+p.first;
                            pq.push({dis[p.second-1],p.second-1});
                    }
                    if(p.second+1<n && dis[p.second+1]>1+p.first){
                            dis[p.second+1]=1+p.first;
                            pq.push({dis[p.second+1],p.second+1});
                    }
            }
            return dis[n-1];
    }
};