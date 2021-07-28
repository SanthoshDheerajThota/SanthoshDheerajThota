#include <iostream>
using namespace std;
class node{
    public :
        int data;
        node *next;
};
void insert(node *&head,int data){
    node *newnode=new node;
    newnode->data=data;
    newnode->next=head;
    head=newnode;
    return ;
}
void print(node *head){
    node *temp=head;
    while(temp->next!=NULL){
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
    return ;
}
void insert_at(node *head,int data,int index){
    node *temp=head;
    node *next=NULL;
    for(int i=0;i<index;i++){
        temp=temp->next;
        next=temp->next;
    }
    node *newnode=new node;
    newnode->data=data;
    newnode->next=next;
    temp->next=newnode;
    return ;
}
void reverse(node *&head){
    node *temp=head;
    node *previous=NULL;
    node *next=NULL;
    while(temp->next!=NULL){
        next=temp->next;
        temp->next=previous;
        previous=temp;
        temp=next;
    }
    temp->next=previous;
    head=temp;
    return ;
}
void delete_at(node *&head,int index=0){
    if(index==0){
        head=head->next;
        return ;
    }
    node *temp=head;
    node *previous=NULL;
    node *next=NULL;
    for(int i=0;i<index;i++){
        previous=temp;
        temp=temp->next;
        next=temp->next;
    }
    previous->next=next;
    return ;
}
void delete_at_end(node *&head){
    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp=NULL;
    return ;
}
class Stack{
    private :
        node *head=NULL;
        int sizer=0;
    public :
        void push(int data){
            insert(this->head,data);
            sizer++;
            return ;
        }
        void pop(){
            delete_at(head);
            sizer--;
            return ;
        }
        void print(){
            ::print(head);
        }
        int size(){
            return sizer;
        }
};
class Queue{
    private :
        node *head=NULL;
        int  sizer=0;
    public :
        void enqueue(int data){
            insert(this->head,data);
            sizer++;
        }
        void dequeue(){
            node *temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp=NULL;
            sizer--;
            return ;
        }
        void print(){
            ::print(head);
            return ;
        }
        int size(){
            return sizer;
        }
};
int main(){
    Stack santhosh;
    santhosh.push(12);
    santhosh.push(38);
    santhosh.push(82);
    santhosh.push(73);
    santhosh.push(333);
    santhosh.print();
    santhosh.pop();
    santhosh.print();
    Queue dheeraj;
    dheeraj.enqueue(12);
    dheeraj.enqueue(38);
    dheeraj.enqueue(82);
    dheeraj.enqueue(73);
    dheeraj.enqueue(333);
    dheeraj.print();
    dheeraj.dequeue();
    dheeraj.print();
    return 0;
}
