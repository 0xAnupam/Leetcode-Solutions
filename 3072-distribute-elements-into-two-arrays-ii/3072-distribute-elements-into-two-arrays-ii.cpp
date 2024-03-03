#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
const int N=1e5+1;
int arr1[N];
int arr2[N];
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        pbds A,B;
           
            int x,y;
            int m=0,n=0;
            for(auto &i:nums){
                    x=A.order_of_key(i),y=B.order_of_key(i);
                    if(m==0){
                            arr1[m++]=i;
                            A.insert(i);
                    }
                    else if(n==0){
                            arr2[n++]=i;
                            B.insert(i);
                    }
                    else if(x>y){
                            arr1[m++]=i;
                            A.insert(i);
                    }
                    else if(x<y){
                            arr2[n++]=i;
                            B.insert(i);
                    }
                    else if(A.size()<=B.size()){
                            arr1[m++]=i;
                            A.insert(i);
                    }
                    else{
                            arr2[n++]=i;
                            B.insert(i);
                    }
            }
            vector<int> res(m+n);
            for(int i=0;i<m;i++)res[i]=arr1[i];
            for(int i=0;i<n;i++)res[i+m]=arr2[i];
            return res;
    }
};
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);