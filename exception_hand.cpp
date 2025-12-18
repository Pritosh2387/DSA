#include<bits/stdc++.h>
using namespace std;
int main(){
    try{
        int a = 10, b = 0;
        if (b == 0)
            throw "Division by zero error"; 
        cout << a / b;
    }
    catch (char const *msg){  
        cout << "Exception caught: " << msg << endl;
    }
}