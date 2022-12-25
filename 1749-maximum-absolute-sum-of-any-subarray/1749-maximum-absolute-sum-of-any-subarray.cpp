class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        long long res=0,sum=0,sum1=0;
            for(auto &i:nums){
                    sum+=i;
                    sum1-=i;
                    if(sum<0){
                            sum=0;
                    }
                    if(sum1<0){
                            sum1=0;
                    }
              
                    res=max(res,sum);
                    res=max(res,sum1);
            }
            return res;
            
    }
};