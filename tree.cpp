#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node*left;
    node*right;
    node(int data): data(data),left(nullptr),right(nullptr){}
    node(int data,node*left):data(data),left(left),right(nullptr){}
};
node* createTree() {
    node* n4 = new node(4);
    node* n5 = new node(5);
    node* n6 = new node(6);
    node* n7 = new node(7);
    node* n2 = new node(2);
    n2->left = n4;
    n2->right = n5;
    node* n3 = new node(3);
    n3->left = n6;
    n3->right = n7;
    node* root = new node(1);
    root->left = n2;
    root->right = n3;
    return root;
}
void inorder(node*root){
    if(root==nullptr)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right); 
}
vector<int> ioit(node*root){
    vector<int> ans;
    stack<node*>st;
    node* curr = root;
    while(curr!=nullptr || !st.empty()){
        // Extreme left
        while(curr!=nullptr){
            st.push(curr);
            curr=curr->left;
        }
        // process node 
        curr = st.top();
        st.pop();
        ans.push_back(curr->data);
        // go to right
        curr=curr->right;
    }
    return ans;
}
void preorder(node*root){
    if(root==nullptr)return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right); 
}
vector<int> poit(node*root){
    stack<node*> st;
    vector<int> ans;
    if(root==nullptr)return ans;
    st.push(root);
    while(!st.empty()){
        node* NODE = st.top();
        st.pop();
        ans.push_back(NODE->data);
        if(NODE->right!=nullptr){
            st.push(NODE->right);
        }
        if(NODE->left!=nullptr){
            st.push(NODE->left);
        }
    }
    return ans;
}
void postorder(node*root){
    if(root==nullptr)return;
    postorder(root->left);
    postorder(root->right); 
    cout<<root->data<<" ";
}
vector<int> postorderTraversal(node* root) {
    vector<int> ans;
    if (root == nullptr) return ans;
    stack<node*> s1, s2;
    s1.push(root); 
    while (!s1.empty()) {
        node* curr = s1.top();
        s1.pop();
        s2.push(curr);
        if (curr->left != nullptr)
            s1.push(curr->left);
        if (curr->right != nullptr)
            s1.push(curr->right);
    }
    while (!s2.empty()) {
        ans.push_back(s2.top()->data);
        s2.pop();
    }
    return ans;
}
vector<int> s1poit(node*root){
    stack<node*> st;
    vector<int> ans;
    node* curr = root;
    while (!st.empty() || curr!=nullptr){
        if(curr!=nullptr){
            st.push(curr);
            curr=curr->left;
        }else{
            node*temp=st.top()->right;
            if(temp==nullptr){
                temp=st.top();
                st.pop();
                ans.push_back(temp->data);
                while(!st.empty() && temp==st.top()->right){
                    temp=st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }else{
                curr=temp;
            }
        }
    }
    return ans;
}
vector<vector<int>> BFS_traversal(node*root){
    vector<vector<int>> ans;
    queue<node*> qe;
    if(root==nullptr)return ans;
    qe.push(root);
    while(!qe.empty()){
        int n = qe.size();
        vector<int> level;
        for(int i = 0 ; i < n ; i++){
            node* NODE = qe.front();
            level.push_back(NODE->data);
            qe.pop();
            if(NODE->left!=nullptr)qe.push(NODE->left);
            if(NODE->right!=nullptr)qe.push(NODE->right);
        }
        ans.push_back(level);
    }
    return ans;
}
int maxdepth(node*root){
    if(root==nullptr)return 0;
    int left = maxdepth(root->left); 
    int right = maxdepth(root->right); 
    return 1 + max(left,right);
}
int maxdepth_for_balanced(node* root){
    if (root == nullptr)
        return 0;
    int left = maxdepth(root->left);
    if (left == -1 ) {
        return -1;
    }
    int right = maxdepth(root->right);
    if (right == -1) {
        return -1;
    }
    if (abs(right - left) > 1) {
        return -1;
    }
    return 1 + max(left, right);
}
bool isBalanced(node* root){
        if (maxdepth_for_balanced(root) == -1)
            return false;
        else
            return true;
    }
int diameter(node* root, int& maxi) {
    if (root == nullptr)
        return 0;
    int left = diameter(root->left, maxi);
    int right = diameter(root->right, maxi);
    maxi = max(maxi, left + right);
    return 1 + max(left, right);
}
int diameterOfBinaryTree(node* root){
    int maxi = 0;
    diameter(root, maxi);
    return maxi;
}
int pathsum(node*root,int &maxi){
    if(root==nullptr)return 0;
    int left = max(0,pathsum(root->left,maxi));
    int right = max(0,pathsum(root->right,maxi));
    maxi=max(maxi,root->data+left+right);
    return root->data+max(left,right);
}
int maxPathSum(node* root){
    int maxi=INT32_MIN;
    pathsum(root,maxi);
    return maxi;
}
bool sametreeornot(node* p ,node* q){
    if(p==nullptr || q==nullptr){
        return(p==q);
    }
    return(p->data==q->data && sametreeornot(p->left,q->left) && sametreeornot(p->right,q->right));
}
vector<vector<int>> zigzag(node*root){
    vector<vector<int>> ans;
    if(root==nullptr){
        return ans;
    }
    queue<node*> qe;
    bool L_R = true;
    qe.push(root);
    while(!qe.empty()){
        int n = qe.size();
        vector<int> level(n);
        for(int i = 0 ; i < n ; i++){
            node*NODE=qe.front();
            int j = (L_R)?i:n-i-1;
            level[j]=NODE->data;
            if(NODE->left!=nullptr){
                qe.push(NODE->left);
            }
            if(NODE->right!=nullptr){
                qe.push(NODE->right);
            }
            qe.pop();
        }
        L_R = !L_R;
        ans.push_back(level);
    }
    return ans;
}
bool is_leaf(node* root){
    if(root->left==nullptr  && root->right==nullptr){
        return true;
    }else{
        return false;
    }
}
void add_left(node*root,vector<int>&ans){
    node*temp=root->left;
    while(temp!=nullptr){
        if(!is_leaf(temp)){
            ans.push_back(temp->data);
        }
        if(temp->left!=nullptr){
            temp=temp->left;
        }else{
            temp=temp->right;
        }
    }
}
void add_right(node*root,vector<int>&ans){
    node*temp=root->right;
    stack<int> st;
    while(temp!=nullptr){
        if(!is_leaf(temp)){
            st.push(temp->data);
        }
        if(temp->right!=nullptr){
            temp=temp->right;
        }else{
            temp=temp->left;
        }
    }
    while (!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
}
void add_leafs(node*root,vector<int>&ans){
    if (root == nullptr) return;
    if(is_leaf(root)){
        ans.push_back(root->data);
        return;
    }
    add_leafs(root->left,ans);
    add_leafs(root->right,ans);
}
vector<int> boundry_traversal(node*root){
    vector<int> ans;
    if(root==nullptr)return ans;
    if(!is_leaf(root)){
        ans.push_back(root->data);
    }
    add_left(root,ans);
    add_leafs(root,ans);
    add_right(root,ans);
    return ans;
}
vector<vector<int>> vertical_order_traversal(node*root){
    map<int,map<int,multiset<int>>> mpp;
    queue<pair<node*,pair<int,int>>> qe;
    qe.emplace(root,make_pair(0,0));
    while (!qe.empty()){
        auto it = qe.front();
        qe.pop();
        node*NODE=it.first;
        int x = it.second.first;
        int y = it.second.second;
        mpp[x][y].insert(NODE->data);
        if(NODE->left!=nullptr){
            qe.emplace(NODE->left,make_pair(x-1,y+1));
        }
        if(NODE->right!=nullptr){
            qe.emplace(NODE->right,make_pair(x+1,y+1));
        }
    }
    vector<vector<int>> ans;
    for(auto it : mpp){
        vector<int> vert;
        for(auto jt : it.second){
            vert.insert(vert.end(),jt.second.begin(),jt.second.end());
        }
        ans.push_back(vert);
    }
    return ans;
}
vector<int> top_view(node*root){
    vector<int> ans;
    if(root==nullptr)return ans;
    queue<pair<node*,int>> qe;
    map<int,int> mpp;
    qe.emplace(root,0);
    while (!qe.empty()){
        auto it = qe.front();
        qe.pop();
        int x = it.second;
        node*NODE = it.first;
        if(mpp.find(x)==mpp.end()){
            mpp[x]=NODE->data;
        }
        if(NODE->left!=nullptr){
            qe.emplace(NODE->left,x-1);
        }
        if(NODE->right!=nullptr){
            qe.emplace(NODE->right,x+1);
        }
    }
    for(auto i : mpp){
        ans.push_back(i.second);
    }
    return ans;
}
vector<int> bottom_view(node*root){
    vector<int> ans;
    if(root==nullptr)return ans;
    queue<pair<node*,int>> qe;
    map<int,int> mpp;
    qe.emplace(root,0);
    while (!qe.empty()){
        auto it = qe.front();
        qe.pop();
        int x = it.second;
        node*NODE = it.first;
        mpp[x]=NODE->data;        
        if(NODE->left!=nullptr){
            qe.emplace(NODE->left,x-1);
        }
        if(NODE->right!=nullptr){
            qe.emplace(NODE->right,x+1);
        }
    }
    for(auto i : mpp){
        ans.push_back(i.second);
    }
    return ans;
}
vector<int> right_view(node*root){
    vector<int> ans;
    if(root==nullptr)return ans;
    queue<pair<node*,int>> qe;
    qe.emplace(root,0);
    map<int,int> mpp;
    while (!qe.empty()){
        auto it = qe.front();
        qe.pop();
        node*NODE=it.first;
        int y = it.second;
        if(mpp.find(y)==mpp.end()){
            mpp[y]=NODE->data;
        }
        if(NODE->right!=nullptr){
            qe.emplace(NODE->right,y+1);
        }
        if(NODE->left!=nullptr){
            qe.emplace(NODE->left,y+1);
        }
    }
    for(auto it : mpp){
        ans.push_back(it.second);
    }
    return ans;
}
void right_view_opt(node*root,vector<int>&ans,int i){
    if(root==nullptr){
        return;
    }
    if(ans.size()==i){
        ans.push_back(root->data);
    }
    right_view_opt(root->right,ans,i+1);
    right_view_opt(root->left,ans,i+1);
}
bool symmertichelp(node*left,node*right){
    if(left==nullptr || right==nullptr){
        return left==right;
    }
    if(left->data!=right->data){
        return false;
    }  
    return (symmertichelp(left->left,right->right) && symmertichelp(left->right,right->left));
}
bool symmtric(node*root){
    return(root == nullptr || symmertichelp(root->left,root->right));
}
bool node2leafhelp(node*root,vector<int>&ans,int a){
    if(root==nullptr)return false;
    ans.push_back(root->data);
    if(root->data==a)return true;
    if(node2leafhelp(root->left,ans,a) || node2leafhelp(root->right,ans,a)){
        return true;
    }
    ans.pop_back();
    return false;
}
vector<int> node2leaf(node*root,int a){
    vector<int> ans;
    if(root==nullptr)return ans;
    node2leafhelp(root,ans,a);
    return ans;
}
node* lca(node*root,node*p,node*q){
    if(root==nullptr || root==p || root==q){
        return root;
    }
    node*left=lca(root->left,p,q);
    node*right=lca(root->right,p,q);
    if(right==nullptr){
        return left;
    }else if(left==nullptr){
        return right;
    }else{
        return root;
    }
}
int max_width(node*root){
    int ans=0;
    if(root==nullptr)return ans; 
    queue<pair<node*,int>> qe;
    qe.emplace(root,0);
    while (!qe.empty()){
        int strt,end;
        int mmin=qe.front().second;
        int n = qe.size();
        for(int i = 0 ; i < n ; i++){
            node*NODE=qe.front().first;
            int curr = qe.front().second-mmin;
            qe.pop();
            if(i==0)strt=curr;
            if(i==n-1)end=curr;
            if(NODE->left!=nullptr){
                qe.emplace(NODE->left,2LL*curr+1);
            }
            if(NODE->right!=nullptr){
                qe.emplace(NODE->right,2LL*curr+2);
            }
        }
        ans=max(ans,end-strt+1);
    }
    return ans;
}
void children_sum_prop(node*root){
    if(root==nullptr)return;
    int child = 0;
    if(root->left!=nullptr){
        child+=root->left->data;
    }
    if(root->right!=nullptr){
        child+=root->right->data;
    }
    if(child>=root->data){
        root->data=child;
    }else{
        if(root->left!=nullptr){
            root->left->data=root->data;
        }else if(root->right!=nullptr){
            root->right->data=root->data;
        }
    }
    children_sum_prop(root->left);
    children_sum_prop(root->right);
    int total = 0 ; 
    if(root->left!=nullptr){
        total+=root->left->data;
    }
    if(root->right!=nullptr){
        total+=root->right->data;
    }
    if(root->left!=nullptr || root->right!=nullptr){
        root->data=total;
    }
}
void mark_parents(node*root,unordered_map<node*,node*> &mpp){
    if(root==nullptr){
        return;
    }
    queue<node*> qe;
    qe.push(root);
    while (!qe.empty()){
        node* NODE = qe.front();
        qe.pop();
        if(NODE->left!=nullptr){
            mpp[NODE->left]=NODE;
            qe.push(NODE->left);
        }
        if(NODE->right!=nullptr){
            mpp[NODE->right]=NODE;
            qe.push(NODE->right);
        }
    }
}
vector<int> distance_K(node*root,int k,node*target){
    vector<int> ans;
    unordered_map<node*,node*> parents;
    mark_parents(root,parents);
    unordered_map<node*,bool> visited;
    queue<node*> qe;
    int curr_level=0;
    visited[target]=true;
    qe.push(target);
    while (!qe.empty()){
        int n = qe.size();
        if(curr_level++==k)break;
        for(int i = 0 ; i < n ; i++){
            auto NODE=qe.front();
            qe.pop();
            if(NODE->left!=nullptr && !visited[NODE->left]){
                qe.push(NODE->left);
                visited[NODE->left]=true;
            }
            if(NODE->right!=nullptr && !visited[NODE->right]){
                qe.push(NODE->right);
                visited[NODE->right]=true;
            }
            if(parents.find(NODE)!=parents.end() && !visited[parents[NODE]]){
                qe.push(parents[NODE]);
                visited[parents[NODE]]=true;
            }
        }
    }
    while (!qe.empty()){
        ans.push_back(qe.front()->data);
        qe.pop();
    }
    return ans;
}
int burn(node*root,node*target){
    queue<node*> qe;
    qe.push(target);
    unordered_map<node*,node*> parents;
    unordered_map<node*,bool> visited;
    visited[target]=true;
    mark_parents(root,parents);
    int ans = 0; 
    while (!qe.empty()){
        int flag = 0; 
        int n = qe.size();
        for(int i = 0 ; i < n ; i++){
            node*NODE=qe.front();
            qe.pop();
            if(NODE->left!=nullptr && !visited[NODE->left]){
                flag=1;
                qe.push(NODE->left);
                visited[NODE->left]=true;
            }
            if(NODE->right!=nullptr && !visited[NODE->right]){
                flag=1;
                qe.push(NODE->right);
                visited[NODE->right]=true;
            }
            if(parents.find(NODE)!=parents.end() && !visited[parents[NODE]]){
                flag=1;
                visited[parents[NODE]]=true;
                qe.push(parents[NODE]);
            }
        }
        if(flag==1){
            ans++;
        }
    }
    return ans;
}
int countleft(node*root){
    if(root==nullptr)return 0;
    int sum=0;
    while (root!=nullptr){
        sum++;
        root=root->left;
    }
    return sum;
}
int countright(node*root){
    if(root==nullptr)return 0;
    int sum=0;
    while (root!=nullptr){
        sum++;
        root=root->right;
    }
    return sum;
}
int countNodes(node*root){
    if(root==nullptr){
        return 0;  
    }
    int left=countleft(root);
    int right=countright(root);
    if(left==right)return (1<<left)-1;
    else{
        return 1+countNodes(root->left)+countNodes(root->right);
    }
}
node* build(vector<int>&inorder,int instrt,int inend,vector<int>&preorder,int prestrt,int pre_end,unordered_map<int,int>&mpp){
    if(instrt>inend || prestrt>pre_end)return nullptr;
    node* root = new node(preorder[prestrt]);
    int inroot = mpp[root->data];
    int numsleft = inroot-instrt;
    root->left=build(inorder,instrt,inroot-1,preorder,prestrt+1,prestrt+numsleft,mpp);
    root->right=build(inorder,inroot+1,inend,preorder,prestrt+numsleft+1,pre_end,mpp);
    return root;
}
node* builfIo_PO(vector<int>&preorder,vector<int>&inorder){
    unordered_map<int,int> mpp;
    for(int i = 0 ; i < inorder.size() ; i++){
        mpp[inorder[i]]=i;
    }
    node* root = build(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1,mpp);
    return root;
}
node* buildpost(vector<int>&inorder,int instrt,int inend,vector<int>&postorder,int poststrt,int postend,unordered_map<int,int>&mpp){
    if(instrt>inend || poststrt>postend)return nullptr;
    node*root=new node(postorder[postend]);
    int inroot = mpp[root->data];    
    int left = inroot-instrt;
    root->left=buildpost(inorder,instrt,inroot-1,postorder,poststrt,poststrt+left-1,mpp);
    root->right=buildpost(inorder,inroot+1,inend,postorder,poststrt+left,postend-1,mpp);
    return root;
}
node* root(vector<int>&postorder,vector<int>&inorder){
    unordered_map<int,int> mpp;
    for(int i = 0 ; i < inorder.size() ; i++){
        mpp[inorder[i]]=i;
    }
    node*root=buildpost(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mpp);
    return root;
}
class codec{
public:
    string serialise(node*root){
        string str="";
        if(root==nullptr)return str;
        queue<node*>qe;
        qe.push(root);
        while (!qe.empty()){
            auto i = qe.front();
            qe.pop();
            if(i==nullptr){
                str.append("#,");
            }else{
                str.append(to_string(i->data)+",");
            }
            if(i!=nullptr){
                qe.push(i->left);
                qe.push(i->right);
            }
        }
        return str;
    }
    node* deserialise(string str){
        if(str.length()==0)return nullptr;
        stringstream ss(str);
        string s;
        getline(ss,s,',');
        node*root=new node(stoi(s));
        queue<node*>qe;
        qe.push(root);
        while (!qe.empty()){
            auto curr = qe.front();
            qe.pop();
            getline(ss,s,',');
            if(s=="#"){
                curr->left=nullptr;
            }else{
                curr->left=new node(stoi(s));
                qe.push(curr->left);
            }
            getline(ss,s,',');
            if(s=="#"){
                curr->right=nullptr;
            }else{
                curr->right=new node(stoi(s));
                qe.push(curr->right);
            }
        }
        return root;
    }
};
vector<int> morris_inorder(node*root){
    vector<int> ans;
    node*curr=root;
    while(curr!=nullptr){
        if(curr->left==nullptr){
            ans.push_back(curr->data);
            curr=curr->right;
        }else{
            node*temp=curr->left;
            while(temp->right!=nullptr && temp->right!=curr){
                temp=temp->right;
            }
            if(temp->right==nullptr){
                temp->right=curr;
                curr=curr->left;
            }else{
                temp->right=nullptr;
                ans.push_back(curr->data);
                curr=curr->right;
            }
        }
    }
    return ans; 
}
vector<int> morris_preorder(node*root){
    vector<int> ans;
    node*curr=root;
    while(curr!=nullptr){
        if(curr->left==nullptr){
            ans.push_back(curr->data);
            curr=curr->right;
        }else{
            node*temp=curr->left;
            while(temp->right!=nullptr && temp->right!=curr){
                temp=temp->right;
            }
            if(temp->right==nullptr){
                temp->right=curr;
                ans.push_back(curr->data);
                curr=curr->left;
            }else{
                temp->right=nullptr;
                curr=curr->right;
            }
        }
    }
    return ans; 
}
node*prevo=nullptr;
void BT2LL_recursive(node*root){
    if(root==nullptr){
        return;
    }
    BT2LL_recursive(root->right);
    BT2LL_recursive(root->left);
    root->right=prevo;
    root->left=nullptr;
    prevo=root;
}
void BT2LL_iterative(node*root){
    stack<node*> st;
    if (root == nullptr)
    return;
    st.push(root);
    while(!st.empty()){
        node*temp=st.top();
        st.pop();
        if(temp->right){
            st.push(temp->right);
        }
        if(temp->left){
            st.push(temp->left);
        }
        if(!st.empty()){
            temp->right=st.top();
            temp->left=nullptr;
        }
    }
}
void BT2LL_morris(node*root){
    node*curr=root;
    while(curr!=nullptr){
        if(curr->left){
            node*prev=curr->left;
            while(prev->right){
                prev=prev->right;
            }
            prev->right=curr->right;
            curr->right=curr->left;
            curr->left=nullptr;
        }
        curr=curr->right;
    }
}
int main(){ 
    return 0; 
}