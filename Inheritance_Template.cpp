//this code is written by T.Santhosh Dheeraj
#include <iostream>
using namespace std;
template <class T>
class santhosh{
    protected :
        T data;
    public :
        virtual void setData()=0;
        virtual void printData()=0;
};
template <class T>
class  A :virtual public santhosh<T> {  //this is called dynamic polymorphism or ad hoc
    private :
        T derivedClassData;
    public :
        void setData(){
            cout<<"enetr the data and other data of the derived class  :"<<endl;
            cin>>this->data>>this->derivedClassData;
        }
        void printData(){
            cout<<"the data is "<<this-> data<<endl;
            cout<<"the derived class data is "<<this->derivedClassData<<endl;
        }
};
template <class T>
class B :virtual public santhosh<T>{
    private :
        T name;
        int age;
        T mobilenumber;
        void setData(){
            cout<<"eneter the name of the person and age of the person :"<<endl;
            cin>>this->name>>this->age;
            cout<<"enetr his data and mobile number :"<<endl;
            cin>>this->data>>this->mobilenumber;
        }
        void printData(){
            cout<<"the name of the person is "<<this->name<<endl;
            cout<<"the age of the person is "<<this->age<<endl;
            cout<<" the data of the person is "<<this-> data<<endl;
            cout<<"the mobile number of the person is "<<this->mobilenumber<<endl;
        }
};
int main(){
    santhosh<string> *mySan;
    mySan=new A<string>;
    mySan->setData();
    mySan->printData();
    cout<<endl;
    mySan=new B<string>;
    mySan->setData();
    mySan->printData();
    return 0;
}
