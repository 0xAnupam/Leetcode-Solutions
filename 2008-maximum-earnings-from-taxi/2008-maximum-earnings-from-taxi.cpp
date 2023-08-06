const int N=1e5+1;
long long seg_tree[4*N];
void update(int idx,int l,int r,int x,long long k){
        if(r-l==1){
                seg_tree[x]=max(seg_tree[x],k);
                return ;
        }
        int m=l+(r-l)/2;
        if(idx<m){
                update(idx,l,m,2*x+1,k);
        }
        else{
                update(idx,m,r,2*x+2,k);
        }
        seg_tree[x]=max(seg_tree[2*x+1],seg_tree[2*x+2]);
}
long long maxi(int l,int r,int x,int a,int b){
        if(l>=b || a>=r){
                return 0;
        }
        if(a<=l && r<=b){
                return seg_tree[x];
        }
        int m=l+(r-l)/2;
        return max(maxi(l,m,2*x+1,a,b),maxi(m,r,2*x+2,a,b));
}

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        int m=arr.size();
        memset(seg_tree,0,sizeof(seg_tree));
        int i=1,j=0;
        while(i<=n){
            while(j<m && arr[j][0]==i){
               long long mm=maxi(0,n+1,0,0,arr[j][0]+1);
                update(arr[j][1],0,n+1,0,arr[j][1]-arr[j][0]+arr[j][2]+mm);
                j++;
            }
            i++;
        }
        return maxi(0,n+1,0,0,n+1);
    }
};