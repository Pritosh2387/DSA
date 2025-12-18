#include <bits/stdc++.h>
using namespace std;
double power(double base, int expo) {
    double ans = 1.0;
    int original_expo = expo;
    expo = abs(expo); // Use positive exponent for calculation
    while (expo > 0) {
        if (expo % 2 == 1) {
            ans *= base;
            expo--;
        } else {
            base *= base;
            expo /= 2;
        }
    }
    if (original_expo < 0) {
        return 1.0 / ans;
    } else {
        return ans;
    }
}
int main(){
    cout << fixed << setprecision(10) << power(2.0, -3) << endl;   // 0.125
    cout << fixed << setprecision(10) << power(2.5, 3) << endl;    // 15.625
    cout << fixed << setprecision(10) << power(5.0, 0) << endl;    // 1
    return 0;
}