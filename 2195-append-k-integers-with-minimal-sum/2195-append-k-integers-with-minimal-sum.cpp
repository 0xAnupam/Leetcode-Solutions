class Solution {
public:
    long long minimalKSum(vector<int>& nums, long long k) {
       sort(nums.begin(),nums.end());
            long long sum=0,prev=0;
            for(auto &i:nums){
                    long long p=min(k,max(0LL,i-prev-1));
                    sum+=((prev+p+1)*(prev+p))/2-((prev+1)*(prev))/2;
                    k-=p;
                    prev=i;     
            }
            sum+=((prev+k+1)*(prev+k))/2-((prev+1)*(prev))/2;
            return sum;
            
    }
};