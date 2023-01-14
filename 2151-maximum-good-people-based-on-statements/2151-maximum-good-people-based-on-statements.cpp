bool correct(int x,vector<vector<int>> &statement,int n){
   
             for(int i=0;i<n;i++){
                     for(int j=0;j<n;j++){
                             if((1<<i)&x){
                                     if(statement[i][j]==1 && ((1<<j)&x)==0){
                                             return 0;
                                     }
                                     if(statement[i][j]==0 && ((1<<j)&x)){
                                             return 0;
                                     }
                             }
                     }
             
     }
        return 1;
}

class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n=statements.size(),p=(1<<n),res=0;
            for(int i=1;i<p;i++){
                    if(correct(i,statements,n)){
                       ///     cout<<i<<'\n';
                            res=max(res,__builtin_popcount(i));
                    }
            }
            return res;
    }
};