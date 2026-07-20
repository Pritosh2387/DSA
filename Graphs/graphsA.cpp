#include<bits/stdc++.h>
using namespace std;
void adjacency_matrix(int nodes , int edges){
    vector<vector<int>> matrix(nodes+1,vector<int>(nodes+1,0));
    for(int i = 0 ; i < edges ; i++){
        int a,b;
        cin>>a>>b;
        matrix[a][b]=1;
        matrix[b][a]=1;
    }
}
void adjacency_list(int nodes,int edges){
    vector<vector<int>> list(nodes+1);
    for(int i = 0 ; i < edges ; i++){
        int a,b;
        cin>>a>>b;
        list[a].push_back(b);
        list[b].push_back(a);
    }
}
vector<int> BFS(vector<vector<int>>&adj,int n){
    vector<int> ans;
    queue<int> qe;
    vector<int> visi(n,0);
    qe.push(0);
    visi[0]=1;
    while(!qe.empty()){
        int node = qe.front();
        ans.push_back(node);
        qe.pop();
        for(int i : adj[node]){
            if(!visi[i]){
                qe.push(i);
                visi[i]=1;
            }
        }
    }
    return ans;
}
void dfs(vector<int>&ans,vector<int>&visi,int node,vector<vector<int>>&adj){
    visi[node]=1;
    ans.push_back(node);
    for(int i : adj[node]){
        if(!visi[i]){
            dfs(ans,visi,i,adj);
        }
    }
}
// with matrix
vector<int> DEPTH_FIRST_SEARCH(vector<int>&ans,vector<vector<int>>&matrix,vector<int>&visi,int node){
    visi[node]=1;
    ans.push_back(node);
    for(int j = 0 ; j < matrix.size() ; j++){
        if(matrix[node][j]==1 && !visi[j]){
            DEPTH_FIRST_SEARCH(ans,matrix,visi,j);
        }
    }
    return ans;
}
vector<int> DFS(vector<vector<int>>&adj,int n){
    vector<int> ans;
    vector<int> visi(n,0);
    dfs(ans,visi,0,adj);
    return ans;   
}
void depthfs(int node,vector<int>&visi,vector<vector<int>>&adj){
    visi[node]=1;
    for(int i : adj[node]){
        if(!visi[i]){
            depthfs(i,visi,adj);
        }
    }
}
int provinces(vector<vector<int>>& isConnected){
    int n =isConnected.size(); 
    vector<vector<int>> adj(n);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(isConnected[i][j]==1 && i!=j){
                adj[i].push_back(j);
            }
        }
    }
    vector<int> visi(n,0);
    int ans=0;
    for(int i = 0 ; i < n ; i++){
        if(!visi[i]){
            ans++;
            depthfs(i,visi,adj);
        }
    }
    return ans;
}
int rooten_eggs(vector<vector<int>>&grid){
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<pair<int,int>,int>>qe;
    vector<vector<int>>visi(n,vector<int>(m,0));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(grid[i][j]==2){
                qe.emplace(make_pair(i,j),0);
                visi[i][j]=2;
            }
        }
    }
    int ans=0;
    while(!qe.empty()){
        int row = qe.front().first.first;
        int col = qe.front().first.second;
        int time = qe.front().second;
        qe.pop();
        ans=max(ans,time);
        vector<int>rowdel={-1,0,1,0};
        vector<int>coldel={0,-1,0,1};
        for(int i = 0 ; i < 4 ; i++){
            int nrow=row+rowdel[i];
            int ncol = col+coldel[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visi[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                qe.emplace(make_pair(nrow,ncol),time+1);
                visi[nrow][ncol]=2;
            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(visi[i][j]!=2 &&grid[i][j]==1){
                return -1;
            }
        }
    }
    return ans;
}
void dfs_for_flood_fill(vector<vector<int>>&image,int sr, int sc, int newcolor,int inicolor,vector<int>&delrow,vector<int>delcol){
    if(image[sr][sc]==newcolor)return;
    image[sr][sc]=newcolor;
    int n = image.size();
    int m = image[0].size();
    for(int i = 0 ; i < 4 ; i++){
        int newr=sr+delrow[i];
        int newc=sc+delcol[i];
        if(newc>=0 && newr<n && newr>=0 && newc<m && image[newr][newc]==inicolor){
            dfs_for_flood_fill(image,newr,newc,newcolor,inicolor,delrow,delcol);
        }
    }
    return;
}
vector<vector<int>> flood_fill(vector<vector<int>>&image,int sr, int sc, int newcolor){
    int inicolor = image[sr][sc];
    vector<int>delrow={-1,0,1,0};
    vector<int>delcol={0,1,0,-1};
    dfs_for_flood_fill(image,sr,sc,newcolor,inicolor,delrow,delcol);
    return image;
}
// By BFS
bool detectcycle(int s ,vector<vector<int>>&adj,vector<int>&visi){
    queue<pair<int,int>> qe;
    qe.emplace(s,-1);
    visi[s]=1;
    while(!qe.empty()){
        int parent = qe.front().second;
        int node = qe.front().first;
        qe.pop();
        for(int it : adj[node]){
            if(!visi[it]){
                visi[it]=1;
                qe.emplace(it,node);
            }else if(parent!=it){
                return true;
            }
        }
    }
    return false;
}
bool iscycle(vector<vector<int>>&adj,int n){
    vector<int>visi(n,0);
    for(int i = 0 ; i < n ; i++){
        if(!visi[i]){
            if(detectcycle(i,adj,visi)){
                return true;
            }
        }
    }
    return false;
}
// By DFS
bool detectcycleDFS(int s,int parent ,vector<vector<int>>&adj,vector<int>&visi){
    visi[s]=1;
    for(int it : adj[s]){
        if(visi[it]==0){
            if(detectcycleDFS(it,s,adj,visi)){
                return true;
            }
        }else if(it!=parent){
            return true;
        }
    }
    return false;
}
bool iscycleDFS(vector<vector<int>>&adj,int n){
    vector<int>visi(n,0);
    for(int i = 0 ; i < n ; i++){
        if(!visi[i]){
            if(detectcycleDFS(i,-1,adj,visi)){
                return true;
            }
        }
    }
    return false;
}
vector<vector<int>> nearest1(vector<vector<int>>&matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    queue<pair<pair<int,int>,int>> qe;
    vector<vector<int>> visi(n,vector<int>(m,0));
    vector<vector<int>> ans(n,vector<int>(m,0));
    for(int i = 0 ; i < matrix.size() ; i++){
        for(int j = 0 ; j < matrix[0].size() ; j++){
            if(matrix[i][j]==1){
                qe.emplace(make_pair(i,j),0);
                visi[i][j]=1;
            }
        }
    }
    while(!qe.empty()){
        int row = qe.front().first.first;
        int col = qe.front().first.second;
        int dist = qe.front().second;
        qe.pop();
        ans[row][col]=dist;
        vector<int> delrow = {1,0,-1,0};
        vector<int> colrow = {0,-1,0,1};
        for(int i  = 0 ; i < 4 ; i++){
            int nrow = row+delrow[i];
            int ncol = col+colrow[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visi[nrow][ncol]){
                visi[nrow][ncol]=1;
                qe.emplace(make_pair(nrow,ncol),dist+1);
            }
        }
    }
    return ans;
}
void dfs_for_fill(int row,int col ,vector<vector<char>>&mat,vector<vector<int>>&visi){
    int n = mat.size();
    int m = mat[0].size();
    visi[row][col]=1;
    vector<int>delrow={-1,0,1,0};
    vector<int>delcol={0,-1,0,1};
    for(int i = 0 ; i < 4 ; i++){
        int nrow = row+delrow[i]; 
        int ncol = col+delcol[i];
        if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !visi[nrow][ncol] && mat[nrow][ncol]=='O'){
            dfs_for_fill(nrow,ncol,mat,visi);
        }
    }
}
vector<vector<char>> fill(vector<vector<char>>&mat){
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>>visi(n,vector<int>(m,0));
    for(int j = 0 ; j < m ; j++){
        if(!visi[0][j]&& mat[0][j] == 'O'){
            dfs_for_fill(0,j,mat,visi);
        }
        if(!visi[n-1][j]&& mat[n-1][j] == 'O'){
            dfs_for_fill(n-1,j,mat,visi);
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(!visi[i][0] && mat[i][0] == 'O'){
            dfs_for_fill(i,0,mat,visi);
        }
        if(!visi[i][m-1]&& mat[i][m-1] == 'O'){
            dfs_for_fill(i,m-1,mat,visi);
        }
    }
    for(int i = 0 ; i < n ; i++ ){
        for(int j = 0 ; j < m ; j++){
            if(!visi[i][j] && mat[i][j]=='O'){
                mat[i][j]='X';
            }
        }
    }
    return mat;
}
int land_seas(vector<vector<int>>&mat){
    int ans=0;
    int n = mat.size();
    int m = mat[0].size();
    queue<pair<int,int>>qe;
    vector<vector<int>>visi(n,vector<int>(m,0));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(i ==0 || i==n-1 || j == 0 || j==m-1){
                if(mat[i][j]==1){
                    qe.emplace(i,j);
                    visi[i][j]=1;
                }
            }
        }
    }
    while(!qe.empty()){
        int row = qe.front().first;
        int col = qe.front().second;
        qe.pop();
        vector<int>delrow = {1,0,-1,0};
        vector<int>delcol = {0,1,0,-1};
        for(int i = 0 ; i <4 ; i++){
            int nrow = row + delrow[i]; 
            int ncol = col + delcol[i];
            if(nrow>=0 && ncol >=0 && nrow < n && ncol < m && !visi[nrow][ncol] && mat[nrow][ncol]==1){
                qe.emplace(nrow,ncol);
                visi[nrow][ncol]=1;
            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(visi[i][j]==0 && mat[i][j]==1){
                ans++;
            }
        }
    }
    return ans;
}
void dfs_landseasII(int row , int col,int baserow,int basecol,vector<pair<int,int>>&vec,vector<vector<int>> &visi,vector<vector<int>>&matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    visi[row][col]=1;
    vec.emplace_back(row-baserow,col-basecol);
    vector<int>delrow={-1,0,1,0};
    vector<int>delcol={0,-1,0,1};
    for(int i = 0 ; i < 4 ; i++){
        int nr = row+delrow[i];
        int nc = col + delcol[i];
        if(nr>=0 && nc>=0 && nr< n && nc<m && !visi[nr][nc]&& matrix[nr][nc]){
            dfs_landseasII(nr,nc,row,col,vec,visi,matrix);
        } 
    }
}
int landseas_II(vector<vector<int>>&matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> visi(n,vector<int>(m,0));
    set<vector<pair<int,int>>> seti;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(!visi[i][j]){
                vector<pair<int,int>> vec;
                dfs_landseasII(i,j,i,j,vec,visi,matrix);
                seti.insert(vec);
            }
        }
    }
    return seti.size();
}
int word_ladder(string strt , string end , vector<string>&wordlist){
    unordered_set<string> seti(wordlist.begin(),wordlist.end());
    queue<pair<string,int>> qe;
    qe.emplace(strt,1);
    seti.erase(strt);
    while(!qe.empty()){
        string word = qe.front().first;
        int steps = qe.front().second;
        qe.pop();
        if(word==end)return steps;
        for(int i = 0 ; i < word.length() ; i++){
            char orig = word[i];
            for(char ch = 'a' ; ch <= 'z' ; ch++){
                word[i]=ch;
                if(seti.find(word)!=seti.end()){
                    qe.emplace(word,steps+1);
                    seti.erase(word);
                }
            } 
            word[i]=orig;
        } 
    }
    return 0;
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList){
    vector<vector<string>> ans;
    unordered_set<string> seti(wordList.begin(),wordList.end());
    queue<vector<string>> q;
    vector<string> inorder;
    inorder.push_back(beginWord);
    q.push(inorder);
    int level = 0; 
    while(!q.empty()){
        vector<string> vec = q.front();
        q.pop();
        if(vec.size()>level){
            level++;
            for(auto it : inorder){
                seti.erase(it);
            }
            inorder.clear();
        }
        string wordb = vec.back();
        if(wordb==endWord){
            if(ans.size()==0){
                ans.push_back(vec);
            }else if(ans[0].size()==vec.size()){
                ans.push_back(vec);
            }
        }
        for(int i = 0 ; i < wordb.size() ; i++){
            char c = wordb[i];
            for(char ch = 'a' ; ch <='z' ; ch++){
                wordb[i]=ch;
                if(seti.count(wordb)>0){
                    inorder.push_back(wordb);
                    vec.push_back(wordb);
                    q.push(vec);
                    vec.pop_back();
                }
                wordb[i]=c;
            }
        }
    }
    return ans;
}
// CP 
unordered_map<string,int>mpp;
vector<vector<string>> ans;
string str;
void dfs_word(string s , vector<string>&vec){
    if(s==str){
        reverse(vec.begin(),vec.end());
        ans.push_back(vec);
        reverse(vec.begin(),vec.end());
        return;
    }
    int lev = mpp[s];
    int size = str.size();
    for(int i = 0 ; i < size ; i++){
            char c = s[i];
            for(char ch='a' ; ch<='z' ; ch++){
                s[i]=ch;
                if(mpp.find(s)!=mpp.end() && mpp[s]+1==lev){
                    vec.push_back(s);
                    dfs_word(s,vec);
                    vec.pop_back();
                }
            }
            s[i]=c;
        }
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList){
    str = beginWord;
    mpp[beginWord]=1;
    queue<string> q;
    unordered_set<string> seti(wordList.begin(),wordList.end());
    q.push(beginWord);
    seti.erase(beginWord);
    int size = beginWord.size();
    while(!q.empty()){
        string word = q.front();
        int level = mpp[word];
        q.pop();
        if(word==endWord)break;
        for(int i = 0 ; i < size ; i++){
            char c = word[i];
            for(char ch='a' ; ch<='z' ; ch++){
                word[i]=ch;
                if(seti.count(word)){
                    seti.erase(word);
                    q.push(word);
                    mpp[word]=level+1;
                }
            }
            word[i]=c;
        }
    }
    if(mpp.find(endWord)!=mpp.end()){
        vector<string> vec;
        vec.push_back(endWord);
        dfs_word(endWord,vec);
    }
    return ans;
}
bool bfs_bipartite(int v,vector<vector<int>>&adj,vector<int>&visi){
    visi[v]=0;
    queue<int>qe;
    qe.push(v);
    while(!qe.empty()){
        int node = qe.front();
        qe.pop();
        for(int it : adj[node]){
            if(visi[it]==-1){
                visi[it]= !visi[node];
                qe.push(it);
            }else if(visi[it]==visi[node]){
                return false;
            }
        }
    }
    return true;
}
bool dfs_bipartite(int node,int color,vector<int>&visi,vector<vector<int>>&adj){
    visi[node]=color;
    for(int it : adj[node]){
        if(visi[it]==-1){
            if(dfs_bipartite(it,!color,visi,adj)==false)return false;
        }else if(visi[it]==color){
            return false;
        }
    }
    return true;
}
bool bipartite(vector<vector<int>>&adj){
    int n = adj.size();
    vector<int>visi(n,-1);
    for(int i = 0 ; i < n ; i++){
        if(visi[i]==-1){
            if(dfs_bipartite(i,0,visi,adj)==false)return false;
        }
    }
    return true;
}
void bfs_isII(int row, int col, vector<vector<int>>&mat,vector<vector<int>>&visi){
    int n = mat.size();
    int m = mat[0].size();
    queue<pair<int,int>> qe;
    visi[row][col]=1;
    qe.emplace(row,col);
    while(!qe.empty()){
        int r = qe.front().first;
        int c = qe.front().second;
        for(int i = -1 ;  i <=1 ;i++){
            for(int j = -1 ;  j <= 1 ; j++){
                int nrow = r +i;
                int ncol = c +j;
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !visi[nrow][ncol] && mat[nrow][ncol]==1){
                    visi[nrow][ncol]=1;
                    qe.emplace(nrow,ncol);
                }
            }
        }
    }
}
int island_II(vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();
    int ans=0;
    vector<vector<int>>visi(n,vector<int>(m,0));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(!visi[i][j] && mat[i][j]){
                bfs_isII(i,j,mat,visi);
                ans++;
            }
        }
    }
    return ans;
}
// Cycle detection in directed graph (DFS)
bool iscycledfs_dg(vector<int>&visi,vector<int>&path_visi,int node , vector<vector<int>>&adj){
    visi[node]=1;
    path_visi[node]=1;
    for(int it : adj[node]){
        if(!visi[it]){
            if(iscycledfs_dg(visi,path_visi,it,adj)){
                return true;
            }
        }else if(path_visi[node]){
            return true;
        }
    }
    path_visi[node]=0;
    return false;
}
bool detect_cycle_dg(int n , vector<vector<int>>&adj){
    vector<int>visi(n,0);
    vector<int> path_visi(n,0);
    for(int i = 0 ; i < n ; i++){
        if(!visi[i]){
            if(iscycledfs_dg(visi,path_visi,i,adj)){
                return true;
            }
        }
    }
    return false;
}
bool dfseventual_safe_states(int node ,vector<int>&visi,vector<int>&pathvisi,vector<int>&check,vector<vector<int>>&adj){
    visi[node]=1;
    pathvisi[node]=1;
    for(int it : adj[node]){
        if(!visi[it]){
        if(dfseventual_safe_states(it,visi,pathvisi,check,adj)){   
            return true;
        }
        }else if(pathvisi[it]){
            return true;
        }
    }
    check[node]=1;
    pathvisi[node]=0;
    return false;
}
vector<int> safe_states(vector<vector<int>>&adj,int n){
    vector<int> ans;
    vector<int>visi(n,0);
    vector<int>pathvisi(n,0);
    vector<int> check(n,0);
    for(int i = 0 ; i < n ; i++){
        if(!visi[i]){
            dfseventual_safe_states(i,visi,pathvisi,check,adj);
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(check[i]){
            ans.push_back(i);
        }
    }
    return ans;
}
void dfs_topo(vector<int>&visi,int node,vector<vector<int>>&adj,stack<int>&st){
    visi[node]=1;
    for(int it : adj[node]){
        if(!visi[it]){
            dfs_topo(visi,it,adj,st);
        }
        st.push(it);
    }
}
vector<int> topo_sort(int n , vector<vector<int>>adj){
    stack<int>st;
    vector<int>ans;
    vector<int>visi(n,0);
    for(int i = 0 ; i < n ; i++){
        if(!visi[i]){
            dfs_topo(visi,i,adj,st);
        }
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
// BY  BFS
vector<int> topo_sort(int n,vector<vector<int>>adj){
    vector<int>ans;
    vector<int>indergree(n,0);
    queue<int> qe;
    for(int i = 0 ; i < n ; i++){
        for(int it : adj[i]){
            indergree[it]++;
        }
    }
    for(int i = 0 ; i<n ; i++){
        if(indergree[i]==0){
            qe.push(i);
        }
    }
    while(!qe.empty()){
        int node = qe.front();
        qe.pop();
        ans.push_back(node);
        for(auto it : adj[node]){
            indergree[it]--;
            if(indergree[it]==0){
                qe.push(it);
            }
        }
    }
    return ans;
}
bool cycledetectionbydfrs(vector<vector<int>>&adj,int n){
    queue<int>qe;
    vector<int>indegree(n,0);
    for(int i = 0 ; i < n ; i++){
        for(int it : adj[i]){
            indegree[it]++;
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(indegree[i]==0){
            qe.push(i);
        }
    }
    int cnt = 0; 
    while(!qe.empty()){
        int node = qe.front();
        qe.pop();
        cnt++;
        indegree[node]--;
        for(int it : adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                qe.push(it);
            }
        }
        
    }
    if(cnt==n){
        return false;
    }else{
        return true;
    }
}
vector<int> course_schedule(vector<pair<int,int>>&pre,int n){
    vector<vector<int>>adj(n);
    vector<int>indegree(n,0);
    for(auto it : pre){
        adj[it.first].push_back(it.second);
        indegree[it.second]++;
    }
    queue<int>qe;
    for(int i = 0 ;i<n ;i++){
        if(indegree[i]==0){
            qe.push(i);
        }
    }
    vector<int>ans;
    while(!qe.empty()){
        int node = qe.front();
        ans.push_back(node);
        qe.pop();
        for(int it : adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                qe.push(it);
            }
        }
    }
    if(ans.size()==n)return ans;
    else return {};
}
vector<int> safe_states(int n,vector<vector<int>>&adj){
    vector<vector<int>> adjrev(n);
    queue<int>qe;
    vector<int>ans;
    vector<int>indeg(n,0);
    for(int i = 0 ; i < n ; i++){
        for(int it : adj[i]){
            adjrev[it].push_back(i);
            indeg[i]++;
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(indeg[i]==0){
            qe.push(i);
        }
    }
    while(!qe.empty()){
        int node = qe.front();
        qe.pop();
        ans.push_back(node);
        for(int it : adjrev[node]){
            indeg[it]--;
            if(indeg[it]==0){
                qe.push(it);
            }
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
string ailen_dict(vector<string>&dict, int k){
    int n = dict.size();
    vector<vector<int>>adj(k);
    for(int i = 0 ; i < n-1 ;i++){
        string s1 = dict[i];
        string s2 = dict[i+1];
        int minl = min(s1.length(),s2.length());
        for(int j = 0 ; j <  minl ; j++){
            if(s1[j]!=s2[j]){
                adj[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
        }
    }
    vector<int>topo = topo_sort(k,adj);
    string ans="";
    for(auto it : topo){
        ans+=char(it+'a');
    }
    return ans;
}
// in  DACG
void dfstopo_shortestdist(int node , vector<vector<pair<int,int>>>&adj,stack<int>&st,vector<int>&visi){
    visi[node]=1;
    for(auto it : adj[node]){
        if(!visi[it.first]){
            dfstopo_shortestdist(it.first,adj,st,visi);
        }
    }
    st.push(node);
}
vector<int> shortest_distance(vector<vector<int>>&edges,int n){
    int m = edges.size(); 
    vector<vector<pair<int,int>>> adj(n);
    for(int i = 0 ; i < m ; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].emplace_back(adj[v],wt);
    }
    stack<int> st;
    vector<int>visi(n,0);
    for(int i = 0 ; i < n ; i++){
        if(!visi[i]){
            dfstopo_shortestdist(i,adj,st,visi);
        }
    }
    vector<int>ans(n,INT_MAX);
    ans[0]=0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        for(auto it : adj[node]){
            int u = it.first;
            int wt = it.second;
            if(ans[node]+wt<ans[u]){
                ans[u]=ans[node]+wt;
            }
        }
    }
    return ans;
}
// In UNDCG
vector<int> shortest_ist(vector<vector<int>>&edges,int n,int src){
    int m = edges.size();
    vector<vector<int>>adj(n);
    for(int i = 0 ; i < m ; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int>qe;
    vector<int>dist(n,INT_MAX);
    qe.push(src);
    dist[src]=0;
    while(!qe.empty()){
        int node= qe.front();
        qe.pop();
        for(int it : adj[node]){
            if(dist[node]+1<dist[it]){
                dist[it]=dist[node]+1;
                qe.push(it);
            }
        }
    }
    return dist;
}
int main(){
    return 0;
}