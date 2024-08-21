class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n=wall.size();
        map<int,int> mp;
        int ans=n,d;
        for(auto &i:wall){
            int s=0;
            for(auto &j:i)s+=j,mp[s]++;
            d=s;
        }
        for(auto &i:mp){
            if(i.first==d)continue ;
            ans=min(ans,n-i.second);
        }
        return ans;
    }
};