mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int arr[100];
vector<int> sh;
int n;
class Solution {
public:
    Solution(vector<int>& nums) {
        n=0;
            while(sh.size()){
                    sh.pop_back();
            }
            for(auto &i:nums){
                    sh.emplace_back(i);
                    arr[n++]=i;
            }
    }
    
    vector<int> reset() {
        for(int i=0;i<n;i++){
                sh[i]=arr[i];
        }
            return sh;
    }
    
    vector<int> shuffle() {
        for(int i=0;i<100;i++){
                int a=uniform_int_distribution<int>(0, n-1)(rng);
                int b=uniform_int_distribution<int>(0, n-1)(rng);
                swap(sh[a],sh[b]);
        }
            return sh;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */