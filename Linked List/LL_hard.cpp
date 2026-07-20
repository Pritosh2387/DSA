#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node* next;
    node* child;
    node(int data){
        this->data=data;
        this->child=nullptr;
        this->next=nullptr;
    }
};
node * merge(node*list1,node*list2){
    node * dummy = new node(-1);
    node * temp=dummy;
    while(list1!=nullptr && list2!=nullptr){
        if(list1->data<list2->data){
            temp->child=list1;
            temp=list1;
            list1=list1->child;
        }else{
            temp->child=list2;
            temp=list2;
            list2=list2->child;
        }
        temp->next=nullptr;
    }
    if(list1){
        temp->child=list1;
    }else{
        temp->child=list2;
    }
    node*del=dummy;
    node* newhead=dummy->child;
    delete del;
    return newhead;
}
node*flat_ll(node*head){
    if(head==nullptr || head->next==nullptr)return head;
    node*merged=flat_ll(head->next);
    head=merge(merged,head);
    return head;
}