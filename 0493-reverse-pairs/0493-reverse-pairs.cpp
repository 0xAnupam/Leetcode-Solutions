#include<ext/pb_ds/assoc_container.hpp>     
#include<ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds; 
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        pbds A;
            int n=nums.size();
            int res=0;
            for(int i=0;i<n;i++){
                    int p=A.order_of_key(nums[i]*2LL+1);
                    res+=A.size()-p;
                    A.insert(nums[i]);
            }
            return res;
    }
};