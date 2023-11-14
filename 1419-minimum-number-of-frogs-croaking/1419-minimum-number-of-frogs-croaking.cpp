class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int n=croakOfFrogs.size();
            if(n%5){
                    return -1;
            }
            vector<int> adj[18];
            vector<int> dp(n+1,0);
            vector<int> gg(18,0);
            string s="croak";
            for(int i=0;i<n;i++){
                    adj[croakOfFrogs[i]-'a'].emplace_back(i);
            }
            set<int> t;
            for(auto &i:s){
                    t.insert(adj[i-'a'].size());
            }
            if(t.size()>1){
                    return -1;
            }
            int K=n/5;
            while(K--){
                    int idx=0;
                    for(auto &i:s){
                            int index=gg[i-'a']++;
                            if(index>=adj[i-'a'].size()){
                                    return -1;
                            }
                            if(adj[i-'a'][index]<idx){
                                    return -1;
                            }
                            idx=adj[i-'a'][index];
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