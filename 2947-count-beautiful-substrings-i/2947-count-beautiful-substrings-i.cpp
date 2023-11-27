class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        vector<int> arr(26,-1);
            string vow="aeiou";
            for(auto &i:vow){
                    arr[i-'a']=1;
            }
            int res=0,n=s.size();
            for(int i=0;i<n;i++){
                    int a=0,b=0;
                    for(int j=i;j<n;j++){
                            if(arr[s[j]-'a']==1){
                                    a++;
                            }
                            else{
                                    b++;
                            }
                            if(a==b && (a*b)%k==0)res++;
                    }
            }
            return res;
    }
};