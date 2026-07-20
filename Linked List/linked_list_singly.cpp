#include<bits/stdc++.h>
using namespace std;
class node {
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
node* convert_arr_2LL(vector<int>&a){
    node* head = new node(a[0]);
    node* mover = head;

    for(int i = 1; i < a.size(); i++) {
        node* temp = new node(a[i]);
        mover->next = temp;
        mover = temp; // or mover = mover->next;
    }
    return head;
}
void print_LL(node*head){
    node*temp=head;
    while(temp!=nullptr){
        cout<<temp->data;
        if(temp->next!=nullptr){
            cout<<"->";
        }
        temp=temp->next;
    }
    cout<<"\n";
}
node* Delete_tail(node*head){
    if(head==nullptr)return nullptr;
    else if(head->next==nullptr){
        delete head;
        return nullptr;
    }
    node*temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    return head;
}
node* removes_head(node*head){
    node*temp=head;
    head=head->next;
    delete temp;
    return head;
}
node* remove_kth(node*head,int k){
    if(k==1)return removes_head(head);
    node*temp=head;
    node* prev=nullptr;
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
node* insert_head(node*head,int val){
    node* temp = new node(val,head);
    head=temp;
    return head;
}
node*insert_tail(node* head,int val){
    if(head==nullptr){
        node*temp=new node(val);
        head=temp;
        return head;
    }
    node*mover=head;
    while(mover->next!=nullptr){
        mover=mover->next;
    } 
    node*temp=new node(val);
    mover->next=temp;
    return head; 
}
node* insert_kth(node*head,int val,int k){
    if(head==nullptr){
        if(k==1){
            node*head=new node(val);
            return head;
        }else{
            return nullptr;
        }
    }
    if(k==1)return insert_head(head,val);
    int cnt=0;
    node*temp=head;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k-1){
            node*newnode=new node(val,temp->next);
            temp->next=newnode;
            return head;
        }
        temp=temp->next;
    }
    return head;
}
vector<int> merge_k_sorted_ararys(vector<vector<int>>&a){
    int n = a.size();
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
    for(int i = 0 ; i < n ; i++){
        pq.emplace(a[i][0],make_pair(i,0));
    }
    vector<int> ans;
    while(!pq.empty()){
        auto i = pq.top();
        ans.push_back(i.first);
        pq.pop();
        if(i.second.second+1<a[i.second.first].size()){
            pq.emplace(a[i.second.first][i.second.second+1],make_pair(i.second.first,i.second.second+1));
        }
    }
    return ans;
}
int range_k_sorted_arrays(vector<vector<int>>&a){
    using T = pair<int,pair<int,int>>;
    priority_queue<T,vector<T>,greater<T>> pq;
    int ans=INT_MAX;
    int maxi = INT_MIN;
    for(int i = 0 ;i < a.size() ; i++ ){
        pq.emplace(a[i][0],make_pair(i,0));
        maxi=max(maxi,a[i][0]);
    }
    while(!pq.empty()){
        auto it = pq.top();
        int mini = it.first;
        int row=it.second.first;
        int col = it.second.second;
        pq.pop();
        ans=min(maxi-mini,ans);
        if(col+1<a[row].size()){
            pq.emplace(a[row][col+1],make_pair(row,col+1));
            maxi=max(maxi,a[row][col+1]);
        }else{
            break;
        }
    }
    return ans;
}
int main(){
    vector<int> a = {2,1,3,8,4,5,6};
    node* head = convert_arr_2LL(a);
    print_LL(head);
    head = insert_kth(head,7,1);
    print_LL(head);
    return 0;
}