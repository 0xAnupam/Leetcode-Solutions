#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        pbds A={nums.begin(),nums.end()};
            long long res=0,n=nums.size();
            while(*A.find_by_order(n/2)!=k){
                    res+=abs(*A.find_by_order(n/2)-k);
                    A.erase(A.find_by_order(n/2));
                    A.insert(k);
            }
            return res;
            
    }
};