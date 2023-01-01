class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        map<long long,long long>mp;
            long long res=0,m=1e9+7;
            sort(arr.begin(),arr.end());
            for(auto &i:arr){
                   mp[i]++;
            }
            int i=0,n=arr.size();
            while(i<n-2){
                    long long cur=mp[arr[i]];
                    mp[arr[i]]--;
                    int j=i+1;while(j<n-1){
                            long long cur2=mp[arr[j]];
                            
                            auto p=lower_bound(arr.begin()+j+1,arr.end(),target-arr[i]-arr[j]);
                            if(p!=arr.end() && target==arr[i]+arr[j]+*p){
                                //    cout<<arr[i]<< ' '<<arr[j]<<" "<<*p<<'\n';
                                    if(arr[i]==arr[j] && arr[j]==*p){
                                            res+=((cur*(cur-1)*(cur-2))/6);
                                    }
                                    else if(arr[i]==arr[j]){
                                            res+=(cur*(cur-1)*mp[*p])/2;
                                            //cout<<arr[i]<< ' '<<arr[j]<<" "<<*p<<'\n';
                                    }
                                    else if(arr[j]==*p ){
                                            
                                            res+=((cur*cur2*(cur2-1))/2);
          
                                    }
                                    else{
                                            res+=(cur*cur2*mp[*p])%m;
 
                                    }
                                    res%=m;
                            }
                            int P=arr[j];
                            while(j<n-1 && arr[j]==P){
                                    j++;
                            }
                    }
                    int p=arr[i];
                    while(i<n-2 && arr[i]==p){
                            i++;
                            
                    }
            }
            return res;
    }
};