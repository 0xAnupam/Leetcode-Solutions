void f(vector<int>&res,int cur,int low,int high,long long N){
        
        if(N>high){
                
                return ;
        }
        if(N>=low){
                res.push_back(N);
        }
        if(cur==10){
                return ;
        }
        N*=10;
        N+=cur;
        f(res,cur+1,low,high,N);
        
}
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
           for(int i=1;i<=9;i++){
                   f(res,i,low,high,0);
           }
            sort(res.begin(),res.end());
            return res;
    }
};