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
                if(palindrome(t,len) && palindrome(S,S.size())){
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
class Solution {
public:
    long long kMirror(int k, int n) {
        set<long long> s;
            int len=1;
            string S="0";
            while(s.size()<n){
                    vector<long long> p;
                    S[0]='0';
                    gen(p,S,len,0,k);
                    for(auto &i:p){
                            s.insert(i);
                    }
                    S+='0';
                    len++;
            }
            int j=0;
            long long res=0;
            auto it=s.begin();
            while(j<n){
                    res+=*it;
                    it++;
                    j++;
            }
            return res;
    }
};