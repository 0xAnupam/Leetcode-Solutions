class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
    map<long long,long long>mp;
            for(auto &i:basket1){
                    mp[i]++;
            }
            for(auto &i:basket2){
                    mp[i]--;
            }
            long long r=1e9,l=r;
            vector<long long> a,b;
            for(auto &i:mp){
                    if(i.second&1){
                            return -1;
                    }
                    if(i.second==0){
                            r=min(r,i.first);
                    }else{
                             l=min(l,i.first);
                    }
                    i.second/=2;
                    if(i.second<0){
                           
                            for(long long j=0;j<-i.second;j++){
                                    a.push_back(i.first);
                            }
                            
                    }
                    else{
                            for(long long j=0;j<i.second;j++){
                                    a.push_back(i.first);
                            }
                            
                    }
            }
            long long m=(*mp.begin()).first;
            long long res=0;
            int n=a.size()/2;
            for(int i=0;i<n;i++){
                    res+=min(a[i],2*m);
            }
            return res;
            
    }
};