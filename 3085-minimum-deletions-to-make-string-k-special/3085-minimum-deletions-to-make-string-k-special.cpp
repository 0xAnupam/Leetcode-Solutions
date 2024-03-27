class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> fre(26,0);
            for(auto &i:word){
                    fre[i-'a']++;
            }
            int res=word.size(),n=res;
            for(int i=0;i<=n;i++){
                    int op=0;
                    for(int j=0;j<26;j++){
                            if(fre[j]<i){
                                    op+=fre[j];
                            }
                            else if(fre[j]>i+k){
                                    op+=(fre[j]-i-k);
                            }
                    }
                    res=min(res,op);
            }
            return res;
    }
};