class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
            int *l=new int[n],*r=new int[n];
            int p=0,s=0,res=0;
            for(int i=0;i<n;i++){
                    l[i]=p;
                    r[n-1-i]=s;
                    p+=arr[i];
                    s+=arr[n-1-i];
                    p=max(0,p);
                    s=max(0,s);
                    res+=arr[i];
            }
            for(int i=0;i<n;i++){
                    res=max(res,l[i]+r[i]);
            }
            return res <1 ? *max_element(arr.begin(),arr.end()):res;
    }
};