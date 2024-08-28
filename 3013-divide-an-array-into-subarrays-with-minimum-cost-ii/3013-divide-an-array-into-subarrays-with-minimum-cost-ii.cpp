class MinKSum{
    private:
      multiset<int> a,b;
      long long sum;
      int k;
    public:
        MinKSum(int k){
            this->k=k;
            this->sum=0;
            a.clear();
            b.clear();
        }
        long long query(){
            repair();
            if(a.size()<k)return 1e18;
            return sum;
        }
        void insert(int n){
            b.insert(n);
        }
        void remove(int n){
            if(b.find(n)!=b.end()){
                b.erase(b.find(n));
                return;
            }
            sum-=n;
            a.erase(a.find(n));
            repair();
        }
        void repair(){
            while(a.size()<k && b.size()){
                sum+=*b.begin();
                a.insert(*b.begin());
                b.erase(b.begin());
            }
            while(a.size() && b.size() && (*(a.rbegin()))>*b.begin()){
                sum-=(*(a.rbegin()));
                b.insert((*(a.rbegin())));
                a.erase(a.find(*a.rbegin()));
                sum+=*b.begin();
                a.insert(*b.begin());
                b.erase(b.begin());
            }
        }
    
    
};
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        MinKSum obj(k-1);
        long long res=1e18,n=nums.size();
        for(int i=0;i<=dist;i++)obj.insert(nums[i]);
        for(int i=dist+1;i<n;i++){
            obj.insert(nums[i]);
            obj.remove(nums[i-dist-1]);
            res=min(res,nums[0]+obj.query());
        }
        
        return res;
        
    }
};