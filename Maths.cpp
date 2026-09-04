#include<bits/stdc++.h>
using namespace std;
//4002
using ll = long long;
int countValidSequences(int n, int k){
    const int mod = 1e9+7;
    auto power = [&](ll a,ll b)->ll {
        ll ans = 1;
        while(b){
            if(b&1){
                ans = ans * a % mod;
            }
            a = a*a % mod;
            b>>=1;
        }
        return ans;
    };
    vector<ll> fact(n+1,1);
    for(int i = 1 ; i <= n ; i++){
        fact[i] = fact[i-1]*i % mod;
    }
    vector<ll> ifact(n+1);
    ifact[n] = power(fact[n],mod-2) % mod;
    for(int i = n ; i >= 0 ; i--){
        ifact[i-1] = ifact[i+1]*i % mod;
    }
    auto ncr = [&](ll n,ll r)->ll {
        if(r<0 || r>n)return 0;
        return fact[n] * ifact[r] % mod * ifact[n-r] % mod;
    };
    int total = ncr(n-1,k-1);
    if((n-k) % 2 != 0){
        return total;
    }
    int m = (n-k)/2;
    return (total - ncr(m + k - 1, k - 1) + mod) % mod;
}