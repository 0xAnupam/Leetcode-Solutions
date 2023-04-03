class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> a,b;
            int n=version1.size();
            int i=0;
            while(i<n){
                    int cnt=0;
                    while(i<n && version1[i]!='.'){
                            cnt*=10;
                            cnt+=(version1[i]-'0');
                            i++;
                    }
                    i++;
                    a.push_back(cnt);
            }
            n=version2.size();
            i=0;
             while(i<n){
                    int cnt=0;
                    while(i<n && version2[i]!='.'){
                            cnt*=10;
                            cnt+=(version2[i]-'0');
                            i++;
                    }
                    i++;
                    b.push_back(cnt);
            }
            i=0;
            n=a.size();
            int m=b.size(),N=min(n,m);
            while(i<N){
                    if(a[i]>b[i]){
                            return 1;
                    }
                    if(a[i]<b[i]){
                            return -1;
                    }
                    i++;
            }
            while(i<n){
                    if(a[i]){
                            return 1;
                    }
                    i++;
            }
            while(i<m ){
                    if(b[i]){
                            return -1;
                    }

                    i++;
            }
            return 0;
    }
};