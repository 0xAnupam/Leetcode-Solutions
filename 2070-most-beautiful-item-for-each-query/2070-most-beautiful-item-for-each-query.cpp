const int N=4e5+10;
int seg_tree[N];
void build(vector<vector<int>>&nums,int l,int r,int x){
        if(r-l==1){
                 seg_tree[x]=nums[l][1];
                return ;
        }
        int  m=l+(r-l)/2;
        build(nums,l,m,2*x+1);
        build(nums,m,r,2*x+2);
        seg_tree[x]=max(seg_tree[2*x+1],seg_tree[2*x+2]);
}
int maxi(int l,int r,int x,int a,int b){
        if(l>=b || a>=r){
                return 0;
        }
        if(a<=l && r<=b){
                return seg_tree[x];
        }
        int m=l+(r-l)/2;
        return max(maxi(l,m,2*x+1,a,b),maxi(m,r,2*x+2,a,b));
}
int n;class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
            int n=items.size();
            build(items,0,n,0);
            vector<int> res;
            for(auto &i:queries){
                   vector<int> temp;temp.push_back(i+1);
                    auto p=lower_bound(items.begin(),items.end(),temp)-items.begin();
                    res.push_back(maxi(0,n,0,0,p));
            }
            return res;
    }
};