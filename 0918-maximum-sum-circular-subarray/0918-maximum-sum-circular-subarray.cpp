class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        multiset<int> a,b;
         a.insert(-1e9);
        b.insert(0);
            int sum=0,n=nums.size();
            vector<int> arr;
            for(auto &i:nums){
                    sum+=i;
                    a.insert(sum);
                    arr.push_back(sum);
            }
            sum=0;
            int res=*(a.rbegin());
            for(int i=n-1;i>=0;i--){
                    a.erase(a.find(arr[i]));
                    sum+=nums[i];
                    res=max(res,sum+*(a.rbegin()));
                    res=max(res,sum-*(b.begin()));
                    b.insert(sum);
            }
            return res;
    }
};