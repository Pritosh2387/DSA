#include <bits/stdc++.h>
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
node* middle_of_a_LL(node*head){
    node*fast=head;
    node*slow=head;
    while(fast!=nullptr && fast->next!=nullptr){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
node*reverse_list(node*head){
    node*prev=nullptr;
    node*temp=head;
    while(temp!=nullptr){
        node*front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}
node*reverse_recursive(node*head){
    if(head==nullptr)return nullptr;
    if(head->next==nullptr)return head;
    node*newhead= reverse_recursive(head->next);
    node*front=head->next;
    front->next=head;
    head->next=nullptr;
    return newhead; 
}
bool detect_cycle(node*head){
    node*slow=head;
    node*fast=head;
    while(fast != nullptr &&  fast->next != nullptr){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}
node *detectCycle(node*head){
        node*slow=head;
        node*fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head;
                    while(slow!=fast){
                        slow=slow->next;
                        fast=fast->next;
                    }
                    return slow;
            }
        }
        return nullptr;
    }
int length_od_loop(node*head){
    node*slow=head;
    node*fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast){
            fast=fast->next;
            int cnt= 1;
            while(slow!=fast){
                cnt++;
                fast=fast->next;
            }
            return cnt;
        }
    }
    return 0 ; 
}
bool is_palindrome(node*head){
    if(head==nullptr || head->next==nullptr)return true;
    node*slow=head;
    node*fast=head;
    while(fast->next != nullptr && fast->next->next != nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    node*newhead = reverse_list(slow->next);
    node*temp=newhead;
    node*temp1=head;
    while(temp!=nullptr){
        if(temp->data!=temp1->data){
            node*dc=reverse_list(newhead);
            return false;
        }
        temp=temp->next;
        temp1=temp1->next;
    }
    node*dc=reverse_list(newhead);
    return true;
}
node* odd_then_even(node*head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    node*odd=head;
    node*even=head->next;
    node*evenhead=even;
    while(even!=nullptr && even->next!=nullptr){
        odd->next=odd->next->next;
        even->next=even->next->next;
        odd=odd->next;
        even=even->next;
    }
    head->next=evenhead;
    return head;
}
node* remove_nth_node_from_last(node*head,int n ){
    node*fast=head;
    for(int i = 0 ; i < n ; i++){
        fast=fast->next;
    }
    if(fast==nullptr){
        node*del=head;
        node*temp=head->next;
        delete head;
        return temp;
    }
    node*slow=head;;
    while(fast->next!=nullptr){
        fast=fast->next;
        slow=slow->next;
    }
    node*del=slow->next;
    slow->next=slow->next->next;
    delete del;
    return head;
}
node* delete_middle(node*head){
    node*slow=head;
    node*fast=head;
    fast=fast->next->next;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    node*del=slow->next;
    slow->next=slow->next->next;
    delete del;
    return head;
}
node* add_2_numbers(node* head1,node*head2){
    node*dummy= new node(-1);
    node*curr=dummy;
    node*temp1=head1;
    node*temp2=head2;
    int carry=0;
    while(temp1!=nullptr || temp2 !=nullptr){
        int sum = carry ;
        if(temp1!=nullptr){
            sum+=temp1->data;
            temp1=temp1->next;
        }
        if(temp2!=nullptr){
            sum+=temp2->data;
            temp2=temp2->next;
        }
        node* newnode = new node(sum%10);
        curr->next=newnode;
        curr=newnode;
        carry=sum/10;
    }
    if(carry>0){
        node*newnode=new node(carry);
        curr->next=newnode;
    }
    return dummy->next;
}
node* sort012(node*head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    node*head0=new node(-1);
    node*head1=new node(-1);
    node*head2=new node(-1);
    node*t0=head0;
    node*t1=head1;
    node*t2=head2;
    node*temp = head;
    while(temp!=nullptr){
        if(temp->data==0){
            t0->next=temp;
            t0=t0->next;
        }else if(temp->data==1){
            t1->next=temp;
            t1=t1->next;
        }else{
            t2->next=temp;
            t2=t2->next;
        }
        temp=temp->next;
    }
    if(head1->next){
        t0->next=head1->next;
    }else{
        t0->next=head2->next;
    }
    t1->next=head2->next;
    t2->next=nullptr;
    return head0->next;
}
int calculate_carry(node*temp){
    if(temp==nullptr){
        return 1;
    }
    int carry =calculate_carry(temp->next);
    temp->data+=carry;
    if(temp->data<10){
        return 0 ; 
    }else{
        return 1;
    }
}
node* add_1_recursive(node*head){
    int carry = calculate_carry(head);
    if(carry==1){
        node*newnode=new node (1);
        newnode->next=head;
        head = newnode;
    }
    return head;
}
node* intersection_of_linked_list( node*head1 , node*head2 ){
    if(head1==nullptr || head2==nullptr)return nullptr;
    node*temp1=head1;
    node*temp2=head2;
    while(temp1!=temp2){
        temp1=temp1->next;
        temp2=temp2->next;
        if(temp1==temp2){
            return temp1;
        }
        if(temp1==nullptr){
            temp1=head2;
        }
        if(temp2==nullptr){
            temp2=head1;
        }
    }
    return temp1; 
}
node* merge(node*head1,node*head2){
    node*temp1=head1;
    node*temp2=head2;
    node* dummy= new node(-1);
    node*temp=dummy;
    while(temp1!=nullptr && temp2!=nullptr){
        if(temp1->data>temp2->data){
            temp->next=temp2;
            temp2=temp2->next;
        }else{
            temp->next=temp1;
            temp1=temp1->next;
        }
        temp=temp->next;
    }
    while(temp1!=nullptr){
        temp->next=temp1;
        temp1=temp1->next;
        temp=temp->next;
    }
    while(temp2!=nullptr){
        temp->next=temp2;
        temp2=temp2->next;
        temp=temp->next;
    }
    node*head=dummy->next;
    return head;
}
node* middle_for_merge(node*head){
    node*slow=head;
    node*fast=head->next;
    while(fast!=nullptr && fast->next!=nullptr){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
node* merge_sort(node*head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    node* middle = middle_for_merge(head);
    node*right =middle->next;
    middle->next=nullptr;
    node*head1=merge_sort(head);
    node*head2=merge_sort(right);
    return merge(head1,head2);
}
node* getKth_node(node*head,int k ){
    int j = k-1;
    node*temp=head;
    while(temp!=nullptr && j>0){
        temp=temp->next;
        j--;
    }
    return temp;
}
node* reverese_nodes_k_grp(node*head,int k){
    node*temp=head;
    node*prev=nullptr;
    while(temp!=nullptr){
        node*kthnode=getKth_node(temp,k);
        if(kthnode==nullptr){
            if(prev){
                prev->next=temp;
                break;
            }
        }
        node*nextnode=kthnode->next;
        kthnode->next=nullptr;
        reverse_list(temp);
        if(kthnode==head){
            head=kthnode;
        }else{
            prev->next=kthnode;
        }
        prev=temp;
        temp=nextnode;
    }
    return head;
}
node* findk_th_node(node*head,int k){
    int cnt = 1;
    node*temp=head;
    while(temp!=nullptr){
        if(cnt==k){
            return temp;
        }
        cnt++;
        temp=temp->next;
    }
    return nullptr;
}
node* Rotate_LL(node*head,int k){
    if(head==nullptr || head->next==nullptr)return head;
    node*temp=head;
    node*tail;
    int len=0;
    while(temp!=nullptr){
        len++;
        if(temp->next==nullptr){
            tail=temp;
        }
        temp=temp->next;
    }
    int n =  k % len;
    if(n==0)return head;
    node* newlastnode = findk_th_node(head,len-n);
    tail->next=head;
    node*newhead=newlastnode->next;
    newlastnode->next=nullptr;
    return newhead;
}
int main() {
    vector<int> a = {1, 3, 10, 7};
    node* head1 = convert_arr_2LL(a);
    cout << "List 1: ";
    print_LL(head1);
    node* sorted = merge_sort(head1);
    cout << "Sorted List: ";
    print_LL(sorted);
    return 0;
}
