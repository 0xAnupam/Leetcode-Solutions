class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int a=0,b=0,res=s.size();
            for(auto &i:s){
                    if(i=='0'){
                            a++;
                    }
                    else{
                            b++;
                    }
            }
            res=min(b,a);
            b=0;
            for(auto &i:s){
                   if(i=='0'){
                           a--;
                   }
                    else{
                            b++;
                    }
                    res=min(res,a+b);
            }
            return res;
    }
};