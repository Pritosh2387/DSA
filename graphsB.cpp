#include<bits/stdc++.h>
using namespace std;
// By PQ(Min-Heap)
vector<int> dijkstra(int v,vector<vector<vector<int>>>&adj,int src){
    vector<int> dist(v,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.emplace(0,src);
    dist[src]=0;
    while(!pq.empty()){
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it : adj[node]){
            int adjnode = it[0];
            int adjdist = it[1];
            if(distance+adjdist<dist[adjnode]){
                dist[adjnode]=distance+adjdist;
                pq.emplace(distance+adjdist,adjnode);
            }
        }
    }
    return dist;
}
// By Set
vector<int> dijkstra_set(int v,vector<vector<vector<int>>>&adj,int src){
    set<pair<int,int>>st;
    st.insert(make_pair(0,src));
    vector<int>dist(v,INT_MAX);
    while(!st.empty()){
        auto it = *(st.begin());
        int node = it.first;
        int distance = it.second;
        for(auto it : adj[node]){
            int adjnode = it[0]; 
            int adjwt = it[1];
            if(distance+adjwt<dist[adjnode]){
                if(dist[adjnode]!=INT_MAX){
                    st.erase(make_pair(dist[adjnode],adjnode));
                    dist[adjnode]=distance+adjwt;
                }
                st.insert(make_pair(distance+adjwt,node));
            }
        }
    }
    return dist;
}
vector<int> print_shortest_path(vector<vector<int>>&edges,int n , int m){
    vector<vector<pair<int,int>>>adj(n+1);
    for(int i = 0 ; i < m ; i++){
        adj[edges[i][0]].emplace_back(edges[i][1],edges[i][2]);
        adj[edges[i][1]].emplace_back(edges[i][0],edges[i][2]);
    }
    vector<int>parent(n+1);
    vector<int>distance(n+1,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    distance[1]=0;
    for(int i = 1 ; i <= n ; i++)parent[i]=i;
    pq.emplace(0,1);
    while(!pq.empty()){
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it : adj[node]){
            int adjnode = it.first;
            int adjdist = it.second;
            if(dist+adjdist<distance[adjnode]){
                distance[adjnode]=dist+adjdist;
                parent[adjnode]=node;
                pq.emplace(dist+adjdist,adjnode);
            }
        }
    }
    if(distance[n]==INT_MAX)return{-1};
    vector<int>ans;
    int node = n;
    while(parent[node]!=node){
        ans.push_back(node);
        node = parent[node];
    }
    ans.push_back(1);
    reverse(ans.begin(),ans.end());
    return ans;
}
int shortestPathBinaryMatrix(vector<vector<int>>& grid){
    int n = grid.size();
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;
    if(n==1)return 1;
    queue<pair<int,pair<int,int>>>qe;
    vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
    qe.emplace(1,make_pair(0,0));
    dist[0][0]=1;
    vector<int>delrow={1,0,-1,0,-1,1,1,-1};         
    vector<int>delcol={0,-1,0,1,1,1,-1,-1};
    while(!qe.empty()){
        int distance = qe.front().first;
        int r = qe.front().second.first;
        int c = qe.front().second.second;
        qe.pop();
        for(int i = 0 ; i < 8 ; i++){
            int nr = r+delrow[i];
            int nc = c+delcol[i];
            if(nr>=0 && nc >=0 && nc < n && nr<n && grid[nr][nc]==0 && distance+1<dist[nr][nc]){
                if(nr == n-1 && nc == n-1)return distance+1;
                dist[nr][nc]=distance+1;
                qe.emplace(distance+1,make_pair(nr,nc));
            }
        }
    }
    return -1;  
}
int minimumEffortPath(vector<vector<int>>&heights){
    int n = heights.size();
    int m = heights[0].size();
    priority_queue< pair<int,pair<int,int>>
    ,vector<pair<int,pair<int,int>>>
    ,greater<pair<int,pair<int,int>>>>pq;
    pq.emplace(0,make_pair(0,0));
    vector<vector<int>>dist(n,(vector<int>(m,INT_MAX)));
    dist[0][0]=0;
    vector<int>delrow = {1,0,-1,0};
    vector<int>delcol = {0,-1,0,1};
    while(!pq.empty()){
        auto it = pq.top();
        int distance = it.first;
        int row = it.second.first;
        int col = it.second.second;
        pq.pop();
        if(row == n-1 && col ==m-1){
            return distance;
        }
        for(int i = 0 ; i < 4 ; i++){
            int nr = row+delrow[i];
            int nc = col+delcol[i];
            if(nr>=0 && nr < n && nc >=0 && nc < m){
                int maxeffort = max(abs(heights[nr][nc]-heights[row][col]),distance);
                if(maxeffort<dist[nr][nc]){
                    dist[nr][nc]=maxeffort;
                    pq.emplace(maxeffort,make_pair(nr,nc));
                }
            }
        }   
    }
}
int findCheapestPrice(int n,vector<vector<int>>&flights,int src,int dst,int k){
    vector<vector<pair<int,int>>>adj(n);
    for(int i = 0 ; i < flights.size() ; i++){
        adj[flights[i][0]].emplace_back(flights[i][1],flights[i][2]);
    }
    queue<pair<int,pair<int,int>>>qe;
    vector<int>dist(n,INT_MAX);
    qe.emplace(0,make_pair(src,0));
    dist[src]=0;
    while(!qe.empty()){
        int stops = qe.front().first;
        int node = qe.front().second.first;
        int distance = qe.front().second.second;
        qe.pop();
        if(stops>k)continue;
        for(auto it : adj[node]){
            int adjnode = it.first;
            int adjdist = it.second;
            if(adjdist+distance< dist[adjnode] && stops<=k){
                dist[adjnode] = adjdist+distance;
                qe.emplace(stops+1,make_pair(adjnode,adjdist+distance));
            }
        }
    }
    if(dist[dst]==INT_MAX){
        return-1;
    }else{
        return dist[dst];
    }
}
int min_multi(vector<int>&a,int strt,int end){
    vector<int>dist(1e5,INT_MAX);
    queue<pair<int,int>>qe;
    dist[strt]=0;
    qe.emplace(strt,0);
    int mod = 1e5;
    while(!qe.empty()){
        int node = qe.front().first;
        int steps = qe.front().second;
        qe.pop();
        for(auto it : a){
            int noden = (node*it)%mod;
            if(steps+1<dist[noden]){
                dist[noden]=steps+1;
                if(dist[noden]==end)return steps+1;
                qe.emplace(noden,steps+1);
            }
        }
    }
    return -1;
}
int countPaths(int n,vector<vector<int>>& roads){
    vector<vector<pair<int,int>>>adj(n);
    for(int i = 0 ; i < roads.size() ; i++){
        adj[roads[i][0]].emplace_back(roads[i][1],roads[i][2]);
        adj[roads[i][1]].emplace_back(roads[i][0],roads[i][2]);
    }        
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>>pq;
    pq.emplace(0,0);
    vector<long long> dist(n, LLONG_MAX),ways(n,0);
    dist[0]=0;
    ways[0]=1;
    int mod = 1e9+7; 
    while(!pq.empty()){
        long long distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it : adj[node]){
            int adjnode = it.first; 
            long long adjdist = it.second;
            long long newd = distance+adjdist;
            if(newd<dist[adjnode]){
                dist[adjnode] = newd;
                pq.emplace(newd, adjnode);
                ways[adjnode]=(ways[node]);
            }else if(newd==dist[adjnode]){
                ways[adjnode]=(ways[node]+ways[adjnode])%mod;
            }
        }
    }
    return (ways[n-1])%mod;
}
vector<int> bellman_ford(vector<vector<int>>&edges , int v , int src){
    int n = edges.size();
    vector<int> dist(v,1e8);
    dist[src]=0;
    for(int i = 0 ; i < v-1 ; i++){
        for(int j = 0 ; j < n ; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            if(dist[u]!=1e8 && dist[u]+wt<dist[v]){
                dist[v]=dist[u]+wt;
            }
        }
    }
    for(int k = 0 ; k < n ; k++){
        int u = edges[k][0];
        int vt = edges[k][1];
        int wt = edges[k][2];
        if(dist[u]!=1e8 && dist[u]+wt<dist[vt]){
            return{-1};
        }
    }
    return dist; 
}
vector<vector<int>> floyd_warshall(vector<vector<int>>&mat){
    int n = mat.size();
    for(int vis = 0 ; vis < n ; vis++){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                mat[i][j]=(min(mat[i][j],mat[i][vis] + mat[vis][j]));
            }
        }
    }
    return mat;
}
int findTheCity(int n,vector<vector<int>>&edges, int distanceThreshold){
    vector<vector<int>>mat(n,vector<int>(n,1e9));
    for(int i = 0 ; i < edges.size() ; i++){
        mat[edges[i][1]][edges[i][0]]=edges[i][2];
        mat[edges[i][0]][edges[i][1]]=edges[i][2];
    }
    for(int i = 0 ; i < n ; i++){
        mat[i][i] = 0;
    }
    for(int k = 0 ; k < n ; k++){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][k]==1e9 || mat[k][j]==1e9)continue;
                mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
            }
        }
    }
    int ans = 0;
    int anscnt = 1e9;
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if (mat[i][j] <= distanceThreshold){
                cnt++;
            }
        }
        if(cnt <= anscnt){
            ans = i;
            anscnt = cnt;
        }
    }
    return ans;
}
int prims_algo(int n ,vector<vector<vector<int>>>&adj){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.emplace(0,0);
    int minsum = 0;
    vector<int>visi(n,0);
    while(!pq.empty()){
        auto it = pq.top();
        int node = it.second;
        int wt = it.first;
        pq.pop();
        if(visi[node]){
            continue;
        }
        minsum+=wt;
        visi[node]=1;
        for(auto it: adj[node]){
            int adjnode= it[0];
            int adjwt= it[1];
            if(!visi[adjnode]){
                pq.emplace(adjwt,adjnode);
            }
        }
    }
    return minsum;
}
class DSU{
public:
    vector<int> rank, parent, 
    size;
    DSU(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int find_par(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find_par(parent[x]); 
    }
    void union_by_rank(int u, int v) {
        u = find_par(u);
        v = find_par(v);
        if (u == v) return;
        if (rank[u] < rank[v]) {
            parent[u] = v;
        } else if (rank[u] > rank[v]) {
            parent[v] = u;
        } else {
            parent[v] = u;
            rank[u]++;   // only when ranks are equal
        }
    }
    void union_by_size(int u, int v) {
        u = find_par(u);
        v = find_par(v);
        if (u == v) return;

        if (size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};
int krushal_algo(int v , vector<vector<vector<int>>>&adj){
    vector<pair<int,pair<int,int>>>edges;
    // wt u,v
    for(int i = 0 ; i < v ; i++){
        for(int j = 0 ; j < v ; j++){
            int node = i;
            int adjnode = adj[i][j][0];
            int wt = adj[i][j][1];
            edges.emplace_back(wt,make_pair(node,adjnode));
        }
    }
    sort(edges.begin(),edges.end());
    DSU d1(v);
    int ans = 0;
    for(auto it : edges){
        int wt = it.first;
        int node = it.second.first;
        int adjnode = it.second.second;
        if(d1.find_par(node)!=d1.find_par(adjnode)){
            ans+=wt;
            d1.union_by_size(node,adjnode);
        }
    }
}
int make_connections(int v , vector<vector<int>>&edges){
    if (edges.size() < v - 1)return -1;
    DSU d1(v);
    int extraEdges = 0;
    for(auto it : edges){
        int a = it[0];
        int b = it[1];
        if(d1.find_par(a)==d1.find_par(b)){
            extraEdges++;
        }else{
            d1.union_by_rank(a,b);
        }
    }
    int comp = 0;
    for(int i = 0 ; i < v ; i++){
        if(d1.find_par(i)==i){
            comp++;
        }
    }
    if(extraEdges>=comp-1){
        return comp-1;
    }else{
        return -1;
    }
}
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts){
    unordered_map<string,int>mpp;
    int n = accounts.size();
    vector<vector<string>>mergedMail(n);
    DSU d1(n);
    for(int i = 0 ; i < n ; i++){
        for(int j = 1 ; j < accounts[i].size() ; j++){
            string mail = accounts[i][j];
            if(mpp.find(mail)==mpp.end()){
                mpp[mail]=i;
            }else{
                d1.union_by_rank(mpp[mail],i);
            }
        }
    }
    for(auto it : mpp){
        string mail = it.first;
        int node = d1.find_par(it.second);
        mergedMail[node].push_back(mail);
    }
    vector<vector<string>>ans;
    for(int i = 0 ; i < n ; i++){
        if(mergedMail[i].size()==0)continue;
        vector<string>temp;
        sort(mergedMail[i].begin(),mergedMail[i].end());
        temp.push_back(accounts[i][0]);
        for(auto it : mergedMail[i]){
            temp.push_back(it);
        }
        ans.push_back(temp);
    }
    return ans;
}
int remove_stones(vector<vector<int>>&stones,int n){
    int maxr = 0;
    int maxc = 0;
    for(auto it : stones){
        maxr = max(maxr,it[0]);
        maxc = max(maxc,it[1]);
    }
    DSU d1(maxr+maxc+1);
    unordered_map<int,int>mpp;
    for(auto it : stones){
        int row = it[0];
        int col = it[1]+maxr+1;
        d1.union_by_rank(row,col);
        mpp[row]=1;
        mpp[col]=1;
    }
    int comp = 0;
    for(auto it : mpp){
        if(d1.find_par(it.first)==it.first){
            comp++;
        }
    }
    return n - comp;
}
bool isvalid(int row , int col , int n){
    return (row>=0 && col >=0 && row < n && col < n);
}
int largestIsland(vector<vector<int>>&grid) {
    int n = grid.size();
    DSU d1(n*n);
    vector<int>delrow={1,0,-1,0};
    vector<int>delcol={0,1,0,-1};
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(grid[i][j]==1){
                int node = i*n+j;
                for(int k = 0 ; k < 4 ; k++){
                    int nr = i+delrow[k];
                    int nc = j+delcol[k];
                    int adjnode = nr * n + nc;
                    if(isvalid(nr,nc,n) && grid[nr][nc]==1){
                        d1.union_by_size(node,adjnode);
                    } 
                }
            }
        }
    }
    int ans = 1;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            set<int>st;
            if(grid[i][j]==0){
                for(int io = 0 ; io < 4 ; io++){
                    int nr  = i + delrow[io];
                    int nc  = j + delcol[io];
                    if(isvalid(nr,nc,n) && grid[nr][nc]==1){
                        int node = nr*n + nc; 
                        st.insert(d1.find_par(node));
                    }
                }
            }
            int nodes = 0;
            for(auto it : st){
                nodes+=d1.size[it];
            }
            ans = max(nodes,ans);
        }
    }
    for(int cell = 0 ; cell < n*n ; cell++){
        ans=max(ans,d1.size[d1.find_par(cell)]);
    }
    return ans;
}
bool isValid(int i , int j , int n , int m ){
    return (i>=0 && j >=0 && i < n && j < m); 
}
vector<int> largest_island_2(int n, int m, vector<vector<int>>&intervals){
    DSU d1(n*m);
    vector<vector<int>> visi(n,vector<int>(m,0));
    vector<int>delrow={-1,0,1,0};
    vector<int>delcol={0,1,0,-1};
    vector<int>ans;
    int cnt = 0;
    for(auto it : intervals){
        int i = it[0];
        int j = it[1];
        if(visi[i][j]==1){
            ans.push_back(cnt);
            continue;
        }
        visi[i][j]=1;
        cnt++;
        for(int l = 0 ; l < 4 ; l ++){
            int adjr = i + delrow[l];
            int adjc = j + delcol[l];
            if(isValid(adjr,adjc,n,m) && visi[adjr][adjc]==1){
                int node = i*m+j;
                int adjnode = adjr * m + adjc;
                if(d1.find_par(adjnode)!=d1.find_par(node)){
                    cnt--;
                    d1.union_by_rank(adjnode,node);
                }
            }
        }
        ans.push_back(cnt);
    }
    return ans;
} 
void dfs1(int i,vector<int>&visi,stack<int>&st,vector<vector<int>>&adj){
    visi[i] = 1;
    for(auto it : adj[i]){
        if(!visi[it]){
            dfs1(it,visi,st,adj);
        }
    }
    st.push(i);
}
void dfs3(int i,vector<int>&visi,vector<vector<int>>&rev_adj){
    visi[i] = 1;
    for(auto it : rev_adj[i]){
        if(!visi[it]){
            dfs3(it,visi,rev_adj);
        }
    }
}
int kosarajus(int v , vector<vector<int>>&adj){
    vector<int>visi(v,0);
    stack<int>st;
    for(int i = 0 ; i < v ; i++){
        if(!visi[i]){
            dfs1(i,visi,st,adj);
        }
    }
    vector<vector<int>>rev_adj(v);
    for(int i = 0 ; i < v ; i++){
        visi[i]=0;
        for(auto it : adj[i]){
            rev_adj[it].push_back(i);
        }
    }
    int ans = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!visi[node]){
            ans++;
            dfs3(node,visi,rev_adj);
        }
    }
    return ans;
}
int timer = 0;
void dfs_for_tarjan(int node , int parent , vector<vector<int>>&adj,vector<vector<int>>&ans,vector<int>&visi,vector<int>&tin,vector<int>&low){
    visi[node] = 1; 
    low[node] = tin[node] = timer++;
    for(auto it : adj[node]){
        if(it == parent){
            continue;
        }
        if(visi[it]==0){
            dfs_for_tarjan(it,node,adj,ans,visi,tin,low);
            low[node]=min(low[it],low[node]);
            if(low[it]>tin[node]){
                ans.push_back({node,it});
            }
        }else{
            low[node]=min(low[it],low[node]);
        }
    }
}
vector<vector<int>> bridges(int n , vector<vector<int>>&connections){
    vector<vector<int>>adj(n);
    for(auto it : connections){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int>visi(n,0);
    vector<int>tin(n,0);
    vector<int>low_adj(n,0);
    vector<vector<int>>ans;
    dfs_for_tarjan(0,-1,adj,ans,visi,tin,low_adj);
    return ans;
}
void dfs_for_56(int node , int parent , vector<int>&visi,vector<int>&tin,vector<int>&low,vector<int>&mark,vector<vector<int>>&adj){
    visi[node] = 1;
    int child = 0;
    tin[node]= low[node] = timer++;
    for(auto it : adj[node]){
        if(it==parent)continue;
        if(!visi[node]){
            dfs_for_56(it,node,visi,tin,low,mark,adj);
            low[node]=min(low[it],low[node]);
            if(low[it]>=tin[node] && parent!=-1){
                mark[node]=1;
            }
            child++;
        }else{
            low[node]=min(low[node],tin[it]);
        }
    } 
    if(child>1 && parent==-1){
        mark[node]=1;
    }
}
vector<int> articulation_point(vector<vector<int>>&adj,int n){
    vector<int>visi(n,0);
    vector<int>tin(n,0);
    vector<int>low(n,0);
    vector<int>mark(n,0);
    vector<int>ans;
    for(int i = 0 ; i < n ; i++){
        if(!visi[i]){
            dfs_for_56(i,-1,visi,tin,low,mark,adj);
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(mark[i]){
            ans.push_back(i);
        }
    }
    return ans;
}
int main(){
    return 0;
}