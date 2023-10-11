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
bool omk(int m,int n,vector<vector<int>> &arr,int mid,int threshold){
        if(mid==0){
                return 0;
        }
        for(int i=0;i<=m-mid;i++){
                for(int j=0;j<=n-mid;j++){
                        if(sum(i,j,i+mid-1,j+mid-1,arr)<=threshold){
                                return 1;
                        }
                }
        }
        return 0;
        
}
 
class Solution {
public:
    int maxSideLength(vector<vector<int>>& arr, int threshold) {
        int m=arr.size(),n=arr[0].size();
        
            for(int i=0;i<m;i++){
                    for(int j=0;j<n;j++){
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
                    if(omk(m,n,arr,mid,threshold)){
                            l=mid+1;
                    }
                    else{
                            h=mid-1;
                    }
            }
           
            return h;
    }
};