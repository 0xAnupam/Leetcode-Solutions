class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n=word1.size(),m=word2.size();
            int i=0,j=0,k=0;
            string r="";
            while(i<n && j<m){
                    if(k&1){
                        r+=word2[j++];    
                    }
                    else{
                            r+=word1[i++];
                    }
                    k++;
            }
            while(i<n){
                    r+=word1[i++];
            }
            while(j<m){
                    r+=word2[j++];
            }
            return r;
    }
};