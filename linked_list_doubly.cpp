#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node*next;
    node*back;
    node(int data,node*back,node*next){
        this->data=data;
        this->back=back;
        this->next=next;
    }
    node(int data,node*back){
        this->data=data;
        this->next=nullptr;
        this->back=back;
    }
    node(int data){
        this->data=data;
        this->back=nullptr;
        this->next=nullptr;
    }
};
node* convert_arr_2LL(vector<int>&a){
    node*head=new node(a[0]);
    node*temp=head;
    for(int i = 1 ; i < a.size() ; i++){
        node*newnode=new node(a[i],temp);
        temp->next=newnode;
        temp=newnode;
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
node* delete_head(node*head){
    if(head==nullptr)return nullptr;
    else if(head->next==nullptr){
        delete head;
        return nullptr;
    }    
    node*temp=head;
    head=head->next;
    head->back=nullptr;
    delete temp;
    return head;
}
node* delete_tail(node*head){
    if(head==nullptr)return nullptr;
    else if(head->next==nullptr){
        delete head;
        return nullptr;
    }    
    node*temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }// temp is at second last
    node*dead=temp->next;//last 
    temp->next=nullptr;
    delete dead;
    return head;
}
node*delete_kth(node*head,int k ){
    if(head==nullptr){
        return nullptr;
    }
    node*temp=head;
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k){
            break;
        }
        temp=temp->next;
    }
    if(temp==nullptr){
        return head; // k > length
    }

    node*prev=temp->back;
    node* front=temp->next;
    if(prev==nullptr&&front==nullptr){
        delete temp;
        return nullptr;
    }else if(prev==nullptr){
        return delete_head(head);
    }else if(front==nullptr){
        return delete_tail(head);
    }else{
        prev->next=front;
        front->back=prev;
    }
    delete temp;
    return head;
}
node* insert_before_head(node*head,int val){
    node* newnode=new node(val,nullptr,head);
    head->back=newnode;
    head=newnode;
    return head;
}
node* insert_after_tail(node*head,int val){
    node*temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    node* newnode= new node(val,temp,nullptr);
    temp->next=newnode;
    return head;
}
node* insert_before_tail(node*head,int val){
    if(head->next==nullptr){
        return insert_before_head(head,val);
    }
    node*temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    node* newnode= new node(val,temp->back,temp);
    temp->back->next=newnode;
    temp->next=nullptr;
    temp->back=newnode;
    return head;
}
node* insert_before_kth(node*head,int val,int k){
    if(k==1){
        return insert_before_head(head,val);
    }
    node*temp=head;
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k){
            break;
        }
        temp=temp->next;
    }
    if (temp == nullptr) {// k is out of bounds,insert at tail
        return insert_after_tail(head, val);
    }
    node*prev=temp->back;
    node*newnode=new node(val,prev,temp);
    prev->next=newnode;
    temp->back=newnode;
    return head;
}
node*reverse_DD_list(node*head){
    node*curr=head;
    node*prev=nullptr;
    while(curr!=nullptr){
        prev=curr->back;
        curr->back=curr->next;
        curr->next=prev;
        curr=curr->back;
    }
    return prev->back;;
}
node* delete_all_occurances(node*head,int k){
    if(head==nullptr)return nullptr;
    node* temp = head;
    while(temp!=nullptr){
        if(temp->data==k){
            node* todelete=temp;
            node*prev=temp->back;
            node*nextnode=temp->next;
            if(temp==head){
                head=head->next;
                if(head!=nullptr)head->back=nullptr;
            }
            if(prev!=nullptr){
                prev->next=nextnode;
            }
            if(nextnode!=nullptr){
                nextnode->back=prev;
            }   
            temp=nextnode;
            delete todelete;
        }else{
            temp=temp->next;
        }
    }
    return head;
}
vector<pair<int,int>> two_sum_sorted(node*head,int sum){
    if (!head || !head->next) return {};
    vector<pair<int,int>> ans;
    node*x=head;
    while(x->next!=nullptr){
        x=x->next;
    }
    node*tail = x;
    node*lp=head;
    node*rp=tail;
    while(lp->data<rp->data){
        if(lp->data+rp->data==sum){
            ans.emplace_back(lp->data,rp->data);
            lp=lp->next;
            rp=rp->back;
        }else if(lp->data+rp->data>sum){
            rp=rp->back;
        }else{
            lp=lp->next;
        }
    }
    return ans;
}
node* remove_duplicates(node*head){
    if(head==nullptr || head->next==nullptr)return head;
    node*temp=head->next;
    node*prev=head;
    while(temp!=nullptr){
        if(temp->data==prev->data){
            node*todel=temp;
            temp=temp->next;
            prev->next = temp;
            if (temp != nullptr) temp->back = prev;
            delete todel;
        }else{
            prev->next=temp;
            temp->back=prev;
            prev=temp;
            temp=temp->next;
        }
    }
    return head;
}
int main(){
    vector<int> a = {2, 10,7,10,10,10 ,3, 8};
    node*head=convert_arr_2LL(a);
    print_LL(head);
    node*x=delete_all_occurances(head,10);
    print_LL(x);
    return 0 ; 
}