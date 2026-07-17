#include<bits/stdc++.h>
using namespace std;
int lcs(vector<int>&nums){
    vector<int>temp;
    temp.push_back(nums[0]);
    int n = nums.size();
    for(int i = 1 ; i < n ; i++){
        if(nums[i] > temp.back()){
            temp.push_back(nums[i]);
        }else{
            int ind = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
            temp[ind] = nums[i];
        }
    }
    return temp.size();
}
vector<int> largestDivisibleSubset(vector<int>&nums){
    int n = nums.size();
    vector<int>dp(n,1),hash(n);
    sort(nums.begin(),nums.end());
    int maxl = 1,maxin = 0;
    for(int i = 0 ; i < n ; i++){
        hash[i] = i;
        for(int j = 0 ; j < i ; j++){
            if(nums[i] % nums[j] == 0 && dp[i] < dp[j] +1){
                dp[i] = dp[j]+1;
                hash[i] = j;
            }
        }
        if(dp[i] > maxl){
            maxl = dp[i];
            maxin = i;
        }
    }
    vector<int>ans;
    while(hash[maxin]!=maxin){
        ans.push_back(nums[maxin]);
        maxin = hash[maxin];
    }
    ans.push_back(nums[maxin]);
    reverse(ans.begin(),ans.end());
    return ans;
}
bool comp(string &s, string &t){
    int n1 = s.length();
    int n2 = t.length();
    if(n1-n2 != 1)return false;
    int lp = 0;
    int rp = 0;
    while(lp!=n1){
        if(rp < t.size() && s[lp]==t[rp]){
            lp++;
            rp++;
        }else{
            lp++;
        }
    }
    return rp == n2;
}
int longestStrChain(vector<string>&words){
    sort(words.begin(),words.end(),[](string s,string t){
        return s.length()<t.length();
    });
    int n = words.size();
    vector<int> dp(n,1);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            if(comp(words[i],words[j]) && 1 + dp[j] > dp[i]){
                dp[i] = 1 + dp[j];
            }
        }
    }
    return *max_element(dp.begin(),dp.end());
}
int longestBitonicSequence(int n, vector<int> &nums){
    vector<int> dp1(n,1),dp2(n,1);
    for(int i = 0 ; i< n ; i++){
        for(int j = 0 ; j < i ; j++){
            if(nums[j] < nums[i] && 1 + dp1[j] > dp1[i]){
                dp1[i] = 1+ dp1[j];
            }
        }
    }        
    for(int i = n-1 ; i > -1 ; i--){
        for(int j = n-1 ; j > i ; j--){
            if(nums[j] < nums[i] && 1 + dp2[j] > dp2[i]){
                dp2[i] = 1+ dp2[j];
            }
        }
    }        
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        ans = max(ans,(dp1[i]+dp2[i]-1));
    }
    return ans;
}
int findNumberOfLIS(vector<int>&nums){
    int n = nums.size();
    int maxi = 0;
    vector<int>dp(n,1),cnt(n,1);
    for(int i  = 0 ; i < n ; i++){
        for(int j  = 0 ; j < i ; j++){
            if(nums[i]>nums[j] && 1+ dp[j]>dp[i]){
                dp[i] = 1 + dp[j];
                cnt[i] = cnt[j];
            }else if(nums[i]>nums[j] && 1 + dp[j] == dp[i]){
                cnt[i]+=cnt[j];
            }
        }
        maxi = max(maxi,dp[i]);
    }
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        if(dp[i] == maxi){
            ans+=cnt[i];
        }
    }
    return ans;
}
int minCost(int n, vector<int>&cuts){
    int c = cuts.size();
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(),cuts.end());
    int dp[101][101];
    memset(dp,-1,sizeof(dp));
    auto f = [&](auto&self,int i,int j)->int{
        if (i > j) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans = 2e8;
        for(int k = i ; k <= j ; k++){
            int cost = cuts[j+1]-cuts[i-1]+self(self,i,k-1)+self(self,k+1,j);
            ans = min(ans,cost);
        }
        return dp[i][j]=ans;
    };
    return f(f,1,c);
}
int maxCoins(vector<int>&nums){
    int c = nums.size();
    nums.insert(nums.begin(),1);
    nums.push_back(1);
    int dp[301][301];
    memset(dp,-1,sizeof(dp));
    auto f = [&](auto&self,int i,int j)->int{
        if (i > j) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans = -2e8;
        for(int k = i ; k <= j ; k++){
            int cost = nums[i-1]*nums[k]*nums[j+1]+self(self,i,k-1)+self(self,k+1,j);
            ans = max(ans,cost);
        }
        return dp[i][j]=ans;
    };
    return f(f,1,c);
}
class lecture52{
    vector<vector<vector<int>>> dp;
    int solve(string &s, int i, int j, bool isTrue) {
        if (i > j) return 0;
        if (i == j) {
            if (isTrue)
                return s[i] == 'T';
            else
                return s[i] == 'F';
        }
        if (dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];
        int ways = 0;
        for (int k = i + 1; k < j; k += 2) {
            int lt = solve(s, i, k - 1, true);
            int lf = solve(s, i, k - 1, false);
            int rt = solve(s, k + 1, j, true);
            int rf = solve(s, k + 1, j, false);
            if (s[k] == '&') {
                if (isTrue)
                    ways += lt * rt;
                else
                    ways += lt * rf + lf * rt + lf * rf;
            }
            else if (s[k] == '|') {
                if (isTrue)
                    ways += lt * rt + lt * rf + lf * rt;
                else
                    ways += lf * rf;
            }
            else { // '^'
                if (isTrue)
                    ways += lt * rf + lf * rt;
                else
                    ways += lt * rt + lf * rf;
            }
        }
        return dp[i][j][isTrue] = ways;
    }
};
int minCut(string s){
    int n = s.length();
    int dp[n];
    memset(dp,-1,sizeof(dp));
    auto palindrome = [&](int i,int j)->bool{
        while(i<j){
            if(s[i++]!=s[j--]){
                return false;
            }
        }
        return true;
    };
    auto solve = [&](auto&self,int i)->int{
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int ways = 1e9; 
        for(int j = i ; j < n; j++){
            if(palindrome(i ,j)){
                ways  = min(ways,1 + self(self,j+1));
            }
        }
        return dp[i] = ways;
    };
    return solve(solve,0)-1;
}
int solve(int i,int n,vector<int>&dp,vector<int>&a,int k){
    if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int ans = -1e9;
        int maxi  = a[i];
        int l = 0;
        for(int j = i ; j < min(n,i+k) ; j++){
            maxi=max(maxi,a[j]);
            l++;
            int ways = l * maxi;
            ways+=solve(j+1,n,dp,a,k);
            ans=max(ways,ans);  
        }
        return dp[i]=ans;
}
int maxSumAfterPartitioning(vector<int>&a, int k){
    vector<int>dp(501,-1);
    int n = a.size();
    return solve(0,n,dp,a,k);
}
int countSquares(vector<vector<int>>&matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>>dp(n,vector<int>(m,0));
    for(int i = 0 ; i < n ; i++){
        dp[i][0] = matrix[i][0];
    }
    for(int j = 0 ; j < m ; j++){
        dp[0][j] = matrix[0][j];
    }
    for(int i = 1 ; i < n ; i++){
        for(int j = 1 ; j < m ; j++){
            if (matrix[i][j] == 1)
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
            else
                dp[i][j] = 0;
        }
    }
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            ans+=dp[i][j];
        }
    }
    return ans;
}
int main(){
    return 0;
}