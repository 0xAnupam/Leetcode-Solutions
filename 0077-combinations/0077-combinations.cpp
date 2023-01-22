void f(vector<vector<int>> &res,vector<int> &t,int i,int n,int k){
        if(k==0){
                res.push_back(t);
                return ;
        }
        if(i>n){
                return ;
        }
        
        t.push_back(i);
        f(res,t,i+1,n,k-1);
        t.pop_back();
        f(res,t,i+1,n,k);
        
}
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
            vector<int> t;
            f(res,t,1,n,k);
            return res;    }
};