#include <iostream>
#include <cmath>
using namespace std;
class simpleCalculator{
    protected :
        int num1;
        int num2;
    public :
        void setData(){
            cout<<"enter two numbers :"<<endl;
            cin>>this->num1>>this->num2;
        }
        void showThem(){
            cout<<"the entered two numbers are "<<this->num1<<" , "<<this->num2<<endl;
        }
        void operate(){
            setData();
            showThem();
            int choice;
            cout<<"enter teh operation you want to perform "<<endl;
            cout<<" 1) +    2) /    3) *     4)-"<<endl;
            cin>>choice;
            switch(choice){
                case 1:
                    cout<<"the sum of "<<num1<<" + "<<num2<<" = "<<num1+num2<<endl;
                    break;
                case 2 :
                    cout<<"the / of "<<num1<<" / "<<num2<<" = "<<num1/num2<<endl;
                    break;
                case 3:
                    cout<<"the product of "<<num1<<" x "<<num2<<" = "<<num1*num2<<endl;
                    break;
                case 4:
                    cout<<"the minus of "<<num1<<" - "<<num2<<" = "<<num1-num2<<endl;
                    break;
                default:
                    break;
            }
            return;
        }
};
class scientificCalculator{
    protected :
        float angle;
        float value;
        float number;
        float power;
    public :
        void operate(){
            int choice;
            cout<<"enter teh operation you want to perform "<<endl;
            cout<<" 1) sin    2) cos    3) tan     4)log"<<endl;
            cin>>choice;
            cout<<"enter the number you wish to operate on"<<endl;
            cin>>this->value;
            switch(choice){
                case 1:
                    cout<<"sin("<<this->value<<") = "<<sin(this->value)<<endl;
                    break;
                case 2 :
                    cout<<"cos("<<this->value<<") = "<<cos(this->value)<<endl;
                    break;
                case 3:
                    cout<<"tan("<<this->value<<") = "<<tan(this->value)<<endl;
                    break;
                case 4:
                    cout<<"log("<<this->value<<") = "<<log(this->value)<<endl;
                    break;
                default:
                    break;
            }
        }
};
class hybridCalculator:public simpleCalculator,public scientificCalculator{
    int choiceOfUser;
    public:
        void operate(){
            while(true){
                cout<<"do you wnat to use simple(1) or scientific(2) exit(0)"<<endl;
                cin>>this->choiceOfUser;
                switch(this->choiceOfUser){
                    case 0:
                        cout<<"thank you for using the program have a nice day"<<endl;
                        return;
                    case 1:
                        simpleCalculator::operate();
                        break;
                        break;
                    case 2:
                        scientificCalculator::operate();
                        break;
                    default:
                        cout<<"you entered wrong input waste fellow"<<endl;
                        break;
                }
            }
        }
};
int main(){
    hybridCalculator calculator;
    calculator.operate();
}
