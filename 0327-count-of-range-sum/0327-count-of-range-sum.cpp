#include<ext/pb_ds/assoc_container.hpp>     
#include<ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds; 
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long long sum=0;
            pbds A;
        for(auto &i:nums){
                sum+=i;
                A.insert(sum);
        }
            long long res=0;
            sum=0;
            res+=(A.order_of_key(lower)-A.order_of_key(upper+1));
            for(auto &i:nums){
                    sum+=i;
                    A.erase(A.upper_bound(sum));
                    res+=(A.order_of_key(lower+sum)-A.order_of_key(upper+sum+1));
            }
            return -res;
    }
};