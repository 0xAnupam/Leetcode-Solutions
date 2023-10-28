const int M = 1e5+10;
const int mod=1e9+7;
//struct to store sum and sum of square of all the elements in the segment tree
struct Node{
   long long sum;
    long long sumOfSquare;
   Node(){
       sum = 0;
       sumOfSquare = 0;
   }
};
//struct for lazy tree
struct LazyNode{
    long long type;
    long long val;
   LazyNode(){
       type = -1;
       val = 0;
   }
};
//array to store segment tree
Node segTree[8 * M];
//array to store lazy tree
LazyNode lazy[8 * M];
//function to update the values in the segment tree using the the values of lazy tree
void push( long long node,  long long &st, long long &en){
   if(lazy[node].type == -1)
       return;
   if(lazy[node].type == 0){
           lazy[node].val%=mod;
       segTree[node].sum = ((en - st + 1LL)%mod * lazy[node].val%mod)%mod;
       segTree[node].sumOfSquare = (((en - st + 1) * lazy[node].val )%mod* lazy[node].val)%mod;
       lazy[2 * node + 1] = lazy[node];
       lazy[2 * node + 2] = lazy[node];
   }
   else{
       segTree[node].sumOfSquare += (((en - st + 1) * lazy[node].val )%mod * lazy[node].val + 
                                     2 * lazy[node].val * segTree[node].sum+mod)%mod;
           segTree[node].sumOfSquare%=mod;
       segTree[node].sum += ((en - st + 1LL) * lazy[node].val+mod)%mod;
           segTree[node].sum%=mod;
       if(lazy[2 * node + 1].type == -1){
           lazy[2 * node + 1] = lazy[node];
       }
       else{
           lazy[2 * node + 1].val += lazy[node].val;
               lazy[2 * node + 1].val%=mod;
               
       }
       if(lazy[2 * node + 2].type == -1)
           lazy[2 * node + 2] = lazy[node];
       else
           lazy[2 * node + 2].val += lazy[node].val;
           lazy[2 * node + 2].val%=mod;
   }
   lazy[node].type = -1;
}
//query function
 long long query( long long node,  long long cl,  long long cr,  long long l,  long long r){
   push(node, cl, cr);
   if(cr < l || cl > r)
       return 0;
   if(cl >= l and cr <= r){
       return segTree[node].sumOfSquare%mod;
   }
    long long mid = (cl + cr)/2;
    long long x = query(2 * node + 1, cl, mid, l, r)%mod;
    long long y = query(2 * node + 2, mid + 1, cr, l, r)%mod;
   return (x + y)%mod;
}
//update function
void update( long long node,  long long cl,  long long cr,  long long l,  long long r,  long long type,  long long val){
   push(node, cl, cr);
   if(cr < l || cl > r)
       return;
   if(cl >= l and cr <= r){
       lazy[node].type = type;
       lazy[node].val = val;
       push(node, cl, cr);
   }
   else{
        long long mid = (cl + cr)/2;
       update(2 * node + 1, cl, mid, l, r, type, val);
       update(2 * node + 2, mid + 1, cr, l, r, type, val);
       segTree[node].sum = (segTree[2 * node + 1].sum + segTree[2 * node + 2].sum+mod)%mod;
       segTree[node].sumOfSquare = (segTree[2 * node + 1].sumOfSquare + segTree[2 * node + 2].sumOfSquare+mod)%mod; 
   }
}
//build function to construct the segment tree
void build( long long node,  long long st,  long long en, int a[]){
   if(st == en){
       segTree[node].sum = a[st];
       segTree[node].sumOfSquare = (a[st] *1LL* a[st])%mod;
       return;
   }
    long long mid = (st + en)/2;
   build(2 * node + 1, st, mid, a);
   build(2 * node + 2, mid + 1, en, a);
   segTree[node].sum = (segTree[2 * node + 1].sum + segTree[2 * node + 2].sum)%mod;
   segTree[node].sumOfSquare = (segTree[2 * node + 1].sumOfSquare + segTree[2 * node + 2].sumOfSquare)%mod;
}
class Solution {
public:
    int sumCounts(vector<int>& nums) {
            int arr[M+1],n=nums.size();
            memset(arr,0,sizeof(arr));
            map<int,vector<int>> mp;
            for(int i=0;i<n;i++){
                    if(mp.find(nums[i])==mp.end()){
                            
                            arr[i]=1;
                            
                    }
                    mp[nums[i]].push_back(i);
            }
            for(auto &i:mp){
                    i.second.push_back(n);
            }
            int sum=0;
            for(int i=0;i<M;i++){
                    
                    sum+=arr[i];
                    arr[i]=sum;
            }
            long long res=0;
             build(1, 0, M, arr);
            map<int,int> dp;
            for(int i=0;i<n;i++){
                    
                 
                res+= query(1, 0, M, i,n-1)%mod;
                res%=mod;
                int idx=dp[nums[i]];
                int till=mp[nums[i]][idx+1];
                dp[nums[i]]++;
                update(1, 0, M,mp[nums[i]][idx] , mp[nums[i]][idx+1]-1, 1, -1)  ;  
                  
            }
            
            
        return res;
    }
};