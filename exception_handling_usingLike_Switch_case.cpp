#include <iostream>
using namespace std;
class santhosh{
    private :
        int data;
    public :
        void geteData(){
            cout<<"enter  tha data :"<<endl;
            cin>>this->data;
            cout<<"santhosh entered the data is "<<this->data<<endl;
        }
};
class dheeraj{
    private :
        int data;
    public :
        void geteData(){
            cout<<"enter  tha data :"<<endl;
            cin>>this->data;
            cout<<"dheeraj entered the data is "<<this->data<<endl;
        }
};
class laddu{
    private :
        int data;
    public :
        void geteData(){
            cout<<"enter  tha data :"<<endl;
            cin>>this->data;
            cout<<"laddu entered the data is "<<this->data<<endl;
        }
};
int main(){
    try{
        int number;
        cout<<"enter as your choice :"<<endl;
        cout<<"enter 1 for santhosh :"<<endl;
        cout<<"enter 2 for dheeraj  :"<<endl;
        cout<<"enter 3 for laddu    :"<<endl;
        cin>>number;
        if(number==1){
            santhosh thota;
            throw thota;
        }
        else if(number==2){
            dheeraj thota;
            throw thota;
        }
        else if(number==3){
            laddu thota;
            throw thota;
        }
        throw;
    }
    catch(santhosh thota){
        thota.geteData();
    }
    catch(dheeraj thota){
        thota.geteData();
    }
    catch(laddu thota){
        thota.geteData();
    }
    catch(...){
        cout<<"enter a godd choice "<<endl;
    }
    return 0;
}
