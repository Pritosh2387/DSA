#include <bits/stdc++.h>
using namespace std;
// optimal for positive and negatives
int LongestSubarray(vector<int>& a, int k) {
    unordered_map<int,int> mpp;
    int n = a.size();
    int sum = 0 ; 
    int maxlen=0;
    for(int i = 0;i< n;i++){
        sum+=a[i];
        if(sum==k){
            maxlen=i+1;
        }
        int prefixsum = sum - k;
        if(mpp.find(prefixsum)!=mpp.end()){
            int len = i - mpp[prefixsum];
            maxlen=max(maxlen,len);
        }
            mpp[sum]=i;
        }
        return maxlen;
    }
// optimal for positive and zeros only
int lon_subarr(vector<int>& a, int k){
    int n = a.size();
    int lp=0;
    int maxln=0;
    int sum=0;
    for(int i = 0 ; i < n ; i++){
        sum+=a[i];
        while(lp<n && sum>k){
            sum-=a[lp];
            lp++;
        }
        if(sum==k){
            maxln=max(maxln,i-lp+1);
        }
    }
    return maxln;
}
int hill_valley(vector<int>&a){
    int last = a[0];
    int ans = 0 ; 
    int n = a.size();
    for(int i = 1 ; i < n-1 ; i++){
        if(a[i]==a[i+1]){
            continue;
        }
        if(a[i]>a[i+1] && a[i]>last || a[i]<a[i+1] && a[i]<last){
            ans++;
        }
        last = a[i];   
    }
    return ans;
}
int main(){
    vector<int> a = {1,2,3,1,1,1,1,3,3};
    int k = 4;
    cout<<lon_subarr(a, k);
    return 0;
}