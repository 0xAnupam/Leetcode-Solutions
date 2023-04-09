class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
     sort(people.begin(),people.end());
            int i=0;
            int n=people.size();
            for(int i=n-1;i>=0;i--){
                    int cnt=0;
                    for(int j=0;j<i;j++){
                            if(people[j][0]>=people[i][0]){
                                    cnt++;
                            }
                    }
                    int j=i+1,p=people[i][1];
                    while(j<n && p-cnt>0){
                            if(people[j-1][0]<=people[j][0]){
                                    cnt++;
                                    swap(people[j-1],people[j]);
                            }
                            j++;
                    }
            }
            return people;
    }
};