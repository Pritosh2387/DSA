#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* a[2]={nullptr};
};
class trie{
    Node* root;
public:
    trie(){
        root = new Node;
    }
    void insert(int n){
        Node* node = root;
        for(int i = 31 ; i>=0 ; i--){
            int x = (n>>i) & 1;
            if(!node->a[x]){
                node->a[x] = new Node;
            } 
            node = node->a[x];
        }
    }
    int maxele(int num){
        Node* node = root;
        int mans = 0; 
        for(int i = 31 ; i>=0 ; i--){
            int bit = (num>>i) & 1;
            if(node->a[1-bit]){
                mans = mans | (1<<i);
                node = node->a[!bit];
            }else{
                node = node->a[bit];
            }
        }
        return mans;
    }
};
int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2){
    trie t;
    for(auto it : arr1){
        t.insert(it);
    }
    int ans = 0;
    for(auto x : arr2){
        ans = max(ans,t.maxele(x));
    }
    return ans;
}
vector<int> maximizeXor(vector<int>&nums,vector<vector<int>>&queries){
    trie t;
    int n = nums.size();
    vector<pair<int,pair<int,int>>>q;
    for(int i = 0 ; i < queries.size() ; i++){
        q.push_back({queries[i][1],{queries[i][0],i}});
    }
    vector<int>ans(queries.size(),0);
    sort(nums.begin(),nums.end());
    sort(q.begin(),q.end());
    int in = 0;
    for(int i = 0 ; i < queries.size() ; i++){
        int limit = q[i].first;
        int q_x = q[i].second.first;
        int q_i = q[i].second.second;
        while(in < n && nums[in] <= limit){
            t.insert(nums[in]);
            in++;
        }
        if(in==0){
            ans[q_i]=-1;
        }else{
            ans[q_i] = t.maxele(q_x);
        }
    }
    return ans;
}