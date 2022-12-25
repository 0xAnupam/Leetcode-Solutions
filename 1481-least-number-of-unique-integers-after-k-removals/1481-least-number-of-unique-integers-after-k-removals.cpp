class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> m;
            for(auto &i:arr){
                    m[i]++;
            }
            vector<int> p;
            for(auto &i:m){
                    p.emplace_back(i.second);
            }
            int i=0,n=p.size();
            sort(p.begin(),p.end());
            while(i<n && p[i]<=k){
                    k-=p[i++];
            }
            return n-i;
    }
};