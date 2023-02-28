class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
            if(goal==0){
                    int res=0;
                    int cnt=0;
                    for(auto &i:nums){
                            if(i==0){
                                    cnt++;
                            }
                            else{
                                    res+=(cnt*(cnt+1))/2;
                                    cnt=0;
                            }
                    }
                  res+=(cnt*(cnt+1))/2;
                    return res;
            }
      int sum=0,bsum=0;
            int n=nums.size();
            vector<int> l,r;
            for(int i=0;i<n;i++){
                    sum++;
                    bsum++;
                    if(nums[i]==1){
                            l.push_back(sum);
                            sum=0;
                    }
                   
                    if(nums[n-1-i]==1){
                            r.push_back(bsum);
                            bsum=0;
                    }  
            }
            
            int res=0;
            reverse(r.begin(),r.end());
            n=l.size();
            for(int i=goal-1;i<n;i++){
                    res+=l[i-goal+1]*r[i];
            }
            return res;
        
    }
};