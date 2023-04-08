vector<pair<long long,long long>> mov;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
class Solution {
public:
    Solution(int n, vector<int>& blacklist) {

        blacklist.push_back(n);
            while(mov.size()){
                    mov.pop_back();
            }
            sort(blacklist.begin(),blacklist.end());
            vector<pair<long long,long long>> t;
            int p=-1;long long s=0;
            for(auto &i:blacklist){
                    
                    if(i-p>1){
                            t.push_back({p+1,i-1});
                            s+=(i-p);
                    }
                    p=i;
            }
            for(auto &i:t){
                    long long y=1+i.second-i.first;
                    y*=500000LL;
                    y/=s;
                    while(y--){
                           mov.emplace_back(i); 
                    }
            }
    }
    
    int pick() {
            
            int n=mov.size();
            auto t=mov[uniform_int_distribution<int>(0, n-1)(rng)];
            return uniform_int_distribution<int>(t.first, t.second)(rng);
            
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */