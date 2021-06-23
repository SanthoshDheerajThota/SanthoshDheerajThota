//this code is Completely written by T.Santhosh Dheeraj
#include <iostream>
using namespace std;
template <class T>
class Santhosh{
    T data1,data2;
    public :
        void setData(){
            cin>>this->data1;
            cin>>this->data2;
        }
        void printData(){
            cout<<"the data 1 is "<<data1;
            cout<<endl<<"the data 2 is "<<data2<<endl;
        }
        void addThem(){
            T answer=data1+data2;
            cout<<answer;
        }
};
class Matrix{
    protected :
        int arr[10][10];
        int order;
    public :
        friend istream & operator >>(istream &input,Matrix &m);
        friend ostream & operator <<(ostream &output,const Matrix &m);
        Matrix operator +(Matrix &m);
};
istream &operator >>(istream &input,Matrix &m){
    cout<<"enter the order of matrix :"<<endl;
    input>>m.order;
    for(int i=0;i<m.order;i++){
        for(int j=0;j<m.order;j++){
            input>>m.arr[i][j];
        }
    }
    return input;
}
ostream &operator <<(ostream &output,const Matrix &m){
    output<<"the matrix is "<<endl;
    for(int i=0;i<m.order;i++){
        for(int j=0;j<m.order;j++){
            output<<m.arr[i][j]<<"   ";
        }
        output<<endl;
    }
    return output;
}
Matrix Matrix ::operator+(Matrix &m){
    Matrix answer;
    answer.order=m.order;
    for(int i=0;i<this->order;i++){
        for(int j=0;j<this->order;j++){
            answer.arr[i][j]=this->arr[i][j]+m.arr[i][j];
        }
    }
    return answer;
}
int main(){
    Santhosh<Matrix> MyObj;
    MyObj.setData();
    MyObj.printData();
    MyObj.addThem();
    return 0;
}
