/*
  This code is completely written by T.Santhosh Dheeraj
*/
#include <iostream>
using namespace std;
int main(){
    string rolNumber;
    cout<<"enter the roll number     :"<<endl;
    cin>>rolNumber;
    cout<<"your year is              : "<<rolNumber[5]<<rolNumber[6]<<endl;
    //1602-20-735-158
    int no=0;
    for(int i=12;i<15;i++){
        int temp;
        switch (rolNumber[i])
        {
            case '0':
                no=no*10+0;
                break;
            case '1':
                no=no*10+1;
                break;
            case '2':
                no=no*10+2;
                break;
            case '3':
                no=no*10+3;
                break;
            case '4':
                no=no*10+4;
                break;
            case '5':
                no=no*10+5;
                break;
            case '6':
                no=no*10+6;
                break;
            case '7':
                no=no*10+7;
                break;
            case '8':
                no=no*10+8;
                break;
            case '9':
                no=no*10+9;
                break;
            default :
                break;
        }
    }
    int code=0;
    for(int i=8;i<11;i++){
        int temp;
        switch (rolNumber[i])
        {
            case '0':
                code=code*10+0;
                break;
            case '1':
                code=code*10+1;
                break;
            case '2':
                code=code*10+2;
                break;
            case '3':
                code=code*10+3;
                break;
            case '4':
                code=code*10+4;
                break;
            case '5':
                code=code*10+5;
                break;
            case '6':
                code=code*10+6;
                break;
            case '7':
                code=code*10+7;
                break;
            case '8':
                code=code*10+8;
                break;
            case '9':
                code=code*10+9;
                break;
            default :
                break;
        }
    }
    if(code==735){
        cout<<"you are form Branch   :   ECE"<<endl;
    }
    else if(code==737){
        cout<<"you are form Branch   :   CSE"<<endl;
    }
    else if(code==748){
        cout<<"you are form Branch   :   AI and ML"<<endl;
    }
    cout<<"your roll number is       : "<<no<<endl;
    if(no<=60){
        cout<<"you are from section  :   A"<<endl;
    }
    else if(no<=120){
        cout<<"you are from section  :   B"<<endl;
    }
    else{
        cout<<"you are from section  :   C"<<endl;
    }
    return 0;
}
