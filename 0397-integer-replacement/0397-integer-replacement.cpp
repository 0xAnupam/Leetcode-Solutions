map<long long,int> mp;
int f(long long n){
        if(n==1){
                return 0;
        }
        if(mp.find(n)!=mp.end()){
                return mp[n];
        }
        if(n&1){
                return mp[n]=1+min(f(n-1),f(n+1));
        }
        return mp[n]=1+f(n/2);
}
class Solution {
public:
    int integerReplacement(int n) {

            return f(n);
    }
};