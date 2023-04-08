class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int N=(1<<17);
            int arr[N+100];
            memset(arr,0,sizeof(arr));
            for(auto &i:nums){
                    int r=0;
                    for(auto &c:i){
                        r<<=1;
                        r+=(c-'0');    
                    }
                   arr[r]++;
            }
            int n=nums.size(),i=0;
            while(i<N && arr[i]){
                    
                    i++;
            }
            string res="";
            for(int j=0;j<n;j++){
                    if((1<<j)&i){
                            res+='1';
                    }
                    else{
                            res+='0';
                    }
            }
            reverse(res.begin(),res.end());
            
            return res;
    }
};