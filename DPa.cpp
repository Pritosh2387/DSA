#include<bits/stdc++.h>
using namespace std;
int fibonacci(int n){
    int prev = 1;
    int prev_2 = 0;
    for(int i = 2 ; i <= n ; i++){
        int curr = prev + prev_2;
        prev_2 = prev;
        prev = curr; 
    }
    return prev;
}
int climbStairs(int n){
    int prev_2 = 1;
    int prev_1 = 1;
    for(int i = 2 ; i<= n ; i++){
        int curr = prev_1 + prev_2;
        prev_2=prev_1;
        prev_1=curr;
    }
    return prev_1;
}
int frogJump_recursive(int n,vector<int>&heights){
    if(n==0)return 0;
    int left = frogJump_recursive(n-1,heights)+abs(heights[n]-heights[n-1]);
    int right=1e9;
    if(n>1){
        right = frogJump_recursive(n-2,heights)+abs(heights[n]-heights[n-2]);
    }
    return min(left,right);
}
int frogJump_memorisation(int n,vector<int>&heights,vector<int>&dp){
    if(n==0)return 0;
    if(dp[n]!=-1)return dp[n];
    int left = frogJump_memorisation(n-1,heights,dp)+abs(heights[n]-heights[n-1]);
    int right=1e9;
    if(n>1){
        right = frogJump_memorisation(n-2,heights,dp)+abs(heights[n]-heights[n-2]);
    }
    return dp[n]=min(left,right);
}
int frogJump_tabulation(int n,vector<int>&heights){
    if(n<=0)return 0;
    vector<int>dp(n,0);
    for(int i = 1 ; i < n ; i++){
        int fs = dp[i-1]+abs(heights[i]-heights[i-1]);
        int ss = 1e8;
        if(i>1){
            ss = dp[i-2]+abs(heights[i]-heights[i-2]);
        }
        dp[i]=min(fs,ss);
    }
    return dp[n-1];
}
int frogJump(int n,vector<int>&heights){
    int prev_2 = 0;
    int prev_1 = abs(heights[1]-heights[0]);
    for(int i = 2 ; i < n ; i++){
        int fs = prev_1 + abs(heights[i]-heights[i-1]);
        int ss = 1e8;
        if(i>1){
            ss = prev_2 + abs(heights[i]-heights[i-2]);
        }
        int curr = min(fs,ss);
        prev_2 = prev_1;
        prev_1 = curr;
    }
    return prev_1;
}
int frog_k_r(int n,int k,vector<int>&heights){
    if(n==0){
        return 0;
    }
    int ans = INT_MAX;
    for(int i = 1 ; i <= k ; i++){
        if(n-i>=0){
            int prev = frog_k_r(n-i,k,heights);
            if(prev!=INT_MAX){
                int ways = prev+abs(heights[n]-heights[n-i]);
                ans=min(ans,ways);
            }
        }else{
            break;
        }
    }
    return ans;
}
int frog_k_m(int n,int k,vector<int>&heights,vector<int>&dp){
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans = INT_MAX;
    for(int i = 1 ; i <= k ; i++){
        if(n-i>=0){
            int prev = frog_k_m(n-i,k,heights,dp);
            if(prev!=INT_MAX){
                int ways = prev + abs(heights[n]-heights[n-i]);
                ans=min(ans,ways);
            }
        }else{
            break;
        }
    }
    dp[n]=ans;
    return dp[n];
}
int frog_k_t(int n, int k,vector<int>heights){
    vector<int>dp(n,0);
    for(int i = 1 ; i < n ; i++){
        int min_ways = INT_MAX;
        for(int j = 1 ; j <= k ; j++){
            if(i-j>=0){
                int ways = dp[i-j]+abs(heights[i]-heights[i-j]); 
                min_ways=min(min_ways,ways);
            }
        } 
        dp[i]=min_ways;
    }
    return dp[n-1];
}
int max_sub_no_adj_r(int i,vector<int>&a){
    if(i==0)return a[0];
    if(i<0)return 0;
    int pick = a[i] + max_sub_no_adj_r(i-2,a);
    int notPick = max_sub_no_adj_r(i-1,a);
    return max(pick,notPick);
} 
int max_sub_no_adj_m(int i,vector<int>&a,vector<int>&dp){
    if(dp[i] != -1)return dp[i];
    if(i==0)return a[0];
    if(i<0)return 0;
    int pick = a[i] + max_sub_no_adj_m(i-2,a,dp);
    int notPick = max_sub_no_adj_m(i-1,a,dp);
    return dp[i]=max(pick,notPick);
} 
int max_sub_no_adj_t(vector<int>&a){
    int n = a.size();
    vector<int>dp(n,0);
    dp[0]=a[0];
    for(int i = 1 ; i < n ; i++){
        int take = a[i];
        if(i>1){
            take+=dp[i-2];
        }
        int notTake = dp[i-1];
        dp[i]=max(take,notTake);
    }
    return dp[n-1];
} 
int max_sub_no_adj(vector<int>&a){
    int n = a.size();
    int prev2 = 0;
    int prev1 =a[0];
    int ans; 
    for(int i = 1 ; i < n ; i++){
        int take = a[i]+prev2;
        int notTake = prev1;
        ans =max(take,notTake);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
} 
int rob_2(vector<int>&nums){
    vector<int>temp1;
    vector<int>temp2;
    int n = nums.size();
    if(n==1)return nums[0];
    for(int i = 0 ; i < n ; i++){
        if(i!=0)temp1.push_back(nums[i]);
        if(i!=n-1)temp2.push_back(nums[i]);
    }
    return max(max_sub_no_adj(temp1),max_sub_no_adj(temp2));
}
int ninja_training_r(vector<vector<int>>&a,int last,int n){
    if(n==0){
        int maxi = INT_MIN; 
        for(int i = 0 ; i < 3 ; i++){
            if(i!=last){
                maxi=max(maxi,a[0][i]);
            }
        }
        return maxi;
    }
    int maxi = INT_MIN;
    for(int i = 0 ; i < 3 ; i++){
        if(i!=last){
            maxi=max(maxi,a[n][i]+ninja_training_r(a,i,n-1));
        }
    }
    return maxi;
}
int ninja_training_m(vector<vector<int>>&a,int last,int n,vector<vector<int>>&dp){
    if(n==0){
        int maxi = INT_MIN; 
        for(int i = 0 ; i < 3 ; i++){
            if(i!=last){
                maxi=max(maxi,a[0][i]);
            }
        }
        return maxi;
    }
    if(dp[n][last]!=INT_MIN){
        return dp[n][last];
    }
    int maxi = INT_MIN;
    for(int i = 0 ; i < 3 ; i++){
        if(i!=last){
            maxi=max(maxi,a[n][i]+ninja_training_m(a,i,n-1,dp));
        }
    }
    return dp[n][last]=maxi;
}
int ninja_training_t(vector<vector<int>>&a){
    int n = a.size();
    vector<vector<int>>dp(n,vector<int>(4,INT_MIN));
    dp[0][0]=max(a[0][1],a[0][2]);
    dp[0][1]=max(a[0][0],a[0][2]);
    dp[0][2]=max(a[0][0],a[0][1]);
    dp[0][3] = max(a[0][0], max(a[0][1], a[0][2]));
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < 4 ; j++){
            int maxi = INT_MIN;
            for(int k = 0 ; k < 3 ; k++){
                if(k!=j){
                    maxi=max(maxi,a[i][k]+dp[i-1][k]);
                }
            }
            dp[i][j]=maxi;
        }
    }
    return dp[n-1][3];
}
int ninja_training(vector<vector<int>>&a){
    int n = a.size();
    vector<int>prev(4,INT_MIN);
    prev[0]=max(a[0][1],a[0][2]);
    prev[1]=max(a[0][0],a[0][2]);
    prev[2]=max(a[0][0],a[0][1]);
    prev[3]=max(a[0][0], max(a[0][1], a[0][2]));
    for(int i = 1 ; i < n ; i++){
        vector<int>curr(4,INT_MIN);
        for(int j = 0 ; j < 4 ; j++){
            int maxi = INT_MIN;
            for(int k = 0 ; k < 3 ; k++){
                if(j!=k){
                    maxi=max(maxi,a[i][k]+prev[k]);
                }
            }
            curr[j] = maxi;
        }
        prev = curr;
    }
    return prev[3];
}
int uniquePaths_r(int m, int n){
    if(m == 0 && n == 0) return 1;
    if(m < 0 || n < 0) return 0;
    int p1 = uniquePaths_r(m-1,n);
    int p2 = uniquePaths_r(m,n-1);
    return p1+p2;
}
int uniquePaths_m(int m, int n,vector<vector<int>>&dp){
    if(m == 0 && n == 0) return 1;
    if(m < 0 || n < 0) return 0;
    if(dp[m][n]!=-1)return dp[m][n];
    int p1 = uniquePaths_m(m-1,n,dp);
    int p2 = uniquePaths_m(m,n-1,dp);
    return dp[m][n] = p1+p2;
}
int uniquePaths_t(int m,int n){
    vector<vector<int>> dp(m, vector<int>(n, -1));
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            int p1 = 0, p2 = 0;
            if (i == 0 && j == 0){
                dp[0][0] = 1;
                continue;
            }
            if (i - 1 >= 0) {
                p1 = dp[i - 1][j];
            }
            if (j - 1 >= 0) {
                p2 = dp[i][j - 1];
            }
            dp[i][j] = p1 + p2;
        }
    }
    return dp[m-1][n-1];
}
int uniquePaths_so(int m,int n){
    vector<int>prev(n, 0);
    for (int i = 0; i < m; i++){
        vector<int>curr(n, 0);
        for (int j = 0; j < n; j++){
            int p1 = 0, p2 = 0;
            if (i == 0 && j == 0){
                curr[0] = 1;
                continue;
            }
            if (i - 1 >= 0) {
                p1 = prev[j];
            }
            if (j - 1 >= 0) {
                p2 = curr[j - 1];
            }
            curr[j] = p1 + p2;
        }
        prev = curr;
    }
    return prev[n-1];
}
int uniquePath(int m ,int n){
    int nc = n + m - 2;
    int r = m - 1;
    int ans = 1;
    for(int i = 1 ; i <= r ; i++){
        ans = ans * (n-i+1)/i; 
    }
    return ans;
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)return 0;
    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++){
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++){
            if (obstacleGrid[i][j] == 1){
                curr[j] = 0;
                continue;
            }
            int p1 = 0, p2 = 0;
            if (i == 0 && j == 0){
                curr[0] = 1;
                continue;
            }
            if (i - 1 >= 0){
                p1 = prev[j];
            }
            if (j - 1 >= 0){
                p2 = curr[j - 1];
            }
            curr[j] = p1 + p2;
        }
        prev = curr;
    }
    return prev[n - 1];
}
int minPathSum_r(vector<vector<int>>&grid,int i,int j){ 
    if(i==0 && j==0)return grid[0][0];
    if(i<0 || j < 0 )return INT_MAX;
    int up = grid[i][j] + minPathSum_r(grid,i-1,j);
    int left = grid[i][j] + minPathSum_r(grid,i,j-1);
    return min(up,left);
}
int minPathSum_m(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&dp){ 
    if(i==0 && j==0)return grid[0][0];
    if(i<0 || j < 0 )return 1e9;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int up = grid[i][j] + minPathSum_m(grid,i-1,j,dp);
    int left = grid[i][j] + minPathSum_m(grid,i,j-1,dp);
    return dp[i][j] = min(up,left);
}
int minPathSum_t(vector<vector<int>>&grid){ 
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>>dp(m,vector<int>(n,0));
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i == 0 && j == 0){
                dp[i][j] = grid[0][0];
                continue;
            }
            int left = 1e9;
            int up = 1e9;
            if(i>0){
                up = grid[i][j] + dp[i-1][j];
            }
            if(j>0){   
                left = grid[i][j] + dp[i][j-1];
            }
            dp[i][j] = min(up,left);
        }
    }
    return dp[m-1][n-1];
}
int minPathSum(vector<vector<int>>&grid){ 
    int m = grid.size();
    int n = grid[0].size();
    vector<int>prev(n,0);
    for(int i = 0 ; i < m ; i++){
        vector<int>curr(n,0);
        for(int j = 0 ; j < n ; j++){
            if(i == 0 && j == 0){
                curr[j] = grid[0][0];
                continue;
            }
            int left = 1e9;
            int up = 1e9;
            if(i>0){
                up = grid[i][j] + prev[j];
            }
            if(j>0){   
                left = grid[i][j] + curr[j-1];
            }
            curr[j] = min(up,left);
        }
        prev = curr;
    }
    return prev[n-1];
}
int minimumTotal_r(vector<vector<int>>&triangle,int i , int j){
    int n = triangle.size();
    if(i==n-1){
        return triangle[i][j];
    }
    int d = triangle[i][j]+minimumTotal_r(triangle,i+1,j);
    int rd = triangle[i][j]+minimumTotal_r(triangle,i+1,j+1);
    return min(d,rd);
}
int minimumTotal_m(vector<vector<int>>&triangle,int i , int j,vector<vector<int>>&dp){
    int n = triangle.size();
    if(i==n-1){
        return triangle[i][j];
    }
    if(dp[i][j]!=INT_MAX){
        return dp[i][j];
    }
    int d = triangle[i][j]+minimumTotal_m(triangle,i+1,j,dp);
    int rd = triangle[i][j]+minimumTotal_m(triangle,i+1,j+1,dp);
    return dp[i][j] =  min(d,rd);
}
int minimumTotal_t(vector<vector<int>>&triangle){
    int n = triangle.size();
    vector<vector<int>>dp(n);
    for(int i = 0 ; i < n ; i++){
        dp[i]= vector<int>(i+1,INT_MAX);
    }
    for(int j = 0 ; j < n ; j++){
        dp[n-1][j] = triangle[n-1][j];
    }
    for(int i = n-2 ; i>=0 ; i--){
        for(int j = i ; j >= 0 ; j--){
            int d = triangle[i][j]+ dp[i+1][j];
            int rd = triangle[i][j]+ dp[i+1][j+1];
            dp[i][j] = min(d,rd);
        }
    }
    return dp[0][0];
}
int minimumTotal(vector<vector<int>>&triangle){
    int n = triangle.size();
    vector<int>next = triangle[n-1];
    for(int i = n-2 ; i>=0 ; i--){
        vector<int>curr(i+1);
        for(int j = i ; j >= 0 ; j--){
            int d = triangle[i][j]+ next[j];
            int rd = triangle[i][j]+ next[j+1];
            curr[j] = min(d,rd);
        }
        next = curr;
    }
    return next[0];
}
int maxFallingPathSum_r(vector<vector<int>>&matrix,int i,int j){
    int n = matrix.size();
    if(i < 0 || j > n-1){
        return -1e9;
    }
    if(i==0){
        return matrix[i][j];
    }
    int u = maxFallingPathSum_r(matrix,i-1,j);
    int ul = maxFallingPathSum_r(matrix,i-1,j-1);
    int ur = maxFallingPathSum_r(matrix,i-1,j+1);
    return max(ur,max(u,ul));
}
int maxFallingPathSum_m(vector<vector<int>>&matrix,int i,int j,vector<vector<int>>&dp){
    int n = matrix.size();
    if(j < 0 || j > n-1){
        return -1e9;
    }
    if(i==0){
        return matrix[i][j];
    }
    if(dp[i][j]!= -1e9){
        return dp[i][j];
    }
    int u = matrix[i][j] + maxFallingPathSum_m(matrix,i-1,j,dp);
    int ul = matrix[i][j] + maxFallingPathSum_m(matrix,i-1,j-1,dp);
    int ur = matrix[i][j] + maxFallingPathSum_m(matrix,i-1,j+1,dp);
    return dp[i][j] = max(ur,max(u,ul));
}
int maxFallingPathSum_t(vector<vector<int>>&matrix){
    int n = matrix.size();
    vector<vector<int>>dp(n,(vector<int>(n,-1e9)));
    dp[0] = matrix[0];
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            int u = matrix[i][j] + dp[i-1][j];
            int ul = -1e9;
            int ur = -1e9;
            if(j-1>=0){
                ul = matrix[i][j] + dp[i-1][j-1];
            }
            if(j+1<n){
                ur = matrix[i][j] + dp[i-1][j+1];
            }
            dp[i][j] = max(ur,max(u,ul));
        }
    }
    return *(max_element(dp[n-1].begin(),dp[n-1].end()));
}
int maxFallingPathSum(vector<vector<int>>&matrix){
    int n = matrix.size();
    vector<int>prev(n,-1e9);
    prev = matrix[0];
    for(int i = 1 ; i < n ; i++){
        vector<int>curr(n,-1e9);
        for(int j = 0 ; j < n ; j++){
            int u = matrix[i][j] + prev[j];
            int ul = -1e9;
            int ur = -1e9;
            if(j-1>=0){
                ul = matrix[i][j] + prev[j-1];
            }
            if(j+1<n){
                ur = matrix[i][j] + prev[j+1];
            }
            curr[j] = max(ur,max(u,ul));
        }
        prev = curr;
    }
    return *(max_element(prev.begin(),prev.end()));
}
int ninja_friends_r(vector<vector<int>>&matrix,int i ,int j1,int j2){
    int n = matrix.size();
    if(j1 > n-1 || j2 > n-1 || j1 < 0 || j2 < 0){
        return -1e8;
    }
    if(i == n-1){
        if(j1==j2){
            return matrix[i][j1];
        }else{
            return matrix[i][j1]+matrix[i][j2];
        }
    }
    int maxi = -1e9;
    for(int dj1 = -1 ; dj1 < 2 ; dj1++){
        for(int dj2 = -1 ; dj2 < 2 ; dj2++){
            int value = 0;
            if(j1==j2){
                value = matrix[i][j1];
            }else{
                value = matrix[i][j1] + matrix[i][j2];
            }
            value+= ninja_friends_r(matrix,i+1,j1+dj1,j2+dj2);
            maxi= max(maxi,value);
        }
    }
    return maxi;
}
int ninja_friends_m(vector<vector<int>>&matrix,int i ,int j1,int j2,vector<vector<vector<int>>>&dp){
    int n = matrix.size();
    if(j1 > n-1 || j2 > n-1 || j1 < 0 || j2 < 0){
        return -1e8;
    }
    if(i == n-1){
        if(j1==j2){
            return matrix[i][j1];
        }else{
            return matrix[i][j1]+matrix[i][j2];
        }
    }
    if(dp[i][j1][j2]!=-1e9){
        return dp[i][j1][j2];
    }
    int maxi = -1e9;
    for(int dj1 = -1 ; dj1 < 2 ; dj1++){
        for(int dj2 = -1 ; dj2 < 2 ; dj2++){
            int value = 0;
            if(j1==j2){
                value = matrix[i][j1];
            }else{
                value = matrix[i][j1] + matrix[i][j2];
            }
            value+= ninja_friends_m(matrix,i+1,j1+dj1,j2+dj2,dp);
            maxi= max(maxi,value);
        }
    }
    return dp[i][j1][j2] = maxi;
}
int ninja_friends_t(vector<vector<int>>&matrix){
    int n = matrix.size();
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n,0)));
    for(int j1 = 0 ; j1 < n ;j1++){
        for(int j2 = 0 ; j2 < n ; j2++){
            if(j1==j2){
                dp[n-1][j1][j1] = matrix[n-1][j1]; 
            }else{
                dp[n-1][j1][j2] = matrix[n-1][j1] + matrix[n-1][j2];
            }
        }
    }
    for(int i = n-2 ; i >=0 ; i--){
        for(int j1 = 0 ; j1 < n ;j1++){
            for(int j2 = 0 ; j2 < n ; j2++){
                int maxi = -1e9;
                for(int dj1 = -1 ; dj1 < 2 ; dj1++){
                    for(int dj2 = -1 ; dj2 < 2 ; dj2++){
                        int value = 0;
                        if(j1==j2){
                            value = matrix[i][j1];
                        }else{
                            value = matrix[i][j1] + matrix[i][j2];
                        }
                        if(j1+dj1>=0 && j1+dj1<n && j2+dj2>=0 && j2+dj2<n){
                            value+= dp[i+1][j1+dj1][j2+dj2];
                        }else{
                            value = -1e9;
                        }
                        maxi= max(maxi,value);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][n-1];
}
int ninja_friends(vector<vector<int>>&matrix){
    int n = matrix.size();
    vector<vector<int>>next(n,vector<int>(n,0));
    for(int j1 = 0 ; j1 < n ;j1++){
        for(int j2 = 0 ; j2 < n ; j2++){
            if(j1==j2){
                next[j1][j1] = matrix[n-1][j1]; 
            }else{
                next[j1][j2] = matrix[n-1][j1] + matrix[n-1][j2];
            }
        }
    }
    for(int i = n-2 ; i >=0 ; i--){
        vector<vector<int>>curr(n,vector<int>(n,0));
        for(int j1 = 0 ; j1 < n ;j1++){
            for(int j2 = 0 ; j2 < n ; j2++){
                int maxi = -1e9;
                for(int dj1 = -1 ; dj1 < 2 ; dj1++){
                    for(int dj2 = -1 ; dj2 < 2 ; dj2++){
                        int value = 0;
                        if(j1==j2){
                            value = matrix[i][j1];
                        }else{
                            value = matrix[i][j1] + matrix[i][j2];
                        }
                        if(j1+dj1>=0 && j1+dj1<n && j2+dj2>=0 && j2+dj2<n){
                            value+= next[j1+dj1][j2+dj2];
                        }else{
                            value = -1e9;
                        }
                        maxi= max(maxi,value);
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        next = curr;
    }
    return next[0][n-1];
}
bool sub_seq_k_sum_r(int i,int target,vector<int>&a){
    if(target==0)return true;
    if(i==0)return (a[i]==target);
    bool not_take = sub_seq_k_sum_r(i-1,target,a); 
    bool take = false;
    if(a[i]<=target){
        bool take = sub_seq_k_sum_r(i-1,target-a[i],a);
    }
    return (not_take || take); 
}
bool sub_seq_k_sum_m(int i,int target,vector<int>&a,vector<vector<int>>&dp){
    if(target==0)return true;
    if(i==0)return (a[i]==target);
    if(dp[i][target]!=-1){
        return dp[i][target];
    }
    bool not_take = sub_seq_k_sum_m(i-1,target,a,dp); 
    bool take = false;
    if(a[i]<=target){
        take = sub_seq_k_sum_m(i-1,target-a[i],a,dp);
    }
    return dp[i][target]=(not_take || take); 
}
bool sub_seq_k_sum_t(int target,vector<int>&a){
    int n = a.size();
    vector<vector<bool>>dp(n,vector<bool>(target+1,false));
    for(int i = 0 ; i < n ; i++){
        dp[i][0]=true;
    }
    if(a[0]<=target){
        dp[0][a[0]]=true;
    }
    for(int i = 1 ; i < n ; i++){
        for(int k = 1 ; k <= target ; k++){
            bool not_take = dp[i-1][k]; 
            bool take = false;
            if(a[i]<=k){
                take = dp[i-1][k-a[i]];
            }
            dp[i][k] = (take || not_take);
        }
    }
    return dp[n-1][target];
}
bool sub_seq_k_sum(int target,vector<int>&a){
    int n = a.size();
    vector<bool>prev(target+1,false);
    prev[0] = true;
    if(a[0]<=target){
        prev[a[0]]=true;
    }
    for(int i = 1 ; i < n ; i++){
        vector<bool>curr(target+1,false);
        curr[0] = true;
        for(int k = 1 ; k <= target ; k++){
            bool not_take = prev[k]; 
            bool take = false;
            if(a[i]<=k){
                take = prev[k-a[i]];
            }
            curr[k] = (take || not_take);
        }
        prev = curr;
    }
    return prev[target];
}
bool canPartition(vector<int>&a){
    int sum = accumulate(a.begin(),a.end(),0);
    if((sum%2)==1)return false;
    if(sub_seq_k_sum(sum/2,a)){
        return true;
    }
    return false;
}
int min_diff(vector<int>&a){
    long long total = accumulate(a.begin(),a.end(),0LL);
    long long half = total/2;
    long long target = total;
    int n = a.size();
    vector<bool>prev(half+1,false);
    prev[0] = true;
    if(a[0] >= 0 && a[0] <= half){
        prev[a[0]] = true;
    }    
    for(int i = 1 ; i < n ; i++){
        vector<bool>curr(half+1,false);
        curr[0] = true;
        for(int k = 1 ; k <= half ; k++){
            bool not_take = prev[k]; 
            bool take = false;
            if(a[i]<=k){
                take = prev[k-a[i]];
            }
            curr[k] = (take || not_take);
        }
        prev = curr;
    }
    long long mini = INT_MAX;
    for(int i = 0 ; i <= (target)/2 ; i++){
        if(prev[i]==true){
            long long sum1 = i;
            long long sum2 = total-sum1;
            mini = min(abs(sum1-sum2),mini);
        }
    }
    return mini;
}
int count_sub_seq_r(int i,int target,vector<int>&a){
    if(i==0){
        if(a[i] == 0 && target == 0){
            return 2;
        }
        if(target == 0 || target == a[0]){
            return 1;
        }
        return 0;
    }
    int notPick = count_sub_seq_r(i-1,target,a);
    int pick = 0;
    if(a[i]<=target){
        pick = count_sub_seq_r(i-1,target-a[i],a);
    }
    return pick + notPick;
}
int count_sub_seq_m(int i,int target,vector<int>&a,vector<vector<int>>&dp){
    if(i==0){
        if(a[i] == 0 && target == 0){
            return 2;
        }
        if(target == 0 || target == a[0]){
            return 1;
        }
        return 0;
    }
    if(dp[i][target]!=-1)return dp[i][target];
    int notPick = count_sub_seq_m(i-1,target,a,dp);
    int pick = 0;
    if(a[i]<=target){
        pick = count_sub_seq_m(i-1,target-a[i],a,dp);
    }
    return dp[i][target] = pick + notPick;
}
int count_sub_seq_t(vector<int>&a,int target){
    int n = a.size();
    vector<vector<int>>dp(n,vector<int>(target+1,0));
    dp[0][0] = (a[0] == 0 ? 2 : 1);
    if (a[0] != 0 && a[0] <= target) dp[0][a[0]] = 1;
    for(int i = 1; i < n ; i++){
        for(int j = 0 ; j <= target ; j++){
            int notPick = dp[i-1][j];
            int pick = 0;
            if(a[i]<=j){
            pick = dp[i-1][j-a[i]];
            }
            dp[i][j] = pick + notPick;
        }
    }
    return dp[n-1][target];
}
int count_sub_seq(vector<int>&a,int target){
    int n = a.size();
    vector<int>prev(target+1,0);
    prev[0]=1;
    if(a[0]<=target){
        prev[a[0]] += 1; 
    }
    for(int i = 1; i < n ; i++){
        vector<int>curr(target+1,0);
        curr[0]=1;
        for(int j = 1 ; j <= target ; j++){
            int notPick = prev[j];
            int pick = 0;
            if(a[i]<=j){
            pick = prev[j-a[i]];
            }
            curr[j] = pick + notPick;
        }
        prev = curr;
    }
    return prev[target];
}
int knapsack_r(vector<int>&wt,vector<int>&val,int w,int n){
    if(n==0){
        if(wt[0]<=w)return val[0];
        else return 0;
    }
    int notpick = knapsack_r(wt,val,w,n-1);
    int pick = INT_MIN;
    if(wt[n]<=w){
        pick = val[n] +knapsack_r(wt,val,w-wt[n],n-1);
    }
    return max(pick,notpick);
}
int knapsack_m(vector<int>&wt,vector<int>&val,int w,int n,vector<vector<int>>&dp){
    if(n==0){
        if(wt[0]<=w)return val[0];
        else return 0;
    }
    if(dp[n][w]!=-1)return dp[n][w];
    int notpick = knapsack_m(wt,val,w,n-1,dp);
    int pick = INT_MIN;
    if(wt[n]<=w){
        pick = val[n] +knapsack_m(wt,val,w-wt[n],n-1,dp);
    }
    return dp[n][w] = max(pick,notpick);
}
int knapsack_t(vector<int>&wt,vector<int>&val,int w){
    int n = wt.size();
    vector<vector<int>>dp(n,vector<int>(w+1,0));
    for(int i = wt[0] ; i <= w ;i++){
        dp[0][i]=val[0];
    }
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j <= w  ; j++){ 
            int notpick = dp[i-1][j];
            int pick = INT_MIN;
            if(wt[i]<=j){
                pick = val[i] + dp[i-1][j-wt[i]];
            }
            dp[i][j] = max(pick,notpick);
        }
    }
    return dp[n-1][w];
}
int knapsack_2(vector<int>&wt,vector<int>&val,int w){
    int n = wt.size();
    vector<int>prev(w+1,0);
    for(int i = wt[0] ; i <= w ;i++){
        prev[i]=val[0];
    }
    for(int i = 1 ; i < n ; i++){
        vector<int>curr(w+1,0);
        for(int j = 0 ; j <= w  ; j++){ 
            int notpick = prev[j];
            int pick = INT_MIN;
            if(wt[i]<=j){
                pick = val[i] + prev[j-wt[i]];
            }
            curr[j] = max(pick,notpick);
        }
        prev=curr;
    }
    return prev[w];
}
int knapsack(vector<int>&wt,vector<int>&val,int w){
    int n = wt.size();
    vector<int>prev(w+1,0);
    for(int i = wt[0] ; i <= w ;i++){
        prev[i]=val[0];
    }
    for(int i = 1 ; i < n ; i++){
        for(int j = w ; j >= 0  ; j--){ 
            int notpick = prev[j];
            int pick = INT_MIN;
            if(wt[i]<=j){
                pick = val[i] + prev[j-wt[i]];
            }
            prev[j] = max(pick,notpick);
        }
    }
    return prev[w];
}
int coinChanger_r(vector<int>& coins,int amount,int n){
    if(n==0){
        if(amount%coins[0]==0){
            return amount/coins[0];
        }else{
            return 1e9;
        }
    }
    int notpick = coinChanger_r(coins,amount,n-1);
    int pick = 1e9;
    if(coins[n]<=amount){
        pick = coins[n] + coinChanger_r(coins,amount-coins[n],n);
    }
    return min(pick,notpick);
}
int coinChanger_m(vector<int>& coins,int amount,int n,vector<vector<int>>&dp){
    if(amount==0)return 0;
    if(n==0){
        if(amount%coins[0]==0){
            return amount/coins[0];
        }else{
            return 1e9;
        }
    }
    if(dp[n][amount]!=-1)return dp[n][amount];
    int notpick = coinChanger_m(coins,amount,n-1,dp);
    int pick = 1e9;
    if(coins[n]<=amount){
        pick = 1 + coinChanger_m(coins,amount-coins[n],n,dp);
    }
    return dp[n][amount]=min(pick,notpick);
}
int coinChanger_t(vector<int>& coins,int amount){
    int n = coins.size();
    vector<vector<int>>dp(n,vector<int>(amount+1,0));
    for(int i = 1 ; i <= amount ;i++){
        if(i%coins[0]==0){
            dp[0][i]=i/coins[0];
        }else{
            dp[0][i]=1e9;
        }
    }
    for(int i = 1 ; i < n; i++){
        for(int j = 1 ; j <= amount ; j++){
            int notpick = dp[i-1][j];
            int pick = 1e9;
            if(coins[i]<=j){
                pick = 1 + dp[i][j-coins[i]];
            }
            dp[i][j]=min(pick,notpick);
        }
    }
    if(dp[n - 1][amount] >= 1e9)
        return -1;
    return dp[n - 1][amount];
}
int coinChanger(vector<int>& coins,int amount){
    int n = coins.size();
    vector<int>prev(amount+1,0);
    for(int i = 1 ; i <= amount ;i++){
        if(i%coins[0]==0){
            prev[i]=i/coins[0];
        }else{
            prev[i]=1e9;
        }
    }
    for(int i = 1 ; i < n; i++){
        vector<int>curr(amount+1,0);
        for(int j = 1 ; j <= amount ; j++){
            int notpick = prev[j];
            int pick = 1e9;
            if(coins[i]<=j){
                pick = 1 + curr[j-coins[i]];
            }
            curr[j]=min(pick,notpick);
        }
        prev = curr;
    }
    if(prev[amount] >= 1e9)
        return -1;
    return prev[amount];
}
int coinChanger_r_2(vector<int>& coins,int amount,int n){
    if(amount==0)return 1;
    if(n==0){
        if(coins[0]%amount==0){
            return 1;
        }else{
            return 0;
        }
    }
    int notpick = coinChanger_r(coins,amount,n-1);
    int pick = 0;
    if(coins[n]<=amount){
        pick = coinChanger_r(coins,amount-coins[n],n);
    }
    return pick+notpick;
}
int coinChanger_m_2(vector<int>& coins,int amount,int n,vector<vector<int>>&dp){
    if(amount==0)return 1;
    if(n==0){
        if(amount%coins[0]==0){
            return 1;
        }else{
            return 0;
        }
    }
    if(dp[n][amount]!=-1)return dp[n][amount];
    int notpick = coinChanger_m_2(coins,amount,n-1,dp);
    int pick = 0;
    if(coins[n]<=amount){
        pick = coinChanger_m_2(coins,amount-coins[n],n,dp);
    }
    return dp[n][amount]=pick+notpick;
}
int coinChanger_t_2(vector<int>& coins,int amount){
    int n = coins.size();
    vector<vector<int>>dp(n,vector<int>(amount+1,0));
    for(int i = 0 ; i < n ; i++){
        dp[i][0]=1;
    }
    for(int i = 1 ; i <= amount ;i++){
        if(i%coins[0]==0){
            dp[0][i]=1;
        }
    }
    for(int i = 1 ; i < n; i++){
        for(int j = 1 ; j <= amount ; j++){
            int notpick = dp[i-1][j];
            int pick = 0;
            if(coins[i]<=j){
                pick = dp[i][j-coins[i]];
            }
            dp[i][j]=pick+notpick;
        }
    }
    return dp[n - 1][amount];
}
int main(){
    return 0;
}