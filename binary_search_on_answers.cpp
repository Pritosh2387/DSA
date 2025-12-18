#include<bits/stdc++.h>
using namespace std;
int squa_rt(int n){
    int lp=1,rp=n;
    while(lp<=rp){
        int mid=lp+(rp-lp)/2;
        if(mid*mid<=n){
            lp=mid+1;
        }else{
            rp=mid-1;
        }
    }
    return rp;
}
int root_or_not(int mid, int n , int m){
    long long ans = 1; 
    for(int i = 0 ; i < n; i++){
        ans *= mid;
        if(ans > m){
            return 2;  // Too big
        }
    }
    if(ans == m){
        return 1;  // Exact root
    }
    return 0;  // Too small
}
int n_th_root_of_m(int n , int m ){
    int lp = 1, rp = m;
    while(lp <= rp){
        int mid = lp + (rp - lp) / 2;
        int state = root_or_not(mid, n, m);
        
        if(state == 1){
            return mid;
        }else if(state == 2){
            rp = mid - 1;
        }else{
            lp = mid + 1;
        }
    }
    return -1;  // No integer root
}
long long count_total_hours(vector<int>& a, int mid) {
        long long total_hrs = 0;
        for (int i = 0; i < a.size(); i++) {
            total_hrs += ceil(a[i] / double(mid));
        }
        return total_hrs;
    }
int minEatingSpeed(vector<int>& piles, int h){
    int lp = 1;
    int rp = *max_element(piles.begin(), piles.end());
    while (lp <= rp){
        int mid = lp + (rp - lp) / 2;
        if(count_total_hours(piles, mid) <= double(h)){
            rp = mid - 1;
        }else{
            lp = mid + 1;
        }
    }
    return lp;
}
bool possible_days_or_not(vector<int>&a,int m,int k,int mid){
    int no_of_bouquets_possible=0,count=0;
    for(int i = 0 ; i<a.size();i++){
        if(a[i]<=mid){
            count++;
        }else{
            no_of_bouquets_possible+=count/k;
            count=0;
        }
    }
    no_of_bouquets_possible+=count/k;
    if(no_of_bouquets_possible>=m){
        return true;
    }else{
        return false;
    }
}
int min_days_to_form_m_bouquets(vector<int> &a ,int m , int k){
    if (1LL * m * k > a.size())return -1;
    int lp= *min_element(a.begin(),a.end());
    int rp = *max_element(a.begin(),a.end());
    while(lp<=rp){
        int mid = lp+(rp-lp)/2;
        if(possible_days_or_not(a,m,k,mid)){
            rp=mid-1;
        }else{
            lp=mid+1;
        }
    }
    return lp;
}
long long sum_of_div(vector<int> &a,int mid){
    long long  sum=0;
    for(int i = 0 ; i<a.size();i++){
        sum+= ceil(a[i]/double(mid));
    }
    return sum;
}
int smallest_divisor(vector<int>&a,int threshold){
    int lp = 1;
    int rp = *max_element(a.begin(),a.end());
    while(lp<=rp){
        int mid=lp+(rp-lp)/2;
        if(sum_of_div(a,mid)<=threshold){
            rp=mid-1;
        }else{
            lp=mid+1;
        }
    }
    return lp;
}
int count_no_of_days(vector<int>&a,int mid){
    int days=1;
    long long sum = 0 ; 
    for(int i = 0 ; i<a.size();i++){
        if(sum+a[i]<=mid){
            sum+=a[i];
        }else{
            sum=a[i];
            days++;
        }
    }
    return days;
}
int min_capacity_ship(vector<int> &a,int days){
    int lp = *max_element(a.begin(),a.end());
    int rp =accumulate(a.begin(),a.end(),0);
    while(lp<=rp){
        int mid=lp+(rp-lp)/2;
        if(count_no_of_days(a,mid)<=days){
            rp=mid-1;
        }else{
            lp=mid+1;
        }
    }
    return lp;
}
int findKthPositive(vector<int>& a, int k){
    int lp = 0,rp=a.size()-1;
    while(lp<=rp){
        int mid = lp+(rp-lp)/2;
        if(a[mid]-(mid+1)<k){
            lp=mid+1;
        }else{
            rp=mid-1;
        }
    }
    return lp+k; // or rp +1 +k 
}
bool can_we_place_cows(vector<int>&a,int mid,int No_of_cows){
    int cows=1,last_placed=a[0];
    for(int i= 1 ; i<a.size();i++){
        if(a[i]-last_placed>=mid){
            cows++;
            last_placed=a[i];
        }
        if(cows>=No_of_cows){
            return true;
        }
    }
    return false;
}
int aggress_cow_prob(vector<int> &a,int no_of_cows){
    sort(a.begin(),a.end());
    int lp = 1,rp=(*max_element(a.begin(),a.end())-*min_element(a.begin(),a.end()));
    while(lp<=rp){
        int mid=lp+(rp-lp)/2;
        if(can_we_place_cows(a,mid,no_of_cows)){
            lp=mid+1;
        }else{
            rp=mid-1;
        }
    }
    return rp;
}
bool is_possible(vector<int>&a,int students,long long mid){
    int std_cnt=1;
    long long pages_to_be_given=a[0];
    for(int i = 1 ;i<a.size();i++){
        if(pages_to_be_given+a[i]>mid){
            std_cnt++;
            pages_to_be_given=a[i];
        }else{
            pages_to_be_given+=a[i];
        }
        if(std_cnt>students){
            return false;
        }
    }
    return true;
}
long long book_allocation(vector<int> &a,int students){
    if(students>a.size())return -1;
    long long lp=*max_element(a.begin(),a.end());
    long long  rp = accumulate(a.begin(),a.end(),0LL);
    while(lp<=rp){
        long long mid = lp+(rp-lp)/2;
        if(is_possible(a,students,mid)){
            rp=mid-1;
        }else{
            lp=mid+1;
        }
    }
    return lp;
}
bool answer_possible(vector<int>&a,int k,int mid){
    int cnt=1;
    int sum=a[0];
    for(int i = 1 ; i<a.size();i++){
        if(sum+a[i]>mid){
            cnt++;
            sum=a[i];
        }else{
            sum+=a[i];
        }
        if(cnt>k){
            return false;
        }
    }
    return true;
}
int split_array_largest_sum(vector<int>&a,int k){
    int lp = *max_element(a.begin(),a.end());
    int rp = accumulate(a.begin(),a.end(),0);
    while(lp<=rp){
        int mid=lp+(rp-lp)/2;
        if(answer_possible(a,k,mid)){
            rp=mid-1;
        }else{
            lp=mid+1;
        }
    }
    return lp;
}
long double  minimise_max_distance_between_gas_stations(vector<int>&a,int k){
    int n = a.size();
    priority_queue<pair<long double,int>> pq;
    vector<int> how_many(n-1,0);
    for(int i =0;i<n-1;i++){
        pq.emplace(a[i+1]-a[i],i);
    }
    for(int i = 1;i<=k;i++){
        auto x = pq.top();
        pq.pop();
        int count = x.second;
        how_many[count]++;
        long double int_diff =a[count+1]-a[count];
        long double new_length=int_diff/double(how_many[count]+1);
        pq.emplace(new_length,count); 
    }
    return pq.top().first;
}
double findMedianSortedArrays(vector<int>& a, vector<int>& b){
    int n1=a.size(),n2=b.size();
    if(n1>n2){
        return findMedianSortedArrays(b,a);
    }
    int lp =0,rp=n1;
    int left = (n1+n2+1)/2;
    while(lp<=rp){
        int l1=INT_MIN,l2=INT_MIN, r1=INT_MAX,r2=INT_MAX;
        int mid1=lp+(rp-lp)/2;
        int mid2=left-mid1;;
        if(mid1<n1)r1=a[mid1];
        if(mid2<n2)r2=b[mid2];
        if((mid1-1)>=0)l1=a[mid1-1];
        if((mid2-1)>=0)l2=b[mid2-1];
        if(l1<=r2 && l2<=r1){
            if((n1+n2)%2==1)return double(max(l1,l2));
            else return (max(l1,l2)+min(r1,r2))/double(2);
        }else if(l1>r2){
            rp=mid1-1;
        }else{
            lp=mid1+1;
        }
    }
    return 0.0;
}
bool search_2d_Matrix(vector<vector<int>>& a, int target){
    int n=a.size(),m=a[0].size();
    int lp=0,rp=n*m-1;
    while(lp<=rp){
        int mid=lp+(rp-lp)/2;
        int row = mid/m,col=mid%m;
        if(a[row][col]==target){
            return true;
        }else if(a[row][col]<target){
            lp=mid+1;
        }else{
            rp=mid-1;
        }
    }
    return false;
}
bool search_2dMatrix_part_2(vector<vector<int>>& matrix, int target){
    int row=0,col=matrix[0].size()-1;
    while(row<matrix.size() && col>=0){
        if(matrix[row][col]==target){
            return true;
        }else if(matrix[row][col]>target){
            col--;
        }else{
            row++;
        }
    }
    return false;
}
vector<int> peak_element_2d(vector<vector<int>>&a){
    int n = a.size(),m=a[0].size();
    int lp=0,rp=n-1;
    while(lp<=rp){
        int mid=lp+(rp-lp)/2;
        int max_index=max_element(a[mid].begin(),a[mid].end())-a[mid].begin();
        int max=a[mid][max_index];
        int up;
        if(mid-1>=0){
            up = a[mid-1][max_index]; 
        }else{
            up=-1;
        }
        int down;
        if(mid+1<=n-1){
            down = a[mid+1][max_index]; 
        }else{
            down=-1;
        }
        if(a[mid][max_index]>up && a[mid][max_index]>down){
            return {mid,max_index};
        }else if(a[mid][max_index]<up){
            rp=mid-1;
        }else{
            lp=mid+1;
        }
    }
    return {-1,-1};
}
int blackbox(vector<vector<int>>&a,int mid){
    int n=a.size(),m=a[0].size();
    int cnt=0;
    for(int i = 0 ; i < n ; i++){
        cnt+=upper_bound(a[i].begin(),a[i].end(),mid)-a[i].begin();
    }
    return cnt;
}
int median_of_2d_matrix(vector<vector<int>>&a){
    int n = a.size(),m=a[0].size();
    int lp=INT_MAX,rp=INT_MIN;
    for(int i = 0 ; i < n ; i++ ){
        lp=min(lp,a[i][0]);
        rp=max(rp,a[i][m-1]);
    }
    int rew_small=(n*m)/2;
    while(lp<=rp){
        int mid=lp+(rp-lp)/2;
        int smaller_than_mid=blackbox(a,mid);
        if(smaller_than_mid>rew_small){
            rp=mid-1;
        }else{
            lp=mid+1;
        }
    }
    return lp;
}
int main(){
    vector<vector<int>> a = {{3,4,7},{13,16,18},{20,21,23}};
    cout<<median_of_2d_matrix(a);
    return 0;
}