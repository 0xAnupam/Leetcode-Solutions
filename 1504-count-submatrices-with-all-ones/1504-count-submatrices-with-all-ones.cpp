inline int F(int a,int b,int x,int y,vector<vector<int>>& mat){
        int res=mat[x][y];
        if(a){
                res-=mat[a-1][y];
        }
        if(b){
                res-=mat[x][b-1];
        }
        if(a && b){
                res+=mat[a-1][b-1];
        }
        return res;
}
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
            for(auto &i:mat){
                    int sum=0;
                    for(auto &j:i){
                            sum+=j;
                            j=sum;
                    }
            }
            for(int j=0;j<n;j++){
                    for(int i=1;i<m;i++){
                            mat[i][j]+=mat[i-1][j];
                    }
            }
            int res=0;
            for(int i=0;i<m;i++){
                    for(int j=0;j<n;j++){
                            for(int x=i;x<m;x++){
                                    int l=j,h=n-1,mid;
                                    while(l<=h){
                                            mid=(l+h)/2;
                                            if((F(i,j,x,mid,mat))==((x-i+1)*(mid-j+1))){
                                                    l=mid+1;
                                            }
                                            else{
                                                    h=mid-1;
                                            }
                                    }
                                    res+=(l-j);
                            }
                    }
            }
            return res;
    }
};