bool pos(vector<int>&arr,int k,int &m,int &n){
        int i=0;
        while(i<n){
                auto p=lower_bound(arr.begin()+i,arr.end(),arr[i]+m)-arr.begin();
                if(p==n){
                        return 0;
                }
                i=p;
                k--;
                if(k==0){
                        return 1;
                }       
        }
        return 0;
}
class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
            int n=price.size();
           int l=0,h=price[n-1]-price[0],m;
            while(l<=h){
                    m=l+(h-l)/2;
                    if(pos(price,k-1,m,n)==false){
                            h=m-1;
                    }
                    else{
                            l=m+1;
                    }
            }
            return h;
    }
};