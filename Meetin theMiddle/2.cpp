#include<bits/stdc++.h>
using namespace std;
int minimumDifference(vector<int>&nums){
    int n = nums.size()/2;
    unordered_map<int,vector<int>>left;
    int S = accumulate(begin(nums),end(nums),0);
    unordered_map<int,vector<int>>right;
    for(int mask = 0 ; mask < (1<<n) ; mask++){
        int cntA = 0;
        int sumA = 0;
        int cntB = 0;
        int sumB = 0;
        for(int i = 0 ; i < n ; i++){
            if(mask & (1<<i)){
                cntA++;
                cntB++;
                sumA+=nums[i];
                sumB+=nums[i+n];
            }
        }
        left[cntA].push_back(sumA);
        right[cntB].push_back(sumB);
    }
    for(auto& [_,it] : right){
        sort(begin(it),end(it));
    }
    int ans = 1e9;
    for(int i = 0 ; i <= n ; i++){
        for(int leftsubsetsum : left[i]){
            int need = (S - 2*leftsubsetsum) / 2;
            int m = n-i;
            int r = lower_bound(begin(right[m]),end(right[m]),need)-right[m].begin();
            if(r < right[m].size()){
                ans = min(ans,abs(2*(leftsubsetsum+right[m][r])-S));
            }
            if(r-1 >=0){
                ans = min(ans,abs(2*(leftsubsetsum+right[m][r-1])-S));
            }
        }
    }
    return ans;
}