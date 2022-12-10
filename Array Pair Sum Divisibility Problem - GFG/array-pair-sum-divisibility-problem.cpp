//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        map<int,int> mp;
        for(auto &i:nums){
            mp[i%k]++;
        }
        mp[k]=mp[0];
        for(auto &i:mp){
            if(mp[k-i.first]!=i.second){
                return 0;
            }
            if(i.first*2==k){
                if(i.second&1){
                    return 0;
                }
            }
        }
        return mp[0]%2==0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends