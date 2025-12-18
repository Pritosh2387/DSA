#include<bits/stdc++.h>
using namespace std;
int nCr(int n ,int r){
    int ans=1;
    for(int i = 0 ; i< r ; i++){
        ans*=(n-i);
        ans/=i+1;
    }
    return ans;
}
int find_r_th_row_c_th_columm(int r,int c){
    return nCr(r-1,c-1);
}
void print_n_th_row(int n){
    long long int ans = 1;
    cout<<ans;
    for(int i = 1 ; i < n ; i++){
        ans*=n-i;
        ans/=i;
        cout<<ans;
    }
}
vector<int> generate_N_th_row(int n){
    vector<int> ans;
    int x = 1;
    ans.push_back(x);
    for(int i = 1 ; i< n ; i++){
        x*=n-i;
        x/=i;
        ans.push_back(x);
    }
    return ans;
}
vector<vector<int>> pascal_triangle(int n){
    vector<vector<int>> final_ans;
    for(int i =1 ; i<=n;i++){
        final_ans.push_back(generate_N_th_row(i));
    }
    return final_ans;
}
vector<int> majority_element_3times(vector<int> &a){
    vector<int> ans;
    unordered_map<int,int> mpp;
    for(int i: a){
        mpp[i]++;
    }
    for(auto i : mpp){
        if(i.second>a.size()/3){
            ans.push_back(i.first);
        }
    }
    return ans;
}
vector<int> moores_extended_version(vector<int> &a){
    vector<int> ans;
    int cnt1=0,cnt2=0;
    int ele1,ele2;
    int n = a.size();
    for(int i = 0 ; i<n;i++){
        if(cnt1==0 && a[i]!=ele2){
            ele1=a[i];
        }else if(cnt2==0 && a[i]!=ele1){
            ele2=a[i];
        }
        if(a[i]==ele1){
            cnt1++;
        }else if(a[i]==ele2){
            cnt2++;
        }else{
            cnt1--;
            cnt2--;
        }
    }
    int x=0,y=0;
    for(int i = 0 ; i< n; i++){
        if(a[i]==ele1)x++;
        else if(a[i]==ele2)y++;
    }
    int mini = (n/3)+1;
    if(x>=mini)ans.push_back(ele1);
    if(y>=mini)ans.push_back(ele2);
    return ans;
}
vector<vector<int>> _3sum(vector<int> &a){
    sort(a.begin(),a.end());
    int n = a.size();
    vector<vector<int>> ans;
    for(int i = 0 ; i < n ; i++){
        if(i>0 && a[i]==a[i-1]){
            continue;
        }
        int j = i + 1;
        int k = n-1;
        while(j<k){
            int sum = a[i]+a[j]+a[k];
            if(sum>0){
                k--;
            }else if(sum<0){
                j++;
            }else{
                vector<int> temp={a[i],a[j],a[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && a[j]==a[j-1]){
                    j++;
                }
                while(j<k && a[k]==a[k+1]){
                    k--;
                }
            }
        }
    }
    return ans;
}
vector<vector<int>> _4sum(vector<int> &a,int target){
    sort(a.begin(),a.end());
    int n = a.size();
    vector<vector<int>> ans;
    for(int i = 0 ; i < n ; i++ ){
        if (i > 0 && a[i] == a[i - 1]) continue;
        for(int j = i+1 ; j < n ; j++){
            if(j>i+1 && a[j]==a[j-1])continue;
            int k = j+1;
            int l = n-1;
            while(k<l){
                long long sum = a[i]+a[j];
                sum+=a[k];
                sum+=a[l];
                if(sum>target){
                    l--;
                }else if(sum<target){
                    k++;
                }else{
                    vector<int> temp = {a[i],a[j],a[k],a[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l && a[k]==a[k-1])k++;
                    while(k<l && a[l]==a[l+1])l--;
                }
            } 
        }
    }
    return ans;
}
int longest_subarrays_with_sum_0(vector<int> &a){
    unordered_map<int,int> mpp;
    int n = a.size();
    int maxi = 0 ;
    int sum = 0 ;
    for(int i = 0 ; i < n ; i++){
        sum+=a[i];
        if(sum==0){
            maxi=i+1;
        }else{
            if(mpp.find(sum)!=mpp.end()){
                maxi=max(maxi,i-mpp[sum]);
            }else{
                mpp[sum]=i;
            }
        }
    }
    return maxi;
}
int no_of_subarrays_xor_k(vector<int> &a, int k ){
    int n = a.size();
    unordered_map <int,int> mpp;
    int sum_xor=0;
    mpp[0]=1;
    int cnt= 0 ; 
    for(int i = 0 ; i< n ;i++){
        sum_xor^=a[i];
        if(mpp.find(sum_xor^k)!=mpp.end()){
            cnt+=mpp[sum_xor^k];
        }
        mpp[sum_xor]++;
    }
    return cnt;
}
vector<vector<int>> merge_overlapping_intervals(vector<vector<int>> &a){
    vector<vector<int>> ans;
    int n = a.size();
    sort(a.begin(),a.end());
    for(int i = 0 ; i < n ; i++){
        if(ans.empty() || a[i][0]>ans.back()[1]){
            ans.push_back(a[i]);
        }else{
            ans.back()[1]=max(ans.back()[1],a[i][1]);
        }
    }
    return ans;
}
void merge_sorted_arrays(vector<int> &a , vector<int> &b){
    int lp = a.size()-1;
    int rp = 0;
    while(lp>=0 && rp <b.size()){
        if(a[lp]>b[rp]){
            swap(a[lp--],b[rp++]);
        }else{
            break;
        }
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
}
void missing_reapting_nos(vector<int> &a){
    int n = a.size();
    int sum = 0 ;
    int img_sum = (n*(n+1)) / 2 ;
    int sum2 = 0 ;
    int img_sum2 = (n*(n+1)*(2*n+1)) / 6 ;
    for(int i : a){
        sum+=i;
        sum2+=i*i;
    }
    int val1 = sum-img_sum; // x-y
    int val2 = sum2-img_sum2; // x2-y2
    int val3 = val2/val1; // x+y
    int x = (val1+val3)/2;
    int y = val3-x;
    cout<<"Repeating Number : "<< x;
    cout<<"\n";
    cout<<"Missing Number : "<< y;
}
int maximum_product_subarray(vector<int> &a){
    int maxi= INT16_MIN;
    int prefix = 1 , suffix = 1;
    int n = a.size();
    for(int i = 0 ; i<n;i++){
        if(prefix==0)prefix=1;
        if(suffix==0)suffix=1;
        prefix*=a[i];
        suffix*=a[n-i-1];
        maxi = max(maxi,max(prefix,suffix));
    }
    return maxi;
}
int main(){
    vector<int> a = {4,3,6,2,-1,2};
    cout<<maximum_product_subarray(a);
    return 0;
}