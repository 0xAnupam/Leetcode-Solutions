class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long res=0,m=1e9+7,o=0,e=0,sum=0;
        for(auto &i:arr){
                sum+=i;
                if(sum&1){
                        o++;
                }
                else{
                        e++;
                }
        }
            
            res+=o;
            sum=0;
            for(auto &i:arr){
                    sum+=i;
                    if(sum&1){
                            res+=e;
                            o--;
                    }
                    else{
                            res+=o;
                            e--;
                    }
                    
                    res%=m;
            }
            return res;
    }
};