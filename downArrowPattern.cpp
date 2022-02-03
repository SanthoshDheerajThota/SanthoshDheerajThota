#include <iostream>
using namespace std;
int main(){
    int num;
    cout<<"enter the number"<<endl;
    cin>>num;
    int f=1,b=num;
    for(int i=1;i<=num;i++){
        for(int j=1;j<=num;j++){
            if(f==b&&f==j){
                cout<<" "<<f<<" ";
                return 0;
            }
            if(j==f||j==b){
                cout<<" "<<j<<" "<<" ";
            }
            else{
                cout<<"   ";
            }
        }
        f++;
        b--;
        cout<<endl;
    }
}
