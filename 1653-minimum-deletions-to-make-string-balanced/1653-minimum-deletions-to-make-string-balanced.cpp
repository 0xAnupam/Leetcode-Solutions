class Solution {
public:
    int minimumDeletions(string s) {
        int a=0,n=s.size();
        for(auto &i:s)a+=(i=='a');
        int res=min(a,n-a),b=0;
        for(auto &i:s)a-=(i=='a'),b+=(i=='b'),res=min(res,a+b);
        return res;
    }
};