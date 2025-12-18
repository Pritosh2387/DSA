#include<bits/stdc++.h>
using namespace std;
int assign_cookies(vector<int>&g,vector<int>&s){
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int lp= 0,rp=0;
    while(lp<s.size() && rp<g.size()){
        if(s[lp]>=g[rp]){
            rp++;
        }
        lp++;
    }
    return rp;
}
bool lemonade(vector<int>&a){
    int five = 0;
    int ten = 0;
    for(int i = 0; i < a.size() ; i++){
        if(a[i]==5){
            five++;
        }else if(a[i]==10){
            if(five){
                five--;
                ten++;
            }else{
                return false;
            }
        }else{
            if(five && ten){
                five--;
                ten--;
            }else if(five>=3){
                five-=3;
            }else{
                return false;
            }
        }
    }
    return true;
}
int SJF(vector<int>&a){
    int n = a.size();
    int wt=0;
    int t=0;
    sort(a.begin(),a.end());
    for(int i = 0 ; i < n ; i++){
        wt+=t;
        t+=a[i];
    }
    return wt/n;
}
bool jump_game(vector<int>&a){
    int n = a.size();
    int maxd=0;
    for(int i = 0 ; i< n ; i++){
        if(i>maxd){
            return false;
        }
        maxd=max(maxd,i+a[i]);
    }
    return true;
}
int jump_gameII(vector<int>&a){
    int n = a.size();
    int lp=0,rp=0;
    int jumps=0;
    while(rp<n-1){
        int farthest=0;
        for(int i = lp ; i <= rp ; i++){
            farthest=max(farthest,a[i]+i);
        }
        jumps++;
        lp=rp+1;
        rp=farthest;
    }
    return jumps;
}
vector<vector<int>> insert_interval(vector<vector<int>>&a,vector<int>new_int){
    vector<vector<int>> ans;
        int n = a.size();
        int i = 0;
        while (i < n && a[i][1] < new_int[0]) {
            ans.push_back(a[i]);
            i++;
        }
        while (i < n && a[i][0] <= new_int[1]) {
            new_int[0] = min(new_int[0], a[i][0]);
            new_int[1] = max(new_int[1], a[i][1]);
            i++;
        }
        ans.push_back(new_int);
        while (i < n) {
            ans.push_back(a[i]);
            i++;
        }
        return ans;
}
class item{
public:
    int data;
    int wgt;
};
bool comp(item i1, item i2){
    if(((double)i1.data/i1.wgt)>(double)i2.data/i2.wgt){
        return true;
    }else{
        return false;
    }
}
double fractional_knapsack(vector<item>&a , int w){
    double ans=0;
    int wt=w;
    sort(a.begin(),a.end(),comp);
    int n = a.size();
    for(int i = 0 ; i < n ; i++){
        if(a[i].wgt<=wt){
            ans+=a[i].data;
            wt-=a[i].wgt;
        }else{
            ans+=(double(a[i].data)/a[i].wgt)*wt;
            break;
        }
    }
    return ans;
}
vector<int> no_of_coins(int val){
    vector<int> ans;
    vector<int> deno = {1,2,5,10,20,50,100,500,1000};
    int n = deno.size();
    for(int i = n-1 ; i>=0 ; i++){
        while(val>=deno[i]){
            ans.push_back(deno[i]);
            val-=deno[i];
        }
    }    
    return ans;
} 
bool valid_parenthesis(string str){
    int mini= 0;
    int maxi= 0;
    for(int i = 0 ; i < str.length() ; i++){
        if(str[i]=='('){
            mini++;
            maxi++;
        }else if(str[i]==')'){
            mini--;
            maxi--;
        }else{
            mini--;
            maxi++;
        }
        if(maxi<0){
            return false;
        }
        if(mini<0){
            mini=0;
        }
    }
    if(mini==0){
        return true;
    }
}
class data{
public:
    int strt;
    int end;
    int pos;
};
bool comp_N(data d1,data d2){
    if(d1.end<d2.end){
        return true;
    }else{
        return false;
    }
}
int N_meeting_in_a_room(vector<int> &st,vector<int>&en){
    int n = st.size();
    vector<data> data_N(n);
    for(int i = 0 ; i < n ; i++){
        data_N[i].strt=st[i];
        data_N[i].end=en[i];
        data_N[i].pos=i;
    }
    sort(data_N.begin(),data_N.end(),comp_N);
    queue<data> qe;
    int freetime=data_N[0].end;
    int count=1;
    qe.push(data_N[0]);
    for(int i = 1 ; i < n ; i++){
        if(data_N[i].strt>freetime){
            qe.push(data_N[i]);
            freetime=data_N[i].end;
            count++;
        }
    }
    return count;
}
int min_platforms(vector<int>&a,vector<int>&d){
    sort(a.begin(),a.end());
    int ans=0;
    int cnt=0;
    sort(d.begin(),d.end());
    int i=0,j=0;
    while(i<a.size() && j<d.size()){
        if(a[i]<=d[j]){
            cnt++;
            i++;
        }else{
            cnt--;
            j++;
        }
        ans=max(ans,cnt);
    }
    return ans;
}
class jobs{
public:
    int id;
    int deadline;
    int profit;
};
bool comp_profit(jobs j1 , jobs j2){
    if(j1.profit>j2.profit){
        return true;
    }else{
        return false;
    }
}
pair <int,int> max_profit(vector<jobs>&a){
    sort(a.begin(),a.end(),comp_profit);
    pair<int,int> ans;
    int profit = 0;
    int cnt=0;
    int max_deadline=0;
    for(int i = 0 ; i < a.size() ; i++){
        max_deadline=max(max_deadline,a[i].deadline);
    }
    vector<int> hash(max_deadline+1,-1);
    for(int i = 0 ; i < a.size() ; i++){
        for(int j = a[i].deadline ; j >= 1 ; j++){
            if(hash[j]==-1){
                hash[j]=a[i].id;
                cnt++;
                profit+=a[i].profit;
                break;
            }
        }
    }
    ans={profit,cnt};
    return ans;
}
bool comp_inter(vector<int> &a,vector<int>&b){
    if(a[1]<b[1]){
        return true;
    }else{
        return false;
    }
}
int eraseOverlapIntervals(vector<vector<int>>&a){
    sort(a.begin(),a.end(),comp_inter);
    int n = a.size();
    int cnt=1;
    int last_int=a[0][1];
    for(int i = 1 ; i < n ; i++){
        if(a[i][0]>=last_int){
            cnt++;
            last_int=a[i][1];
        }
    }
    return n - cnt;
}
vector<vector<int>> merge_intervals(vector<vector<int>>&a){
    vector<vector<int>> ans;
    sort(a.begin(),a.end());
    vector<int> merge=a[0];
    for(int i = 1 ; i < a.size() ; i++){
        if(a[i][0]<=merge[1]){
            merge[1]=max(merge[1],a[i][1]);
        }else{
            ans.push_back(merge);
            merge=a[i];
        }
    }
    ans.push_back(merge);
    return ans;
}
int sum_candy(vector<int>&a){
    int sum = 1;
    int up = 0;
    int down = 0;
    int peak=0;
    for(int i = 1 ; i < a.size() ; i++){
        if(a[i]==a[i-1]){
            sum++;
            up=down=peak=0;
        }
        else if(a[i]>a[i-1]){
            up++;
            down=0;
            peak=up;
            sum+=1+up;
        }else{
            down++;
            up=0;
            sum+=down;
            if(down>peak){
                sum+=1;
            }
        }
    }
    return sum;
}
int main(){
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    cout << N_meeting_in_a_room(start, end);
    return 0 ; 
}