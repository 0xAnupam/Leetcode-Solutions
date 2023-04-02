class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        set<pair<int,int>> s;
            int n=nums.size();
            for(int i=0;i<n-k+1;i++){
                    s.insert({nums[i],i});
            }
            int idx=-1;
            vector<int> res;
            int i=n-k+1;
            auto it=s.begin();
            idx=(*it).second;
            res.push_back((*it).first);
            pair<int,int> to_rem[n+1];
            while(i<n){
                   int l=0;
                    
                    s.insert({nums[i],i});
                    auto it=s.begin();
                    while((*it).second<=idx){
                            l++;
                            it++;
                    }
                    while(l--){
                            s.erase(s.begin());
                    }
                    res.push_back((*s.begin()).first);
                    idx=(*s.begin()).second;
                    i++;
                    
            }
            return res;
    }
};