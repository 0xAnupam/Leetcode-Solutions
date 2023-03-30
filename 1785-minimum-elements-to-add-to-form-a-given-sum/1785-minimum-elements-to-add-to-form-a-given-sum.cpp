class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
       
            long long sum=0;
            int res=0;
            for(auto &i:nums){
                    sum+=i;
            }
            if(sum==goal){
                    return 0;
            }
            if(goal>sum){
                   long long p=goal-sum;
                    res=(p+limit-1)/limit;
                    return res;
            }
            long long p=goal-sum;
                    res=(-p+limit-1)/limit;
        return res;
    }
};