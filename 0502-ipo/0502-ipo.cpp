class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> v;
        int n =capital.size();
        for(int i=0;i<n;i++){
            v.push_back({capital[i],profits[i]});
        }
        sort(v.begin(),v.end());
        long long res=0;
        int i=0;
        priority_queue<int> pq;
        while(k &&i<n){
            while(i<n && v[i].first<=w){
                pq.push(v[i++].second);
            }
            if(pq.size()==0){
                return w;
            }
            while(pq.size() && k){
                k--;
                w+=pq.top();
                pq.pop();
                while(k && i<n && v[i].first<=w){
                pq.push(v[i++].second);
            }    
            }
        }
        return w;
    }
};