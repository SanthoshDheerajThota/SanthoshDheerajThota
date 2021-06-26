//this code is completely written by T.Santhosh Dheeraj
#include <iostream>
using namespace std;
template <class T>
class Santhosh{
    private :
        T data;
    public :
        void setData();
        void print();
        
        template<class S>
        friend void printIt(Santhosh<S> dheeraj);
};
template<class T>
void Santhosh<T>::setData(){
    cout<<"enter the data "<<endl;
    cin>>data;
}
template<class T>
void Santhosh<T>::print(){
    cout<<"the data is "<<data<<endl;
}
template<class T>
void printIt(Santhosh<T> dheeraj){
    cout<<"the data is "<<dheeraj.data<<endl;
}
int main(){
    Santhosh <string> myObj;
    myObj.setData();
    myObj.print();
    printIt(myObj);
    return 0;
}
