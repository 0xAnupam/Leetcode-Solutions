bool pal[2001][2001];
void fun(string &s,int idx,int n){
        int l=idx,r=idx;
        while(l>=0 && r<n && s[l]==s[r] ){
                pal[l][r]=1;
                l--;
                r++;
        }
        l=idx;
        r=l+1;
        while(l>=0 && r<n && s[l]==s[r] ){
                pal[l][r]=1;
                l--;
                r++;
        }
        
}
class Solution {
public:
    bool checkPartitioning(string s) {
        memset(pal,0,sizeof(pal));
        int n=s.size();
        for(int i=0;i<n;i++){
                fun(s,i,n);
        } 
            
        for(int i=0;i<n-2;i++){
                for(int j=i+1;j<n-1;j++){
                        if(pal[0][i] && pal[i+1][j] && pal[j+1][n-1]){
                                return 1;
                        }
                }
        }    
            cout<<pal[0][0];
            return 0;
    }
};