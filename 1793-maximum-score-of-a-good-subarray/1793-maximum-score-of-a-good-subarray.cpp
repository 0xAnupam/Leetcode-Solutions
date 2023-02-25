class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        stack<pair<int,int>> s;
        int n=nums.size();
        vector<int> left(n),right(n);
        vector<long long> prefix_sum(n);
            long long sum=0;
        for(int i=0;i<n;i++){
                sum+=nums[i];
                left[i]=i;
                prefix_sum[i]=sum;
                s.push({nums[i],i});
                int l=0;
                while(s.size() && s.top().first>=nums[i]){
                        l=s.top().second;
                        s.pop();
                }
                s.push({nums[i],i});
                left[i]=left[l] ;
        }
            stack<pair<int,int>> q;
            for(int i=n-1;i>=0;i--){
                    q.push({nums[i],i});
                    int r=0;
                    right[i]=i;
                    while(q.size() && q.top().first>=nums[i]){
                            r=q.top().second;
                            q.pop();
                    }
                    q.push({nums[i],i});
                    right[i]=right[r];
            }
            long long res=0;
            for(int i=0;i<n;i++){
                    if(left[i]<=k && right[i]>=k){
                             sum=right[i]-left[i]+1;
                             sum*=(1LL*nums[i]);
                             res=max(res,sum);
                    }
            }
           
            return res;
    }
};