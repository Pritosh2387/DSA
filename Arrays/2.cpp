#include<bits/stdc++.h>
using namespace std;
int missing_number(vector<int> &a){
    int n = a.size();
    long long int  sum = ((n+1)*(n+2))/2;
    int sumarr = 0;
    for(int i = 0 ; i < n ; i++){
        sumarr+=a[i];
    }
    return sum-sumarr;
}
int missing_number_by_xor(vector<int> &a){
    int n = a.size();
    int zor1 = 0,zor2=0;
    for(int i = 0 ; i < n ; i++){
        zor2=zor2^a[i];
        zor1 = (i+1)^zor1;
    }
    zor1^=n+1;
    return zor1^zor2;
}
int max_cocecutive1s(vector<int> &a){
    int maxa = 0 ; 
    int count = 0 ; 
    for(int i = 0 ; i < a.size(); i++){
        if(a[i]==1){
            count++;
        }else{
            if(count>maxa){
                maxa = count;
            }
            count=0;
        }
    }
    return maxa;
}
int main(){
    vector<int> b = {1,1,0,1,1,1,0,1,1};
    cout<<max_cocecutive1s(b)<<"\n";
    return 0 ; 
}