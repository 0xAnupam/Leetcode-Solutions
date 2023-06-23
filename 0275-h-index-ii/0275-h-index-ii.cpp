class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l=1,h=1e3,m,n=citations.size();
            while(l<=h){
                    m=(l+h)/2;
                    int idx=lower_bound(citations.begin(),citations.end(),m)-citations.begin();
                    if(n-idx>=m){
                            l=m+1;
                    }
                    else{
                            h=m-1;
                    }
            }
            return h;
    }
};