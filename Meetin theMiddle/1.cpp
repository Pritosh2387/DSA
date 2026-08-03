// You are given an array of n numbers. In how many ways can you choose a subset of the numbers with sum x?
#include<bits/stdc++.h>
using ll = long long;
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    int n1 = n/2;
    int n2 = n-n1;
    vector<ll> sumA;
    vector<ll> sumB;
    for(int mask = 0 ; mask < (1 << n1) ; mask++){
        ll sum = 0;
        for(int i = 0 ; i < n1 ; i++){
            if(mask & (1<<i)){
                sum+=a[i];
            }
        }
        sumA.push_back(sum);
    }
    for(int mask = 0 ; mask < (1 << n2) ; mask++){
        ll sum = 0;
        for(int i = 0 ; i < n2 ; i++){
            if(mask & (1<<i)){
                sum+=a[n1+i];
            }
        }
        sumB.push_back(sum);
    }
    ll ans = 0;
    sort(begin(sumB),end(sumB));
    for(ll it : sumA){
        ll need = x-it;
        ll lower = lower_bound(begin(sumB),end(sumB),need)-sumB.begin();
        ll upper = upper_bound(begin(sumB),end(sumB),need)-sumB.begin();
        ans+=(upper-lower);
    }
    cout<<ans<<endl;
    return 0;
}