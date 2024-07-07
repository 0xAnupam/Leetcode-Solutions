class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n=s.size();
        k%=n;
        if(k==0)return s;
        s+=s;
        string res="";
        for(int i=0;i<n;i++)res+=s[i+k];
        return res;
    }
};