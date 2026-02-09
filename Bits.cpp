#include<bits/stdc++.h>
using namespace std;
void swap_no(int&a,int&b){
    a = a^b;
    b = a^b;//a
    a = a^b;
}
bool i_bit(int a , int i){
    /*left
    return (a&(1<<i));
    */
    //Right
    return ((a>>i)&1);
}
int set_i(int num,int i){
    int a = num|(1<<i);
    return a;
}
int clear_i(int num,int i){
    int a = num &(~(1<<i));
    return a;
}
int unset_right(int a){
    return a&a-1;
}
int set_right(int n){
    //101001
    //101000
    return n|(n+1);
}
int set_of2(int a){
    return a & a-1;
}
int set_bits(int n){
    int cnt =0;
    while(n>0){
        n = n & (n - 1);
        cnt++;
    }
   // return cnt;
   return __builtin_popcount(n);
}
vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>>ans;
    int n = nums.size();
    int subsets = 1<<n;
    for(int i = 0 ; i < subsets ; i++){
        vector<int>temp;
        for(int j = n-1 ; j>=0 ; j--){
            if(1<<j & i){
                temp.push_back(nums[j]);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}
int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;
    long long a = labs(dividend);
    long long b = labs(divisor);
    long long res = 0;
    while(a >= b){
        long long temp = b, multiple = 1;
        while (a >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        a -= temp;
        res += multiple;
    }
    if((dividend < 0) ^ (divisor < 0))
            res = -res;
    if (res > INT_MAX) return INT_MAX;
    if (res < INT_MIN) return INT_MIN;
    return (int)res;
}
vector<int> single_no_3(vector<int>&a){
    int n = a.size();
    long long sum = 0;
    for(int it : a){
        sum^=it;
    }
    int b1=0;
    int b2=0;
    int rightmost = sum & ~(sum - 1);
    for(int it : a){
        if(it&rightmost){
            b1^=it;
        }else{
            b2^=it;
        }
    }
    return {b1,b2};
}
int XORtillN(int n){
    if(n % 4 == 1)return 1;
    if(n % 4 == 2)return n+1;
    if(n % 4 == 3)return 0;
    return n;
}

int main(){
    int a = 8;
    int b = 6;
    cout<<a<<b;
    cout<<"\n";
    swap_no(a,b);
    cout<<a<<b;
    return 0;
}