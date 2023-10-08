class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mine) {
        int l[n][n],r[n][n],u[n][n],d[n][n];
            vector<vector<int>> mines(n,vector<int>(n,1));
            for(auto &i:mine){
                    mines[i[0]][i[1]]=0;
            }
            for(int i=0;i<n;i++){
                    int a=0,b=0,c=0,dd=0;
                    for(int j=0;j<n;j++){
                            a=(a+mines[i][j])*mines[i][j];
                            l[i][j]=a;
                            
                            b=(b+mines[i][n-1-j])*mines[i][n-1-j];
                            r[i][n-1-j]=b;
                            
                            c=(c+mines[j][i])*mines[j][i];
                            u[j][i]=c;
                            
                            dd=(dd+mines[n-1-j][i])*mines[n-1-j][i];
                            d[n-j-1][i]=dd;
                            
                    }
            }
            int res=0;
            for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                            res=max(res,min({l[i][j],r[i][j],u[i][j],d[i][j]}));
                    }
            }
            return res;
    }
};