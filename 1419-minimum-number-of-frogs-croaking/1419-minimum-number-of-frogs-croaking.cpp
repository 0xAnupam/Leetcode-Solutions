class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int n=croakOfFrogs.size();
            if(n%5){
                    return -1;
            }
            set<int> adj[18];
            vector<int> dp(n+1,0);
            string s="croak";
            for(int i=0;i<n;i++){
                    adj[croakOfFrogs[i]-'a'].insert(i);
            }
            set<int> t;
            for(auto &i:s){
                    t.insert(adj[i-'a'].size());
            }
            if(t.size()>1){
                    return -1;
            }
            while(adj[2].size()){
                    int idx=0;
                    for(auto &i:s){
                            auto it=adj[i-'a'].lower_bound(idx);
                            if(it==adj[i-'a'].end()){
                                    return -1;
                            }
                            idx=*it;
                            adj[i-'a'].erase(it);
                            if(i=='c'){
                                    dp[idx]++;
                            }
                    }
                    dp[idx+1]--;
            }
            int res=0,sum=0;
            for(int i=0;i<n;i++){
                    sum+=dp[i];
                    res=max(res,sum);
            }
            return res;
    }
};