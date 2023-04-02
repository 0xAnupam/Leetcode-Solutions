mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6+1;
pair<int,int> X[N];
pair<int,int> Y[N];
int n;
class Solution {
public:
    Solution(vector<vector<int>>& rects) {
      n=0;
           
            long long sum=0;
            for(auto &i:rects){
                    long long p=(i[3]-i[1]+1)*(i[2]-i[0]+1);
                    sum+=p;
            }
            int j=0;
            for(auto &i:rects){
                    long long p=(i[3]-i[1]+1)*(i[2]-i[0]+1);
                    p*=100;
                    p/=sum;
                    while(p--){
                            X[n]={i[0],i[2]};
                            Y[n]={i[1],i[3]};
                            n++;
                    }
                    
            }
    }
    
    vector<int> pick() {
        int idx=uniform_int_distribution<int>(0, n-1)(rng);
           // cout<<idx<<'\n';
            
                int x=uniform_int_distribution<long long>(X[idx].first, X[idx].second)(rng),
                    y=uniform_int_distribution<long long>(Y[idx].first, Y[idx].second)(rng);
            return {x,y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */