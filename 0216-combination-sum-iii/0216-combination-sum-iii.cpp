void f(vector<vector<int>> &res,vector<int> &temp,int k,int n,int cur){
        
        if(k==0){
                if(n==0){
                        res.push_back(temp);
                }
                return ;
        }
        for(int i=cur;i<=9;i++){
                if(n>=i ){
                        temp.push_back(i);
                        f(res,temp,k-1,n-i,i+1);
                        temp.pop_back();
                }
        }
}
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
            vector<int> temp;
            f(res,temp,k,n,1);
            return res;
            
           
    }
};