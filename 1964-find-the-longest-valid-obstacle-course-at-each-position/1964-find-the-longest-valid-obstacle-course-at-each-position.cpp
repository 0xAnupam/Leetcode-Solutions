const int N=1e7+1;
int bit[N];
struct FenwickTreeMax {
    int n;
    

    FenwickTreeMax(int n) {
        this->n = n;
        memset(bit,0,n*sizeof(int));
    }
    int getmax(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = max(ret, bit[r]);
        return ret;
    }

    void update(int idx, int val) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] = max(bit[idx], val);
    }
};
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& arr) {
        int N=*max_element(arr.begin(),arr.end()),n=arr.size();
            FenwickTreeMax A(N+1);
            vector<int> res(n);
            for(int i=0;i<n;i++){
                  int f=A.getmax(arr[i]);
                  res[i]=1+f;
                    A.update(arr[i],res[i]);
            }
         return res;
    }
};