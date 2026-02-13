#include<bits/stdc++.h>
using namespace std;
int max_pt_from_cards(vector<int>&a,int k){
    int n = a.size();
    int ls = 0;
    for(int i = 0 ; i < k ; i++){
        ls+=a[i];
    }
    int rs = 0;
    int ans = ls;
    for(int i = k-1 ; i >= 0 ; i--){
        ls-=a[i];
        rs+=a[n-i-1];
        ans = max(ans,ls+rs);
    } 
    return ans;
}
int lengthOfLongestSubstring(string s){
    int n=s.length();
    int lp =0,rp=0;
    int ans =0;
    vector<int>hash(256,-1);
    while(rp<n){
        if(hash[s[rp]]!=-1){
            if(hash[s[rp]]>=lp){
                lp = hash[s[rp]] + 1; 
            }
        }
        ans = max(ans,rp-lp+1);
        hash[s[rp]] = rp;
        rp++;
    }
    return ans;
}
int longestOnes(vector<int>&nums,int k){
    int n = nums.size();
    int lp=0,rp =0;
    int zero = 0,ans=0;
    while(rp<n){
        if(nums[rp]==0)zero++;
        if(zero>k){
            if(nums[lp]==0)zero--;
            lp++;
        }
        if(zero<=k){
            ans = max(ans,rp-lp+1);
        }
        rp++;
    }
    return ans;
}
int characterReplacement(string s,int k){
    int n = s.length();
    int ans=0,lp=0,rp=0;
    vector<int>hash(26,0);
    int maxf=0;
    while(rp<n){
        hash[s[rp]-'A']++;
        maxf=max(maxf,hash[s[rp]-'A']);
        if((rp-lp+1)-maxf>k){
            hash[s[lp] - 'A']--;
            lp++;
        } 
        ans = max(ans,rp-lp+1);
        rp++;
    }
    return ans;
}
int numSubarraysithSum(vector<int>&nums,int goal){
    if(goal<0)return 0;
    int n = nums.size();
    int lp=0,rp=0;
    long long tsum = 0,currsum=0;
    while(rp<n){
        currsum+=nums[rp];
        while(currsum>goal){
            currsum-=nums[lp];
            lp++;
        }
        tsum+=rp-lp+1;
        rp++;
    }
    return (int)tsum;
}
int numberOfSubstrings(string s){
    int n = s.length();
    vector<int>hash(3,-1);
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        hash[s[i]-'a'] = i;
        ans = ans + 1 + min(min(hash[0],hash[1]),hash[2]);
    }
    return ans;
}
vector<int> constructTransformedArray(vector<int>&nums){
    int n = nums.size();
    vector<int>ans;
    for(int i = 0; i < n; i++){
        int pos = ((i + nums[i]) % n + n) % n;
        ans[i] = nums[pos];
    }
    return ans;
}
int minRemoval(vector<int>&nums,int k){
    int n = nums.size();
    sort(nums.begin(),nums.end());
    int lp = 0;
    int ans = 0;
    for(int rp = 0; rp < n; rp++){
        while(1LL*nums[lp]*k<1LL*nums[rp]){
            lp++;
        }
        ans = max(ans,rp-lp+1);
    }
    return n - ans;
}
int minimumDeletions(string s){
    int n = s.length();
    int b_store = 0,ans = 0;
    for(int i = 0 ; i < n ; i++){
        if(s[i]=='b'){
            b_store++;
        }else{
            ans = min(ans+1,b_store);
        }
    }
    return ans;
}
int lengthOfLongestSubstringKDistinct(string s, int k){
    if (k == 0 || s.empty()) return 0;
    unordered_map<char, int> freq;
    int left = 0;
    int maxLen = 0;
    for(int right = 0; right < s.length(); right++){
        freq[s[right]]++;
        while(freq.size() > k){
            freq[s[left]]--;
            if(freq[s[left]] == 0){
                freq.erase(s[left]);
            }
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
int subarraysWithK_less_Distinct(vector<int>& nums, int k){
    int n = nums.size();
    int lp=0,rp=0;
    int cnt =0;
    unordered_map<int,int>mpp;
    while(rp<n){
        mpp[nums[rp]]++;
        while(mpp.size()>k){
            mpp[nums[lp]]--;
            if(mpp[nums[lp]]==0){
                mpp.erase(nums[lp]);
            }
            lp++;
        }
        cnt+=(rp-lp+1);
        rp++;
    }
    return cnt;
}
string minWindow(string s, string t){
    int n = s.length(),m = t.length();
    vector<int>hash(256);
    int minlen=INT_MAX;
    int cnt=0;
    int strt=-1;
    for(int i = 0 ; i <  m; i++){
        hash[t[i]]++;
    }       
    int lp = 0,rp=0;
    while(rp<n){
        if(hash[s[rp]]>0){
            cnt++;
        }
        hash[s[rp]]--;
        while(cnt==m){
            if(rp-lp+1<minlen){
                minlen = rp-lp+1;
                strt = lp;
            }
            hash[s[lp]]++;
            if(hash[s[lp]]>0){
                cnt--;
            } 
            lp++;
        }
        rp++;
    }
    return strt==-1?"":s.substr(strt,minlen);
}
int longestBalanced(vector<int>&nums){
    int n = nums.size();
    unordered_set<int>even,odd;
    unordered_map<int,int>mpp;
    int balance=0,ans=0; 
    mpp[0] = -1;
    for(int i = 0 ; i < n ; i++){
        int x = nums[i];
        if(x%2==0){
            if(!even.count(x)){
                even.insert(x);
                balance++;
            }
        }else{
            if(!odd.count(x)){
                odd.insert(x);
                balance--;
            }
        }
        if(mpp.count(balance)){
            ans = max(ans,i-mpp[balance]);
        }else{
            mpp[balance]=i;
        }
    }        
    return ans;
}
int main(){
    cout << -4%2;
    return 0;
}