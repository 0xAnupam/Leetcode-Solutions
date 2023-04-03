int var(string &s,char c){
        int res=0,sum=0,other=0;
        for(char a='a';a<='z';a++){
                sum=0;other=0;
                if(a!=c){
                        for(auto &i:s){
                                if(i==c){
                                        sum++;
                                        if(other){
                                                res=max(res,sum-other);
                                        }
                                        
                                }
                                else if(i==a){
                                        other++;
                                        if(other>sum){
                                                other=sum=0;
                                        }
                                        if(other){
                                                 res=max(res,sum-other);
                                        }
                                }
                        }
                }
        }
        return res;
}
class Solution {
public:
    int largestVariance(string s) {
        int res=0;
            for(char c='a';c<='z';c++){
                    res=max(res,var(s,c));
            }
            reverse(s.begin(),s.end());
            for(char c='a';c<='z';c++){
                    res=max(res,var(s,c));
            }
            return res;
    }
};