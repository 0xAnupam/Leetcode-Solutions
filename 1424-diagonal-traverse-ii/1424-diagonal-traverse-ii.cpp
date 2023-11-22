class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> res;
            queue<pair<int,int>> q;
            int n=nums.size();
            q.push({0,0});
            while(q.size()){
                    auto p=q.front();
                    q.pop();
                    res.emplace_back(nums[p.first][p.second]);
                    if(p.second==0 && p.first+1<n){
                            q.push({p.first+1,p.second});
                            
                    }
                     if(nums[p.first].size()>1+p.second){
                            q.push({p.first,1+p.second});
                    }
            }
            return res;
    }
};