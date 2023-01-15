class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0,p=0;int e=1e6;
            bool f=0;
            for(auto &i:matrix){
                    for(auto &j:i){
                            if(j<0){
                                    p++;
                                   
                            }
                            if(j==0){
                                    f=1;
                            }
                             e=min(e,abs(j));
                            sum+=abs(j);
                    }
            }
            
            if(f){
                    return sum;
            }
            return p&1 ? sum-2*e:sum;
    }
};