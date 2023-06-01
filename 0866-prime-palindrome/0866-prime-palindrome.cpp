long long convert(string &s,int base){
        int p=0;
        long long res=0;
        for(auto &i:s){
                res+=(i-'0')*pow(base,p);
                p++;
        }
        return res;
}
bool palindrome(string &s,int n){
        if(s[0]=='0'){
                return 0;
        }
        for(int i=0;i<n/2;i++){
                if(s[i]!=s[n-1-i]){
                        return 0;
                }
        }
        return 1;
}
void gen(vector<long long> &s,string &t,int len,int idx,int base){
        if(2*idx>=len){
                long long N=convert(t,base);
                string S=to_string(N);
                if(palindrome(S,S.size())){
                        s.push_back(N);
                }
                return ;
        }
        char c='0';
        for(int i=0;i<base;i++){
                
                t[idx]=t[len-1-idx]=c;
                c++;
                gen(s,t,len,idx+1,base);
        }
}
bool prime(int n){
        if(n==1){
                return 0;
        }
        if(n<4){
                return 1;
        }
        if(n%2==0){
                return 0;
        }
        int y=sqrt(n);
        for(int i=3;i<=y;i+=2){
                if(n%i==0){
                        return 0;
                }
        }
        return 1;
}
class Solution {
public:
    int primePalindrome(int n) {
        string temp=to_string(n);
            int len=temp.size();
            int res=1e9;
            while(res==1e9){
                    vector<long long> p;
                    temp[0]='0';
                    gen(p,temp,len,0,10);

                    for(auto &i:p){
                            if(i>=n && i<res && prime(i)){
                                    res=i;
                            }
                    }
                    temp+='0';
                    len++;
            }
            return res;
    }
};