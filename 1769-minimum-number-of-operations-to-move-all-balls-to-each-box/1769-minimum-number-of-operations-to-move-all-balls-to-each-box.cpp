class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
            vector<int> arr(n);
            for(int i=0;i<n;i++){
                    int j=i,k=0;
                    int res=0;
                    while(j<n ){
                            res+=(boxes[j++]-'0')*k++;
                    }
                    j=i;
                    k=0;
                    while(j>=0){
                            res+=(boxes[j--]-'0')*k++;
                    }
                    arr[i]=res;
                    
            }
            return arr;
    }
};