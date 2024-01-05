int lis(vector<int> const& a) {
    int n = a.size(),x;
    vector<int> d;
        int res=0;
	for(int i=0;i<n;++i)
	{
		x=a[i];
		vector<int>::iterator it=upper_bound(d.begin(),d.end(),x);
		if(it==d.end()){
			d.emplace_back(x);
		}
		else{
			*it=x;
			
		}
	}
        return d.size();
}
class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int sum=0,n=arr.size();
            vector<int> nums[k];
            int idx=0;
            for(int i=0;i<n;i++){
                    nums[idx].emplace_back(arr[i]);
                    idx++;
                    if(idx==k)idx=0;
            }
            for(auto &i:nums){
                    sum+=i.size()-lis(i);
            }
        return sum;
        
    }
};