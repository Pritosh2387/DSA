#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node*left;
    node*right;
    node(int data):data(data),left(nullptr),right(nullptr){}
};
void heapify(vector<int> &a , int n , int i){
    int largest = i;
    int leftchild = 2*i;
    int rightchild = 2*i+1;
    if(leftchild < n && a[i]<a[leftchild]){
        largest=i;
    }
    if(rightchild < n && a[i]<a[rightchild]){
        largest=i;
    }
    if(largest!=i){
        swap(a[i],a[largest]);
        heapify(a,n,largest);
    }
}
vector<int> build_heap(vector<int> &a,int n ){
    for(int i = n/2 ; i>0 ; i--){
        heapify(a,n,i);
    } 
    return a;
}
vector<int> heap_sort(vector<int>&a,int size){
    int n = size;
    while(n>1){
        swap(a[1],a[n]);
        n--;
        heapify(a,n,1);
    }
}
int kth_smallest(vector<int>&a,int k ,int size){
    priority_queue<int> pq;
    for(int i = 0 ; i < k ; i++){
        pq.push(a[i]);
    }
    for(int i = k ; i < size ; i++){
        if(a[i]<pq.top()){
            pq.pop();
            pq.push(a[i]);
        }
    }
    return pq.top();
    /*alternative
    nth_element(a.begin(),a.begin()+k-1,a.end());
    return a[k-1];
    */
}
bool is_CBT(node*root,int i ,int size){
    if(root==nullptr)return true;
    if(i>=size){
        return false;
    }
    bool lefti = is_CBT(root,2*i+1,size);
    bool righti = is_CBT(root,2*i+2,size);
    return lefti && righti;
}
bool maxheap(node*root){
    if(root==nullptr)return true;
    if(root->right==nullptr){
        return (root->data>root->left->data);
    }else{
        bool lefti = maxheap(root->left);
        bool righti = maxheap(root->right);
        return (lefti && righti && (root->data>root->left->data) && (root->data>root->right->data));
    }
}
int countnodes(node*root){
    if(root==nullptr)return 0;
    return 1+countnodes(root->left)+ countnodes(root->right);
}
bool isheap(node*root){
    int size = countnodes(root);
    return is_CBT(root,0,size) && maxheap(root);
}
long long min_cost(vector<int>&a){
    priority_queue<int,vector<int>,greater<int>>pq;
    long long ans=0;
    for(int i : a){
        pq.push(i);
    }
    while(pq.size()>1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        long long sum = a+b;
        ans+=sum;
        pq.push(sum);
    }
    return ans;
}
int k_th_greatest_subarray(vector<int>&a,int k){
    priority_queue<int , vector<int>,greater<int>> pq;
    int n = a.size();
    for(int i = 0 ; i < n ; i++){
        int sum = 0;
        for(int j = i ; j < n ; j++){
            sum+=a[j];
            if(pq.size()<k){
                pq.push(sum);
            }else if(sum>pq.top()){
                pq.pop();
                pq.push(sum);
            }
        }
    }
    return pq.top();
}
int main(){
    return 0;
}