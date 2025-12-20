#include<bits/stdc++.h>
class node{
public:
    int data;
    node* next;
    node(int data, node* next) {
        this->data = data;
        this->next = next;
    }
    node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
class Treenode{
public:
    int data;
    Treenode*left;
    Treenode*right;
    Treenode(int data): data(data),left(nullptr),right(nullptr){}
    Treenode(int data,Treenode*left):data(data),left(left),right(nullptr){}
};
using namespace std;
// 3446
vector<vector<int>> sortMatrix(vector<vector<int>>& grid){
    int n = grid.size();
    for(int si = 0 ; si < n ; si++){
        int i = si;
        int j = 0;
        vector<int>level;
        while(i< n && j < n ){
            level.push_back(grid[i++][j++]);
        }
        sort(level.begin(),level.end(),greater<int>());
        int i = si;
        int j = 0;
        for(int k = 0 ; k < level.size() ; k++){
            grid[i++][j++]=level[k];
        }
    }
    for(int sj = 1 ; sj < n ; sj++){
        int i = 0;
        int j = sj;
        vector<int>level;
        while(i< n && j < n ){
            level.push_back(grid[i++][j++]);
        }
        sort(level.begin(),level.end(),greater<int>());
        int i = 0;
        int j = sj;
        for(int k = 0 ; k < level.size() ; k++){
            grid[i++][j++]=level[k];
        }
    }
    return grid;
}
// 3021
long long flowerGame(int n,int m){
    long long xodd = (n+1)/2; 
    long long xeven = (n)/2; 
    long long yodd = (m+1)/2; 
    long long yeven = (m)/2;
    return (xodd*yeven)+(yodd*xeven);
}
//1304
vector<int>sumZero(int n){
    vector<int>ans;
    int num = - n/2;
    if( n % 2 == 1 ){
        for(int i = 0 ; i < n ; i++){
            ans.push_back(num++);
        }
    }else{
        for(int i = 0 ; i < n ; i++){
            if(num==0)continue;
            ans.push_back(num++);
        }
    }
    return ans;
}
//3541
int maxFreqSum(string s){
    vector<int>hash(26,0);
    for(auto it : s){
        hash[it-'a']++;
    }
    int maxVowel = 0;
    for(char v : {'a','e','i','o','u'}) {
        maxVowel = max(maxVowel, hash[v - 'a']);
    }
    int maxconso = 0;
    for(int i = 0 ; i < 26 ; i++){
        if(i==0 || i == 'e'-'a' || i == 'i'-'a' || i == 'o'-'a' || i == 'u'-'a')continue;
        maxconso=max(maxconso,hash[i]);
    }
    return maxconso+maxVowel;
}
// 1935
int canBeTypedWords(string text, string brokenLetters){
    int word=0;
    int alphacount = 0; 
    for(int i = 0 ; i < text.length() ; i++){
        if(text[i]==' '){
            if(alphacount==0){
                word++;
            }
            alphacount = 0; 
            continue;
        }
        for(char it : brokenLetters){
            if(text[i]==it){
                alphacount=1;
                break;
            }
        }
    }
    if(alphacount==0)word++;
    return word;
}
// 3005
int maxFrequencyElements(vector<int>& nums){
    int n = nums.size();
    unordered_map<int,int>mpp;
    for(int i = 0 ; i < n ; i++){
        mpp[nums[i]]++;
    }
    int maxi = 0;
    for(int i = 0 ; i < n ; i++){
        maxi=max(mpp[nums[i]],maxi);
    }
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
        if(mpp[nums[i]]==maxi){
            sum++;
        }
    }
    return sum;
}
// 2221
int triangularSum(vector<int>&a){
    int n = a.size();
    vector<int>temp_before=a;
    for(int i = n-1 ; i >= 1 ; i--){
        vector<int>temp_after;
        for(int j = 0 ; j < temp_before.size() -1 ; j++){
            temp_after.push_back((1LL*temp_before[j]+temp_before[j+1]) % 10);
        }
        temp_before.swap(temp_after);
    }
    return temp_before[0];
}
// 1716
int totalMoney(int n){
    int ans = 0; 
    int add = 1;
    for(int i = 1 ; i <= n ; i++){
        ans+=add;
        add++;
        if(i%7==0){
            add = (i/7)+1;
        }
    }    
    return ans;    
}
// 2591
int distMoney(int money, int children){
    if(money<children)return -1;
    int money_to_be_dist = money-children;
    int ans = min(children,money_to_be_dist / 7);
    int m = money_to_be_dist - 7*ans;
    int c = children - ans;
    if(c == 0 && m > 0)return children -1;
    if(c == 1 && m == 3){
        ans--;
    } 
    return ans;
}
//2043
class Bank{
int n;
vector<long long>balance;
public:
    Bank(vector<long long>& balance){
        this->n= balance.size();
        this->balance=balance;
    }
    
    bool transfer(int account1, int account2, long long money){
        if(account1 <= 0 || account1 > n || account2 <= 0 || account2 > n)return false;
        if(balance[account1-1]< money)return false;
        balance[account1-1]-=money;
        balance[account2-1]+=money;
        return true;
    }
    
    bool deposit(int account, long long money){
        if(account <= 0 || account > n)return false;
        balance[account-1]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money){
        if(account <= 0 || account > n)return false;
        if(balance[account-1]< money)return false;
        balance[account-1]-=money;
        return true;
    }
};
// 2125
int numberOfBeams(vector<string>&bank){
    int prev = 0;
    int ans = 0;
    for(int i = 0 ; i < bank.size() ; i++){
        int curr = 0;
        for(int j = 0 ; j < bank[i].size() ; j++){
            if(bank[i][j]=='1'){
                curr++;
            }
        }
        if(curr!=0){
            ans+=curr*prev;
            prev=curr;
        }
    }
    return ans;
}
//12
string intToRoman(int num){
    map<int, string, greater<int>>mpp ={
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
        {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"}, {1, "I"}
    };
    string ans = "";
    for (auto it : mpp) {
        while (num >= it.first) {
            ans += it.second;
            num-= it.first;
        }
    }
    return ans;
}
// 3289
vector<int> getSneakyNumbers(vector<int>& nums){
    unordered_map<int, int> freq;
        for(int num : nums){
            freq[num]++;
        }
        vector<int> ans;
        for(auto it : freq){
            if (it.second == 2)
                ans.push_back(it.first);
        }
        return ans;
}
//3217
node* modifiedList(vector<int>& nums,node* head){
    unordered_set<int> st(nums.begin(), nums.end());
        node* temp = head;
        node* prev = nullptr;
        while(temp){
            if (st.count(temp->data)){
                if(prev){
                    prev->next = temp->next;
                    temp = prev->next;
                }else{
                    head = temp->next;
                    temp = head;
                }
            }else{
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
}
//14
string longestCommonPrefix(vector<string>& strs){
    string ans = strs[0];
    for(int i = 1 ; i < strs.size() ; i++){
        int lp=0,rp=0;
        string temp = "";
        while(lp < ans.size() && rp < strs[i].size()){
            if(ans[lp]==strs[i][rp]){
                temp+=ans[lp];
                lp++;
                rp++;
            }else{
                break;
            }
        }
        ans = temp;
    }
    return ans;
}
//2257
int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls){
    // 0 = empty (answer cell)
    // 1 = guard
    // 2 = wall
    // 3 = guarded (blocked)
    vector<vector<int>> visi(m, vector<int>(n, 0));
    for (auto it : guards) visi[it[0]][it[1]] = 1;    
    for (auto it : walls)  visi[it[0]][it[1]] = 2;    
    for (auto it : guards){
        int x = it[0];
        int y = it[1];
        int i = x - 1;
        while(i >= 0 && visi[i][y] != 1 && visi[i][y] != 2){
            if(visi[i][y] == 0) visi[i][y] = 3;
            i--;
        }
        i = x + 1;
        while(i < m && visi[i][y] != 1 && visi[i][y] != 2){
            if(visi[i][y] == 0) visi[i][y] = 3;
            i++;
        }
        int j = y - 1;
        while(j >= 0 && visi[x][j] != 1 && visi[x][j] != 2){
            if(visi[x][j] == 0) visi[x][j] = 3;
            j--;
        }
        j = y + 1;
        while(j < n && visi[x][j] != 1 && visi[x][j] != 2){
            if(visi[x][j] == 0) visi[x][j] = 3;
            j++;
        }
    }
    int cnt = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if (visi[i][j] == 0)
                cnt++;
        }
    }
    return cnt;
}
//3318
bool comp(pair<int,int>a,pair<int,int>b){
    if (a.first != b.first)
        return a.first > b.first; // freq desc
    return a.second > b.second;   // value desc
}
vector<int> findXSum(vector<int>& nums, int k, int x){
    int n = nums.size();
    vector<int> ans;
    if (k > n)
        return ans;
    for (int i = 0; i <= n - k; ++i){
        vector<int> ht(51, 0);
            // window [i, i+k-1]
        for (int j = i; j < i + k; ++j)
            ht[nums[j]]++;
        // build candidates as (freq, value)
        vector<pair<int, int>> cand;
        cand.reserve(51);
        for (int v = 0; v <= 50; ++v)
            if (ht[v] > 0)
                cand.push_back({ht[v], v});
        sort(cand.begin(), cand.end(), comp);
        int sum = 0;
        for (int t = 0; t <cand.size() && t < x; ++t)
            sum += cand[t].first * cand[t].second;
        ans.push_back(sum);
    }
    return ans;
}
//26
int removeDuplicates(vector<int>& nums){
    int n  =nums.size();
    int lp = 0;
    for(int i = 0 ; i < n ; i++){
        if(nums[i]!=nums[lp]){
            lp++;
            nums[lp]=nums[i];
        }
    }        
    return lp+1;
}
//28
int strStr(string haystack, string needle){
    int a = haystack.length();
    int b = needle.length();
    int lp = 0,rp=0;
    while(lp<a){
        if(rp==b){
            return lp-rp+1;
        }
        if(haystack[lp]==needle[rp]){
            lp++;
            rp++;
        }else{
            rp=0;
            lp++;
        }
    }
    return -1;
}
//1437
bool kLengthApart(vector<int>&nums,int k){
    int n = nums.size();
    int f1 = -1;
    for(int i = 0 ; i < n ; i++){
        if(nums[i]==1){
            f1=i;
            break;
        }
    }
    if(f1==-1){
        return false;
    }
    for(int i = f1 + 1 ; i < n ; i++){
        if(nums[i]==1){
            if(i - f1 - 1 == k){
                return true;
            }
        }
    }
    return false;
}
//58
int lengthOfLastWord(string s){
    int n = s.length();
    int ans = 0;
    int j = -1;
    for(int i = n-1 ; i>=0 ; i--){
        if(s[i]!=' '){
            j = i;
            break;
        }
    }
    while (j >= 0 && s[j] != ' '){
        ans++;
        j--;
    }
    return ans;
}
//2154
bool bs(vector<int>&a,int x){
    int lp = 0 ,rp =a.size()-1;
    while(lp<=rp){
        int mid  = lp+(rp-lp)/2;
        if(a[mid]==x){
            return true;
        }else if(a[mid]>x){
            rp=mid-1;
        }else{
            lp = mid + 1;
        }
    }
    return false;
}
int findFinalValue(vector<int>& nums, int original){
    sort(nums.begin(),nums.end());
    int x = original;
    while(bs(nums,x)==true){
        x=x*2;
    }
    return x;
}
//3190
int minimumOperations(vector<int>&nums){
    int n = nums.size();
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        if(nums[i]%3!=0)ans++;
    }
    return ans;
}
//66
vector<int> plusOne(vector<int>&digits){
    vector<int>a = digits;
    int n = a.size();
    if(a[n - 1] + 1 == 10){
        a[n-1]=1;
        a.push_back(0);
    }else{
        a[n - 1] = a[n - 1] + 1;
    }
    return a;
}
//1018
vector<bool> prefixesDivBy5(vector<int>&nums){
    int n = nums.size();
    vector<bool>ans(n,false);
    int rem = 0;
    for (int i = 0; i < n; i++){
        rem = (rem * 2 + nums[i]) % 5;
        ans[i] = (rem == 0);
    }
    return ans;
}
//1590
int minSubarray(vector<int>&a,int p){
    long long total = accumulate(a.begin(),a.end(),0);
    int rem = total % p;
    if(rem == 0){
        return 0;
    }
    unordered_map<int, int> mpp;  
    mpp[0] = -1;   
    long long prefix = 0;
    int ans = a.size();
    for(int i = 0; i < a.size(); i++){
        prefix = (prefix + a[i]) % p;
        int cur = prefix;
        int need = (cur - rem + p) % p;
        if(mpp.count(need)){
            ans = min(ans, i - mpp[need]);
        }
        mpp[cur] = i;
    }
    return ans == a.size() ? -1 : ans;
}
//217
bool containsDuplicate(vector<int>&nums){
    unordered_map<int,int>mpp;
    int n = nums.size();
    for(int i = 0 ; i < n ; i++){
        if(mpp.find(nums[i])!=mpp.end()){
            return true;
        }
        mpp[nums[i]]++;
    }
    return false;
}
//3142
bool satisfiesConditions(vector<vector<int>>&grid){
    int m = grid.size();
    int n = grid[0].size();
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            int r = j+1;
            int d = i+1;
            if(d<m){
                if(grid[i][j]!=grid[d][j]){
                    return false;
                }
            }
            if(r<n){
                if(grid[i][j]==grid[i][r]){
                    return false;
                }
            }
        }
    }
    return true;
}
//67
string addBinary(string a, string b){
    int i = a.length()-1;
    int j = b.length()-1;
    string ans = "";
    int c = 0; 
    while(i >= 0 || j >= 0 || c){
        int sum = c;
        if(i >= 0){
            sum += a[i] - '0';
            i--;
        } 
        if(j >= 0){
            sum += b[j] - '0';
            j--;
        }
        ans.push_back(char((sum % 2) + '0'));
        c = sum / 2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
//944
int minDeletionSize(vector<string>&strs){
    int n = strs.size();
    int m = strs[0].size();
    int count = 0;
    for (int j = 0; j < m; j++) {
        for (int i = 1; i < n; i++) {
            if (strs[i][j] < strs[i - 1][j]) {
                count++;
                break; 
            }
        }
    }
    return count;
}