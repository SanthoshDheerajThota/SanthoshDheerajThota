// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
void calculater(int n){
    static int count=0;
    if(n==1){
        cout<<"the count is "<<count;
    }
    else if(n%2!=0){
        count ++;
        calculater(n*3+1);
    }
    else if(n%2==0){
        count++;
        calculater(n/2);
    }
}
void calculate(int n){
    int count =0;
    while(n!=1){
        if(n%2==0){
            n=n/2;
            count++;
            continue;
        }
        else{
            n=n*3+1;
            count++;
            continue;
        }
    }
    cout<<"the count is "<<count;
}
void calculate_each_step(int number){
    int count=0;
    while(number!=1){
        if(number%2==0){
            count++;
            number=number/2;
            cout<<"step - "<<count<<"  =  "<<number<<endl;
            continue;
        }
        else if(number%2!=0){
            count ++;
            number=number*3+1;
            cout<<"step - "<<count<<"  =  "<<number<<endl;
        }
    }
    return ;
}
int main() {
    int number;
    cout<<"enter the number to search :"<<endl;
    cin>>number;
    calculate_each_step(number);
    
}
