#include<bits/stdc++.h>
using namespace std;
int main(){
    int s = 5;
    int *p = &s;
    cout<<dec<<(uintptr_t)p;
}