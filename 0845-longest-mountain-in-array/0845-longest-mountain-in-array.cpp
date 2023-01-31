class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int res=0,n=arr.size(),i=0;
        while(i<n-res){
                int cnt=1,p=arr[i++];
                bool f1=0;
                while(i<n && arr[i]>p){
                        cnt++;
                        f1=1;
                        p=arr[i++];
                }bool f=0;
                while(i<n && arr[i]<p){
                        cnt++;
                        f=1;
                        p=arr[i++];
                }
                if(f){
                        i--;
                }
                if(f1&&  f && cnt>=3){
                res=max(res,cnt);
                }
        }
            return res;
    }
};