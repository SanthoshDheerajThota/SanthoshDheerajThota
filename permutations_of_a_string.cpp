/*
  this program is completely written by T.Santhosh Dheeraj.This is a recursive way to print all the possible permutations of a string
*/
#include <iostream>
using namespace std;
void permutation(string s,string answer){
    if(s.length()==0){
        cout<<answer<<endl;
        return ;
    }
    for(int i=0;i<s.length();i++){
        char fixed=s[i];
        string ros=s.substr(0,i)+s.substr(i+1);
        permutation(ros,answer+fixed);
    }
}
int main() {
    string name;
    cin>>name;
    permutation(name,"");
    return 0;
}
