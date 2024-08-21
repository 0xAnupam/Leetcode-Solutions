const int mod=1e9+7;
int dp[2001][1001];
int  Seg_Tree[4269];
const int maxA=1002;
void build(int x,int l,int r){
    if(r-l==1){
        Seg_Tree[x]=1;
        return ;
    }
    int mid=l+(r-l)/2;
    build(2*x+1,l,mid);
    build(2*x+2,mid,r);
    Seg_Tree[x]=(Seg_Tree[2*x+1]+Seg_Tree[2*x+2])%mod;
}
void update(int x,int idx,int val,int l,int r){
    if(r-l==1){
        Seg_Tree[x]=val;
        return ;
    }
    int m=l+(r-l)/2;
    if(idx<m){
        update(2*x+1,idx,val,l,m);
    }
    else{
        update(2*x+2,idx,val,m,r);
    }
    Seg_Tree[x]=(Seg_Tree[2*x+1]+Seg_Tree[2*x+2])%mod;
}
int query(int x,int a,int b,int l,int r){
   
    if(a>=r || b<=l){
        return 0;
    }
    else if(a<=l && b>=r){
        return Seg_Tree[x];
    }
    int mid=l+(r-l)/2;
    auto left=query(2*x+1,a,b,l,mid);
    auto right=query(2*x+2,a,b,mid,r);
    return (left+right)%mod;
}
class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int x=nums.back(),n=nums.size();
        vector<int> arr=nums;
        arr.push_back(1000);
        for(int i=n-1;i>=0;i--){
            x=min(x,nums[i]);
            nums[i]=x;
        }
        build(0,0,maxA);
        for(int i=0;i<n;i++){
            for(int j=0;j<=arr[i];j++)dp[i][j]=0;
        }
        for(int i=n-1;i>=0;i--){
            for(int cur=0;cur<=nums[i];cur++){
                int l=max(arr[i+1]-arr[i]+cur,cur),r=arr[i+1];
                
                    dp[i][cur]=query(0,l,r+1,0,maxA);
                    // dp[i][cur]%=mod;
              
            }
            for(int cur=0;cur<=arr[i];cur++){
                update(0,cur,dp[i][cur],0,maxA);
            }
            
        }
        return dp[0][0];
    
        
    }
};