struct trie{
        map<int,trie*> mp;
};
trie* root;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        root=new trie();
        int n=nums1.size();
            for(int i=0;i<n;i++){
                    trie* head=root;
                    for(int j=i;j<n;j++){
                            if(head->mp[nums1[j]]==NULL){
                                    head->mp[nums1[j]]=new trie();
                            }
                            head=head->mp[nums1[j]];
                    }
            }
            int res=0;
            n=nums2.size();
            for(int i=0;i<n;i++){
                    int j=i;
                    trie* head=root;
                    while(j<n && head->mp[nums2[j]]){
                            head=head->mp[nums2[j++]];
                    }
                    res=max(res,j-i);
                    
            }
            return res;
    }
};