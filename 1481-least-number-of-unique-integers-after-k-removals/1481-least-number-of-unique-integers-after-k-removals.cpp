class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
            sort(arr.begin(),arr.end());    
            vector<int> p;
            int i=0,n=arr.size();
            while(i<n){
                    int tmp=arr[i],cnt=0;
                    while(i<n && arr[i]==tmp)i++,cnt++;
                    p.emplace_back(cnt);
            }
            i=0,n=p.size();
            sort(p.begin(),p.end());
            while(i<n && p[i]<=k){
                    k-=p[i++];
            }
            return n-i;
    }
};