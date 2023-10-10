int sum(int a,int b,int x,int y,vector<vector<int>> &arr){
        int sum=arr[x][y];
        if(a){
                sum-=arr[a-1][y];
        }
        if(b){
                sum-=arr[x][b-1];
        }
        if(a && b){
                sum+=arr[a-1][b-1];
        }
        return sum;
}
bool omk(int m,int n,vector<vector<int>> &arr,int mid){
        int res=mid*mid;
        for(int i=0;i<=m-mid;i++){
                for(int j=0;j<=n-mid;j++){
                        if(sum(i,j,i+mid-1,j+mid-1,arr)==res){
                                return 1;
                        }
                }
        }
        return 0;
}
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> arr(m,vector<int>(n));
            for(int i=0;i<m;i++){
                    for(int j=0;j<n;j++){
                            arr[i][j]=(matrix[i][j]-'0');
                            if(j){
                                    arr[i][j]+=arr[i][j-1];
                            }
                    }
            }
            for(int j=0;j<n;j++){
                    for(int i=1;i<m;i++){
                            arr[i][j]+=arr[i-1][j];
                    }
            }
            int l=1,h=min(n,m),mid;
            while(l<=h){
                    mid=(l+h)/2;
                    if(omk(m,n,arr,mid)){
                            l=mid+1;
                    }
                    else{
                            h=mid-1;
                    }
            }
            return h*h;
    }
};