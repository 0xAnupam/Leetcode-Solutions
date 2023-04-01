const int N=1e7+1;
int arr[N];
int len;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
class Solution {
public:
    Solution(vector<int>& w) {
            len=0;
            
        long long sum=0,n=w.size();
            for(int i=0;i<n;i++){
                    sum+=w[i];
            }
            for(int i=0;i<n;i++){
                    long long p=w[i];p*=1000;
                    p/=sum;
                    while(len<N && p>0){
                            p--;
                            arr[len++]=i;
                    }
                    
            }
    }
    
    int pickIndex() {
        return arr[uniform_int_distribution<int>(0, max(0,len-1))(rng)];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */