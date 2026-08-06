#include<bits/stdc++.h>
using namespace std;
bool splitArraySameAverage(vector<int>& nums){
    int n = nums.size();
    int n1 = n/2;
    int n2 = n-n1;
    unordered_map<int,vector<int>>left;
    int S = accumulate(begin(nums),end(nums),0);
    unordered_map<int,vector<int>>right;
    for(int mask = 0 ; mask < (1<<n1) ; mask++){
        int cnt = 0;
        int sum = 0;
        for(int i = 0 ; i < n1 ; i++){
            if(mask & (1<<i)){
                cnt++;
                sum+=nums[i];
            }
        }
        left[cnt].push_back(sum);
    }
    for(int mask = 0 ; mask < (1<<n2) ; mask++){
        int cnt = 0;
        int sum = 0;
        for(int i = 0 ; i < n2 ; i++){
            if(mask & (1<<i)){
                cnt++;
                sum+=nums[i+n1];
            }
        }
        right[cnt].push_back(sum);
    }
    for(auto& [_,it] : right){
        sort(begin(it),end(it));
    }
    for(int i = 0 ; i <= n1 ; i++){
        for(int leftsubsetsum : left[i]){
            for(int m = 0 ; m <= n2 ; m++){
                int size = i+m;
                if(size == 0 || size == n){
                    continue;
                }
                if(size*S % n !=0){
                    continue;
                }
                int rightsum = size*S/n-leftsubsetsum;
                bool r = binary_search(begin(right[m]),end(right[m]),rightsum);
                if(r){
                    return true;
                }
            }
        }
    }
    return false;
}