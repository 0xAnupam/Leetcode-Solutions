const int N=1e4+10;
int arr[N];
class SummaryRanges {
public:
    SummaryRanges() {
        memset(arr,0,sizeof(arr));
    }
    
    void addNum(int value) {
        arr[value]++;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
            int i=0;
            while(i<N){
                    while(i<N && arr[i]==0){
                            i++;
                    }
                    if(i<N){
                            int cnt=0,l=i;
                            while(i<N && arr[i]){
                            i++;cnt++;
                                
                         }
                            vector<int> t={l,l+cnt-1};
                            res.emplace_back(t);
                            
                    }
            }
            return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */