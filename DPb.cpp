#include<bits/stdc++.h>
using namespace std;
int unboundedknapsack_r(vector<int>&wt,vector<int>&val,int i,int w){
    if(i==0){
        if(wt[0]<=w){
            int u = w/wt[0];
            return val[0]*u;
        }else{
            return 0;
        }
    }
    int notpick = unboundedknapsack_r(wt,val,i-1,w);
    int pick = INT_MIN;
    if(wt[i]<=w){
        pick = val[i]+unboundedknapsack_r(wt,val,i,w-wt[i]);
    }
    return max(pick,notpick);
}
int unboundedknapsack_m(vector<int>&wt,vector<int>&val,int i,int w,vector<vector<int>>&dp){
    if(i==0){
        if(wt[0]<=w){
            int u = w/wt[0];
            return val[0]*u;
        }else{
            return 0;
        }
    }
    if(dp[i][w]!=-1)return dp[i][w];
    int notpick = unboundedknapsack_m(wt,val,i-1,w,dp);
    int pick = INT_MIN;
    if(wt[i]<=w){
        pick = val[i]+unboundedknapsack_m(wt,val,i,w-wt[i],dp);
    }
    return dp[i][w]=max(pick,notpick);
}
int unboundedknapsack_t(vector<int>&wt,vector<int>&val,int w){
    int n = wt.size();
    vector<vector<int>>dp(n,vector<int>(w+1,0));
    for(int i = 0 ; i <= w ; i++){
        if (wt[0] <= i){
            int cnt = i / wt[0];
            dp[0][i] = cnt* val[0];
        }
    }
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j <= w ; j++){        
            int notpick = dp[i-1][j];
            int pick = INT_MIN;
            if(wt[i]<=j){
                pick = val[i]+dp[i][j-wt[i]];
            }
            dp[i][j]=max(pick,notpick);
        }
    }
    return dp[n-1][w];
}
int main(){
    return 0;
}