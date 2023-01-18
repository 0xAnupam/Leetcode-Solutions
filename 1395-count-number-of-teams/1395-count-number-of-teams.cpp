class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        int res=0;
            for(int i=1;i<n-1;i++){
                    int j=i-1,a=0,b=0,c=0,d=0;
                    while(j>=0){
                            if(rating[i]>rating[j]){
                                    a++;
                            }
                            else{
                                    b++;
                            }
                            j--;
                    }
                    j=i+1;
                    while(j<n){
                            if(rating[i]>rating[j]){
                                    c++;
                            }
                            else{
                                    d++;
                            }
                            j++;
                    }
                  res+=(a*d+b*c);
                    
            }
            return res;
    }
};