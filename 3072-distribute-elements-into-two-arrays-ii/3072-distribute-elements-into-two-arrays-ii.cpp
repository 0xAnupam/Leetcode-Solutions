#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        pbds A,B;
            vector<int> arr1,arr2;
            int x,y;
            for(auto &i:nums){
                    x=A.order_of_key(i),y=B.order_of_key(i);
                    if(arr1.empty()){
                            arr1.emplace_back(i);
                            A.insert(i);
                    }
                    else if(arr2.empty()){
                            arr2.emplace_back(i);
                            B.insert(i);
                    }
                    else if(x>y){
                            arr1.emplace_back(i);
                            A.insert(i);
                    }
                    else if(x<y){
                            arr2.emplace_back(i);
                            B.insert(i);
                    }
                    else if(A.size()<=B.size()){
                            arr1.emplace_back(i);
                            A.insert(i);
                    }
                    else{
                            arr2.push_back(i);
                            B.insert(i);
                    }
            }
            arr1.insert(arr1.end(),arr2.begin(),arr2.end());
            return arr1;
    }
};
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);