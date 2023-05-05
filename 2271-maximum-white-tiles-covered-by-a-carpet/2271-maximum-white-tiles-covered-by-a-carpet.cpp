class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
       sort(tiles.begin(),tiles.end());
            
       int res=0,n=tiles.size();
       int arr[n],sum[n];     
       for(int i=0;i<n;i++){
               arr[i]=(tiles[i][1]-tiles[i][0]+1);
               sum[i]=arr[i];
               if(i){
                       sum[i]+=sum[i-1];
               }
       }
            vector<int> t={0+carpetLen,0};
       for(int i=0;i<n;i++){
               t[0]=tiles[i][0]+carpetLen;
               auto it=lower_bound(tiles.begin()+i,tiles.end(),t)-tiles.begin();
               it--;
               int q=sum[it];
               if(i){
                       q-=sum[i-1];
               }
               q-=arr[it];
               q+=(min(tiles[i][0]+carpetLen-1,tiles[it][1])-tiles[it][0]+1);
               // cout<<i<<'\t'<<q<<'\n';
               res=max(res,q);
               
       }     return res;
    }
};