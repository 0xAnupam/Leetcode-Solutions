class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<pair<int,int>> a,b,c,d;
            int n=nums.size();
            vector<int> A(n),B=A,C=A,D=A;
            a.push({INT_MAX,-1});
            for(int i=0;i<n;i++){
                    while(a.top().first<nums[i]){
                            a.pop();
                    }
                    A[i]=a.top().second;
                    a.push({nums[i],i});
            }
            b.push({INT_MAX,n});
            for(int i=n-1;i>=0;i--){
                    while(b.top().first<=nums[i]){
                            b.pop();
                    }
                    B[i]=b.top().second;
                    b.push({nums[i],i});
            }
            c.push({INT_MIN,-1});
            for(int i=0;i<n;i++){
                    while(c.top().first>nums[i]){
                            c.pop();
                    }
                    C[i]=c.top().second;
                    c.push({nums[i],i});
            }
            d.push({INT_MIN,n});
            for(int i=n-1;i>=0;i--){
                    while(d.top().first>=nums[i]){
                            d.pop();
                    }
                    D[i]=d.top().second;
                    d.push({nums[i],i});
            }
            long long res=0;
            for(long long i=0;i<n;i++){
                    long long contri=nums[i];
                    contri*=((i-A[i])*(B[i]-i)-(i-C[i])*(D[i]-i));
                    res+=contri;
            }
            return res;
    }
};