#include<bits/stdc++.h>
using namespace std;
vector<int> two_sum(vector<int> &a,int target){
    int n = a.size();
    vector<int> ans ;
    unordered_map<int,int> mpp;
    for(int i = 0 ; i < n ; i++){
        if(mpp.find(target-a[i])!=mpp.end()){
            ans.push_back(i);
            ans.push_back(mpp[target-a[i]]);
            return ans;
        }
        mpp[a[i]]=i;
    }
}
void dutch_national_flag_algo(vector<int> &a){
    int n = a.size();
    int low = 0;
    int mid = 0;
    int high = n-1;
    while(mid<=high){
        if(a[mid]==0){
            swap(a[low],a[mid]);
            low++;
            mid++;
        }else if(a[mid]==1){
            mid++;
        }else{
            swap(a[high],a[mid]);
            high--;
        }
    }
}
int moores_voting_algo(vector<int> &a){
    int n = a.size();
    int curr_ele;
    int count = 0 ; 
    for(int i = 0 ; i < n ; i++){
        if(count==0){
            curr_ele=a[i];
        }
        if(a[i]==curr_ele){
            count++;
        }else{
            count--;
        }
    }
    int actual_count = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == curr_ele){
            actual_count++;
        }    
    }
    if(actual_count > n/2){
        return curr_ele;
    }
    else{
        return -1;
    }
}
void kadane(vector<int> &a){
    int n = a.size();
    int maxsum = INT32_MIN;
    int currsum = 0 , start = 0 ,ans_end = 0 ,ans_strt=0; 
    for(int i = 0 ; i < n ; i++){
        if(currsum==0){
            start=i;
        }
        currsum +=a[i];
        if(currsum>maxsum){
            maxsum=currsum;
            ans_strt=start;
            ans_end = i ;
        }
        if(currsum<0){
            currsum=0;
        }
    }
    cout<<maxsum<<"\n";
    for(int i = ans_strt ; i <=ans_end ; i++){
         cout<<a[i]<<"  ";
    }
}
void buy_sell_stock(vector<int> &a){
    int max_profit = INT16_MIN;
    int n = a.size();
    int curr_profit = 0;
    int best_buy = a[0];
    for(int i = 1 ; i < n ; i++){
        curr_profit=a[i]-best_buy;
        max_profit=max(max_profit,curr_profit);
        best_buy=min(best_buy,a[i]);
    }
    cout<<max_profit;
}
void rearrange_by_sign(vector<int> &a){
    vector<int> pos;
    vector<int> neg;
    int n = a.size();
    for(int i = 0 ; i < n ; i++){
        if(a[i]<0){
            neg.push_back(a[i]);
        }else{
            pos.push_back(a[i]);
        }
    }
    if(pos.size()>neg.size()){
        for( int i = 0 ; i < neg.size(); i++){
            a[2*i]=pos[i];
            a[2*i+1]=neg[i];
        }
        int index = neg.size()*2;
        for( int i = neg.size()  ; i < pos.size() ; i++){
            a[index++]=pos[i];
        }
    }else{
        for( int i = 0 ; i < pos.size(); i++){
            a[2*i]=pos[i];
            a[2*i+1]=neg[i];
        }
        int index = pos.size()*2;
        for( int i = pos.size()  ; i < neg.size() ; i++){
            a[index++]=neg[i];
        }
    }
}  
void nextpermutation(vector<int> &a){
    int n = a.size();
    int breakpoint=-1;
    for(int i = n-1 ; i > 0 ; i-- ){
        if(a[i-1]<a[i]){
            breakpoint=i-1;
            break;
        }
    }
    if(breakpoint == -1){
    reverse(a.begin(), a.end());
    return;
}
    for(int i = n-1 ; i>=0 ; i--){
        if(a[i]>a[breakpoint]){
            swap(a[breakpoint],a[i]);
            break;
        }
    }
   reverse(a.begin()+breakpoint+1,a.end());
}
vector<int> leaders_in_an_array(vector<int> &a){
    vector<int> ans;
    int n = a.size();
    int maxi = INT16_MIN;
    for(int i = n-1 ; i >= 0 ; i--){
        if(a[i]>maxi){
            ans.push_back(a[i]);
        }
        maxi=max(maxi,a[i]);
    }
    return ans;
}
int longest_consecutive_sequence(vector<int> &a){
    unordered_set<int> ans;
    if(a.size()==0)return 0;
    for(int i = 0 ; i < a.size() ; i++){
        ans.insert(a[i]);
    }
    int longest = 1;
    for(auto i : ans){
        int count = 1 ;
        int x = i;
        if(ans.find(x-1)==ans.end()){
            while(ans.find(x+1)!=ans.end()){
                x++;
                count++;
            }
            longest=max(longest,count);
        }
    }
    return longest;
} 
void set_matrix_zeros(vector<vector<int>> &a){
    int col1=1;
    for(int i = 0 ; i < a.size() ; i++){
        for(int j = 0 ; j < a[0].size() ; j++){
            if(a[i][j]==0){
                if(j!=0){
                    a[0][j]=0;
                }else{
                    col1=0;
                }
                a[i][0]=0;
            }
        }
    }
    for(int i = 1 ; i < a.size() ; i++){
        for(int j = 1 ; j < a[0].size(); j++){
            if(a[i][j]!=0){
                if(a[i][0] ==0|| a[0][j]==0){
                    a[i][j]=0;
                }
            }
        }
    }
    if(a[0][0]==0){
        for(int j = 0 ; j< a[0].size();j++){
            a[0][j]=0;
        }
    }
    if(col1==0){
        for(int i = 0 ; i < a.size() ; i++){
            a[i][0]=0;
        }
    }
}
void rotate_array_by_90_degrees(vector<vector<int>> &a){
    for(int i = 0 ; i < a.size()-1 ; i++){
        for(int j = i+1 ; j<a[0].size() ; j++){
            swap(a[i][j],a[j][i]);
        }
    }
    for(int i = 0 ; i<a.size() ; i++){
        reverse(a[i].begin(),a[i].end());
    }
}
vector<int> spiral_matrix(vector<vector<int>> &a){
    int top = 0 , left = 0;
    vector<int> ans;
    int right = a[0].size()-1,bottom = a.size()-1;;
    while(top<=bottom && left <= right){
        for(int i = left ; i<=right ; i++){
            ans.push_back(a[top][i]);
        }
        top++;
        for(int i = top ; i<=bottom; i++){
            ans.push_back(a[i][right]);
        }
        if(top<=bottom){
            right--;
            for(int i = right ; i>=left ; i--){
                ans.push_back(a[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for(int i = bottom ; i>=top ; i--){
                ans.push_back(a[i][left]);
            }
            left++;
        }
    }
    return ans;
}
int subarrays_withsum_k(vector<int> &a,int k ){
    unordered_map<int,int> mpp;//sum,count
    mpp[0]=1;
    int sum = 0 ,cnt=0;
    for(int i = 0 ; i<a.size();i++ ){
        sum+=a[i];
        int rem = sum-k;
        cnt+=mpp[rem];
        mpp[sum]++;
    }
    return cnt;
}
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
// 27
int removeElement(vector<int>& nums, int val) {
    int k = 0;  
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
        nums[k++] = nums[i];  
        }
    }
    return k;  
}
int main(){
    vector<int> a = {1,2,3,-3,1,1,1,4,2,-3};   
    cout<<subarrays_withsum_k(a,3);
    return 0 ; 
}