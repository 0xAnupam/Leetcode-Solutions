int f(int idx,int n,int k,int* digits,string &s){
        if(idx==n){
                return 1;
        }
        int res=0;
        if(k){
                for(int j=1;j<s[idx]-'0';j++){
                        if(digits[j]){
                                res+=f(idx+1,n,0,digits,s);
                        }
                }
                if(digits[s[idx]-'0']){
                        res+=f(idx+1,n,1,digits,s);
                }
        }
        else{
                for(int j=1;j<10;j++){
                        if(digits[j]){
                                res+=f(idx+1,n,0,digits,s);
                        }
                }
        }
        return res;
}
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int N) {
        int digit[10];
            memset(digit,0,sizeof(digit));
            for(auto &i:digits){
                    digit[stoi(i)]=1;
            }
             string s=to_string(N);
            int n=s.size();
            int res=0;
            for(int i=1;i<n;i++){
                    for(int j=1;j<10;j++){
                            if(digit[j]){
                                    res+=f(i+1,n,0,digit,s);
                            }
                    }
            }
             for(int j=1;j<s[0]-'0';j++){
                        if(digit[j]){
                                res+=f(1,n,0,digit,s);
                        }
              }
                if(digit[s[0]-'0']){
                        res+=f(1,n,1,digit,s);
                }
            
            return res;
    }
};