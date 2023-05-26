int idx(int* arr,int ele){
        for(int i=0;;i++){
                if(arr[i]==ele){
                        return i;
                }
        }
        return -1;
}
class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> res(queries.size());
            int n=queries.size();
            int arr[m];
            for(int i=0;i<m;i++){
                    arr[i]=i+1;
            }
            for(int i=0;i<n;i++){
                    int j=idx(arr,queries[i]);
                    res[i]=j;
                    while(j>0){
                            swap(arr[j],arr[j-1]);
                            j--;
                    }
            }
            return res;
    }
};