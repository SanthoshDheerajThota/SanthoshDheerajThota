#include <iostream>
using namespace std;
class Set{
    private:
        int arr[20];
        int size;
        int removeDuplicates(int arr[],int size);
    public:
        Set();
        void setThem();
        void printThem();
        friend ostream & operator <<(ostream &output,const Set &s);
        friend istream & operator >>(istream &input,Set &s);
        Set operator+(Set s);
        Set operator-(Set s);
        Set operator^(Set s);
        ~Set();
};
ostream & operator <<(ostream &output,const Set &s){
    output<<"the set is "<<endl;
    for(int i=0;i<s.size;i++){
        output<<s.arr[i]<<"   ";
    }
    output<<endl;
    return output;
}
istream & operator >>(istream &input,Set &s){
    cout<<"enter the size of the set :"<<endl;
    input>>s.size;
    cout<<"enter "<<s.size<<" elements of the set"<<endl;
    for(int i=0;i<s.size;i++){
        input>>s.arr[i];
    }
    return input;
}
Set::Set(){
    size=0;
    for(int i=0;i<20;i++){
        arr[i]=0;
    }
}
void Set::setThem(){
    cout<<"enter the size of the set :"<<endl;
    cin>>size;
    cout<<"enter "<<size<<" element so set"<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
}
void Set::printThem(){
    if(this->size==0){
        cout<<"the set is empty "<<endl;
        return;
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}
int Set::removeDuplicates(int arr[],int size){
    int temp[20]={0};
    int realSize=0;
    for(int i=0;i<size;i++){
        int count=0;
        for(int j=0;j<realSize;j++){
            if(arr[i]==temp[j]){
                count++;
            }
        }
        if(count==0){
            temp[realSize]=arr[i];
            realSize++;
        }
    }
    for(int i=0;i<realSize;i++){
        arr[i]=temp[i];
    }
    return realSize;
}
Set Set::operator+(Set s){
    Set answer;
    for(int i=0;i<size;i++){
        answer.arr[i]=arr[i];
        answer.size++;
    }
    int temp=0;
    for(int i=size;i<(s.size+size);i++){
        answer.arr[i]=s.arr[temp];
        temp++;
        answer.size++;
    }
    answer.size=answer.removeDuplicates(answer.arr,answer.size);
    return answer;
}
Set Set::operator-(Set s){
    Set answer;
    for(int i=0;i<size;i++){
        int count=0;
        for(int j=0;j<s.size;j++){
            if(this->arr[i]==s.arr[j]){
                count++;
            }
        }
        if(count==0){
            answer.arr[answer.size]=this->arr[i];
            answer.size++;
        }
    }
    return answer;
}
Set Set::operator^(Set s){
    Set answer;
    for(int i=0;i<this->size;i++){
        for(int j=0;j<s.size;j++){
            if(this->arr[i]==s.arr[j]){
                answer.arr[answer.size]=arr[i];
                answer.size++;
            }
        }
    }
    answer.size=answer.removeDuplicates(answer.arr,answer.size);
    return answer;
}
Set::~Set(){

}
int main(){
    Set *s1=new Set,*s2= new Set;
    Set *unionSet=new Set,*minusSet=new Set,*intersectionSet=new Set;
    cout<<"for the set 1 :"<<endl;
    cin>>(*s1);
    cout<<"for the set 2 :"<<endl;
    cin>>(*s2);
    cout<<"the enetered set 1 is :"<<endl;
    cout<<(*s1);
    cout<<"the enetered set 2 is :"<<endl;
    cout<<(*s2);
    (*unionSet)=(*s1)+(*s2);
    cout<<"the resultant of set s1 union set2  s1 + s2 is :"<<endl;
    cout<<(*unionSet);
    (*minusSet)=(*s1)-(*s2);
    cout<<"the resultant of set1 minus set2  s1 - s2 is :"<<endl;
    cout<<(*minusSet);
    (*intersectionSet)=(*s1)^(*s2);
    cout<<"the resultant of set1 intersection set2  s1 ^ s2 is :"<<endl;
    cout<<(*intersectionSet);
    delete s1;
    delete s2;
    delete unionSet;
    delete intersectionSet;
    delete minusSet;
    return 0;
}
