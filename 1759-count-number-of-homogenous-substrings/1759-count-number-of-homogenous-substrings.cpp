const int M=1e9+7;
class Solution {
public:
    int countHomogenous(string s) {
        long long res=0,i=0,n=s.size();
            while(i<n){
                    long long cnt=0;
                    char c=s[i];
                    while(c==s[i]){
                            cnt++;
                            i++;
                    }
                    res+=(cnt*(cnt+1))/2;
                    res%=M;
            }
            return res;
    }
};