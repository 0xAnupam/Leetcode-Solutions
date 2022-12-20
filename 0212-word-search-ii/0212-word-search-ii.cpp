struct Tries{
        Tries* arr[26];
        bool f=0;
        int c=0;
        bool pres=0;        
};
bool valid(int i,int j,int &m,int &n){
                if(i>=0 && j>=0 &&i<m && j<n){return 1;}
                return 0;
}
vector<pair<int,int>> moves ={{0,1},{0,-1},{1,0},{-1,0}};
void dfs(vector<vector<char>>& board,int i,int j,int m,int n,vector<vector<bool>> &vis,Tries* head){
        if(!valid(i,j,m,n) || vis[i][j] || head==NULL || head->arr[board[i][j]-'a']==NULL){
                return ;
        }
        vis[i][j]=1;
        head=head->arr[board[i][j]-'a'];
        
                head->pres=1;
        
        for(auto &xy:moves){
                dfs(board,i+xy.first,j+xy.second,m,n,vis,head);
        }
        vis[i][j]=false;
}
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Tries* root=new Tries();
         for(auto &i:words){
                Tries* head=root;
                for(auto &j:i){
                        if(head->arr[j-'a']==NULL){
                                head->arr[j-'a']=new Tries();
                        }
                        head=head->arr[j-'a'];
                        head->c=1;
                }
                head->f=1;
        }   
        int m=board.size(),n=board[0].size();
            for(int i=0;i<m;i++){
                    for(int j=0;j<n;j++){
                            vector<vector<bool>>vis(m,vector<bool>(n));
                            dfs(board,i,j,m,n,vis,root);
                    }
            }
            vector<string> res;
            for(auto &i:words){
                Tries* head=root;
                for(auto &j:i){
                        if(head->arr[j-'a']==NULL){
                                head->arr[j-'a']=new Tries();
                        }
                        head=head->arr[j-'a'];
                       
                }
               if(head->pres){
                       res.push_back(i);
               }
        }   
            
            return res;
    }
};