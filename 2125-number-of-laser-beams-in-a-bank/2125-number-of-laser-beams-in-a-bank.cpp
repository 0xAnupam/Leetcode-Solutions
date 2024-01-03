class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
       int i=0,j=1,n=bank.size(), sum=0;
        while(i<n && j<n){
            int laser1=0;
            int laser2=0;
            for(auto a: bank[i]){
                    if (a=='1')laser1++;
            }
            for(auto a: bank[j]){
                    if (a=='1')laser2++;
            }
            int t=laser1*laser2;
            sum+=t;
            if(laser1==0)i++;
            if(t>0)i=j;
            j++;   
        }
        return sum;
        
    }
};