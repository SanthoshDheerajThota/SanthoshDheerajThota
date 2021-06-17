#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector <int> toDelete;
class node{
    public :
        int data;
        node *next;
};
void insert(node *&head,int data){
    node *newnode;
    newnode=new node;
    newnode->data=data;
    newnode->next=head;
    head=newnode;
    return;
}
void print(node *head){
    while(head->next!=NULL){
        cout<<head->data<<"   ";
        head=head->next;
    }
    cout<<head->data<<endl;
    return;
}
void deleteAt(node *&head,int index){
    if(index==0){
        head=head->next;
    }
    node *temp=head;
    node *previous;
    node *next;
    for(int i=0;i<index;i++){
        previous=temp;
        temp=temp->next;
        next=temp->next;
    }
    previous->next=next;
    return ;
}
int main(){
    node *head=NULL;
    int testCases;
    cout<<"enter the number of elements :"<<endl;
    cin>>testCases;
    for(int i=0;i<testCases;i++){
        int temp;
        cin>>temp;
        insert(head,temp);
    }
    print(head);
    deleteAt(head,3);
    print(head);
    return 0;
}
