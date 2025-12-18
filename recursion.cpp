#include<bits/stdc++.h>
using namespace std;
void reverse_array(vector<int> &a,int i){
    int n = a.size();
    if(i>=n/2)return;
    swap(a[i],a[n-i-1]);
    reverse_array(a,i+1);
    return ;
}
int fibo(int n){
    if(n==1 || n==2){
        if(n==1){
            return 0;
        }else{
            return 1;
        }
    }
    return fibo(n-1)+fibo(n-2);
}
void print_all_subse(vector<int>& ans , vector<int>& a,int i ){
    if(i==a.size()){
        if(ans.size()==0){
            cout<<"{}";
        }
        for(auto it: ans){
            cout<<it<<" ";
        }
        cout<<"\n";
        return ;
    }
    ans.push_back(a[i]);
    print_all_subse(ans,a,i+1);
    ans.pop_back();
    print_all_subse(ans,a,i+1);
}   
void print_with_sum_k(int i,vector<int>&ans,vector<int> &a,int k,int sum){
    if(i==a.size()){
        if(sum==k){
            for(int i : ans){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        return ;
    }
    ans.push_back(a[i]);
    sum+=a[i];
    print_with_sum_k(i+1,ans,a,k,sum);
    ans.pop_back();
    sum-=a[i];
    print_with_sum_k(i+1,ans,a,k,sum);
}
void two_sum_repeat(int i , vector<int>&a,int target,vector<vector<int>> &ans,vector<int>&ds){
    if(i==a.size()){
        if(target==0){
            ans.push_back(ds);
        }
        return;
    }
    if(a[i]<=target){
        ds.push_back(a[i]);
        two_sum_repeat(i,a,target-a[i],ans,ds);
        ds.pop_back();
    }
    two_sum_repeat(i+1,a,target,ans,ds);
}
vector<vector<int>> two_sum_f_repeat(vector<int>&a,int target){
    vector<vector<int>> ans;
    vector<int> ds;
    two_sum_repeat(0,a,target,ans,ds);
    return ans;
}
void two_sum(int i,vector<vector<int>> &ans,vector<int>&a,int target,vector<int>&ds){
    if(target==0){
        ans.push_back(ds);
        return;
    }
    for(int j = i ; j<a.size();j++){
        if(j>i){
            if(a[j]==a[j-1]){
                continue;
            }
        }
        if(a[j]>target)break;
        ds.push_back(a[j]);
        two_sum(j+1,ans,a,target-a[j],ds);
        ds.pop_back();
    }
}
vector<vector<int>> two_sum_f(vector<int> &a,int target){
    sort(a.begin(),a.end());
    vector<vector<int>> ans;
    vector<int> ds;
    two_sum(0,ans,a,target,ds);
    return ans;
}
void subset_sum(int i , vector<int> &a,vector<int> &ans,int sum){
    if(i==a.size()){
        ans.push_back(sum);
        return; 
    }
    subset_sum(i+1,a,ans,sum+a[i]);
    subset_sum(i+1,a,ans,sum);
}
void subset_non_repeat(int i,vector<vector<int>> &ans,vector<int>&a,vector<int>&ds){
    ans.push_back(ds);
    for(int j = i ; j<a.size();j++){
        if(j!=i && a[j]==a[j-1]){
            continue;
        }
        ds.push_back(a[j]);
        subset_non_repeat(j+1,ans,a,ds);
        ds.pop_back();
    }
}
void permute(int i,vector<int>&a,vector<vector<int>>&ans){
    if(i==a.size()){
        ans.push_back(a);
        return;
    }
    for(int j = i ; j < a.size() ; j++){
        swap(a[j],a[i]);
        permute(i+1,a,ans);
        swap(a[j],a[i]);
    }
}
bool is_palindrome(string s , int i , int j ){
    while(i<j){
        if(s[i++]!=s[j--]){
            return false;
        }
    }
    return true;
}
void palindrome_partitioning(string str , int i ,vector<vector<string>>& ans,vector<string>&ds){
    if(i==str.length()){
        ans.push_back(ds);
        return;
    }
    for(int j = i ; j<str.length();j++){
        if(is_palindrome(str,i,j)){
            ds.push_back(str.substr(i,j-i+1));
            palindrome_partitioning(str,i+1,ans,ds);
            ds.pop_back();
        }
    }
}
void rat_in_a_maze(int row, int col,vector<vector<int>>&visi,vector<string>&ans,string str,vector<int>&di,vector<int>&dj,vector<vector<int>>&a){
    int n = a.size();
    if( row == n-1 && col == n-1 ){
        ans.push_back(str);
        return;
    }
    string dir="DLRU";
    for(int i = 0;i<4;i++){
        int nexti=row+di[i];
        int nextj=col+dj[i];
        if(nexti >= 0 && nextj < n && nexti < n && nextj>=0 && !visi[nexti][nextj] && a[nexti][nextj]==1){
            visi[row][col]=1;
            rat_in_a_maze(nexti,nextj,visi,ans,str+dir[i],di,dj,a);
            visi[row][col]=0;

        }
    }
}
void rat(){
    vector<vector<int>> a = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    int n = a.size();
    vector<string> ans;

    if (n == 0 || a[0][0] == 0 || a[n - 1][n - 1] == 0) {
        cout << "No path found.\n";
        return;
    }

    vector<vector<int>> visi(n, vector<int>(n, 0));
    vector<int> di = {1, 0, 0, -1};  // D, L, R, U
    vector<int> dj = {0, -1, 1, 0};

    rat_in_a_maze(0, 0, visi, ans, "", di, dj, a);

    if (ans.empty()) {
        cout << "No path found.\n";
    } else {
        cout << "Paths:\n";
        for (string &s : ans) {
            cout << s << "\n";
        }
    }
}
bool is_valid(vector<vector<char>>&board,int i ,int j ,char c){
    for(int k = 0 ; k < 9 ; k++){
        if(board[i][k]==c){
            return false;
        }
        if(board[k][j]==c){
            return false;
        }
        if(board[3*(i/3) +i/3][3*(j/3)+i%3]==c){
            return false;
        }
        return true;
    }
}
bool solve_sudoko(vector<vector<char>>&board){
    int n = board.size();
    for(int i = 0 ; i<n;i++){
        for(int j =0 ; j<n;j++){
            if(board[i][j]=='.'){
                for(char c = 1 ; c < 10 ; c++){
                    if(is_valid(board,i,j,c)){
                        board[i][j]=c;
                    }
                    if(solve_sudoko(board)==true){
                        return true;
                    }else{
                        board[i][j]='.';
                    }
                }
                return false;
            }
            return true;
        }
    }
}
int main(){
    rat();
    return 0;
}