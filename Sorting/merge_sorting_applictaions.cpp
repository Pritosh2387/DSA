#include<bits/stdc++.h>
using namespace std;
// Count Inversions
int merge_ci(vector<int> &a , int low , int mid , int high){
    vector<int> temp;
    int count = 0 ;
    int lp = low;
    int rp = mid+1;
    while(lp<=mid && rp<=high){
        if(a[lp]<=a[rp]){
            temp.push_back(a[lp++]);
        }else{
            temp.push_back(a[rp++]);
            count+=mid-lp+1;
        }
    }
    while(lp<=mid){
        temp.push_back(a[lp++]);
    }
    while(rp<=high){
        temp.push_back(a[rp++]);

    }
    for(int i = low ; i<=high ; i++){
        a[i]=temp[i-low];
    }
    return count;
}
int  mergesort_ci(vector<int> &a , int low , int high){
    int count = 0 ; 
    if(low>=high)return 0;
    int mid = (low+high)/2;
    count+=mergesort_ci(a,low,mid);
    count+=mergesort_ci(a,mid+1,high);
    count+=merge_ci(a,low,mid,high);
    return count;
}
// Reverse Pairs
void merge_rp(vector<int> &a , int low , int mid , int high){
    vector<int> temp;
    int lp = low;
    int rp = mid+1;
    int right_pt = mid+1;
    while(lp<=mid && rp<=high){
        if(a[lp]<=a[rp]){
            temp.push_back(a[lp++]);
        }else{
            temp.push_back(a[rp++]);
        }
    }
    while(lp<=mid){
        temp.push_back(a[lp++]);
    }
    while(rp<=high){
        temp.push_back(a[rp++]);

    }
    for(int i = low ; i<=high ; i++){
        a[i]=temp[i-low];
    }
}
int countpairs(vector<int> &a , int low , int mid , int high){
    int count = 0; 
    int rp = mid+1;
    for(int i = low;i<=mid;i++){
        while(rp<=high && a[i]>2*a[rp]){
            rp++;
        }
        count+=rp-(mid+1);
    }
    return count;
}
int  mergesort_rp(vector<int> &a , int low , int high){
    int count = 0 ; 
    if(low>=high)return 0;
    int mid = (low+high)/2;
    count+=mergesort_rp(a,low,mid);
    count+=mergesort_rp(a,mid+1,high);
    count+=countpairs(a,low,mid,high);
    merge_rp(a,low,mid,high);
    return count;
}
int main(){
    vector<int> a = {40,25,19,12,9,6,2};
    cout<<mergesort_rp(a,0,a.size()-1)<<"\n";
    for(int i : a){
        cout<<i<<" ";
    }
    return 0 ; 
}