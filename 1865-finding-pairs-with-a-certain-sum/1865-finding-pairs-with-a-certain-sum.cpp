map<int,int> mp;
long long arr[1001];
long long nums[100001];
int n;
class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        mp.clear();
            n=0;
            
            for(auto &i:nums2){
                    nums[n++]=i;
                    mp[i]++;
            }n=0;
            for(auto &i:nums1){
                    arr[n++]=i;
            }
    }
    
    void add(int index, int val) {
        mp[nums[index]]--;
            if(mp[nums[index]]==0){
                    mp.erase(nums[index]);
            }
            nums[index]+=val;
            mp[nums[index]]++;
    }
    
    int count(int tot) {
        int res=0;
            for(int i=0;i<n;i++){
                    if(mp.find(tot-arr[i])!=mp.end()){
                            res+=mp[tot-arr[i]];
                    }
            }
            return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */