#include<bits/stdc++.h>
using namespace std;
int ai_i(vector<int>&a){
    int n = a.size();
    int lp=0,rp=n-1;
    while(lp<=rp){
        int mid = lp+(rp-lp)/2;
        if(a[mid]==mid){
            return mid;
        }else if(a[mid]>mid){
            rp=mid-1;
        }else{
            lp=mid+1;
        }
    }
    return -1;
}