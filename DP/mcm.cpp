#include<bits/stdc++.h>
using namespace std;
int solve(int i ,int j ,vector<int>&arr,vector<vector<int>>&dp){
    if(i==j)return 0;
    int mini = 1e9;
    if(dp[i][j]!=-1)return dp[i][j];
    for(int k = i ; k < j ; k++){
        int steps = arr[i-1]*arr[k]*arr[j] + solve(i,k,arr,dp) + solve(k+1,j,arr,dp);
        mini = min(steps,mini);
    }
    return dp[i][j] = mini;
}
int matrixMultiplication(vector<int> &arr){
    int n = arr.size();
    vector<vector<int>>dp(n,vector<int>(n,-1));
    return solve(1,n-1,arr,dp);        
}
int matrixMultiplication(vector<int> &arr){
    int n = arr.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
    int mini = 1e9;
    for(int i = n-1 ; i > 0 ; i--){
        for(int j = i+1 ; j < n ; j++){   
            for(int k = i ; k < j ; k++){
                int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                mini = min(steps,mini);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][n-1];        
}
int main(){
    return 0;
}