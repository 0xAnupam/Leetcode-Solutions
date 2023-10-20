class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
            vector<int> arr(n),min_req(n);
            int sum=0,m=0;
            for(int i=0;i<n;i++){
                    min_req[i]=m;
                    arr[i]=gas[i]-cost[i];
                    sum+=arr[i];
                    m=min(m,sum);
            }
           int res=-1;
            sum=0;
            m=0;
            for(int i=n-1;i>=0;i--){
                    m+=arr[i];
                    sum+=arr[i];
                    
                    if(m>=0 && sum+min_req[i]>=0){
                            res=i;
                    }
                    m=min(m,0);
            }
            return res;
            
    }
};