class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
          int maxi=max(arr[1],arr[0]);
            if(k==1){
                    return maxi;
            }
            int n=arr.size();
            int cnt=1;
            for(int i=2;i<n;i++){
                    if(maxi>arr[i]){
                            cnt++;
                    }
                    else{
                            maxi=arr[i];
                            cnt=1;
                    }
                    if(cnt==k){
                            return maxi;
                    }
            }
            return maxi;
    }
};