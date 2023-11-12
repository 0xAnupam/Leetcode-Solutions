class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        int n=nums.size();
            for(int i=0;i<n;i++){
                    while(pq.size() && i-pq.top().second>k){
                            pq.pop();
                    }
                    if(pq.size()){
                            nums[i]+=pq.top().first;
                    }
                    pq.push({nums[i],i});
            }
            return nums[n-1];
    }
};