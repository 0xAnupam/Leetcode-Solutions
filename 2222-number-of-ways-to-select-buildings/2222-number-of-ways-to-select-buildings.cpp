class Solution {
public:
    long long numberOfWays(string &s) {
        long long a=0,b=0,c=0,d=0,res=0;
            for(auto &i:s){
                    if(i=='1'){
                            b++;
                    }
                    else{
                            a++;
                    }
            }
            for(auto &i:s){
                    if(i=='1'){
                            b--;
                            d++;
                            res+=(a*c);
                    }
                    else{
                            a--;
                            c++;
                            res+=(b*d);
                    }
            }
            return res;
    }
};