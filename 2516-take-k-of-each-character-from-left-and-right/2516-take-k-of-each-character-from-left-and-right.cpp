bool F(vector<int>&a,vector<int>&b,int k){
        for(int i=0;i<3;i++){
                if(a[i]+b[i]<k){
                        return 0;
                }
        }
        return 1;
}
bool F(vector<int>&a,int k){
        for(int i=0;i<3;i++){
                if(a[i]<k){
                        return 0;
                }
        }
        return 1;
}
class Solution {
public:
    int takeCharacters(string s, int k) {
            if(k==0){
                    return 0;
            }
            int n=s.size();
        vector<vector<int>> mat,mat2;
            vector<int> f(3,0);
            for(int i=0;i<n;i++){
                    f[s[i]-'a']++;
                    mat.emplace_back(f);
            }
            for(auto &i:f){
                    i=0;
            }
            int res=n+1;
            for(int i=n-1;i>=0;i--){
                    f[s[i]-'a']++;
                    int l=0,h=i-1,m;
                    while(l<=h){
                            m=l+(h-l)/2;
                            if(F(mat[m],f,k)){
                                    h=m-1;
                            }
                            else{
                                    l=m+1;
                            }
                    }
                    if(F(f,k)){
                            res=min(res,n-i);
                    }
                    if(l<=i){res=min(res,n-i+l+1);}
            }
           int l=0;
           int h=n-1,m;
            while(l<=h){
                    m=l+(h-l)/2;
                    if(F(mat[m],k)){
                            h=m-1;
                    }
                    else{
                            l=m+1;
                    }
                    
            }
            if(l<n){
                    res=min(res,1+l);
            }
            
            return res==n+1? -1:res;
            
    }
};