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
node* searchBST(node*root,int data){
    while(root!=nullptr&& root->data!=data){
        root = root->data>data?root->left:root->right;
    }
    return root;
}
int ceilo(node*root,int key){
    int ans=-1;
    while(root){
        if(root->data==key){
            ans=root->data;
            return ans;
        }
        if(root->data>key){
            ans=root->data;
            root=root->left;
        }else{
            root=root->right;
        }
    }
    return ans;
}
int flooro(node*root,int key){
    int ans=-1;
    while(root){
        if(root->data==key){
            ans=root->data;
            return ans;
        }
        if(root->data>key){
            root=root->left;
        }else{
            ans=root->data;
            root=root->right;
        }
    }
    return ans;
}
node* insertBST(node*root,int data){
    if(root==nullptr)return new node(data);
    node*temp=root;
    while(true){
        if(temp->data>data){
            if(temp->left){
                temp=temp->left;
            }else{
                temp->left = new node(data);
                break;
            }
        }else{
            if(temp->right){
                temp=temp->right;
            }else{
                temp->right = new node(data);
                break;
            }
        }
    }
    return root;
}
node* rightmost(node*root){
    while(root->right!=nullptr){
        root=root->right;
    }
    return root;
}
node*helper(node*root){
    if(root->left==nullptr)return root->right;
    else if(root->right==nullptr)return root->left;
    node* rightchild=root->right;
    node* rightmostnode = rightmost(root->left);
    rightmostnode->right=rightchild;
    return root->left;
}
node* delete_node(node*root,int key){
    if(root==nullptr){
        return nullptr;
    }
    if(root->data==key){
        return helper(root);
    }
    node*curr=root;
    while(curr!=nullptr){
        if(curr->data>key){
            if(curr->left!=nullptr && curr->left->data==key){
                curr->left=helper(curr->left);
                break;
            }else{
                curr=curr->left;
            }
        }else{
            if(curr->right!=nullptr && curr->right->data==key){
                curr->right=helper(curr->right);
                break;
            }else{
                curr=curr->right;
            }
        }
    }
    return root;
}
int k_th_smallest(node*root,int k ){
    int key = 0; 
    node*curr=root;
    while(curr!=nullptr){
        if(curr->left==nullptr){
            key++;
            if (key == k) return curr->data;
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
                key++;
                if (key == k) return curr->data;
                curr=curr->right;
            }
        }    
    }
    return -1;
}
bool BST_or_not(node*root,long long mini,long long maxi){
    if(root==nullptr)return true;
    if(root->data>=maxi || root->data<=mini){
        return false;
    }
    return(BST_or_not(root->left,mini,root->data) && BST_or_not(root->right,root->data,maxi));
}
node* lca(node*root,node*p,node*q){
    if(root==nullptr){
        return nullptr;
    }
    if(p->data>root->data && q->data>root->data){
        return lca(root->right,p,q);
    }
    if(p->data<root->data && q->data<root->data){
        return lca(root->left,p,q);
    }
    return root;
}
node* BST_from_pre(vector<int>&preorder,int&i,int maxi){
    if(i>=preorder.size() || preorder[i]>maxi){
        return nullptr;
    }
    node*root=new node(preorder[i++]);
    root->left=BST_from_pre(preorder,i,root->data);
    root->right=BST_from_pre(preorder,i,maxi);
    return root;
}
node* inordersuccesor(node*root,node*p){
    node*curr=root;
    node*ans=nullptr;
    while(curr!=nullptr){
        if(curr->data>p->data){
            ans=curr;
            curr=curr->left;
        }else{
            curr=curr->right;
        }
    }
    return ans;
}
class bst_iterator{
public:
    stack<node*>st;
    bool reverse = true;
    // true->prev
    // false->next
    void push_all(node*root){
        while(root){
            st.push(root);
            if(reverse){
                root=root->right;
            }else{
                root=root->left;
            }
        }
    }
    bst_iterator(node*root,bool isreverse){
        reverse=isreverse;
        push_all(root);
    }
    int next(){
        node*NODE=st.top();
        st.pop();
        if(reverse){
            push_all(NODE->left);
        }else{
            push_all(NODE->right);
        }
        return NODE->data;
    }
    bool hasNext(){
        return !st.empty();
    }
};
bool two_sum(node*root,int sum){
    if(root==nullptr)return false;
    bst_iterator l(root,false); 
    bst_iterator r(root,true);
    int i = l.next();
    int j = r.next();
    while(i<j){
        if(i+j==sum){
            return true;
        }else if(i+j>sum){
            j=r.next();
        }else{
            i=l.next();
        }
    }
    return false;
}
node*previ;
node*middle=nullptr;
node*first=nullptr;
node*last;
void inorder(node*root){
    if(root==nullptr)return;
    inorder(root->left);
    if(previ!=nullptr  && root->data< previ->data){
        if(first==nullptr){
            middle=root;
            first=previ;
        }else{
            last=root;
        }
    }
    previ=root;
    inorder(root->right);
}
void recover_tree(node*root){
    previ = new node(INT_MIN);
    last=middle=first=nullptr;
    inorder(root);
    if(first && last)swap(first->data,last->data);
    else if(first && middle)swap(middle->data,first->data);
}
class Nodevalue{
public:
    int mini;
    int maxi;
    int size;
    Nodevalue(int mini,int maxi,int size): mini(mini),maxi(maxi),size(size){}
};
Nodevalue largestBST(node*root){
    if(root==nullptr){
        return Nodevalue(INT_MAX,INT_MIN,0);
    }
    auto left = largestBST(root->left);
    auto right=largestBST(root->right);
    if(root->data>left.maxi && root->data<right.mini){
        return Nodevalue(min(root->data,left.mini),max(root->data,right.maxi),left.size+right.size+1);
    }
    return Nodevalue(INT_MIN,INT_MAX,max(left.size,right.size));
}
int main(){
    return 0;
}