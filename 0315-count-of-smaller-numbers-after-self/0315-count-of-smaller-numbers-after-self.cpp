struct FenwickTree {
    vector<long long> bit;  // binary indexed tree
    long long n;

    FenwickTree(long long n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    long long sum(long long r) {
        long long ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    long long sum(long long l, long long r) {
        return sum(r) - sum(l - 1);
    }

    void add(long long idx, long long delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int N=2e4+2,n=nums.size();
            FenwickTree A(N);
            vector<int> arr(n);
            for(int i=n-1;i>=0;i--){
                    A.add(nums[i]+N/2,1);
                    arr[i]=A.sum(0,nums[i]+N/2-1);
            }
            return arr;
    }
};