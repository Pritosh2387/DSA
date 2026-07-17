#include<bits/stdc++.h>
using namespace std;
class TreeAncestor{
public:
    vector<vector<int>>up;
    int col;
    TreeAncestor(int n, vector<int>&parent){
        col = log2(n)+1;
        up.resize(n,(vector<int>(col,-1)));
        for(int i = 0 ; i < n ; i++){
            up[i][0] = parent[i];
        }
        for(int j = 1 ; j < col ; j++){
            for(int i = 0 ; i < n; i++){
                if(up[i][j-1]!=-1){
                    up[i][j] = up[up[i][j-1]][j-1];
                }
            }
        }
    }
    int getKthAncestor(int node, int k){
        for(int i = 0 ; i < col ; i++){
            if(k & (1<<i)){
                node = up[node][i];
                if(node ==-1)return -1;
            }
        }
        return node;
    }
};