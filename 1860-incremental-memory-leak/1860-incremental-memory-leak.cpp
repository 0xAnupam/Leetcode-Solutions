class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        vector<int> res;
            for(int i=1;;i++){
                    if(memory1>=memory2){
                            if(i>memory1){
                                    return {i,memory1,memory2};
                            }
                            memory1-=i;
                    }
                    else{
                            if(i>memory2){
                                    return {i,memory1,memory2};
                            }
                            memory2-=i;
                    }
            }
            return res;
    }
};