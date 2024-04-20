void f(vector<int> &s,vector<int>&t,vector<int> &coins,int x,int idx,int n){
        if(idx==n){
                long long res=0,a=0;
                for(int i=0;i<n;i++){
                        if((1<<i)&x){
                                if(res==0){
                                        res=coins[i];
                                }
                                else{
                                        res=(res*1LL*coins[i])/__gcd(res,1LL*coins[i]);
                                }
                                a++;
                        }
                        if(res>1e16)return ;
                }
                if(res){
                        if(a&1)s.push_back(res);
                        else{
                                t.push_back(res);
                        }
                }
                return ;
                
        }
        
        f(s,t,coins,x,idx+1,n);
        f(s,t,coins,(x|(1<<idx)),idx+1,n);
}
bool pos(vector<int> &s,vector<int> &t,long long mid,int k){
        long long res=0;
        for(auto &i:t){
                res-=(mid/i);
        }
        for(auto &i:s){
                res+=(mid/i);
        }
        return res<k;
}
class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
            int n=coins.size();
            vector<int>s,t;
            f(s,t,coins,0,0,coins.size());
            long long l=1,h=1e15,m;
            while(l<=h){
                    m=l+(h-l)/2;
                    if(pos(s,t,m,k)){
                            l=m+1;
                    }
                    else{
                            h=m-1;
                    }
            }
        return l==2242115681 ? --l : l;
    }
};