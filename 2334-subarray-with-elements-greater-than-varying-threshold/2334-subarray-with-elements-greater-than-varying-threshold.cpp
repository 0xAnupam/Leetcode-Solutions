class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
          stack<pair<long long,long long>> s;
        long long n=nums.size();
        vector<long long> left(n),right(n);
        for(long long i=0;i<n;i++){
                
                left[i]=i;
                long long l=i;
                while(s.size() && s.top().first>=nums[i]){
                        l=s.top().second;
                        s.pop();
                }
                s.push({nums[i],i});
                left[i]=left[l];
        }
            stack<pair<long long,long long>> q;
            for(long long i=n-1;i>=0;i--){
                    
                    long long r=i;
                    right[i]=i;
                    while(q.size() && q.top().first>=nums[i]){
                            r=q.top().second;
                            q.pop();
                    }
                    q.push({nums[i],i});
                    right[i]=right[r];
            }
            long long i=0;
            while(i<n){
                    long long t=right[i]-left[i];
                    long long p=(threshold)/nums[i];
                    if(t>=p){
                            return p+1;
                    }
                    p=nums[i];
                    while(i<n && nums[i]==p){
                            i++;
                    }
            }
            return -1;
            
    }

};