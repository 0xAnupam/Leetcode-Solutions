class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        sort(barcodes.begin(),barcodes.end());
            priority_queue<pair<int,int>> pq;
            int i=0,n=barcodes.size();
            while(i<n){
                    int p=barcodes[i],cnt=0;
                    while(i<n && barcodes[i]==p){
                            i++;
                            cnt++;
                    }
                    pq.push({cnt,p});
            }
            int a=-1,b=-1;
            vector<int> res;
            while(pq.size()){
                    auto p=pq.top();
                    pq.pop();
                    res.emplace_back(p.second);
                    if(a!=-1){
                            pq.push({a,b});
                    }
                    if(p.first>1){
                            a=p.first-1;
                            b=p.second;
                    }
                    else{
                            a=-1;
                    }
            }
            return res;
    }
};