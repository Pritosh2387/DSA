#include <bits/stdc++.h>
using namespace std;
class ArrayStack {
private:
    int stack[100];
    int topIndex = -1;
public:
    void push(int x) {
        if (topIndex >= 99) {
            cout << "Stack overflow\n";
            return;
        }
        topIndex++;
        stack[topIndex] = x;
    }
    void pop() {
        if (topIndex < 0) {
            cout << "Stack underflow\n";
            return;
        }
        topIndex--;
    }
    int top() {
        if (topIndex < 0) {
            cout << "Stack is empty\n";
            return -1;
        }
        return stack[topIndex];
    }
    int size() {
        return topIndex + 1;
    }
    bool empty() {
        return topIndex == -1;
    }
};
class ArrayQueue {
private:
    int queue[100];
    int frontIndex = -1;
    int rearIndex = -1;
    int count = 0;
public:
    void push(int x) {
        if (count >= 100) {
            cout << "Queue overflow\n";
            return;
        }
        if(count==0)frontIndex=0;
        rearIndex = (rearIndex + 1) % 100;
        queue[rearIndex] = x;
        count++;
    }
    void pop() {
        if (count == 0) {
            cout << "Queue underflow\n";
            return;
        }
        frontIndex = (frontIndex + 1) % 100;
        count--;
    }
    int front() {
        if (count == 0) {
            cout << "Queue is empty\n";
            return -1;
        }
        return queue[frontIndex];
    }
    int size() {
        return count;
    }
    bool empty() {
        return count == 0;
    }
};
class Node{
public:
    int data;
    Node*next;
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
    Node(int data , Node* next){
        this->data=data;
        this->next=next;
    }
};
class LLStack{
public:
    Node* top=nullptr;
    int currsize=0;
    void push(int x){
        Node* temp=new Node(x);
        temp->next=top;
        currsize++;
        top=temp;
    }
    void pop(){
        if(currsize==0){
            cout<<"Underflow";
            return;
        }
        Node*temp = top;
        top=top->next;
        currsize--;
        delete temp;
    }
    int size(){
        return currsize;
    }
    int peek(){
    if (top == nullptr) {
        cout << "Stack is empty\n";
        return -1;
    }
    return top->data;
}
};
bool vaild_parentheses(string s){
    stack<char> st;
    for(char c : s){
        if(c=='('||c=='{'||c=='['){
            st.push(c);
        }else{
            if(st.empty()){
                return false;
            }
            char ch = st.top();
            st.pop();
            if( (c==')' && ch!='(')  || (c=='}' && ch!='{') || (c==']' && ch!='[')){
                return false;
            }
        }
    }
    return st.empty();
}
class MinStack {
private:
    long long mini = LLONG_MAX;
    stack<long long> st;

public:
    MinStack() {}

    void push(int val) {
        long long value = val;
        if (st.empty()) {
            st.push(value);
            mini = value;
        } else if (value >= mini) {
            st.push(value);
        } else {
            st.push(2 * value - mini);
            mini = value;
        }
    }

    void pop() {
        long long x = st.top();
        st.pop();
        if (x < mini) {
            mini = 2 * mini - x;
        }
    }

    int top() {
        long long x = st.top();
        if (x >= mini) {
            return x;
        } else {
            return mini;
        }
    }

    int getMin() { return mini; }
};
vector<int> next_min(vector<int>&a){
    stack<int> st;
    int n= a.size();
    vector<int> ans(n);
    for(int i = n-1 ; i>=0 ; i--){
        while(!st.empty() && st.top()<=a[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i]=-1;
        }else{
            ans[i]=st.top();
        }
        st.push(a[i]);
    }
    return ans;
}
vector<int> next_min2(vector<int> &a){
        stack<int> st;
        int n = a.size();
        vector<int> ans(n,-1);
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= a[i%n]) {
                st.pop();
            }
            if (i < n && !st.empty()) {
                ans[i] = st.top();
            }
            st.push(a[i % n]);
        }
        return ans;
}
int trapped_water(vector<int>&a){
    int l_max=0;
    int r_max=0;
    int water=0;
    int lp=0,rp=a.size()-1;
    while(lp<rp){
        if(a[lp]<=a[rp]){
            if(a[lp]<l_max){
                water+=l_max-a[lp];
            }else{
                l_max=a[lp];
            }
            lp++;
        }else{
            if(a[rp]<r_max){
                water+=r_max-a[rp];
            }else{
                r_max=a[rp];
            }
            rp--;
        }
    }
    return water;
}
vector<int> nse(vector<int>&a){
    int n =a.size(); 
    vector<int>ans(n,n);
    stack<int>st;
    for(int i = n-1 ; i>=0 ; i--){
        while(!st.empty() && a[st.top()]>=a[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i]=st.top();
        }
        st.push(i);
    }
    return ans;
}
vector<int> nge(vector<int>&a){
    int n =a.size(); 
    vector<int>ans(n,n);
    stack<int>st;
    for(int i = n-1 ; i>=0 ; i--){
        while(!st.empty() && a[st.top()]<=a[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i]=st.top();
        }
        st.push(i);
    }
    return ans;
}
vector<int> pse(vector<int>&a){
    int n =a.size(); 
    vector<int>ans(n,-1);
    stack<int>st;
    for(int i = 0 ; i < n ; i++){
        while(!st.empty() && a[st.top()]>a[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i]=st.top();
        }
        st.push(i);
    }
    return ans;
}
vector<int> pge(vector<int>&a){
    int n =a.size(); 
    vector<int>ans(n,-1);
    stack<int>st;
    for(int i = 0 ; i < n ; i++){
        while(!st.empty() && a[st.top()]<a[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i]=st.top();
        }
        st.push(i);
    }
    return ans;
}
int sum_subarray_min(vector<int>&a){
    int n = a.size();
    vector<int> _nse=nse(a);
    vector<int> _pse=pse(a);
    int mod=(int)1e9+7;
    long long sum = 0; 
    for(int i = 0 ; i < n ; i++){
        int left = i -_pse[i];
        int right = _nse[i]-i;
        sum=(sum+((1LL*left*right)*a[i]%mod))%mod;
    }
    return sum;
}
int sum_subarray_max(vector<int>&a){
    int n = a.size();
    vector<int> _nge=nge(a);
    vector<int> _pge=pge(a);
    int mod=(int)1e9+7;
    long long sum = 0; 
    for(int i = 0 ; i < n ; i++){
        int left = i -_pge[i];
        int right = _nge[i]-i;
        sum=(sum+((1LL*left*right)*a[i]%mod))%mod;
    }
    return sum;
}
vector<int> astroid_collison(vector<int>&a){
    vector<int>ans;
    for(int i = 0; i< a.size() ; i++){
        if(a[i]>0){
            ans.push_back(a[i]);
        }else{
            while(!ans.empty() && ans.back()>0 && ans.back()<abs(a[i])){
                ans.pop_back();
            }
            if(!ans.empty() && ans.back()==abs(a[i])){
                ans.pop_back();
            }else if(ans.empty() || ans.back()<0){
                ans.push_back(a[i]);
            }
        }
    }
    return ans;
}
string remove_k(string str ,int k){
    string ans="";
    stack<char> st;
    for(int i = 0 ; i < str.length() ; i++){
        while(!st.empty() && st.top()-'0'>str[i]-'0' && k>0){
            st.pop();
            k--;
        }
        st.push(str[i]);
    }
    while(k>0){
        st.pop();
        k--;
    }
    if(st.empty())return "0";
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    while(!ans.empty() && ans.back()=='0'){
        ans.pop_back();
    }
    if(ans.empty())return "0";
    reverse(ans.begin(),ans.end());
    return ans;
}
int largest_area_rec(vector<int> &a){
    int n = a.size();
    stack<int> st;
    int ans=INT_MIN;
    for(int i = 0 ; i < n ; i++){
        while(!st.empty() && a[i]<a[st.top()]){
            int ele = st.top();
            st.pop();
            int nge = i; 
            int nse = st.empty()? -1:st.top();
            ans=max(ans,a[ele]*(nge-nse-1));
        }
        st.push(i);
    }
    while(!st.empty()){
        int nse = n;
        int ele=st.top();
        st.pop();
        int pse = st.empty()? -1:st.top();
        ans=max(ans,a[ele]*(nse-pse-1));
    }
    return ans;
}
int max_rec(vector<vector<int>> &mat){
    vector<vector<int>> psum(mat.size(), vector<int>(mat[0].size()));
    for (int j = 0; j < mat[0].size(); j++) {
        int sum = 0;
        for (int i = 0; i < mat.size(); i++) {
            sum += mat[i][j] - '0';
            if (mat[i][j] == '0') {
                sum = 0;
            }
            psum[i][j] = sum;
        }
    }
    int ans = INT_MIN;
    for (int j = 0; j < mat.size(); j++) {
        ans = max(ans, largest_area_rec(psum[j]));
    }
    return ans;
}
vector<int> max_sliding_window(vector<int>&a ,int k){
    int n = a.size();
    vector<int> ans;
    deque<int> dq;
    for(int i = 0 ; i < a.size() ; i++){
        if(!dq.empty() && dq.front()<=i-k){
            dq.pop_front();
        }
        while(!dq.empty() && a[i]>=a[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k-1){
            ans.push_back(a[dq.front()]);
        }
    }
    return ans; 
}
int celebrity_prob(vector<vector<int>>&mat){
    int dp = mat.size();
    int up = 0;
    while(up<dp){
        if(mat[up][dp]){
            up++;
        }else if(mat[dp][up]){
            dp--;
        }else{
            up++;
            dp--;
        }
    }
    if(up!=dp)return-1;
    for(int i = 0 ; i < mat.size() ; i++){
        if(i==up){
            continue;
        }
        if(mat[up][i] == 0 && mat[i][up] == 1 ){}
        else{
            return -1;
        }
    }
    return up;    
}
class stock_selector{
private:
stack<pair<int,int>> st;
    int index = -1 ;
public:
    stock_selector(){
        index=-1;
    }
    int next(int price){
        index++;
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        int up = st.empty()?-1:st.top().second;
        int ans = index-up;
        st.emplace(price,index);
        return ans;
    }
};
class node{
public:
    int data;
    int key;
    node*next;
    node*back;
    node(int data,int key){
        this->key=key;
        this->data=data;
        this->back=nullptr;
        this->next=nullptr;
    }
};
class LRUCACHE{
private:
    unordered_map<int,node*> mpp;
    int capacity=0;
    node*head=new node(-1,-1);
    node*tail=new node(-1,-1);
public:
    void addNode(node* newnode) {
        node* temp = head->next;
        head->next = newnode;
        newnode->back = head;
        newnode->next = temp;
        temp->back = newnode;
    }
    void deleteNode(node* delnode){
        node* prev = delnode->back;
        node* next = delnode->next;
        prev->next = next;
        next->back = prev;
    }
    LRUCACHE(int capacity){
        this->capacity=capacity;
        this->head->next=tail;
        this->tail->back=head;
        mpp.clear();
    }
    int get(int key){
        if(mpp.find(key)==mpp.end()){
            return -1;
        }else{
            node* temp= mpp[key];
            deleteNode(temp);
            addNode(temp);
            return temp->data;
        }
    }
    void put(int key, int value) {
    if (mpp.find(key) != mpp.end()) {
        node* existing = mpp[key];
        deleteNode(existing);         
        existing->data = value;                 
        addNode(existing);            
        mpp[key] = head->next;         
        return;
    }

    if (mpp.size() == capacity) {
        node* lru = tail->back;
        deleteNode(lru);              
        mpp.erase(lru->key);       
    }

    node* newNode = new node(value, key);
    addNode(newNode);
    mpp[key] = newNode;
}

};
int main() {
    vector<int> a = {3,1,2,4};
    cout<<sum_subarray_min(a);
    return 0;
}