class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int pos=nums.size(),neg=nums.size()-1,n=nums.size();  vector<int> v;
           for(int i=0;i<n;i++){
                   if(nums[i]>-1){neg=i-1;pos=i;break;}
           }
            while(neg>=0 || pos<n){
                    if(neg<0){v.push_back(pow(nums[pos],2));pos++;}
                    else if(pos>=n){v.push_back(pow(nums[neg],2));neg--;}
                    else{
                            if(nums[pos]+nums[neg]<0){v.push_back(pow(nums[pos],2));pos++;}
                            else{
                                    v.push_back(pow(nums[neg],2));neg--;
                            }
                    }
                    
            }return v;
    }
};