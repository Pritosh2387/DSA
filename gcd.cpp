#include<bits/stdc++.h>
using namespace std;
int gcd(int num1 ,int num2){
    if(num1==0)return num2;
    else if(num2==0) return num1;
    if(num1>num2){
        gcd(num1%num2,num2);
    }else{
        gcd(num2,num1%num2);
    }
}
int main(){
    int n = 546738;
    cout<<gcd(17,34);
    return 0 ;
}