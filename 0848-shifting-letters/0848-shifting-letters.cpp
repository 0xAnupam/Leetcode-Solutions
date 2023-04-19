class Solution {
public:
    string shiftingLetters(string &s, vector<int>& shifts) {
        int n=shifts.size();
         int sum=0;
            for(auto &i:shifts){
                    sum+=i;
                    sum%=26;
                    i=sum;
            }
            int p=0;
            for(int i=0;i<n;i++){
                    int c=s[i]-'a';
                    int S=(sum-p+26)%26;
                    c+=S;
                    c%=26;
                    s[i]=('a'+c);
                    p=shifts[i];
            }
            return s;
    }
};