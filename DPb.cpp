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
int longestCommonSubsequence_r(string &text1, string &text2,int i,int j){
    if(i==-1 || j==-1)return 0;
    if(text1[i]==text2[j]){
        return 1 + longestCommonSubsequence_r(text1,text2,i-1,j-1);
    }
    return max(longestCommonSubsequence_r(text1,text2,i-1,j),longestCommonSubsequence_r(text1,text2,i,j-1));
}
int longestCommonSubsequence_m(string &text1, string &text2,int i,int j,vector<vector<int>>&dp){
    if(i==-1 || j==-1)return 0;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(text1[i]==text2[j]){
        return dp[i][j]=1 + longestCommonSubsequence_m(text1,text2,i-1,j-1,dp);
    }
    return dp[i][j]=max(longestCommonSubsequence_m(text1,text2,i-1,j,dp),longestCommonSubsequence_m(text1,text2,i,j-1,dp));
}
int longestCommonSubsequence_t(string &text1, string &text2){
    int n = text1.length(),m=text2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    for(int i = 0 ; i <= n ; i++){
        dp[i][0] = 0;
    }
    for(int j = 0 ; j <= m ; j++){
        dp[0][j]= 0;
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(text1[i-1]==text2[j-1]){
                dp[i][j]=1 + dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
int longestCommonSubsequence(string &text1, string &text2){
    int n = text1.length(),m=text2.length();
    vector<int>prev(m+1, 0);
    for(int i = 1 ; i <= n ; i++){
        vector<int>curr(m+1, 0);
        for(int j = 1 ; j <= m ; j++){
            if(text1[i-1]==text2[j-1]){
                curr[j]=1 + prev[j-1];
            }else{
                curr[j]=max(prev[j],curr[j-1]);
            }
        }
        prev = curr;
    }
    return prev[m];
}
int longestCommonSubstring(string &text1, string &text2){
    int ans = 0;
    int n = text1.length(),m=text2.length();
    vector<int>prev(m+1, 0);
    for(int i = 1 ; i <= n ; i++){
        vector<int>curr(m+1, 0);
        for(int j = 1 ; j <= m ; j++){
            if(text1[i-1]==text2[j-1]){
                curr[j]=1 + prev[j-1];
                ans = max(curr[j],ans);
            }else{
                curr[j]=0;
            }
        }
        prev = curr;
    }
    return ans;
}
int main(){
    return 0;
}