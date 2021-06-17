//this program is completely written by T.Santhosh Dheeraj
#include <iostream>
using namespace std;
class car{
    protected:
        string regNumer;
        int year;
        string ownerName;
        string mobilenumber;
    public :
        virtual void setData()=0;
        virtual void printData()=0;
        friend class MyCarRecord;
};
class BMW : public car{
    protected :
        string modelNumber;
    public :
        void setData(){
            cout<<"Enter the name of the owner of the BMW  :"<<endl;
            cin>>this->ownerName;
            cout<<"enter the reg Number of the BMW  : "<<endl;
            cin>>this->regNumer;
            cout<<"enter the mobile number of the owner of the BMW  :"<<endl;
            cin>>mobilenumber;
            cout<<"enter the year of purchase and model number  of the BMW :"<<endl;
            cin>>year>>modelNumber;
        }
        void printData(){
            cout<<"the name of the owner of the BMW is  :"<<this->ownerName<<endl;
            cout<<"the reg Number of the BMW is  : "<<this->regNumer<<endl;
            cout<<"the mobile number of the owner of the BMW is  :"<<this->mobilenumber<<endl;
            cout<<"the year of purchase and model number of the BMW is  :"<<this->year<<" "<<this->modelNumber<<endl;
        }
        friend class MyCarRecord;
};
class Lambhorghini : public car{
    protected :
        string modelNumber;
    public :
        void setData(){
            cout<<"Enter the name of the owner of the Lambhorgini  :"<<endl;
            cin>>this->ownerName;
            cout<<"enter the reg Number of the  Lambhorgini  : "<<endl;
            cin>>this->regNumer;
            cout<<"enter the mobile number of the owner of the  Lambhorgini  :"<<endl;
            cin>>mobilenumber;
            cout<<"enter the year of purchase and model number  of the  Lambhorgini :"<<endl;
            cin>>year>>modelNumber;
        }
        void printData(){
            cout<<"the name of the owner of the  Lambhorgini is  :"<<this->ownerName<<endl;
            cout<<"the reg Number of the  Lambhorgini is  : "<<this->regNumer<<endl;
            cout<<"the mobile number of the owner of the  Lambhorgini is  :"<<this->mobilenumber<<endl;
            cout<<"the year of purchase and model number of the  Lambhorgini is  :"<<this->year<<" "<<this->modelNumber<<endl;
        }
        friend class MyCarRecord;
};
class Ferari : public car{
    protected :
        string modelNumber;
    public :
        void setData(){
            cout<<"Enter the name of the owner of the Ferrari  :"<<endl;
            cin>>this->ownerName;
            cout<<"enter the reg Number of the Ferrari  : "<<endl;
            cin>>this->regNumer;
            cout<<"enter the mobile number of the owner of the Ferrari  :"<<endl;
            cin>>mobilenumber;
            cout<<"enter the year of purchase and model number  of the Ferrari :"<<endl;
            cin>>year>>modelNumber;
        }
        void printData(){
            cout<<"the name of the owner of the Ferrari is  :"<<this->ownerName<<endl;
            cout<<"the reg Number of the Ferrari is  : "<<this->regNumer<<endl;
            cout<<"the mobile number of the owner of the Ferrari is  :"<<this->mobilenumber<<endl;
            cout<<"the year of purchase and model number of the Ferrari is  :"<<this->year<<" "<<this->modelNumber<<endl;
        }
        friend class MyCarRecord;
};
class Tesla : public car{
    protected :
        string modelNumber;
    public :
        void setData(){
            cout<<"Enter the name of the owner of the Tesla   :"<<endl;
            cin>>this->ownerName;
            cout<<"enter the reg Number of the Tesla   : "<<endl;
            cin>>this->regNumer;
            cout<<"enter the mobile number of the owner of the Tesla   :"<<endl;
            cin>>mobilenumber;
            cout<<"enter the year of purchase and model number  of the Tesla  :"<<endl;
            cin>>year>>modelNumber;
        }
        void printData(){
            cout<<"the name of the owner of the Tesla  is  :"<<this->ownerName<<endl;
            cout<<"the reg Number of the Tesla  is  : "<<this->regNumer<<endl;
            cout<<"the mobile number of the owner of the Tesla  is  :"<<this->mobilenumber<<endl;
            cout<<"the year of purchase and model number of the Tesla  is  :"<<this->year<<" "<<this->modelNumber<<endl;
        }
        friend class MyCarRecord;
};
class node{
    private :   
        car *data;
        node *next;
    public :
        friend class MyCarRecord;
};
class MyCarRecord{
    private:
        node  *head;
        int size;
    public :
        MyCarRecord(){
            size=0;
            head=NULL;
        }
        void newData(){
            node *newnode=new node;
            cout<<"which car you want :"<<endl;
            cout<<" 1)BMW 2)Lambhorgini 3)Ferrari 4)Tesla "<<endl;
            int temp;
            cin>>temp;
            switch (temp)
            {
            case 1:
                newnode->data=new BMW;
                newnode->data->setData();
                break;
            case 2:
                newnode->data=new Lambhorghini;
                newnode->data->setData();
                break;
            case 3:
                newnode->data=new Ferari;
                newnode->data->setData();
                break;
            case 4:
                newnode->data=new Tesla;
                newnode->data->setData();
                break;
            default:
                break;
            }
            newnode->next=head;
            head=newnode;
            size++;
        }
        void printAll(){
            node *temp=head;
            while(temp->next!=NULL){
                temp->data->printData();
                cout<<endl;
                temp=temp->next;
            }
            temp->data->printData();
            cout<<endl;
        }
};
int main(){
    MyCarRecord record;
    record.newData();
    cout<<endl;
    record.printAll();
}
