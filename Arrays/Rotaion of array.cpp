#include<bits/stdc++.h>
using namespace std;
// Left Rotated
void brute_pritosh(vector<int> &a,int k){
    int n = a.size();
    int d = k % n;
    for(int i = 0 ; i < d ; i++){
        int temp = a[0];
        for(int i = 1 ; i < n ; i++){
            a[i-1]=a[i];
        }
        a[n-1]=temp;
    }
}
void brute(vector<int> &a,int k){
    int n = a.size();
    int d = k % n;
    vector<int> temp;
    for(int i = 0 ; i < d ; i++){
        temp.push_back(a[i]);
    }
    for(int i = d ; i < n ; i++){
        a[i-d]=a[i];
    }
    for(int i = n - d ; i < n ; i++){
        a[i]=temp[i-n+d];
    }
    return;
}
void optimal_left(vector<int> &a , int k ){
    int n = a.size();
    int d = k % n ;
    reverse(a.begin(),a.begin()+d);
    reverse(a.begin() + d ,a.begin() + n );
    reverse(a.begin(),a.end());

}
// Right Rotated
void optimal_right(vector<int> &a , int k ){
    int n = a.size();
    int d = k % n ;
    reverse(a.begin(),a.end());
    reverse(a.begin(),a.begin()+d);
    reverse(a.begin() + d ,a.begin() + n );
}
int main(){
    vector<int> a = {1,2,3,4,5,6,7};
    optimal_right(a,3);
    for(int i : a){
        cout<<i<<" ";
    }
    return 0 ; 
}