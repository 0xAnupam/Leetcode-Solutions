int f(vector<int> arr,int n){
        sort(arr.begin(),arr.end());
        int res=0;
        for(int i=n-1;i>=0;i--){
                res=max(arr[i]*(n-i),res);
        }
        return res;
}
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size(),res=0;
            vector<int> arr(n);
            for(int i=0;i<m;i++){
                    for(int j=0;j<n;j++){
                            if(i==0){
                                    arr[j]=matrix[i][j];
                            }
                            else{
                                    arr[j]=(1+arr[j])*matrix[i][j];
                            }
                    }
                    res=max(res,f(arr,n));
            }
            return res;
    }
};