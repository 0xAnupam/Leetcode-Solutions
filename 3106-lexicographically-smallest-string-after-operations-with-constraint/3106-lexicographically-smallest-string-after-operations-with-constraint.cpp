class Solution {
public:
    string getSmallestString(string s, int k) {
        
            for(auto &i:s){
                    char c=i;int moves=0;
                    for(int j=0;j<26 && j<=k;j++){
                            int p=(i-'a'+j)%26;
                            char C=p+'a';
                            if(C<c || (C==c && moves>j)){
                                    moves=j;
                                    c=C;
                            }
                            p=(i-'a'-j+26)%26;
                            C=p+'a';
                            if(C<c || (C==c && moves>j)){
                                    moves=j;
                                    c=C;
                            }
                    }
                    i=c;
                    k-=moves;
            }
            return s;
    }
};