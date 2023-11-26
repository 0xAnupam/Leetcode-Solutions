const int N=1e5+1;
int parent[N], rnk[N];

void make(int v){
    parent[v] = v;
    rnk[v] = 0;
}

int find(int v){
    if(parent[v] != v)
        parent[v] = find(parent[v]);
    return parent[v];
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if(rnk[a] == rnk[b])
            rnk[a]++;
    }
}class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
            vector<pair<int,int>> arr(n);
            for(int i=0;i<n;i++){
                    make(i);
                    arr[i]={nums[i],i};
            }
            sort(arr.begin(),arr.end());
            for(int i=1;i<n;i++){
                    if(arr[i].first-arr[i-1].first<=limit){
                            Union(arr[i].second,arr[i-1].second);
                    }
            }
            int par[n];
            unordered_map<int,multiset<int>> s;
            for(int i=0;i<n;i++){
                    par[i]=find(i);
                    s[par[i]].insert(nums[i]);
            }
            for(int i=0;i<n;i++){
                    int t=par[i];
                    nums[i]=*s[t].begin();
                    s[t].erase(s[t].begin());
            }
            return nums;
    }
};