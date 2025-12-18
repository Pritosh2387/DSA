#include<bits/stdc++.h>
using namespace std;
int lower_bound_custom(vector<int> &a, int n) {
    int lp = 0, rp = a.size() - 1, ans = rp + 1;
    while (lp <= rp) {
        int mid = lp + (rp - lp) / 2;
        if (a[mid] >= n) {
            ans = mid;
            rp = mid - 1;
        } else {
            lp = mid + 1;
        }
    }
    return ans;
}
int upper_bound_custom(vector<int> &a, int n) {
    int lp = 0, rp = a.size() - 1, ans = rp + 1;
    while (lp <= rp) {
        int mid = lp + (rp - lp) / 2;
        if (a[mid] > n) {
            ans = mid;
            rp = mid - 1;
        } else {
            lp = mid + 1;
        }
    }
    return ans;
}
int floor(vector<int> &a, int n) {
    int lp = 0, rp = a.size() - 1, ans = -1;
    while (lp <= rp) {
        int mid = lp + (rp - lp) / 2;
        if (a[mid] <= n) {
            ans = a[mid];
            lp = mid + 1;
        } else {
            rp = mid - 1;
        }
    }
    return ans;
}
vector<int> smallest_greatest_index(vector<int> &a, int target) {
    int lb = lower_bound_custom(a, target);
    if (lb == a.size() || a[lb] != target) {
        return {-1, -1};
    }
    int ub = upper_bound_custom(a, target);
    return {lb, ub - 1};
}
int sorted_in_a_rotated_array(vector<int> &a , int target){
    int lp=0,rp=a.size()-1;
    while(lp<=rp){
        int mid=lp+(rp-lp)/2;
        if(a[mid]==target){
            return mid;
        }
        // Left Sorted
        if(a[lp]<=a[mid]){
            if(a[lp]<=target && a[mid]>=target){
                rp=mid-1;
            }else{
                lp=mid+1;
            }
        // Right Sorted
        }else{
            if(a[mid]<=target && a[rp]>=target){
                lp=mid+1;
            }else{
                rp=mid-1;
            }
        }
    }
    return -1;
}
// Index of smallest element in an array gives no of times it has been rotated  
int min_in_rotated_sorted_array(vector<int> &a){
    int lp =0,rp=a.size()-1;
    int mini = INT_MAX;
    int index = -1;
    while(lp <= rp){
        int mid=lp+(rp-lp)/2;
        if(a[lp]<=a[rp]){
            if(a[lp]<mini){
                mini=a[lp];
                index=lp;
            }
        }
        if(a[lp]<=a[mid]){
            if(a[lp]<mini){
                mini=a[lp];
                index=lp;
            }
            lp=mid+1;
        }else{
            if(a[mid]<mini){
                mini=a[mid];
                index=mid;
            }
            rp=mid-1;
        }
    }
    cout<<"INDEX = "<<index<<"\n";
    return mini;
}
int single_element_in_an_array(vector<int> &a){
    int n = a.size();
    int lp=1,rp=n-1;
    if(n==1)return a[0];
    if(a[0]!=a[1])return a[0];
    if(a[n-1]!=a[n-2])return a[n-1];
    while(lp<=rp){
        int mid = lp+(rp-lp)/2;
        if(a[mid]!=a[mid+1]&&a[mid]!=a[mid-1]){
            return a[mid];
        }else if(mid % 2 == 0 && a[mid]==a[mid+1] || mid % 2 == 1 && a[mid]==a[mid-1]){
            lp=mid+1;
        }else{
            rp=mid-1;
        }
    }
} 
int peak_element(vector<int>&a){
    int n = a.size();
    if(n==1)return a[0];
    if(a[0]>a[1])return 0;
    if(a[n-1]>a[n-2])return n-1;
    int lp = 1 , rp = n-2;
    while(lp<=rp){
        int mid=lp+(rp-lp)/2;
        if(a[mid]>a[mid-1]&&a[mid]>a[mid+1]){
            return mid;
        }else if(a[mid]>a[mid-1]){
            lp=mid+1;
        }else{
            rp=mid-1;
        }
    }
    return -1;
}
int find_pivot_in_rotated_sorted_array(vector<int>&a){
    
    
} 
int main(){
    vector<int> a = {5,5,6,7,7,8,8,9,9};
    cout << single_element_in_an_array(a);
    return 0;
}