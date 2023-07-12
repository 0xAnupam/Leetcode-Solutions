const long long N=1e5+10;
const long long mod=998244353;
const long long BIG=1e18;
long long  Seg_Tree[4*N];
long long lazy[4*N];
long long arr[N];
void build(long long x,long long l,long long r){
    if(r-l==1){
        lazy[x]=0;
        Seg_Tree[x]=arr[l];
        return ;
    }
    long long mid=l+(r-l)/2;
    build(2*x+1,l,mid);
    build(2*x+2,mid,r);
    lazy[x]=0;
    Seg_Tree[x]=(Seg_Tree[2*x+1]+Seg_Tree[2*x+2]);
}
void update(long long x,long long a,long long b,long long l,long long r,long long val){
     if(lazy[x]){
        if(r-l>1){
            lazy[2*x+1]+=lazy[x];
            lazy[2*x+2]+=lazy[x];
        }
        Seg_Tree[x]+=(r-l)*lazy[x];
        lazy[x]=0;
     }
     if(a>=r || b<=l){
        return ;
     } 
     else if(a<=l && b>=r){
        lazy[x]+=val;
        if(r-l>1){
            lazy[2*x+1]+=lazy[x];
            lazy[2*x+2]+=lazy[x];
            Seg_Tree[x]+=(r-l)*lazy[x];
            lazy[x]=0;
        }
        if(lazy[x]){
 
        }
        return ;
     }
    long long m=(l+r)/2;
    update(2*x+1,a,b,l,m,val);
    update(2*x+2,a,b,m,r,val);
}
long long query(long long x,long long a,long long b,long long l,long long r){
     if(lazy[x]){
        if(r-l>1){
            lazy[2*x+1]+=lazy[x];
            lazy[2*x+2]+=lazy[x];
        }
        Seg_Tree[x]+=(r-l)*lazy[x];
        lazy[x]=0;
     }
    if(a>=r || b<=l){
        return 0;
    }
    else if(a<=l && b>=r){
        return Seg_Tree[x];
    }
    long long mid=l+(r-l)/2;
    auto left=query(2*x+1,a,b,l,mid);
    auto right=query(2*x+2,a,b,mid,r);
    return (left+right);
}
class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n=nums.size();
            for(int i=0;i<n;i++){
                    arr[i]=nums[i];
            }
            build(0,0,n);
            for(int i=0;i<=n-k;i++){
                    long long s=query(0,i,i+1,0,n);
                    if(s<0){
                            
                            return 0;
                    }
                    update(0,i,i+k,0,n,-s);                        
            }
            for(int i=0;i<n;i++){
                    long long s=query(0,i,i+1,0,n);
                    if(s!=0){
                            return 0;
                    }
            }
            return 1;
            
            
    }
};