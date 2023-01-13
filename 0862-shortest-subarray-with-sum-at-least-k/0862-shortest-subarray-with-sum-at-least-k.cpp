const int N=1e6;
long long seg_tree[N];
void build(vector<int>&nums,int l,int r,int x){
        if(r-l==1){
                 seg_tree[x]=nums[l];
                return ;
        }
        int  m=l+(r-l)/2;
        build(nums,l,m,2*x+1);
        build(nums,m,r,2*x+2);
        seg_tree[x]=min(seg_tree[2*x+1],seg_tree[2*x+2]);
}
void Update(int l,int r,int idx,long long val,int x){
        if(r-l==1){
                seg_tree[x]=val;
                return ;
        }
        
        int m=l+(r-l)/2;
        if(idx<m){
                Update(l,m,idx,val,2*x+1);
        }
        else{
                Update(m,r,idx,val,2*x+2);
        }
        seg_tree[x]=min(seg_tree[2*x+1],seg_tree[2*x+2]);
}
long long mini(int l,int r,int x,int a,int b){
        if(l>=b || a>=r){
                return 1e18;
        }
        if(a<=l && r<=b){
                return seg_tree[x];
        }
        int m=l+(r-l)/2;
        return min(mini(l,m,2*x+1,a,b),mini(m,r,2*x+2,a,b));
}
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
         int n=nums.size();
        set<pair<long long,int>> s;
            long long sum=0;
            map<int,int> mp;
            for(int i=0;i<n;i++){
                    sum+=nums[i];
                    s.insert({sum,i});
            }
            long long res=1e18;
            sum=0;
            vector<int> len;
           int K=0;
            for(auto &i:s){  mp[i.second]=K++;
                    len.push_back(i.second);
            }  
            build(len,0,n,0);
            auto p=s.lower_bound({k,0});
            if(p!=s.end()){
                       int q=1+mini(0,n,0,mp[(*p).second],n);
                 
                    res=q;
            }
             for(int i=0;i<n;i++){
                    sum+=nums[i];
                     
                   auto p=s.lower_bound({k+sum-nums[i],-1});
                    
                     if(p!=s.end()){
                           auto P=mp[(*p).second];
                           int q=mini(0,n,0,P,n);
                      
                            if(q>=i){
                            res=min(res,(long long)q-i+1);}
                    }
                     Update(0,n,mp[i],1e18,0);
                    
            }
          
            return res>=1e18? -1:res;
            
            
            
            
    }
};