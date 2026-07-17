#include<bits/stdc++.h>
using namespace std;
class NumArray{
public:
    vector<int>seg;
    vector<int>nums;
    int n;
    void make_seg(int i,int left,int right){
        if(left==right){
            seg[i] = nums[right];
            return;
        }
        int mid = left + (right-left)/2;
        make_seg(2*i+1,left,mid);
        make_seg(2*i+2,mid+1,right);
        seg[i] = seg[2*i+1] + seg[2*i+2];
    }
    NumArray(vector<int>& nums){
        this->nums=nums;
        n = nums.size();
        seg.resize(4*n,0);
        make_seg(0,0,n-1);
    }
    void change(int index,int val,int i,int left,int right){
        if(left==right){
            seg[i] = val;
            return;
        }
        int mid = left + (right-left)/2;
        if(index<=mid){
            change(index,val,2*i+1,left,mid);
        }else{
            change(index,val,2*i+2,mid+1,right);
        }
        seg[i] = seg[2*i+1] + seg[2*i+2];
    }
    void update(int index, int val){
        change(index,val,0,0,n-1);
    }
    int sum(int i,int left,int right,int ql,int qr){
        if(right<ql || left>qr){
            return 0;
        }else if(left>=ql && right<=qr){
            return seg[i];
        }
        int mid = left + (right-left)/2;
        return sum(2*i+1,left,mid,ql,qr) + sum(2*i+2,mid+1,right,ql,qr);
    }
    int sumRange(int left, int right){
        return sum(0,0,n-1,left,right);
    }
};
