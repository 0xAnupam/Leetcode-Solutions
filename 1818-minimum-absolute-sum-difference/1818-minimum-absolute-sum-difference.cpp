const long long mod=1e9+7;
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<long long> arr(n);
        set<long long> s;
        long long res=0,sum=0;    
        for(int i=0;i<n;i++){
                s.insert(nums1[i]);
                sum+=(arr[i]=(abs(nums1[i]-nums2[i])));
                
        }
            res=sum;
            for(int i=0;i<n;i++){
                    auto p=s.lower_bound(nums2[i]);
                    if(p!=s.end()){
                            res=min(res,(sum-arr[i]+*p-nums2[i]));
                    }
                    if(p!=s.begin()){
                            p--;
                            res=min(res,(sum-arr[i]-*p+nums2[i]));
                    }       
            }
            return res%mod;
    }
};