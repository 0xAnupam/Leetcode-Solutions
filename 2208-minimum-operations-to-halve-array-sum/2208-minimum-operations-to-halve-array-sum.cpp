class Solution {
public:
    int halveArray(vector<int>& nums) {
        long double sum=0;
            priority_queue<long double > pq;
            for(auto &i:nums){
                    pq.push(i);
                    sum+=i;
            }
            int res=0;
            sum/=2;
            while(sum>1e-2){
                    auto p=pq.top();
                    sum-=(p/2);
                    pq.pop();
                    pq.push(p/2);
                    res++;
            }
            return res;
            
    }
};