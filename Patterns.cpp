#include<bits/stdc++.h>
using namespace std;
void pattern1(int n ){
    for(int i = 0 ; i < 2*n -1  ; i++){
        if(i>n){
            for(int k = 0 ; k< 2*n-i;k++ ){
                cout<<"* ";
            }
        }else{
            for(int j = 0 ; j <i+1 ; j++){
                cout<<"* ";
            }
        }
        cout<<"\n";
    }
} 
void pattern2( int n ){
    char ch ='E';
    for(int i = 1 ; i<=n ; i++ ){
        for(int j = 1 ; j <= i ; j++){
            cout<<ch;
            ch++;
        }
        ch = ch-i-1;
        cout<<"\n";
    }
}
int main(){ 
    pattern1(5);
    pattern2(5);
    return 0;  
}    