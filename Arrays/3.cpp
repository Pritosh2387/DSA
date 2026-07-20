#include<bits/stdc++.h>
using namespace std;
void zeros_at_last(vector<int> &a){
    int j =-1;
    for(int i=0;i<a.size();i++){
        if(a[i]==0){
            j=i;
            break;
        }
    }
    if(j==-1)return;
    for(int i=j+1;i<a.size();i++){
        if(a[i]!=0){
            swap(a[i],a[j]);
            j++;
        }
    }
}
vector<int> _union_(vector<int> &a, vector<int> &b) {
    vector<int> union_arr;
    int i = 0, j = 0;
    
    while(i < a.size() && j < b.size()) {
        if(a[i] <= b[j]) {
            if(union_arr.empty() || union_arr.back() != a[i]) {
                union_arr.push_back(a[i]);
            }
            i++;
        } else {
            if(union_arr.empty() || union_arr.back() != b[j]) {
                union_arr.push_back(b[j]);
            }
            j++;
        }
    }
    
    while(i < a.size()) {
        if(union_arr.empty() || union_arr.back() != a[i]) {
            union_arr.push_back(a[i]);
        }
        i++;
    }
    
    while(j < b.size()) {
        if(union_arr.empty() || union_arr.back() != b[j]) {
            union_arr.push_back(b[j]);
        }
        j++;
    }
    
    return union_arr;
}
vector<int> _intersection_(vector<int> &a, vector<int> &b) {
    int n = a.size();
    vector<int> ans;
    int m = b.size();
    int i = 0 , j = 0;
    while(i < n && j < m){
        if(a[i]<b[j]){
            i++;
        }else if (a[i]>b[j]){
            j++;
        }else{
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans;
}
int main() {
    vector<int> a = {1,1,2,3,4,4,5};
    vector<int> b = {2,3,4,4,5,6};
    vector<int> ab = _intersection_(a, b);
    for(int i : ab) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}