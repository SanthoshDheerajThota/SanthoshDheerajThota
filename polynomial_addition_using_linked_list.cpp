/*
      This code is completely written by T.Santhosh Dheeraj
*/
#include <iostream>
using namespace std;
class node{
    public:
    int coeff,pow;
    node *next;
};
void insert(node *&head,int coeff,int pow){
    node *newnode=new node();
    newnode->coeff=coeff;
    newnode->pow=pow;
    newnode->next=head;
    head=newnode;
    return ;
}
void print(node *head){
    while(head->next!=NULL){
        cout<<head->coeff<<"x^"<<head->pow<<" + ";
        head=head->next;
    }
    cout<<head->coeff<<"x^"<<head->pow<<endl;
}
void add(node *head1,node *head2){
    node *answer=NULL;
    while(head1!=NULL&&head2!=NULL){
        if(head1->pow==head2->pow){
            insert(answer,(head1->coeff+head2->coeff),head1->pow);
            head1=head1->next;
            head2=head2->next;
        }
        else if(head2->pow>head1->pow){
            insert(answer,head2->coeff,head2->pow);
            head2=head2->next;
        }
        else{
            insert(answer,head1->coeff,head1->pow);
            head1=head1->next;
        }
    }
    while(head1!=NULL){
        insert(answer,head1->coeff,head1->pow);
        head1=head1->next;
    }
    while(head2!=NULL){
        insert(answer,head2->coeff,head2->pow);
        head2=head2->next;
    }
    print(answer);
}
int main(){
    node *head1=NULL;
    node *head2=NULL;
    insert(head1,1,0);
    insert(head1,6,1);
    insert(head1,2,3);
    insert(head1,3,4);
    insert(head2,5,0);
    insert(head2,2,1);
    insert(head2,3,3);
    insert(head2,12,6);
    print(head1);
    print(head2);
    add(head1,head2);
    return 0;
}
