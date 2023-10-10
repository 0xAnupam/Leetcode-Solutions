int f(string &s,int n,int k,char c){
        int i=0,j=0,l=0,res=0;
        while(i<n){
                while(j<n && (l+(s[j]!=c)) <=k){
                        l+=(s[j]!=c);
                        j++;
                }
                res=max(j-i,res);
                l-=(s[i]!=c);
                i++;
        }
        return res;
}
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size();
            return max(f(answerKey,n,k,'T'),f(answerKey,n,k,'F'));
    }
};