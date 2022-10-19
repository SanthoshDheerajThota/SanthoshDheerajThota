/*
    This code is completely written by T.Santhosh Dheeraj
*/
#include <iostream>
using namespace std;
class node{
    public :   
        int data;
        node *next;
};
void insert_at_begin(node *&head,int data){
    node *newnode=new node();
    newnode->data=data;
    newnode->next=head;
    head=newnode;
}
void printrev(node *head){
    if(head==NULL){
        return ;
    }
    else{
        printrev(head->next);
        cout<<head->data;
    }
}
void insert_at_end(node *&head,int data){
    if(head==NULL){
        head=new node();
        head->data=data;
        head->next=NULL;
        return ;
    }
    else{
        node *newnode=new node();
        newnode->data=data;
        newnode->next=NULL;
        node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        return ;
    }
}
int call(node *&answer,int sum){
    int carry;
    if(sum>=10){
            int k=sum%10;
            insert_at_end(answer,k);
            k=sum/10;
            carry=k;
        }
        else{
            insert_at_end(answer,sum);
            carry=0;
        }
        return carry;
}
void add(node *head1,node *head2){
    node *answer=NULL;
    int carry=0;
    while(head1!=NULL&&head2!=NULL){
        int sum=head1->data+head2->data+carry;
        carry=call(answer,sum);
        head1=head1->next;
        head2=head2->next;
    }
    if(head1!=NULL||head2!=NULL){
        if(head2!=NULL){
            while(head2){
                int sum=head2->data+carry;
                carry=call(answer,sum);
                head2=head2->next;
            }
        }
        else{
            while(head1){
                int sum=head1->data+carry;
                carry=call(answer,sum);
                head1=head1->next;
            }
        }
    }
    if(carry!=0){
        call(answer,carry);
    }
    printrev(answer);
}
void load(node *&head,int data){
    while(data){
        insert_at_begin(head,data%10);
        data=data/10;
    }
    return ;
}
int main(){
    node *head1=NULL,*head2=NULL;
    int num1,num2;
    cout<<"Enter the number one and number 2 :"<<endl;
    cin>>num1>>num2;
    load(head1,num1);
    load(head2,num2);
    printrev(head1);
    cout<<endl;
    printrev(head2);
    cout<<endl;
    add(head1,head2);
    return 0;
}
