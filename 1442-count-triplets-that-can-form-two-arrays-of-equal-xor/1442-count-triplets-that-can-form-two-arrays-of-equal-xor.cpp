class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int res=0,n=arr.size();
            
            for(int i=0;i<n;i++){
                    int y=0;
                    map<int,int> mp;
                    int x=0;
                    for(int j=i-1;j>=0;j--){
                            x^=arr[j];
                            mp[x]++;
                    }
                    for(int j=i;j<n;j++){
                            y^=arr[j];
                            
                            res+=mp[y];
                    }
                    
            }
            return res;
    }
};