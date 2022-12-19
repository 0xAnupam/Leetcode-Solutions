//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 



// } Driver Code Ends
class Solution{
  public:
    int maxDistance(int arr[], int n) 
    {   
        for(int i=0;i<n;i++){
            arr[i]-=i;
        }
        int res= *max_element(arr,arr+n)-*min_element(arr,arr+n);
        for(int i=0;i<n;i++){
            arr[i]+=2*i;
        }
        return max(res, *max_element(arr,arr+n)-*min_element(arr,arr+n));
    } 
};

//{ Driver Code Starts.
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i<n; i++)
	        cin>>arr[i];
	    Solution obj;
	    cout<<obj.maxDistance(arr, n)<<endl;
	}
} 

// } Driver Code Ends