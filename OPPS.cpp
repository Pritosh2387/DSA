#include <bits/stdc++.h>
using namespace std;
class Base{
public:
    int x = 9;
}; 
class child:public Base{
    public:
    int x =6;
};
int main(){
    Base b;
    child c;
    cout<<c.x;
    return 0;
}