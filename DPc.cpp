#include<bits/stdc++.h>
using namespace std;
int maxProfit_r(vector<int>&prices,int i,int buy){
    int n = prices.size();
    if(i==n)return 0;
    int profit = 0;
    if(buy){
        profit = max(-prices[i]+maxProfit_r(prices,i+1,0),maxProfit_r(prices,i+1,1));
    }else{
        profit = max(prices[i]+maxProfit_r(prices,i+1,1),maxProfit_r(prices,i+1,0));
    }
    return profit;
}
int maxProfit_m(vector<int>&prices,int i,int buy,vector<vector<int>>&dp){
    int n = prices.size();
    if(i==n)return 0;
    if(dp[i][buy]!=-1){
        return dp[i][buy];
    }
    int profit = 0;
    if(buy){
        profit = max(-prices[i]+maxProfit_m(prices,i+1,0,dp),maxProfit_m(prices,i+1,1,dp));
    }else{
        profit = max(prices[i]+maxProfit_m(prices,i+1,1,dp),maxProfit_m(prices,i+1,0,dp));
    }
    return dp[i][buy]=profit;
}
int maxProfit_t(vector<int>&prices){
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(2, -1));
    dp[n][0]=dp[n][1]=0;
    for(int i = n-1 ; i >= 0 ; i--){
        for(int buy = 0; buy < 2; buy++){
            if(buy){
                dp[i][buy] = max(-prices[i]+maxProfit_m(prices,i+1,0,dp),maxProfit_m(prices,i+1,1,dp));
            }else{
                dp[i][buy] = max(prices[i]+maxProfit_m(prices,i+1,1,dp),maxProfit_m(prices,i+1,0,dp));
            }
        }
    }
    return dp[0][1];
}
int maxProfit_II(vector<int>& prices){
    int n = prices.size();
    vector<int> prev(2, -1);
    prev[0] = prev[1] = 0;
    for(int i = n - 1; i >= 0; i--){
            vector<int> curr(2, -1);
            for(int buy = 0; buy < 2; buy++){
                if(buy){
                    curr[buy] = max(-prices[i] + prev[0], prev[1]);
                }else{
                    curr[buy] = max(prices[i] + prev[1], prev[0]);
                }
            }
            prev = curr;
        }
        return prev[1];
    }
int maxProfit_III_m(vector<int>&prices,int i,int buy,vector<vector<vector<int>>>&dp,int c){
    int n = prices.size();
    if(c==0)return dp[i][buy][0]=0;
    if(i==n)return 0;
    if(dp[i][buy][c]!=-1){
        return dp[i][buy][c];
    }
    int profit = 0;
    if(buy){
        profit = max(-prices[i]+maxProfit_III_m(prices,i+1,0,dp,c),maxProfit_III_m(prices,i+1,1,dp,c));
    }else{
        profit = max(prices[i]+maxProfit_III_m(prices,i+1,1,dp,c-1),maxProfit_III_m(prices,i+1,0,dp,c));
    }
    return dp[i][buy][c]=profit;
}
int maxProfit_III_t(vector<int>&prices){
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
    for(int i = n-1 ; i >=0 ; i--){
        for(int buy = 0 ; buy < 2 ; buy++){
            for(int c = 1 ; c <= 2 ; c++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[i]+dp[i+1][0][c],dp[i+1][1][c]);
                }else{
                    profit = max(prices[i]+dp[i+1][1][c-1],dp[i+1][0][c]);
                }
                dp[i][buy][c]=profit;
            }
        }
    }
    return dp[0][1][2];
}
int maxProfit_III(vector<int>&prices){
    int n = prices.size();
    vector<vector<int>> after(2, vector<int>(3, 0));
    for(int i = n-1 ; i >=0 ; i--){
        vector<vector<int>> curr(2, vector<int>(3, 0));
        for(int buy = 0 ; buy < 2 ; buy++){
            for(int c = 1 ; c <= 2 ; c++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[i]+after[0][c],after[1][c]);
                }else{
                    profit = max(prices[i]+after[1][c-1],after[0][c]);
                }
                curr[buy][c]=profit;
            }
        }
        after = curr;
    }
    return after[1][2];
}
int maxProfit_4(int k, vector<int>& prices){
    int n = prices.size();
    vector<vector<int>> after(2, vector<int>(k + 1, 0));
    for (int i = n - 1; i >= 0; i--) {
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));
        for (int buy = 0; buy < 2; buy++) {
            for (int c = 1; c <= k; c++) {
                int profit = 0;
                if (buy) {
                    profit = max(-prices[i] + after[0][c], after[1][c]);
                } else {
                    profit = max(prices[i] + after[1][c - 1], after[0][c]);
                }
                curr[buy][c] = profit;
            }
        }
        after = curr;
    }
    return after[1][k];
}
int maxProfitcooldown_r(vector<int>&prices,int n,int buy){
    if(n >= prices.size())return 0;
    int profit =0;
    if(buy){
        profit = max(-prices[n]+maxProfitcooldown_r(prices,n+1,0),maxProfitcooldown_r(prices,n+1,1));
    }else{
        profit = max(prices[n]+maxProfitcooldown_r(prices,n+2,1),maxProfitcooldown_r(prices,n+1,0));
    }
    return profit;
}
int maxProfitcooldown_m(vector<int>&prices,int n,int buy,vector<vector<int>>&dp){
    if(n >= prices.size())return 0;
    if(dp[n][buy]!=-1)return dp[n][buy]; 
    int profit =0;
    if(buy){
        profit = max(-prices[n]+maxProfitcooldown_m(prices,n+1,0,dp),maxProfitcooldown_m(prices,n+1,1,dp));
    }else{
        profit = max(prices[n]+maxProfitcooldown_m(prices,n+2,1,dp),maxProfitcooldown_m(prices,n+1,0,dp));
    }
    return dp[n][buy]=profit;
}
int maxProfitcooldown_t(vector<int>&prices){
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int buy = 0; buy < 2; buy++) {
            int profit = 0;
            if (buy) {
                profit = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
            } else {
                profit = max(prices[i] + dp[i + 2][1], dp[i + 1][0]);
            }
            dp[i][buy] = profit;
        }
    }
    return dp[0][1];
}
int maxProfitColldown(vector<int>& prices){
    int n = prices.size();
    vector<int> f2(2, 0);
    vector<int> f1(2, 0);
    vector<int> curr(2, 0);
    for (int i = n - 1; i >= 0; i--) {
        curr[1] = max(-prices[i] + f1[0], f1[1]);
        curr[0] = max(prices[i] + f2[1], f1[0]);
        f2 = f1;
        f1 = curr;
    }
    return f1[1];
}
int lengthOfLIS(vector<int>& nums){
    int n = nums.size();
    int dp[n][n+1];
    memset(dp,-1,sizeof(dp));
    auto memo = [&](auto&self,int i,int last)->int{
        if(i==n)return 0;
        if(dp[i][last+1]!=-1)return dp[i][last+1];
        int nott = self(self,i+1,last);
        int t = -1e9;
        if(last == -1 || nums[i]>nums[last]){
            t = 1+self(self,i+1,i);
        }
        return dp[i][last+1]= max(nott,t);
    }; 
    return memo(memo,0,-1);
}
int main(){
    return 0;
}