string f(string &s,int k){
        if(s.size()==1){
                return s;
        }
        if(s[0]!='$'){
                return s;
        }
        string res="$";
        int i=1;
        long long r=0;
        while(i<s.size()){
                r*=10;
                if(!(s[i]>='0' && s[i]<='9')){
                        return s;
                }
                r+=(s[i]-'0');
                i++;
        }
        long double q=r,cp=100-k;
        q*=cp;
        q/=100;
        string t=to_string(q);
        for(int i=0;i<4;i++){
                t.pop_back();
        }
        res+=t;
        return res;
        
}
class Solution {
public:
    string discountPrices(string sentence, int discount) {
        string res="";
        string temp="";
            for(auto &i:sentence){
                    if(i==' '){
                            res+=f(temp,discount);
                            temp="";
                            res+=' ';
                    }
                    else{
                            temp+=i;
                    }
            }
            res+=f(temp,discount);
            return res;
    }
};